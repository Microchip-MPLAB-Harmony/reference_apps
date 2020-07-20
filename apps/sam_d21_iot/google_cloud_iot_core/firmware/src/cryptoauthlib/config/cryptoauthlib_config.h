#ifndef CRYPTOAUTHLIB_CONFIG_H
#define CRYPTOAUTHLIB_CONFIG_H

#ifndef ATCA_NO_HEAP
#define ATCA_NO_HEAP 1
#endif

#ifndef ATCA_NO_POLL
#define ATCA_NO_POLL 1
#endif

#ifndef ATCA_HAL_I2C
#define ATCA_HAL_I2C 1
#endif

#ifndef ATCA_PRINTF
#define ATCA_PRINTF 1
#endif

#ifndef CONF_CRYPTOAUTHLIB_DEBUG_HELPER
#define CONF_CRYPTOAUTHLIB_DEBUG_HELPER 0
#endif

/* Enable debug helper function */
#if CONF_CRYPTOAUTHLIB_DEBUG_HELPER == 1
#ifndef ATCAdebug_print
#define ATCAdebug_print 1
#endif
#endif

#endif // CRYPTOAUTHLIB_CONFIG_H
