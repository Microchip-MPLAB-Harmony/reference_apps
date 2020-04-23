###############################################################################
######################### WincDriver Configurations ###########################
###############################################################################

def checkPrefix(symbol):
    component = symbol.getComponent()
    wincVerPrefix = component.getSymbolValue('DRV_WIFI_WINC_VER_PREFIX')

    if symbol.getID().startswith('WIFI_'):
        if symbol.getID().startswith('WIFI_' + wincVerPrefix):
            return True
        else:
            return False
    else:
        return True

def importIncFile(component, configName, incFileEntry, firmwarePath = None):
    incFilePath  = incFileEntry[0]
    isEnabled    = incFileEntry[1][0]
    callback     = incFileEntry[1][1]
    dependencies = incFileEntry[1][2]

    incFilePathTup = incFilePath.split('/')

    if len(incFilePathTup) == 1:
        secName = ''
        incFile = incFilePathTup[0]
    else:
        secName = incFilePathTup[0]
        incFile = incFilePathTup[1]

    if firmwarePath:
        symName  = 'WIFI_' + firmwarePath.replace('.', '_').upper() + '_' + incFile.replace('.', '_').upper()
        secSName = firmwarePath + '/' + secName + '/'
        secDName = 'drv/' + secName + '/'

        dependencies = list(dict.fromkeys(dependencies + ['DRV_WIFI_WINC_DEVICE', 'DRV_WIFI_WINC3400_VERSION', 'DRV_WIFI_WINC1500_VERSION']))

        if not callback:
            callback = setEnablePrefix
    else:
        symName = incFile.replace('.', '_').upper()
        secSName = secName + '/'
        secDName = secSName

    incFileSym = component.createFileSymbol(symName, None)
    incFileSym.setSourcePath('driver/winc/' + secSName + 'include/' + incFile)
    incFileSym.setOutputName(incFile)
    incFileSym.setDestPath('driver/winc/include/' + secDName)
    incFileSym.setProjectPath('config/' + configName + '/driver/winc/include/' + secDName)
    incFileSym.setType('HEADER')
    incFileSym.setOverwrite(True)
    incFileSym.setEnabled(isEnabled)

    if callback and dependencies:
        incFileSym.setDependencies(callback, dependencies)

def importSrcFile(component, configName, srcFileEntry, firmwarePath = None):
    srcFilePath  = srcFileEntry[0]
    isEnabled    = srcFileEntry[1][0]
    callback     = srcFileEntry[1][1]
    dependencies = srcFileEntry[1][2]

    srcFilePathTup = srcFilePath.rsplit('/', 1)

    if len(srcFilePathTup) == 1:
        secName = ''
        srcFile = srcFilePathTup[0]
    else:
        secName = srcFilePathTup[0]
        srcFile = srcFilePathTup[1]

    if firmwarePath:
        symName  = 'WIFI_' + firmwarePath.replace('.', '_').upper() + '_' + srcFile.replace('.', '_').upper()
        secSName = firmwarePath + '/' + secName + '/'
        secDName = 'drv/' + secName + '/'
        srcFile  = 'source/' + srcFile

        dependencies = list(dict.fromkeys(dependencies + ['DRV_WIFI_WINC_DEVICE', 'DRV_WIFI_WINC3400_VERSION', 'DRV_WIFI_WINC1500_VERSION']))

        if not callback:
            callback = setEnablePrefix
    else:
        srcFilePrefix   = ''
        symName = srcFile.replace('.', '_').upper()
        secSName = secName + '/'
        secDName = secSName

    srcFileSym = component.createFileSymbol(symName, None)
    srcFileSym.setSourcePath('driver/winc/' + secSName + srcFile)
    srcFileSym.setOutputName(srcFile.rsplit('/', 1)[-1])
    srcFileSym.setDestPath('driver/winc/' + secDName)
    srcFileSym.setProjectPath('config/' + configName + '/driver/winc/' + secDName)
    srcFileSym.setType('SOURCE')
    srcFileSym.setEnabled(isEnabled)

    if callback and dependencies:
        srcFileSym.setDependencies(callback, dependencies)

def setIncPath(component, configName, incPathEntry):
    incPath      = incPathEntry[0]
    isEnabled    = incPathEntry[1][0]
    callback     = incPathEntry[1][1]
    dependencies = incPathEntry[1][2]

    incPathSym = component.createSettingSymbol('WINC_INC_PATH' + incPath.replace('.', '_').replace('/', '_').upper(), None)
    incPathSym.setValue('../src/config/' + configName + '/driver/winc/include' + incPath + ';')
    incPathSym.setCategory('C32')
    incPathSym.setKey('extra-include-directories')
    incPathSym.setAppend(True, ';')
    incPathSym.setEnabled(isEnabled)
    incPathSym.setDependencies(callback, dependencies)

def onAttachmentConnected(source, target):
    if source['id'] == 'spi':
        drvSPIIndex = target['component'].getSymbolValue('INDEX')

        wifiDrvSPIInst = source['component'].getSymbolByID('DRV_WIFI_WINC_SPI_INST')
        wifiDrvSPIInstInx = source['component'].getSymbolByID('DRV_WIFI_WINC_SPI_INST_IDX')

        wifiDrvSPIInst.setValue('drv_spi_' + str(drvSPIIndex))
        wifiDrvSPIInst.setVisible(True)

        wifiDrvSPIInstInx.setValue(drvSPIIndex)

