/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

/*******************************************************************************
  Application File Handle Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_file_handler.c

  Summary:
    This file contains the source code for the file manipulation part of the application.

  Description:
    SD Card File manipulation is treated here
 *******************************************************************************/


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Local Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
/* This section lists the other files that are included in this file.
 */
// file handler defines
#include "app_file_handler.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
// the result of the SD Card parsing
static APP_MEDIA_DATA CACHE_ALIGN appMediaData;

// list of supported file extensions
static const char * const supportedExtensions[] =
{
#if defined(APP_SUPPORT_JPEG)
    ".JPG",
    ".JPEG",
    ".jpg",
    ".jpeg",
#endif
#if defined(APP_SUPPORT_BMP)
    ".bmp",
    ".BMP",
#endif
#if defined(APP_SUPPORT_PNG)
    ".png",
    ".PNG",
#endif
#if defined(APP_SUPPORT_GIF)
    ".gif",
    ".GIF",
#endif
};
#define EXTENSION_TABLE_SIZE  ( sizeof(supportedExtensions)/sizeof(supportedExtensions[0]) )

// local array used to keep temporary file and folder names while reading a folder
static char tempFileName[SYS_FS_FILE_NAME_LEN + 1];

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_SYSFS_EventHandler(SYS_FS_EVENT event, void * eventData, uintptr_t context);

  Summary:
    Callback handler for SYS FS Events

  Description:
    This is function is setup to be called handle sdcard mount and unmount events
*/
void APP_FileHandler_SYS_FS_EventHandler(SYS_FS_EVENT event, void * eventData, uintptr_t context)
{
    switch(event)
    {
        case SYS_FS_EVENT_MOUNT:
            if ( !memcmp((void*)eventData, (const void*)APP_SYS_FS_MOUNT_POINT, strlen((char*)APP_SYS_FS_MOUNT_POINT)) ) {
                SYS_CONSOLE_PRINT("SYS_Initialize: The %s File System is mounted from %s to %s\r\n", APP_SYS_FS_TYPE_STRING, APP_SYS_FS_SD_VOL, APP_SYS_FS_MOUNT_POINT);

                appMediaData.fileSystemMountStatus = APP_FILE_MEDIA_MOUNTED;
            }
            break;
            
        case SYS_FS_EVENT_UNMOUNT:
            if ( !memcmp((void*)eventData, (const void*)APP_SYS_FS_MOUNT_POINT, strlen((char*)APP_SYS_FS_MOUNT_POINT)) ) {
                SYS_CONSOLE_PRINT("SYS_Initialize: The %s File System is unmounted\r\n", APP_SYS_FS_TYPE_STRING);

                appMediaData.fileSystemMountStatus = APP_FILE_MEDIA_UNMOUNTED;
            }
            break;
            
        default:
            break;
    }

    // reset the data stored into the file handler
    APP_FileHandler_ResetData();
    
    return;
}

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Global Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

// Initialize data to startup values
void APP_FileHandler_Initialize()
{
    static bool initialized = false;
    
    // prevent double initialization
    if (initialized) {
        return;
    }
    appMediaData.fileSystemMountStatus = APP_FILE_MEDIA_UNMOUNTED;
    
    // reset the data stored into the file handler
    APP_FileHandler_ResetData();

    // add callback for mount and unmount of the sd card
    SYS_FS_EventHandlerSet(APP_FileHandler_SYS_FS_EventHandler, (uintptr_t)NULL);
       
    return;
}

// Initialize data to startup values
void APP_FileHandler_ResetData()
{
    // no files available
    appMediaData.totalFiles = 0;

    // clear the file name table
    memset(appMediaData.fileNameTable, 0, sizeof(appMediaData.fileNameTable));
    
    // clear the folder table
    memset(appMediaData.dirTable, 0, sizeof(appMediaData.dirTable));
    
    // add the root folder as first folder on the media
    sprintf(appMediaData.dirTable[0].mediaFullPath, "%s", APP_SYS_FS_MOUNT_POINT);
    
    // set the number of folders to 1 - this is the root of the drive
    appMediaData.dirCount = 1;
    
    // set the index of the folder to be examined to 0 - the root of the drive
    appMediaData.dirIndex = 0;
    
    return;
}

