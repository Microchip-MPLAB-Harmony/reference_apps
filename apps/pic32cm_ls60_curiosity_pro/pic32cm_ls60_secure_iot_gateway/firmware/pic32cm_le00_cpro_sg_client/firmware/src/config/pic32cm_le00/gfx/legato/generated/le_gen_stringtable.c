#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   3
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

const uint8_t stringTable_data[36] =
{
    0x03,0x00,0x01,0x00,0x01,0x10,0x00,0x00,0x01,0x16,0x00,0x00,0x01,0x1E,0x00,0x00,
    0x04,0x00,0x54,0x65,0x6D,0x70,0x05,0x00,0x4C,0x69,0x67,0x68,0x74,0x00,0x03,0x00,
    0x30,0x30,0x30,0x00,
};

/* font asset pointer list */
leFont* fontList[2] =
{
    (leFont*)&NotoSans_Bold,
    (leFont*)&NotoMono_Regular,
};

const leStringTable stringTable =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        36, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_ASCII // encoding standard
};


// string list
leTableString string_Temp;
leTableString string_Light;
leTableString string_String;

void initializeStrings(void)
{
    leTableString_Constructor(&string_Temp, stringID_Temp);
    leTableString_Constructor(&string_Light, stringID_Light);
    leTableString_Constructor(&string_String, stringID_String);
}