def onAttachmentDisconnected(source, target):
    if source['id'] == 'spi':
        wifiDrvSPIInst = source['component'].getSymbolByID('DRV_WIFI_WINC_SPI_INST')
        wifiDrvSPIInstInx = source['component'].getSymbolByID('DRV_WIFI_WINC_SPI_INST_IDX')

        wifiDrvSPIInst.setValue('')
        wifiDrvSPIInst.setVisible(False)

        wifiDrvSPIInstInx.setValue(-1)

def instantiateComponent(drvWincComponent):
    print('WINC Driver Component')
    configName = Variables.get('__CONFIGURATION_NAME')

    eicNode = ATDF.getNode("/avr-tools-device-file/devices/device/peripherals/module@[name=\"EIC\"]/instance@[name=\"EIC\"]/parameters/param@[name=\"EXTINT_NUM\"]")

    drvWincComponent.addDependency('spi', 'DRV_SPI', False, True);

    # WINC Device
    wincDevice = drvWincComponent.createComboSymbol('DRV_WIFI_WINC_DEVICE', None, ['WINC1500', 'WINC3400'])
    wincDevice.setLabel('WiFi Device')
    wincDevice.setVisible(True)

    # Log Level
    wincLogLevel = drvWincComponent.createComboSymbol('DRV_WIFI_WINC_LOG_LEVEL', None, ['None', 'Error', 'Inform', 'Trace', 'Verbose'])
    wincLogLevel.setLabel('Driver Log Level')
    wincLogLevel.setVisible(True)

    # SPI Instance Index
    wincSpiInst = drvWincComponent.createStringSymbol('DRV_WIFI_WINC_SPI_INST', None)
    wincSpiInst.setLabel('SPI Driver')
    wincSpiInst.setReadOnly(True)
    wincSpiInst.setDefaultValue('')

    wincSpiInstIdx = drvWincComponent.createIntegerSymbol('DRV_WIFI_WINC_SPI_INST_IDX', None)
    wincSpiInstIdx.setVisible(False)
    wincSpiInstIdx.setDefaultValue(-1)

    # Interrupt Source
    wincIntSrcList = []
    
    wincIntSrcList.append('GPIO')

    if eicNode:
        wincIntSrcList.append('EIC')

    if len(wincIntSrcList):
        wincIntSrc = drvWincComponent.createComboSymbol('DRV_WIFI_WINC_INT_SRC', None, wincIntSrcList)
        wincIntSrc.setLabel('Interrupt Source')
        wincIntSrc.setVisible(True)

    # External Interrupt Selection
    if eicNode:
        extIntCount = int(eicNode.getAttribute('value'))

        eicSrcSelDepList = []

        for x in range(extIntCount):
            wincEicSrcX = drvWincComponent.createBooleanSymbol('DRV_WIFI_WINC_EIC_SRC_' + str(x), wincIntSrc)
            wincEicSrcX.setLabel('EIC Channel ' + str(x))
            wincEicSrcX.setVisible(False)
            wincEicSrcX.setDependencies(setVisibilityEicSource, ['DRV_WIFI_WINC_INT_SRC', 'eic.EIC_INT'])

            eicSrcSelDepList.append('DRV_WIFI_WINC_EIC_SRC_' + str(x))

        wincEicSrcSel = drvWincComponent.createIntegerSymbol('DRV_WIFI_WINC_EIC_SRC_SELECT', None)
        wincEicSrcSel.setVisible(False)
        wincEicSrcSel.setDependencies(setValueEicSource, eicSrcSelDepList)
        wincEicSrcSel.setDefaultValue(-1)
        wincEicSrcSel.setMin(-1)
        wincEicSrcSel.setMax(extIntCount-1)

    # WINC1500 Version
    winc1500Version = drvWincComponent.createComboSymbol('DRV_WIFI_WINC1500_VERSION', None, ['19.6.1'])
    winc1500Version.setLabel('Firmware Version')
    winc1500Version.setVisible(True)
    winc1500Version.setDefaultValue('19.6.1')
    winc1500Version.setDependencies(setVisibilityWincVersion, ['DRV_WIFI_WINC_DEVICE'])

    # WINC3400 Version
    winc3400Version = drvWincComponent.createComboSymbol('DRV_WIFI_WINC3400_VERSION', None, ['1.2.2', '1.3.0'])
    winc3400Version.setLabel('Firmware Version')
    winc3400Version.setVisible(False)
    winc3400Version.setDefaultValue('1.2.2')
    winc3400Version.setDependencies(setVisibilityWincVersion, ['DRV_WIFI_WINC_DEVICE'])

    # WINC3400 BLE API Support
    winc3400UseBle = drvWincComponent.createBooleanSymbol('DRV_WIFI_WINC_USE_BLUETOOTH_WINC3400', None)
    winc3400UseBle.setLabel('Use BLE?')
    winc3400UseBle.setDefaultValue(False)
    winc3400UseBle.setVisible(wincDevice.getValue() == 'WINC3400')
    winc3400UseBle.setDependencies(setVisibilityWincVersion, ['DRV_WIFI_WINC_DEVICE'])

    # WINC Driver Mode
    wincDriverMode = drvWincComponent.createComboSymbol('DRV_WIFI_WINC_DRIVER_MODE', None, ['Ethernet Mode', 'Socket Mode'])
    wincDriverMode.setLabel('Driver Mode')
    wincDriverMode.setDefaultValue('Socket Mode')
    wincDriverMode.setVisible(True)

    # WINC Use TCP/IP Stack
    wincUseTcpipStack = drvWincComponent.createBooleanSymbol('DRV_WIFI_WINC_USE_TCPIP_STACK', wincDriverMode)
    wincUseTcpipStack.setLabel('Use Harmony TCP/IP Stack?')
    wincUseTcpipStack.setVisible(False)
    wincUseTcpipStack.setDefaultValue(False)
    wincUseTcpipStack.setDependencies(setVisibilityUseTcpipStack, ['DRV_WIFI_WINC_DRIVER_MODE'])
    # At startup, Hide Mac Capability
    drvWincComponent.setCapabilityEnabled("libdrvWincMac", False)

    # WINC Use Simple IWPRIV Control Interface
    wincUseIwprivIntf = drvWincComponent.createBooleanSymbol('DRV_WIFI_WINC_USE_IWPRIV_INTF', wincUseTcpipStack)
    wincUseIwprivIntf.setLabel('Use Simple IWPRIV Control Interface?')
    wincUseIwprivIntf.setVisible(False)
    wincUseIwprivIntf.setDependencies(setVisibilityUseIwprivIntf, ['DRV_WIFI_WINC_USE_TCPIP_STACK'])
    wincUseIwprivIntf.setDefaultValue(False)

    # RTOS Configuration
    wincRtosMenu = drvWincComponent.createMenuSymbol('DRV_WIFI_WINC_RTOS_MENU', None)
    wincRtosMenu.setLabel('RTOS Configuration')
    wincRtosMenu.setDescription('RTOS Configuration')
    wincRtosMenu.setVisible(False)
    wincRtosMenu.setVisible((Database.getSymbolValue('HarmonyCore', 'SELECT_RTOS') != 'BareMetal') and (Database.getSymbolValue('HarmonyCore', 'SELECT_RTOS') != None))
    wincRtosMenu.setDependencies(setVisibilityRTOSMenu, ['HarmonyCore.SELECT_RTOS'])

    # RTOS Execution Mode
    wincInstnExecMode = drvWincComponent.createComboSymbol('DRV_WIFI_WINC_RTOS', wincRtosMenu, ['Standalone'])
    wincInstnExecMode.setLabel('Run Driver Tasks as')
    wincInstnExecMode.setVisible(False)
    wincInstnExecMode.setDescription('WiFi WINC Driver RTOS Execution Mode')
    wincInstnExecMode.setDefaultValue('Standalone')

    # WiFi Driver Task Stack Size
    wincTaskSize = drvWincComponent.createIntegerSymbol('DRV_WIFI_WINC_RTOS_STACK_SIZE', wincRtosMenu)
    wincTaskSize.setLabel('Task Size')
    wincTaskSize.setVisible(True)
    wincTaskSize.setDescription('WiFi WINC Driver RTOS Task Stack Size')
    wincTaskSize.setDefaultValue(1024)
    wincTaskSize.setDependencies(setVisibilityRTOSTaskConfig, ['DRV_WIFI_WINC_RTOS'])

    # WiFi Driver Task Priority
    wincTaskPriority = drvWincComponent.createIntegerSymbol('DRV_WIFI_WINC_RTOS_TASK_PRIORITY', wincRtosMenu)
    wincTaskPriority.setLabel('Task Priority')
    wincTaskPriority.setVisible(True)
    wincTaskPriority.setDescription('WiFi WINC Driver RTOS Task Priority')
    wincTaskPriority.setDefaultValue(1)
    wincTaskPriority.setDependencies(setVisibilityRTOSTaskConfig, ['DRV_WIFI_WINC_RTOS'])

    # WiFi Use Task Delay?
    wincUseTaskDelay = drvWincComponent.createBooleanSymbol('DRV_WIFI_WINC_RTOS_USE_DELAY', wincRtosMenu)
    wincUseTaskDelay.setLabel('Use Task Delay?')
    wincUseTaskDelay.setVisible(True)
    wincUseTaskDelay.setDescription('WiFi WINC Driver Task Uses Delay?')
    wincUseTaskDelay.setDefaultValue(True)
    wincUseTaskDelay.setDependencies(setVisibilityRTOSTaskConfig, ['DRV_WIFI_WINC_RTOS'])

    # WiFi Driver Task Delay
    wincDrvTaskDelay = drvWincComponent.createIntegerSymbol('DRV_WIFI_WINC_RTOS_DELAY', wincRtosMenu)
    wincDrvTaskDelay.setLabel('Task Delay')
    wincDrvTaskDelay.setVisible(True)
    wincDrvTaskDelay.setDescription('WiFi Driver Task Delay')
    wincDrvTaskDelay.setDefaultValue(1)
    wincDrvTaskDelay.setDependencies(setVisibilityRTOSTaskDelay, ['DRV_WIFI_WINC_RTOS', 'DRV_WIFI_WINC_RTOS_USE_DELAY'])

    wincVerPrefix = drvWincComponent.createStringSymbol('DRV_WIFI_WINC_VER_PREFIX', None)
    wincVerPrefix.setVisible(False)

    if wincDevice.getValue() == 'WINC1500':
        wincVerPrefix.setValue(wincDevice.getValue() + '_' + winc1500Version.getValue().replace('.', '_'))
    elif wincDevice.getValue() == 'WINC3400':
        wincVerPrefix.setValue(wincDevice.getValue() + '_' + winc3400Version.getValue().replace('.', '_'))

    wincVerPrefix.setDependencies(setValueWincPrefix, ['DRV_WIFI_WINC_DEVICE', 'DRV_WIFI_WINC3400_VERSION', 'DRV_WIFI_WINC1500_VERSION'])

    ############################################################################
    #### Code Generation ####
    ############################################################################

    flagEthernetMode        = (wincDriverMode.getValue() == 'Ethernet Mode')
    flagSocketMode          = (wincDriverMode.getValue() == 'Socket Mode')
    flagTcpipStackPresent   = (flagEthernetMode and (wincUseTcpipStack.getValue() == 'True'))
    flagIwprivIntfPresent   = (flagEthernetMode and (wincUseIwprivIntf.getValue() == 'True'))
    flagBlePresent          = (winc3400UseBle.getValue() == 'True')
    flagWinc1500_19_6_1     = ((wincDevice.getValue() == 'WINC1500') and (winc1500Version.getValue() == '19.6.1'))
    flagWinc3400_1_2_2      = ((wincDevice.getValue() == 'WINC3400') and (winc3400Version.getValue() == '1.2.2'))
    flagWinc3400_1_3_0      = ((wincDevice.getValue() == 'WINC3400') and (winc3400Version.getValue() == '1.3.0'))

    flagHostFileSupport     = (flagSocketMode and flagWinc1500_19_6_1)

    condAlways              = [True,                    None,                       []]
    condSocketMode          = [flagSocketMode,          setEnableSocketMode,        ['DRV_WIFI_WINC_DRIVER_MODE']]
    condEthernetMode        = [flagEthernetMode,        setEnableEthernetMode,      ['DRV_WIFI_WINC_DRIVER_MODE']]
    condHostFileSupport     = [flagHostFileSupport,     setEnableHostFileSupport,   ['DRV_WIFI_WINC_DEVICE', 'DRV_WIFI_WINC1500_VERSION', 'DRV_WIFI_WINC_DRIVER_MODE']]
    condTcpipStackPresent   = [flagTcpipStackPresent,   setEnableTcpipStackPresent, ['DRV_WIFI_WINC_USE_TCPIP_STACK', 'DRV_WIFI_WINC_DRIVER_MODE']]
    condIwprivIntfPresent   = [flagIwprivIntfPresent,   setEnableIwprivIntfPresent, ['DRV_WIFI_WINC_USE_IWPRIV_INTF', 'DRV_WIFI_WINC_DRIVER_MODE']]
    condBle                 = [flagBlePresent,          setEnableBlePresent,        ['DRV_WIFI_WINC_DEVICE','DRV_WIFI_WINC3400_VERSION','DRV_WIFI_WINC_USE_BLUETOOTH_WINC3400']]
    condWinc1500_19_6_1     = [flagWinc1500_19_6_1,     setEnableWinc1500_19_6_1,   ['DRV_WIFI_WINC_DEVICE', 'DRV_WIFI_WINC1500_VERSION', 'DRV_WIFI_WINC_DRIVER_MODE']]
    condWinc3400_1_2_2      = [flagWinc3400_1_2_2,      setEnableWinc3400_1_2_2,    ['DRV_WIFI_WINC_DEVICE', 'DRV_WIFI_WINC3400_VERSION', 'DRV_WIFI_WINC_DRIVER_MODE']]
    condWinc3400_1_3_0      = [flagWinc3400_1_3_0,      setEnableWinc3400_1_3_0,    ['DRV_WIFI_WINC_DEVICE', 'DRV_WIFI_WINC3400_VERSION', 'DRV_WIFI_WINC_DRIVER_MODE']]


    wdrvIncFiles = [
        ['wdrv_winc.h',                         condAlways],
        ['wdrv_winc_api.h',                     condAlways],
        ['wdrv_winc_assoc.h',                   condAlways],
        ['wdrv_winc_authctx.h',                 condAlways],
        ['wdrv_winc_ble.h',                     condBle],
        ['wdrv_winc_bssctx.h',                  condAlways],
        ['wdrv_winc_bssfind.h',                 condAlways],
        ['wdrv_winc_client_api.h',              condAlways],
        ['wdrv_winc_common.h',                  condAlways],
        ['wdrv_winc_custie.h',                  condAlways],
        ['wdrv_winc_debug.h',                   condAlways],
        ['wdrv_winc_ethernet.h',                condEthernetMode],
        ['wdrv_winc_host_file.h',               condHostFileSupport],
        ['wdrv_winc_httpprovctx.h',             condSocketMode],
        ['wdrv_winc_nvm.h',                     condAlways],
        ['wdrv_winc_powersave.h',               condAlways],
        ['wdrv_winc_socket.h',                  condSocketMode],
        ['wdrv_winc_softap.h',                  condAlways],
        ['wdrv_winc_ssl.h',                     condSocketMode],
        ['wdrv_winc_sta.h',                     condAlways],
        ['wdrv_winc_systime.h',                 condAlways],
        ['wdrv_winc_wps.h',                     condAlways],
        ['dev/wdrv_winc_gpio.h',                condAlways],
        ['dev/wdrv_winc_spi.h',                 condAlways],
        ['stack_driver/wdrv_winc_stack_drv.h',  condTcpipStackPresent],
        ['stack_driver/wdrv_winc_pktpool.h',    condTcpipStackPresent],
        ['stack_driver/wdrv_winc_iwpriv.h',     condIwprivIntfPresent]
    ]

    wdrvFirmwareDriverIncFiles = [
        ['bsp/nm_bsp.h',                        condAlways],
        ['common/nm_common.h',                  condAlways],
        ['common/nm_debug.h',                   condAlways],
        ['driver/m2m_flash.h',                  condWinc3400_1_2_2],
        ['driver/m2m_hif.h',                    condAlways],
        ['driver/m2m_periph.h',                 condAlways],
        ['driver/m2m_types.h',                  condAlways],
        ['driver/m2m_wifi.h',                   condAlways],
        ['driver/nmasic.h',                     condAlways],
        ['driver/nmbus.h',                      condAlways],
        ['driver/nmdrv.h',                      condAlways],
        ['driver/nmflash.h',                    condWinc3400_1_2_2],
        ['driver/nmspi.h',                      condAlways],
        ['spi_flash/spi_flash.h',               condAlways],
        ['spi_flash/spi_flash_map.h',           condAlways],
        ['spi_flash/flexible_flash.h',          condWinc1500_19_6_1],
        ['socket/m2m_socket_host_if.h',         condSocketMode],
        ['driver/m2m_ota.h',                    condSocketMode],
        ['driver/m2m_ssl.h',                    condSocketMode],
        ['driver/ecc_types.h',                  condSocketMode],
        ['socket/socket.h',                     condSocketMode],
        ['socket/netinet_in.h',                 condSocketMode],
    ]

    bledrvFirmwareDriverIncFiles = [
        ['at_ble_api/at_ble_api.h',             condBle],
        ['platform/platform.h',                 condBle],
        ['ble_stack/atts_task.h',               condBle],
        ['ble_stack/cmn_defs.h',                condBle],
        ['ble_stack/dbg_task.h',                condBle],
        ['ble_stack/ble_device.h',              condBle],
        ['ble_stack/diss_task.h',               condBle],
        ['ble_stack/error.h',                   condBle],
        ['ble_stack/event.h',                   condBle],
        ['ble_stack/gapc_task.h',               condBle],
        ['ble_stack/gapm_task.h',               condBle],
        ['ble_stack/gattc_task.h',              condBle],
        ['ble_stack/gattm_task.h',              condBle],
        ['ble_stack/htpt.h',                    condBle],
        ['ble_stack/htpt_task.h',               condBle],
        ['ble_stack/interface.h',               condBle],
        ['ble_stack/ll_if.h',                   condBle],
        ['ble_stack/profiles.h',                condBle],
        ['ble_stack/smpc_task.h',               condBle],
        ['ble_stack/wifiprov_task.h',           condBle],
    ]

    for incFileEntry in wdrvIncFiles:
        importIncFile(drvWincComponent, configName, incFileEntry)

    for incFileEntry in wdrvFirmwareDriverIncFiles:
        importIncFile(drvWincComponent, configName, incFileEntry, 'winc1500_19.6.1')

    for incFileEntry in wdrvFirmwareDriverIncFiles:
        importIncFile(drvWincComponent, configName, incFileEntry, 'winc3400_1.2.2')

    for incFileEntry in wdrvFirmwareDriverIncFiles:
        importIncFile(drvWincComponent, configName, incFileEntry, 'winc3400_1.3.0')

    for incFileEntry in bledrvFirmwareDriverIncFiles:
        importIncFile(drvWincComponent, configName, incFileEntry, 'bluetooth_driver')

    wdrvSrcFiles = [
        ['wdrv_winc.c',                         condAlways],
        ['wdrv_winc_assoc.c',                   condAlways],
        ['wdrv_winc_authctx.c',                 condAlways],
        ['wdrv_winc_ble.c',                     condBle],
        ['wdrv_winc_bssctx.c',                  condAlways],
        ['wdrv_winc_bssfind.c',                 condAlways],
        ['wdrv_winc_custie.c',                  condAlways],
        ['wdrv_winc_ethernet.c',                condEthernetMode],
        ['wdrv_winc_host_file.c',               condHostFileSupport],
        ['wdrv_winc_httpprovctx.c',             condSocketMode],
        ['wdrv_winc_nvm.c',                     condAlways],
        ['wdrv_winc_powersave.c',               condAlways],
        ['wdrv_winc_socket.c',                  condSocketMode],
        ['wdrv_winc_softap.c',                  condAlways],
        ['wdrv_winc_ssl.c',                     condSocketMode],
        ['wdrv_winc_sta.c',                     condAlways],
        ['wdrv_winc_systime.c',                 condAlways],
        ['wdrv_winc_wps.c',                     condAlways],
        ['dev/gpio/wdrv_winc_eint.c',           condAlways],
        ['dev/gpio/wdrv_winc_gpio.c',           condAlways],
        ['dev/spi/wdrv_winc_spi.c',             condAlways],
        ['osal/wdrv_winc_osal.c',               condAlways],
        ['stack_driver/wdrv_winc_ctrl_itf.c',   condTcpipStackPresent],
        ['stack_driver/wdrv_winc_stack_drv.c',  condTcpipStackPresent],
        ['stack_driver/wdrv_winc_pktpool.c',    condTcpipStackPresent],
        ['stack_driver/wdrv_winc_stack_itf.c',  condTcpipStackPresent],
        ['stack_driver/wdrv_winc_itf_proxy.c',  condTcpipStackPresent],
        ['stack_driver/wdrv_winc_iwpriv.c',     condIwprivIntfPresent]
    ]

    wdrvFirmwareDriverSrcFiles = [
        ['common/nm_common.c',                  condAlways],
        ['driver/m2m_flash.c',                  condWinc3400_1_2_2],
        ['driver/m2m_hif.c',                    condAlways],
        ['driver/m2m_periph.c',                 condAlways],
        ['driver/m2m_wifi.c',                   condAlways],
        ['driver/nmasic.c',                     condAlways],
        ['driver/nmbus.c',                      condAlways],
        ['driver/nmdrv.c',                      condAlways],
        ['driver/nmflash.c',                    condWinc3400_1_2_2],
        ['driver/nmspi.c',                      condAlways],
        ['spi_flash/spi_flash.c',               condAlways],
        ['spi_flash/flexible_flash.c',          condWinc1500_19_6_1],
        ['driver/m2m_ota.c',                    condSocketMode],
        ['driver/m2m_ssl.c',                    condSocketMode],
        ['socket/socket.c',                     condSocketMode],
        ['socket/inet_ntop.c',                  condSocketMode],
        ['socket/inet_addr.c',                  condSocketMode]
    ]

    bledrvFirmwareDriverSrcFiles = [
        ['ble_stack/dbg_task.c',                 condBle],
        ['ble_stack/error.c',                    condBle],
        ['ble_stack/event.c',                    condBle],
        ['ble_stack/gap.c',                      condBle],
        ['ble_stack/gapc_task.c',                condBle],
        ['ble_stack/gapm_task.c',                condBle],
        ['ble_stack/gatt_client.c',              condBle],
        ['ble_stack/gatt_server.c',              condBle],
        ['ble_stack/gattc_task.c',               condBle],
        ['ble_stack/gattm_task.c',               condBle],
        ['ble_stack/htpt.c',                     condBle],
        ['ble_stack/htpt_task.c',                condBle],
        ['ble_stack/interface.c',                condBle],
        ['ble_stack/security.c',                 condBle],
        ['ble_stack/wifiprov_task.c',            condBle],
        ['platform/platform.c',                 condBle],
    ]

    for srcFileEntry in wdrvSrcFiles:
        importSrcFile(drvWincComponent, configName, srcFileEntry)

    for srcFileEntry in wdrvFirmwareDriverSrcFiles:
        importSrcFile(drvWincComponent, configName, srcFileEntry, 'winc1500_19.6.1')

    for srcFileEntry in wdrvFirmwareDriverSrcFiles:
        importSrcFile(drvWincComponent, configName, srcFileEntry, 'winc3400_1.2.2')

    for srcFileEntry in wdrvFirmwareDriverSrcFiles:
        importSrcFile(drvWincComponent, configName, srcFileEntry, 'winc3400_1.3.0')

    for srcFileEntry in bledrvFirmwareDriverSrcFiles:
        importSrcFile(drvWincComponent, configName, srcFileEntry, 'bluetooth_driver')

    wdrvIncPaths = [
        ['/',                                   condAlways],
        ['/dev',                                condAlways],
        ['/stack_driver',                       condTcpipStackPresent]
    ]

    wdrvFirmwareDriverIncPaths = [
        ['/drv/bsp',                            condAlways],
        ['/drv/bsp/include',                    condAlways],
        ['/drv/common',                         condAlways],
        ['/drv/driver',                         condAlways],
        ['/drv/socket',                         condSocketMode],
        ['/drv/spi_flash',                      condAlways],
        ['/drv/at_ble_api',                     condBle],
        ['/drv/ble_stack',                      condBle],
        ['/drv/platform',                       condBle]
    ]

    for incPathEntry in wdrvIncPaths:
        setIncPath(drvWincComponent, configName, incPathEntry)

    for incPathEntry in wdrvFirmwareDriverIncPaths:
        setIncPath(drvWincComponent, configName, incPathEntry)

    drvwincSystemDefFile = drvWincComponent.createFileSymbol('DRV_WIFI_WINC_DEF', None)
    drvwincSystemDefFile.setType('STRING')
    drvwincSystemDefFile.setOutputName('core.LIST_SYSTEM_DEFINITIONS_H_INCLUDES')
    drvwincSystemDefFile.setSourcePath('driver/winc/templates/system/system_definitions.h.ftl')
    drvwincSystemDefFile.setMarkup(True)

    drvwincSystemDefObjFile = drvWincComponent.createFileSymbol('DRV_WIFI_WINC_SYSTEM_DEF_OBJECT', None)
    drvwincSystemDefObjFile.setType('STRING')
    drvwincSystemDefObjFile.setOutputName('core.LIST_SYSTEM_DEFINITIONS_H_OBJECTS')
    drvwincSystemDefObjFile.setSourcePath('driver/winc/templates/system/system_definitions_objects.h.ftl')
    drvwincSystemDefObjFile.setMarkup(True)

    drvwincSystemConfFile = drvWincComponent.createFileSymbol('DRV_WIFI_WINC_SYSTEM_CFG', None)
    drvwincSystemConfFile.setType('STRING')
    drvwincSystemConfFile.setOutputName('core.LIST_SYSTEM_CONFIG_H_DRIVER_CONFIGURATION')
    drvwincSystemConfFile.setSourcePath('driver/winc/templates/system/system_config.h.ftl')
    drvwincSystemConfFile.setMarkup(True)

    drvwincSystemInitDataFile = drvWincComponent.createFileSymbol("DRV_WIFI_WINC_INIT_DATA", None)
    drvwincSystemInitDataFile.setType("STRING")
    drvwincSystemInitDataFile.setOutputName("core.LIST_SYSTEM_INIT_C_DRIVER_INITIALIZATION_DATA")
    drvwincSystemInitDataFile.setSourcePath("driver/winc/templates/system/system_initialize_data.c.ftl")
    drvwincSystemInitDataFile.setMarkup(True)

    drvwincSystemInitFile = drvWincComponent.createFileSymbol("DRV_WIFI_WINC_SYS_INIT", None)
    drvwincSystemInitFile.setType("STRING")
    drvwincSystemInitFile.setOutputName("core.LIST_SYSTEM_INIT_C_SYS_INITIALIZE_DRIVERS")
    drvwincSystemInitFile.setSourcePath("driver/winc/templates/system/system_initialize.c.ftl")
    drvwincSystemInitFile.setMarkup(True)

    drvwincSystemTaskFile = drvWincComponent.createFileSymbol('DRV_WIFI_WINC_SYSTEM_TASKS_C', None)
    drvwincSystemTaskFile.setType('STRING')
    drvwincSystemTaskFile.setOutputName('core.LIST_SYSTEM_TASKS_C_CALL_DRIVER_TASKS')
    drvwincSystemTaskFile.setSourcePath('driver/winc/templates/system/system_tasks.c.ftl')
    drvwincSystemTaskFile.setMarkup(True)

    drvwincSystemRtosTasksFile = drvWincComponent.createFileSymbol('DRV_WIFI_WINC_SYS_RTOS_TASK', None)
    drvwincSystemRtosTasksFile.setType('STRING')
    drvwincSystemRtosTasksFile.setOutputName('core.LIST_SYSTEM_RTOS_TASKS_C_DEFINITIONS')
    drvwincSystemRtosTasksFile.setSourcePath('driver/winc/templates/system/system_rtos_tasks.c.ftl')
    drvwincSystemRtosTasksFile.setMarkup(True)
    drvwincSystemRtosTasksFile.setEnabled((Database.getSymbolValue('HarmonyCore', 'SELECT_RTOS') != 'BareMetal'))
    drvwincSystemRtosTasksFile.setDependencies(setEnabledRTOSTask, ['HarmonyCore.SELECT_RTOS'])

