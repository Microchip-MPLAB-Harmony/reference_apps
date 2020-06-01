#ifndef BNO055_DEFS_H
#define BNO055_DEFS_H


#if defined( __KERNEL__ )

#include <linux/types.h>
/* singed integer type*/
typedef int8_t s8;/**< used for signed 8bit */
typedef int16_t s16;/**< used for signed 16bit */
typedef int32_t s32;/**< used for signed 32bit */
typedef int64_t s64;/**< used for signed 64bit */

typedef u_int8_t u8;/**< used for unsigned 8bit */
typedef u_int16_t u16;/**< used for unsigned 16bit */
typedef u_int32_t u32;/**< used for unsigned 32bit */
typedef u_int64_t u64;/**< used for unsigned 64bit */

#else /* ! __KERNEL__ */
/**********************************************************
* These definition uses for define the C
* standard version data types
***********************************************************/
/************************************************/
#include <stdint.h>
/************************************************/
/*unsigned integer types*/
typedef uint8_t u8;/**< used for unsigned 8bit */
typedef uint16_t u16;/**< used for unsigned 16bit */
typedef uint32_t u32;/**< used for unsigned 32bit */
typedef uint64_t u64;/**< used for unsigned 64bit */

/*signed integer types*/
typedef int8_t s8;/**< used for signed 8bit */
typedef int16_t s16;/**< used for signed 16bit */
typedef int32_t s32;/**< used for signed 32bit */
typedef int64_t s64;/**< used for signed 64bit */

#endif

#endif
