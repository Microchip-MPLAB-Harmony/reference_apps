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

const uint8_t stringTable_data[64] =
{
    0x03,0x00,0x01,0x00,0x00,0x10,0x00,0x00,0x00,0x24,0x00,0x00,0x00,0x2E,0x00,0x00,
    0x11,0x00,0x52,0x65,0x61,0x64,0x79,0x20,0x74,0x6F,0x20,0x53,0x63,0x61,0x6E,0x2E,
    0x2E,0x2E,0x21,0x00,0x07,0x00,0x52,0x65,0x73,0x75,0x6C,0x74,0x3A,0x00,0x0F,0x00,
    0x42,0x61,0x72,0x63,0x6F,0x64,0x65,0x20,0x53,0x63,0x61,0x6E,0x6E,0x65,0x72,0x00,
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
        64, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_ASCII // encoding standard
};


// string list
leTableString string_Out_Str;
leTableString string_Result;
leTableString string_Title;

void initializeStrings(void)
{
    leTableString_Constructor(&string_Out_Str, stringID_Out_Str);
    leTableString_Constructor(&string_Result, stringID_Result);
    leTableString_Constructor(&string_Title, stringID_Title);
}