def setVisibilityWincVersion(symbol, event):
    if event['value'] == 'WINC1500':
        if symbol.getID() == 'DRV_WIFI_WINC1500_VERSION':
            symbol.setVisible(True)
        else:
            symbol.setVisible(False)
    else:
        if (symbol.getID() == 'DRV_WIFI_WINC3400_VERSION') or (symbol.getID() == 'DRV_WIFI_WINC_USE_BLUETOOTH_WINC3400'):
            symbol.setVisible(True)
        else:
            symbol.setVisible(False)

def setVisibilityRTOSMenu(symbol, event):
    if (event['value'] == None):
        symbol.setVisible(False)
    elif (event['value'] != 'BareMetal'):
        symbol.setVisible(True)
    else:
        symbol.setVisible(False)

def setVisibilityRTOSTaskConfig(symbol, event):
    if (event['value'] == 'Standalone'):
        symbol.setVisible(True)
        print('WiFi Standalone')
    else:
        symbol.setVisible(False)
        print('WiFi Combined')

def setVisibilityRTOSTaskDelay(symbol, event):
    drvWifiRtos = symbol.getComponent().getSymbolByID(event['id'])
    if(drvWifiRtos.getValue() == True):
        symbol.setVisible(True)
    else:
        symbol.setVisible(False)

