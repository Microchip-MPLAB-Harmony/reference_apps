#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   18
 *****************************************************************************/

/*****************************************************************************
 * string table data
 * 
 * this table contains the raw character data for each string
 * 
 * unsigned short - number of indices in the table
 * unsigned short - number of languages in the table
 * 
 * index array (size = number of indices * number of languages
 * 
 * for each index in the array:
 *   unsigned byte - the font ID for the index
 *   unsigned byte[3] - the offset of the string codepoint data in
 *                      the table
 * 
 * string data is found by jumping to the index offset from the start
 * of the table
 * 
 * string data entry:
 *     unsigned short - length of the string in bytes (encoding dependent)
 *     codepoint data - the string data
 ****************************************************************************/

const uint8_t stringTable_data[208] =
{
    0x12,0x00,0x01,0x00,0x00,0x4C,0x00,0x00,0x00,0x54,0x00,0x00,0x00,0x5C,0x00,0x00,
    0x00,0x66,0x00,0x00,0x00,0x74,0x00,0x00,0x00,0x7C,0x00,0x00,0x00,0x82,0x00,0x00,
    0x00,0x88,0x00,0x00,0x00,0x8C,0x00,0x00,0x00,0x90,0x00,0x00,0x00,0xA0,0x00,0x00,
    0x00,0xA6,0x00,0x00,0x00,0xAE,0x00,0x00,0x00,0xB6,0x00,0x00,0x00,0xBA,0x00,0x00,
    0x00,0xC2,0x00,0x00,0x00,0xC8,0x00,0x00,0x00,0xCC,0x00,0x00,0x05,0x00,0x4E,0x6F,
    0x64,0x65,0x33,0x00,0x06,0x00,0x4F,0x6E,0x6C,0x69,0x6E,0x65,0x07,0x00,0x4F,0x66,
    0x66,0x6C,0x69,0x6E,0x65,0x00,0x0C,0x00,0x43,0x6F,0x6E,0x6E,0x65,0x63,0x74,0x69,
    0x76,0x69,0x74,0x79,0x05,0x00,0x47,0x50,0x49,0x4F,0x32,0x00,0x03,0x00,0x2D,0x35,
    0x35,0x00,0x03,0x00,0x4F,0x66,0x66,0x00,0x02,0x00,0x32,0x33,0x02,0x00,0x4F,0x6E,
    0x0D,0x00,0x4D,0x69,0x57,0x69,0x2D,0x49,0x6F,0x54,0x20,0x44,0x65,0x6D,0x6F,0x00,
    0x03,0x00,0x64,0x42,0x6D,0x00,0x05,0x00,0x4E,0x6F,0x64,0x65,0x31,0x00,0x05,0x00,
    0x47,0x50,0x49,0x4F,0x31,0x00,0x01,0x00,0x30,0x00,0x05,0x00,0x4E,0x6F,0x64,0x65,
    0x32,0x00,0x03,0x00,0x4C,0x45,0x44,0x00,0x01,0x00,0x31,0x00,0x02,0x00,0xB0,0x43,
};

/* font asset pointer list */
leFont* fontList[1] =
{
    (leFont*)&NotoSans_Regular,
};

const leStringTable stringTable =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        208, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_ASCII // encoding standard
};


// string list
leTableString string_Device3;
leTableString string_Online;
leTableString string_Offline;
leTableString string_Connectivity;
leTableString string_GPIO2;
leTableString string_String55;
leTableString string_Off;
leTableString string_String23;
leTableString string_On;
leTableString string_title;
leTableString string_dbm;
leTableString string_device;
leTableString string_GPIO1;
leTableString string_String0;
leTableString string_Device2;
leTableString string_LED;
leTableString string_String1;
leTableString string_Cese;

void initializeStrings(void)
{
    leTableString_Constructor(&string_Device3, stringID_Device3);
    leTableString_Constructor(&string_Online, stringID_Online);
    leTableString_Constructor(&string_Offline, stringID_Offline);
    leTableString_Constructor(&string_Connectivity, stringID_Connectivity);
    leTableString_Constructor(&string_GPIO2, stringID_GPIO2);
    leTableString_Constructor(&string_String55, stringID_String55);
    leTableString_Constructor(&string_Off, stringID_Off);
    leTableString_Constructor(&string_String23, stringID_String23);
    leTableString_Constructor(&string_On, stringID_On);
    leTableString_Constructor(&string_title, stringID_title);
    leTableString_Constructor(&string_dbm, stringID_dbm);
    leTableString_Constructor(&string_device, stringID_device);
    leTableString_Constructor(&string_GPIO1, stringID_GPIO1);
    leTableString_Constructor(&string_String0, stringID_String0);
    leTableString_Constructor(&string_Device2, stringID_Device2);
    leTableString_Constructor(&string_LED, stringID_LED);
    leTableString_Constructor(&string_String1, stringID_String1);
    leTableString_Constructor(&string_Cese, stringID_Cese);
}