// Says if some Media available to show or not
bool APP_FileHandler_IsMediaMounted() 
{
    return (appMediaData.fileSystemMountStatus != APP_FILE_MEDIA_UNMOUNTED);
}

// Says if some Media available to show or not
bool APP_FileHandler_IsMediaLoaded()
{
    return (appMediaData.fileSystemMountStatus == APP_FILE_MEDIA_LOADED);
}

// Recursively traverse a folder structure and get supported media files
bool APP_FileHandler_GatherAvailableMedia()
{
    bool result = true;
    // pointer to the folder the function is looking into
    char* dirName;
    // folder handle
    SYS_FS_HANDLE dirHandle = SYS_FS_HANDLE_INVALID;
    // file handle
    SYS_FS_HANDLE fileHandle = SYS_FS_HANDLE_INVALID;
    // the result of the folder read
    static SYS_FS_FSTAT fsStat;
    // result of the folder read
    SYS_FS_RESULT fsResult;
    
    appMediaData.fileSystemMountStatus = APP_FILE_LOADING_MEDIA;
    
    // no more folders to parse
    if (appMediaData.dirIndex >= appMediaData.dirCount) {
        // set the status to loaded
        appMediaData.fileSystemMountStatus = APP_FILE_MEDIA_LOADED;

        // call ends here
        return true;
    }

    // get a pointer to the current folder name
    dirName = &appMediaData.dirTable[appMediaData.dirIndex].mediaFullPath[0];
    // open the folder
    dirHandle = SYS_FS_DirOpen(dirName);
    if(dirHandle == SYS_FS_HANDLE_INVALID)
    {
        SYS_CONSOLE_PRINT("!!! ERROR: Folder %s cannot be opened\r\n", dirName);

        // the folder might be invalid... skip it.
        appMediaData.dirIndex++;

        // skip the rest of the code to the next cycle
        return false;
    }
        
    // start reading the current folder
    // SYS_CONSOLE_PRINT("Reading Folder %s\r\n", dirName);
    do {
        fsResult = SYS_FS_DirRead(dirHandle, &fsStat);
        if(fsResult== SYS_FS_RES_FAILURE)
        {
            SYS_CONSOLE_PRINT("!!! ERROR: Folder %s cannot be read.\r\n", dirName);

            // skip the rest of the folder
            result = false;

            break;
        }

        // End of this directory
        if(fsStat.fname[0] == '\0') 
        {
            // no more items inside the folder
            result = false;

            break;
        }

        // create a copy of the file name
        // set the memory allocated for fileName to all 0
        memset(tempFileName, 0, sizeof(tempFileName));
        // copy the folder name into the file name
        strcpy(tempFileName, dirName);
        // append the folder delimiter to the file name
        strcat(tempFileName, APP_SYS_FS_FOLDER_DELIMITER);
        // append the file name to the 
        strcat(tempFileName, fsStat.fname);

        // folder
        if (fsStat.fattrib == SYS_FS_ATTR_DIR)
        {
            SYS_CONSOLE_PRINT("    Directory found: %s\r\n", tempFileName);
            
            if (appMediaData.dirCount == APP_MEDIA_MAX_FOLDERS) {
                SYS_CONSOLE_PRINT("    Folder limit reached. Skipping folder: %s\r\n", tempFileName);
                
                continue;
            }

            // Skip ".\" and "..\" directories
            if(fsStat.fname[0] == '.' && (fsStat.fname[1] == '.' || fsStat.fname[1] == '\0')) {
                continue;
            }

            // copy the folder name into the dirTable
            strcpy(appMediaData.dirTable[appMediaData.dirCount].mediaFullPath, tempFileName);

            // increment the number of folders found
            appMediaData.dirCount++;

            // go to next item inside the folder
            continue;
        }

        // SYS_CONSOLE_PRINT("    File found: %s\r\n", tempFileName);
        
        if (appMediaData.totalFiles == APP_MEDIA_MAX_FILES) {
            SYS_CONSOLE_PRINT("    File limit reached. Skipping file: %s\r\n", tempFileName);
            
            continue;
        }

        // check the file extension, to skip the files with unsupported extension
        if(APP_FileHandler_IsSupportedFile(tempFileName))
        {
            // attempt to open the file
            fileHandle = SYS_FS_FileOpen(tempFileName, SYS_FS_FILE_OPEN_READ);
            if (fileHandle == SYS_FS_HANDLE_INVALID) {
                SYS_CONSOLE_PRINT("!!! ERROR: File %s cannot be open.\r\n", tempFileName);
                
                // go to next item inside the folder
                continue;
            }
            
            // prepare a pointer to the structure for code readability
            APP_FILE_DATA* ptrFileData;
            // point to the current structure
            ptrFileData = &appMediaData.fileNameTable[appMediaData.totalFiles];

            // get the file type from its headers
            ptrFileData->fileType = APP_FileHandler_Get_Image_Type(fileHandle);

            // check for supported file
            if (ptrFileData->fileType == APP_IMAGE_FILE_TYPE_UNKNOWN) {
                SYS_CONSOLE_PRINT("!!! ERROR: Image type is Unknown, skip: %s\r\n", tempFileName);

                // close the file
                SYS_FS_FileClose(fileHandle);
                
                continue;
            }

            // get the file dimensions in pixels
            APP_FileHandler_Get_Image_Dimensions(fileHandle, &ptrFileData->dimensions, ptrFileData->fileType);
            if ( ptrFileData->dimensions.width == 0 || ptrFileData->dimensions.height == 0) {
                SYS_CONSOLE_PRINT("!!! ERROR: Image dimensions not found, skip: %s\r\n", tempFileName);

                // close the file
                SYS_FS_FileClose(fileHandle);

                continue;
            }
            
            // close the file
            SYS_FS_FileClose(fileHandle);

            SYS_CONSOLE_PRINT("    Supported image found: %s\r\n", tempFileName);

            // set the index of the file
            ptrFileData->mediaFileIdx = appMediaData.totalFiles;

            // add the file to know file names
            strcpy(ptrFileData->mediaFullPath, tempFileName);

            // the web file name is the last portion of the name from the last folder delimiter
            ptrFileData->mediaWebPath = &ptrFileData->mediaFullPath[0];
            
            // skip the media mount point
            ptrFileData->mediaWebPath += strlen(APP_SYS_FS_MOUNT_POINT);

            // increment the file number            
            appMediaData.totalFiles++;
        }
    } while (true);

    // close the folder
    SYS_FS_DirClose(dirHandle);
    
    // go to next folder
    appMediaData.dirIndex++;
    
    if (result == true) {
        // set the status to loaded
        appMediaData.fileSystemMountStatus = APP_FILE_MEDIA_LOADED;
    }

    return result;
}