def setEnabledRTOSTask(symbol, event):
    symbol.setEnabled((Database.getSymbolValue('HarmonyCore', 'SELECT_RTOS') != 'BareMetal'))

def setVisibilityUseTcpipStack(symbol, event):
    if(event['value'] == 'Ethernet Mode'):
        symbol.setVisible(True)
    else:
        symbol.setVisible(False)

def setVisibilityUseIwprivIntf(symbol, event):
    if(event['value'] == True):
        symbol.setVisible(True)
    else:
        symbol.setVisible(False)

def setVisibilityEicSource(symbol, event):
    eicUseSym = symbol.getComponent().getSymbolByID('DRV_WIFI_WINC_INT_SRC')

    if eicUseSym.getValue() == False:
        symbol.setVisible(False)
        symbol.setValue(False)
    else:
        eicID = symbol.getID().split('_')[-1]

        if Database.getSymbolValue('eic', 'EIC_INT_' + eicID):
            symbol.setVisible(True)
        else:
            symbol.setVisible(False)
            symbol.setValue(False)

def setValueEicSource(symbol, event):
    eicCurSel = symbol.getComponent().getSymbolByID('DRV_WIFI_WINC_EIC_SRC_SELECT')

    eicID = int(event['id'].split('_')[-1])

    if symbol.getComponent().getSymbolByID(event['id']).getValue():
        eicCurSel.setValue(eicID)
        for x in range(eicCurSel.getMax()+1):
            if x != eicID:
                symbol.getComponent().getSymbolByID('DRV_WIFI_WINC_EIC_SRC_' + str(x)).setVisible(False)
    elif eicCurSel.getValue() == eicID:
        for x in range(eicCurSel.getMax()+1):
            if Database.getSymbolValue('eic', 'EIC_INT_' + str(x)):
                symbol.getComponent().getSymbolByID('DRV_WIFI_WINC_EIC_SRC_' + str(x)).setVisible(True)

        eicCurSel.setValue(-1)

