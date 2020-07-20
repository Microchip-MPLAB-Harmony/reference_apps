#include "cryptoauthlib_main.h"
#include "crypto_client.h"
#include "../../cryptoauthlib/lib/atca_device.h"
#include "../../cryptoauthlib/lib/basic/atca_basic.h"

struct atca_command  _gmyCommand;
struct atca_iface    _gmyIface;
struct atca_device   _gMyDevice = {&_gmyCommand, &_gmyIface};

void cryptoauthlib_init(void)
{
    uint8_t rv;
    
    atcab_init_device(&_gMyDevice);
    
    rv = atcab_init(&cfg_ateccx08a_i2c_custom);
    if (rv != ATCA_SUCCESS)
    {
       cryptoDeviceInitialized = false;
    } else {
       atcab_lock_data_slot(0);
       cryptoDeviceInitialized = true;
    }
}