// Gets the maximum number of files the app can handle
uint32_t APP_FileHandler_GetMaxNumberOfFiles()
{
    return APP_MEDIA_MAX_FILES;
}

// Function to check if the file is supported by file extension.
bool APP_FileHandler_IsSupportedFile(char *fileName)
{
    char* fileExt;
    uint8_t i;
    
    // point to file extension
    fileExt = strrchr(fileName, '.');
    if (fileExt == NULL) {
        return false;
    }
    
    // search the extension through the supported extensions table
    for (i = 0; i < EXTENSION_TABLE_SIZE; i++)
    {
        if ( !memcmp((void*)fileExt, (const void*)supportedExtensions[i], strlen((char*)fileExt)) ) {
            return true;
        }
    }
    
    return false;
}

// Parses a file header to check what type of file is
APP_IMAGE_FILE_TYPE APP_FileHandler_Get_Image_Type(SYS_FS_HANDLE fileHandler)
{
    APP_IMAGE_FILE_TYPE fileType = APP_IMAGE_FILE_TYPE_UNKNOWN;
    
    if (fileHandler != SYS_FS_HANDLE_INVALID) {
        // reset the handler to the beginning of the file
        SYS_FS_FileSeek(fileHandler, 0, SYS_FS_SEEK_SET);

        // get the file header
        uint8_t fileHeader[8];
        if (SYS_FS_FileRead(fileHandler, fileHeader, 8) > 0) {
            do {
#ifdef APP_SUPPORT_JPEG
                // treat the JPEG files: FF D8 FF
                if (fileHeader[0] == 0xFF && fileHeader[1] == 0xD8 && fileHeader[2] == 0xFF) {
                    fileType = APP_IMAGE_FILE_TYPE_JPEG;

                    break;
                }
#endif
#ifdef APP_SUPPORT_BMP
                // treat bmp files: 42 4D
                if (fileHeader[0] == 0x42 && fileHeader[1] == 0x4D) {
                    fileType = APP_IMAGE_FILE_TYPE_BMP;

                    break;
                }
#endif
#ifdef APP_SUPPORT_PNG
                // treat png files: 0x89 0x50 0x4e 0x47 0x0d 0x0a 0x1a 0x0a
                if (fileHeader[0] == 0x89 && fileHeader[1] == 0x50
                        && fileHeader[2] == 0x4e && fileHeader[3] == 0x47
                        && fileHeader[4] == 0x0d && fileHeader[5] == 0x0a
                        && fileHeader[6] == 0x1a && fileHeader[7] == 0x0a
                        ) {
                    fileType = APP_IMAGE_FILE_TYPE_PNG;

                    break;
                }
#endif
#if defined(APP_SUPPORT_GIF)
#warning "GIF SUPPORT IS NOT IMPLEMENTED ! Implement code here"
                // treat gif files
                if (false) {
                    fileType = APP_IMAGE_FILE_TYPE_GIF;

                    break;
                }
#endif
                // redundant, added for code readability
                fileType = APP_IMAGE_FILE_TYPE_UNKNOWN;
            } while(false);
        }
    }
    
    return fileType;
}