def setValueWincPrefix(symbol, event):
    component = symbol.getComponent()

    wincDevice  = component.getSymbolValue('DRV_WIFI_WINC_DEVICE')
    winc1500Ver = component.getSymbolValue('DRV_WIFI_WINC1500_VERSION')
    winc3400Ver = component.getSymbolValue('DRV_WIFI_WINC3400_VERSION')

    if wincDevice == 'WINC1500':
        symbol.setValue(wincDevice + '_' + winc1500Ver.replace('.', '_'))
    elif wincDevice == 'WINC3400':
        symbol.setValue(wincDevice + '_' + winc3400Ver.replace('.', '_'))
    else:
        symbol.setValue('')

def setEnableSocketMode(symbol, event):
    component = symbol.getComponent()

    setSocketMode  =  component.getSymbolValue('DRV_WIFI_WINC_DRIVER_MODE')
    if ((setSocketMode == 'Socket Mode') and (checkPrefix(symbol))):
        symbol.setEnabled(True)
    else:
        symbol.setEnabled(False)

def setEnableEthernetMode(symbol, event):
    if ((event['value'] == 'Ethernet Mode') and (checkPrefix(symbol))):
       symbol.setEnabled(True)
    else:
       res = symbol.getComponent().getCapabilityEnabled("libdrvWincMac")
       if (res == True):
           symbol.getComponent().setCapabilityEnabled("libdrvWincMac",False)
       symbol.setEnabled(False)

