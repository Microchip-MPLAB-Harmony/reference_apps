#include "legato_optimizations.h"

gfxResult APP_SW_BlitBuffer(const gfxPixelBuffer* src,
                                   const gfxRect * srcRect,
                                   const gfxPixelBuffer* dest,
                                   const gfxRect * destRect)
{
    void* srcPtr;
    
    void* destPtr;
    
    uint32_t row, rowSize;

    rowSize = srcRect->width * gfxColorInfoTable[src->mode].size;

    for(row = 0; row < srcRect->height; row++)
    {
        srcPtr = gfxPixelBufferOffsetGet(src, srcRect->x, srcRect->y + row);
        
        destPtr = gfxPixelBufferOffsetGet(dest, destRect->x, destRect->y + row);

        memcpy(destPtr, srcPtr, rowSize);
    }

    return GFX_SUCCESS;
}
