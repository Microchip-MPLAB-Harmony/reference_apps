#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   2
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

const uint8_t stringTable_data[46] =
{
    0x02,0x00,0x01,0x00,0x01,0x0C,0x00,0x00,0x01,0x24,0x00,0x00,0x16,0x00,0x4D,0x43,
    0x43,0x20,0x48,0x61,0x72,0x6D,0x6F,0x6E,0x79,0x20,0x50,0x68,0x6F,0x74,0x6F,0x66,
    0x72,0x61,0x6D,0x65,0x08,0x00,0x57,0x65,0x6C,0x63,0x6F,0x6D,0x65,0x21,
};

/* font asset pointer list */
leFont* fontList[1] =
{
    (leFont*)&Font1,
};

const leStringTable stringTable =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        46, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_ASCII // encoding standard
};


// string list
leTableString string_Title;
leTableString string_Start_Screen_Text;

void initializeStrings(void)
{
    leTableString_Constructor(&string_Title, stringID_Title);
    leTableString_Constructor(&string_Start_Screen_Text, stringID_Start_Screen_Text);
}