def setEnableBlePresent(symbol, event):
    component = symbol.getComponent()

    wincDeviceMode   = component.getSymbolValue('DRV_WIFI_WINC_DEVICE')
    useBleDriverMode = component.getSymbolValue('DRV_WIFI_WINC_USE_BLUETOOTH_WINC3400')

    if ((wincDeviceMode == 'WINC3400') and (useBleDriverMode == True)):
       symbol.setEnabled(True)
    else:
       symbol.setEnabled(False)

def setEnableTcpipStackPresent(symbol, event):
    component = symbol.getComponent()

    wincDrvMode   = component.getSymbolValue('DRV_WIFI_WINC_DRIVER_MODE')
    useTcpipStack = component.getSymbolValue('DRV_WIFI_WINC_USE_TCPIP_STACK')
    wincMacActive = component.getCapabilityEnabled("libdrvWincMac")

    if ((wincDrvMode == 'Ethernet Mode') and (useTcpipStack == True)):
       symbol.setEnabled(True)
       if (wincMacActive == False):
           component.setCapabilityEnabled("libdrvWincMac", True)
    else:
       symbol.setEnabled(False)
       if (wincMacActive == True):
           component.setCapabilityEnabled("libdrvWincMac", False)

def setEnableIwprivIntfPresent(symbol, event):
    component = symbol.getComponent()

    wincDrvMode   = component.getSymbolValue('DRV_WIFI_WINC_DRIVER_MODE')
    useIwprivIntf = component.getSymbolValue('DRV_WIFI_WINC_USE_IWPRIV_INTF')

    if ((wincDrvMode == 'Ethernet Mode') and (useIwprivIntf == True)):
       symbol.setEnabled(True)
    else:
       symbol.setEnabled(False)