// Gets the file dimensions in pixels
void APP_FileHandler_Get_Image_Dimensions(SYS_FS_HANDLE fileHandler, APP_FILE_IMAGE_DIMENSIONS *dimensions, APP_IMAGE_FILE_TYPE imageType)
{
    // set dimension to 0, if something goes bad, the image will be considered bad and discarded
    dimensions->width = 0;
    dimensions->height = 0;
    
    if (fileHandler == SYS_FS_HANDLE_INVALID) {
        // cannot use the file
        return;
    }
    
    switch (imageType) {
        case APP_IMAGE_FILE_TYPE_BMP:
            APP_FileHandler_Get_BMP_Dimensions(fileHandler, dimensions);
            break;
            
        case APP_IMAGE_FILE_TYPE_JPEG:
            APP_FileHandler_Get_JPEG_Dimensions(fileHandler, dimensions);

            break;
            
        case APP_IMAGE_FILE_TYPE_PNG:
            APP_FileHandler_Get_PNG_Dimensions(fileHandler, dimensions);
            break;
            
        case APP_IMAGE_FILE_TYPE_GIF:
            APP_FileHandler_Get_GIF_Dimensions(fileHandler, dimensions);
            break;
            
        case APP_IMAGE_FILE_TYPE_UNKNOWN:
            // nothing to do
            
            break;
    }
    
    return;
}

