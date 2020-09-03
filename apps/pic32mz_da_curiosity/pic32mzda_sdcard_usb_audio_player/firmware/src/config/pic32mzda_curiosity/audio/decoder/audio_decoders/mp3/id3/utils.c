
#define UTILS_C
#include "utils.h"

/*-----------------------------------------------*/
uint16_t ENCODING_FormatASCII ( uint8_t encoding, uint8_t* source, uint16_t sourceSize, int8_t* dest, uint16_t destSize )
{
//    uint8_t *dest, *source;
    uint16_t actualSize = 0;

//    source = (uint8_t*) source;
//    dest = (uint8_t*) dest;
    destSize --;

    switch ( encoding )
    {
        case ENCODING_ASCII:
            while (( sourceSize > 0 ) && ( destSize > 0 ) && ( *source != 0 ))
            {
                *dest++ = *source++;
                sourceSize --;
                destSize --;
                actualSize ++;
            }
            break;

        case ENCODING_UTF16:
            while ( true )
            {
                if(*source==0 && *(source+1)==0)    //check unicode string end
                    break;
                if(sourceSize < 2)               //length < 2, string end
                    break;

                if( (*(source+1) == 0) && (*source < 0x80))	//ASCII code
                {
                    if(destSize)
                    {
                        *dest++ = *source;
                        actualSize++;
                        destSize--;
                    }
                }
                else if((*source==0xff)&&(*(source+1)==0xfe))	//0xfffe indicates little endia
                {
                    //do nothing here
                }
                else	//not ASCII
                {
                    if(destSize)
                    {
                        *dest++ = ENCODING_UNKNOWN_CODE;
                        actualSize++;
                        destSize--;
                    }
                }
                source += 2;
                sourceSize -= 2;
            }
            break;

        case ENCODING_UTF16_BE:
            while(1)
            {
                if(*source==0 && *(source+1)==0)        //check unicode string end
                    break;
                if(sourceSize < 2)                   //length < 2, string end
                    break;

                if((*source==0)&&(*(source+1)<0x80))	//ASCII code
                {
                    if(destSize)
                    {
                        *dest++ = *(source+1);
                        actualSize++;
                        destSize--;
                    }
                }
                else if((*source==0xfe)&&(*(source+1)==0xff))	//0xfeff indicates big endia
                {
                    //do nothing here
                }
                else			//not ASCII
                {
                    if(destSize)
                    {
                        *dest++ = ENCODING_UNKNOWN_CODE;
                        actualSize++;
                        destSize--;
                    }
                }
                source += 2;
                sourceSize -= 2;
            }
            break;

        case ENCODING_UTF8:
            while ( true )
            {
                if(*source==0)        //check unicode string end
                    break;
                if(sourceSize == 0)
                    break;

                if(*source < 0x80)        //1 byte code
                {
                    if(destSize)
                    {
                        *dest++=*source;
                        actualSize++;
                        destSize--;
                    }
                    source++;
                    sourceSize -= 1;
                }
                else if(*source < 0xE0)       //2 byte code
                {
                    if(sourceSize >= 2)
                    {
                        if(destSize)
                        {
                            *dest++=ENCODING_UNKNOWN_CODE;
                            actualSize++;
                            destSize--;
                        }
                        source += 2;;
                        sourceSize -= 2;
                    }
                    else
                    {
                        sourceSize = 0;
                    }
                }
                else        //3 byte code
                {
                    if(sourceSize>=3)
                    {
                        if(destSize)
                        {
                            *dest++=ENCODING_UNKNOWN_CODE;
                            actualSize++;
                            destSize--;
                        }
                        source += 3;
                        sourceSize -= 3;
                    }
                    else
                        sourceSize = 0;
                }
            }
            break;
    }

    *dest = 0;

    return ( actualSize );
}