def setEnableWinc1500_19_6_1(symbol, event):
    component = symbol.getComponent()

    wincDevice  = component.getSymbolValue('DRV_WIFI_WINC_DEVICE')
    winc1500Ver = component.getSymbolValue('DRV_WIFI_WINC1500_VERSION')
    winc3400Ver = component.getSymbolValue('DRV_WIFI_WINC3400_VERSION')
    wincVerPrefix = component.getSymbolByID('DRV_WIFI_WINC_VER_PREFIX')
    
    if (wincDevice == 'WINC1500'):
        wincVerPrefix.setValue(wincDevice + '_' + winc1500Ver.replace('.', '_'))
    else:
        wincVerPrefix.setValue(wincDevice + '_' + winc3400Ver.replace('.', '_'))
    if ((wincDevice == 'WINC1500') and (winc1500Ver == '19.6.1') and (checkPrefix(symbol))):
       symbol.setEnabled(True)
    else:
       symbol.setEnabled(False)

def setEnableWinc3400_1_2_2(symbol, event):
    component = symbol.getComponent()

    wincDevice  = component.getSymbolValue('DRV_WIFI_WINC_DEVICE')
    winc3400Ver = component.getSymbolValue('DRV_WIFI_WINC3400_VERSION')
    winc1500Ver = component.getSymbolValue('DRV_WIFI_WINC1500_VERSION')
    wincVerPrefix = component.getSymbolByID('DRV_WIFI_WINC_VER_PREFIX')
    if (wincDevice == 'WINC1500'):
        wincVerPrefix.setValue(wincDevice + '_' + winc1500Ver.replace('.', '_'))
    else:
        wincVerPrefix.setValue(wincDevice + '_' + winc3400Ver.replace('.', '_'))
   
    if ((wincDevice == 'WINC3400') and (winc3400Ver == '1.2.2') and (checkPrefix(symbol))):
       symbol.setEnabled(True)
    else:
       symbol.setEnabled(False)