// get the JPEG file dimensions
#define APP_FILE_HANDLER_BYTES_TO_READ 255
void APP_FileHandler_Get_JPEG_Dimensions(SYS_FS_HANDLE handle, APP_FILE_IMAGE_DIMENSIONS *dimensions)
{
    uint32_t imageIndex;
    uint8_t bytesToRead = APP_FILE_HANDLER_BYTES_TO_READ;
    uint8_t readData[APP_FILE_HANDLER_BYTES_TO_READ];
    char* tempData;
    uint32_t fileSize;

    // set the dimensions to 0
    dimensions->width = 0;
    dimensions->height = 0;
    
    // rewind to the beginning of the file
    SYS_FS_FileSeek(handle, 0, SYS_FS_SEEK_SET);

    // get the file size
    fileSize = SYS_FS_FileSize(handle);

    imageIndex = 0;
    while ( (SYS_FS_FileEOF(handle) != true) ) {
        bytesToRead = ((fileSize - imageIndex) > 0) ? APP_FILE_HANDLER_BYTES_TO_READ : (fileSize - imageIndex);
        memset(readData, 0, APP_FILE_HANDLER_BYTES_TO_READ);
        if (SYS_FS_FileRead(handle, &readData, bytesToRead) >= 0) {
            // search for the marker
            // look for 0xFF
            tempData = memchr((const char*)readData, 0xFF, bytesToRead);
            while(tempData != NULL) {
                // check for 0xC0
                if ( (*(tempData+1) == (char)0xC0) ) {
                    Nop();
                    
                    break;
                }

                // tempData++;
                tempData++;
                // search for the next 0xFF
                tempData = memchr((const char*)tempData, 0xFF, bytesToRead);
            };
            
            // see if the marker is found and get the payload with dimensions
            if (tempData != NULL) {
                // set the imageIndex to the position of the marker
                imageIndex += (uint32_t)tempData - (uint32_t)&readData;
                // set the cursor in the file to the imageIndex
                SYS_FS_FileSeek(handle, imageIndex, SYS_FS_SEEK_SET);
                
                /*
                 * the SOF contains
                 * 0:1 => FF C0
                 * 2:3 => segment length
                 * 4 => data bits
                 * 5:6 => height
                 * 7:8 => width
                 * 9 => channels
                 */
                SYS_FS_FileRead(handle, &readData, 10);
                
                // set the dimensions
                dimensions->height = ((int32_t) readData[5] << 8) | (int32_t) (readData[6]);
                dimensions->width  = ((int32_t) readData[7] << 8) | (int32_t) (readData[8]);

                // SYS_CONSOLE_PRINT("    Dimensions found: w = %d : h = %d\r\n", dimensions->width, dimensions->height);
            } else {
                // set the imageIndex to the position of the read data - 1 - maybe we read till the 0xFF of the marker
                imageIndex += bytesToRead - 1;
                // set the cursor in the file to the imageIndex
                SYS_FS_FileSeek(handle, imageIndex, SYS_FS_SEEK_SET);
            }
        }
    }

    return;
}

/*
     // BMP header explained: https://www.donwalizerjr.com/understanding-bmp/
    
    // first 14 Bytes:
    // Signature | File Size   | reserved    | Data Offset
    //   42 4d   | 7e 00 00 00 | 00 00 00 00 | 3e 00 00 00
    
    // next 40 bytes are info
    // Size        | Width       | Height      | Planes | Bits Per Pixel
    // 28 00 00 00 | 10 00 00 00 | 10 00 00 00 | 01 00  | 01 00         
    // Compression | Image Size  | XpixelsPerM | YpixelsPerM
    // 00 00 00 00 | 40 00 00 00 | 00 00 00 00 | 00 00 00 00
    // Colors Used | Important Colors
    // 00 00 00 00 | 00 00 00 00
 */

void APP_FileHandler_Get_BMP_Dimensions(SYS_FS_HANDLE handle, APP_FILE_IMAGE_DIMENSIONS *dimensions)
{
    uint8_t sofPayload[8];
    
    // rewind to the byte 18 of the file, where the dimensions are
    SYS_FS_FileSeek(handle, 18, SYS_FS_SEEK_SET);
    
    // get 8 bytes of data from the file
    SYS_FS_FileRead(handle, sofPayload, 8);
    
    // dimensions are bytes 0:3 for width, 4:7 for height
    dimensions->width =  ((int32_t) sofPayload[3] << 24) | ((int32_t) sofPayload[2] << 16) | ((int32_t) sofPayload[1] << 8) | ((int32_t) (sofPayload[0]));
    dimensions->height = ((int32_t) sofPayload[7] << 24) | ((int32_t) sofPayload[6] << 16) | ((int32_t) sofPayload[5] << 8) | ((int32_t) (sofPayload[4]));

    return;
}

