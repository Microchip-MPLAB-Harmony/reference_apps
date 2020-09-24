Instructions for working with the OTA/Custom Loader support:

(1) In ack_stm32_config.h, adjust configuration for your specific STM32F030xx part. There are two sets of
    #define's in that file, one for STM32F030x8 (64K flash, 8K RAM) and one for STM32F030xC (256K flash,
    32K RAM); ensure that the correct set is uncommented.

(2) Configure ROM and RAM program regions in the ota-loader project.

    In Keil, this is done in the [Options for ota-loader - Target "ota-loader"] dialog, [Target] tab.
    Near the bottom of the dialog there are IROM1 and IRAM1 memory areas defined.

    For STM32F030x8, assuming 5K Loader Partition:
        IROM1: 0x8000000/0x1400
        IRAM1: 0x20000000/0x2000

    For STM32F030xC, assuming 6K Loader Partition:
        IROM1: 0x8000000/0x1800
        IRAM1: 0x20000000/0x8000

    The above are calculated as follows.
        IROM1 starts at the base address of flash memory (always 0x8000000 on STM32F030xx).
        IROM1 size is the size of the Loader Partition (OTA_LOADER_PARTITION_SIZE in ota_config.h).
        
        IRAM1 starts at the base address of RAM (always 0x20000000 on STM32F030xx).
        IRAM1 size is the full amount of RAM on the MCU.

(3) Configure ROM and RAM program regions in the HMCU app.

    In Keil, this is done in the [Options for xxx - Target "xxx"] dialog, [Target] tag.
    Near the bottom of the dialog there are IROM1 and IRAM1 memory areas defined.

    For STM32F030x8, assuming 5K Loader Partition (Status Partition is 1K; 45 interrupt vectors):
        IROM1: 0x8001800/0x7400
        IRAM1: 0x200000B4/0x1F4C

    For STM32F030xC, assuming 6K Loader Partition (Status Partition is 2K; 46 interrupt vectors):
        IROM1: 0x8002000/0x1F000
        IRAM1: 0x200000B8/0x7F48

    The above are calculated as follows (see ota_config.h for the values referenced in these descriptions).
        IROM1 starts at the end of the Status Partition.
        IROM1 size is the total amount of flash minus the sizes of the Loader and Status Partitions,
            divided by 2.

        IRAM1 starts at the end of the interrupt vector table.
        IRAM1 size is the amount of RAM in the MCU minus the size of the interrupt vector table.

(4) The output of building a customloader project and of building the HMCU application must both be
    flashed in the factory. There's a hexmerge.py script to enable merging the two hex files into one,
    to make this more convenient.

(5) To get an OTA image file to be uploaded to the ACK portal, run hex2ota.py on the .hex file that
    results from building the HMCU application.

(6) Important Python scripts:
    * hexmerge.py: merges 2 .hex files into one. Useful to create a single .hex file containing both
      the Custom Loader application and the HMCU application, to program in the factory. (DO NOT USE
      for creating OTA images. OTA images must contain ONLY the HMCU application!)
    * hex2ota.py: creates a file suitable for uploading as an HMCU OTA image, from a .hex file that was
      created by building the HMCU application.
    * hexdump.py, otadump.py: dump .hex and .ota files, respectively.

Optional:
    * Customize the Loader application to turn on LEDs when flashing, etc. Be sure to update
      UninitializeHardware() in ack_stm32_custom_loader.c to match your changes.