def setEnableWinc3400_1_3_0(symbol, event):
    component = symbol.getComponent()

    wincDevice  = component.getSymbolValue('DRV_WIFI_WINC_DEVICE')
    winc1500Ver = component.getSymbolValue('DRV_WIFI_WINC1500_VERSION')
    winc3400Ver = component.getSymbolValue('DRV_WIFI_WINC3400_VERSION')
    wincVerPrefix = component.getSymbolByID('DRV_WIFI_WINC_VER_PREFIX')
    
    if (wincDevice == 'WINC1500'):
        wincVerPrefix.setValue(wincDevice + '_' + winc1500Ver.replace('.', '_'))
    else:
        wincVerPrefix.setValue(wincDevice + '_' + winc3400Ver.replace('.', '_'))

    if ((wincDevice == 'WINC3400') and (winc3400Ver == '1.3.0') and (checkPrefix(symbol))):
       symbol.setEnabled(True)
    else:
       symbol.setEnabled(False)

def setEnableHostFileSupport(symbol, event):
    # Host file API support requires WINC1500 version 19.6.1+ in Socket Mode
    component = symbol.getComponent()

    wincDevice  = component.getSymbolValue('DRV_WIFI_WINC_DEVICE')
    winc1500Ver = component.getSymbolValue('DRV_WIFI_WINC1500_VERSION')
    wincDrvMode = component.getSymbolValue('DRV_WIFI_WINC_DRIVER_MODE')

    if ((wincDevice == 'WINC1500') and (winc1500Ver == '19.6.1') and (wincDrvMode == 'Socket Mode')):
       symbol.setEnabled(True)
    else:
       symbol.setEnabled(False)

def setEnablePrefix(symbol, event):
    symbol.setEnabled(checkPrefix(symbol))