/*
 * https://www.w3.org/TR/PNG-Structure.html
 * The first eight bytes of a PNG file always contain the following (decimal) values:
 * 
 *   137 80 78 71 13 10 26 10
 * 3.2. Chunk layout
 * Each chunk consists of four parts:
 * 
 * Length
 *     A 4-byte unsigned integer giving the number of bytes in the chunk's data field. The length counts only the data field, not itself, the chunk type code, or the CRC. Zero is a valid length. Although encoders and decoders should treat the length as unsigned, its value must not exceed (2^31)-1 bytes. 
 * Chunk Type
 *     A 4-byte chunk type code. For convenience in description and in examining PNG files, type codes are restricted to consist of uppercase and lowercase ASCII letters (A-Z and a-z, or 65-90 and 97-122 decimal). However, encoders and decoders must treat the codes as fixed binary values, not character strings. For example, it would not be correct to represent the type code IDAT by the EBCDIC equivalents of those letters. Additional naming conventions for chunk types are discussed in the next section. 
 * Chunk Data
 *     The data bytes appropriate to the chunk type, if any. This field can be of zero length. 
 * CRC
 *     A 4-byte CRC (Cyclic Redundancy Check) calculated on the preceding bytes in the chunk, including the chunk type code and chunk data fields, but not including the length field. The CRC is always present, even for chunks containing no data. See CRC algorithm. 
 * https://www.w3.org/TR/PNG-Chunks.html#C.Additional-chunk-types
 * The IHDR chunk must appear FIRST. It contains:
 * 
 *    Width:              4 bytes
 *    Height:             4 bytes
 *    Bit depth:          1 byte
 *    Color type:         1 byte
 *    Compression method: 1 byte
 *    Filter method:      1 byte
 *    Interlace method:   1 byte

 */
void APP_FileHandler_Get_PNG_Dimensions(SYS_FS_HANDLE handle, APP_FILE_IMAGE_DIMENSIONS *dimensions)
{
    uint8_t sofPayload[8];
    
    // rewind to the byte 8 of the file, where the dimensions are
    SYS_FS_FileSeek(handle, 16, SYS_FS_SEEK_SET);
    
    SYS_FS_FileRead(handle, sofPayload, 8);
    
    dimensions->width =  ((int32_t) sofPayload[0] << 24) | ((int32_t) sofPayload[1] << 16) | ((int32_t) sofPayload[2] << 8) | ((int32_t) (sofPayload[3]));
    dimensions->height = ((int32_t) sofPayload[4] << 24) | ((int32_t) sofPayload[5] << 16) | ((int32_t) sofPayload[6] << 8) | ((int32_t) (sofPayload[7]));

    return;

}

// TODO implement the image parser to get the GIF file dimensions
void APP_FileHandler_Get_GIF_Dimensions(SYS_FS_HANDLE handle, APP_FILE_IMAGE_DIMENSIONS *dimensions)
{
#if defined(APP_SUPPORT_GIF)
#warning "GIF SUPPORT IS NOT IMPLEMENTED ! Implement function here"
#endif    
    return;
}

// Gets the details of the file to show, by web file path
APP_FILE_DATA* APP_FileHandler_GetPictureByWebName(char* webFileName)
{
    for(uint16_t i = 0; i < appMediaData.totalFiles; i++) {
        if ( !strcmp((void*)webFileName, (const void*)appMediaData.fileNameTable[i].mediaWebPath) ) {
            return &appMediaData.fileNameTable[i];
        }
    }
    
    return (APP_FILE_DATA*)NULL;
}

// Gets the next file to show by into index in the file list
APP_FILE_DATA* APP_FileHandler_GetPictureToShow(uint32_t fileIndex, APP_FILE_NEXT_PREV next_prev) 
{
    // get the next index
    switch (next_prev) {
        case APP_FILE_GET_CURRENT:
        {
            if (fileIndex < APP_FILE_START_INDEX || fileIndex >= appMediaData.totalFiles) {
                fileIndex = APP_FILE_START_INDEX;
            }
            break;
        }
        
        case APP_FILE_GET_PREVIOUS:
        {
            if (fileIndex <= APP_FILE_START_INDEX || fileIndex >= appMediaData.totalFiles) {
                fileIndex = appMediaData.totalFiles - 1;
            } else {
                fileIndex--;
            }
            break;
        }
            
        case APP_FILE_GET_NEXT: 
            // no code here, , no break
            // treating next as default
        default:
        {
            if (fileIndex >= appMediaData.totalFiles - 1 || fileIndex < APP_FILE_START_INDEX) {
                fileIndex = APP_FILE_START_INDEX;
            } else {
                fileIndex++;
            }
            break;
        }
    }
    
    return &appMediaData.fileNameTable[fileIndex];
}

// returns the number of files found on the Media
uint32_t APP_FileHandler_GetNumberOfMediaFiles()
{
    return appMediaData.totalFiles;
}


// EOF
 