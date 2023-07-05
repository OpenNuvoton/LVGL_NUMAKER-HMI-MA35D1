#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

/* Automatically generated file; DO NOT EDIT. */
/* RT-Thread Configuration */

#define USE_MA35D1_AARCH32

/* RT-Thread Kernel */

#define RT_NAME_MAX 8
#define RT_USING_SMP
#define RT_CPUS_NR 2
#define RT_ALIGN_SIZE 32
#define RT_THREAD_PRIORITY_32
#define RT_THREAD_PRIORITY_MAX 32
#define RT_TICK_PER_SECOND 1000
#define RT_USING_OVERFLOW_CHECK
#define RT_USING_HOOK
#define RT_HOOK_USING_FUNC_PTR
#define RT_USING_IDLE_HOOK
#define RT_IDLE_HOOK_LIST_SIZE 4
#define IDLE_THREAD_STACK_SIZE 4096
#define SYSTEM_THREAD_STACK_SIZE 4096
#define RT_USING_TIMER_SOFT
#define RT_TIMER_THREAD_PRIO 4
#define RT_TIMER_THREAD_STACK_SIZE 4096

/* kservice optimization */

#define RT_KSERVICE_USING_STDLIB
#define RT_DEBUG
#define RT_DEBUG_COLOR

/* Inter-Thread communication */

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE

/* Memory Management */

#define RT_USING_MEMPOOL
#define RT_USING_SMALL_MEM
#define RT_USING_MEMHEAP
#define RT_MEMHEAP_FAST_MODE
#define RT_USING_SMALL_MEM_AS_HEAP
#define RT_USING_HEAP

/* Kernel Device Object */

#define RT_USING_DEVICE
#define RT_USING_INTERRUPT_INFO
#define RT_USING_CONSOLE
#define RT_CONSOLEBUF_SIZE 4096
#define RT_CONSOLE_DEVICE_NAME "uart0"
#define RT_VER_NUM 0x50000
#define ARCH_ARM
#define RT_USING_CPU_FFS
#define ARCH_ARM_CORTEX_A
#define RT_SMP_AUTO_BOOT
#define RT_USING_GIC_V2
#define ARCH_ARMV8

/* RT-Thread Components */

#define RT_USING_COMPONENTS_INIT
#define RT_USING_USER_MAIN
#define RT_MAIN_THREAD_STACK_SIZE 4096
#define RT_MAIN_THREAD_PRIORITY 10
#define RT_USING_LEGACY
#define RT_USING_MSH
#define RT_USING_FINSH
#define FINSH_USING_MSH
#define FINSH_THREAD_NAME "tshell"
#define FINSH_THREAD_PRIORITY 20
#define FINSH_THREAD_STACK_SIZE 4096
#define FINSH_USING_HISTORY
#define FINSH_HISTORY_LINES 5
#define FINSH_USING_SYMTAB
#define FINSH_CMD_SIZE 128
#define MSH_USING_BUILT_IN_COMMANDS
#define FINSH_USING_DESCRIPTION
#define FINSH_ARG_MAX 10
#define RT_USING_DFS
#define DFS_USING_POSIX
#define DFS_USING_WORKDIR
#define DFS_FILESYSTEMS_MAX 32
#define DFS_FILESYSTEM_TYPES_MAX 32
#define DFS_FD_MAX 128
#define RT_USING_DFS_MNTTABLE
#define RT_USING_DFS_ELMFAT

/* elm-chan's FatFs, Generic FAT Filesystem Module */

#define RT_DFS_ELM_CODE_PAGE 437
#define RT_DFS_ELM_WORD_ACCESS
#define RT_DFS_ELM_USE_LFN_3
#define RT_DFS_ELM_USE_LFN 3
#define RT_DFS_ELM_LFN_UNICODE_0
#define RT_DFS_ELM_LFN_UNICODE 0
#define RT_DFS_ELM_MAX_LFN 255
#define RT_DFS_ELM_DRIVES 8
#define RT_DFS_ELM_MAX_SECTOR_SIZE 512
#define RT_DFS_ELM_REENTRANT
#define RT_DFS_ELM_MUTEX_TIMEOUT 3000
#define RT_USING_DFS_DEVFS

/* Device Drivers */

#define RT_USING_DEVICE_IPC
#define RT_USING_SYSTEM_WORKQUEUE
#define RT_SYSTEM_WORKQUEUE_STACKSIZE 2048
#define RT_SYSTEM_WORKQUEUE_PRIORITY 23
#define RT_USING_SERIAL
#define RT_USING_SERIAL_V1
#define RT_SERIAL_USING_DMA
#define RT_SERIAL_RB_BUFSZ 256
#define RT_USING_I2C
#define RT_USING_I2C_BITOPS
#define RT_USING_PIN
#define RT_USING_ADC
#define RT_USING_PWM
#define RT_USING_MTD_NAND
#define RT_MTD_NAND_DEBUG
#define RT_USING_RTC
#define RT_USING_SDIO
#define RT_SDIO_STACK_SIZE 4096
#define RT_SDIO_THREAD_PRIORITY 15
#define RT_MMCSD_STACK_SIZE 4096
#define RT_MMCSD_THREAD_PREORITY 22
#define RT_MMCSD_MAX_PARTITION 8
#define RT_USING_SPI
#define RT_USING_QSPI
#define RT_USING_AUDIO
#define RT_AUDIO_REPLAY_MP_BLOCK_SIZE 4096
#define RT_AUDIO_REPLAY_MP_BLOCK_COUNT 2
#define RT_AUDIO_RECORD_PIPE_SIZE 2048
#define RT_USING_SENSOR
#define RT_USING_TOUCH

/* Using USB */

#define RT_USING_USB
#define RT_USING_USB_HOST
#define RT_USBH_MSTORAGE
#define UDISK_MOUNTPOINT "/mnt/udisk"
#define RT_USBD_THREAD_STACK_SZ 4096

/* C/C++ and POSIX layer */

#define RT_LIBC_DEFAULT_TIMEZONE 8

/* POSIX (Portable Operating System Interface) layer */

#define RT_USING_POSIX_FS
#define RT_USING_POSIX_DEVIO
#define RT_USING_POSIX_POLL
#define RT_USING_POSIX_SELECT
#define RT_USING_POSIX_SOCKET
#define RT_USING_POSIX_DELAY
#define RT_USING_POSIX_CLOCK
#define RT_USING_PTHREADS
#define PTHREAD_NUM_MAX 8
#define RT_USING_MODULE
#define RT_USING_CUSTOM_DLMODULE

/* Interprocess Communication (IPC) */

#define RT_USING_POSIX_PIPE
#define RT_USING_POSIX_PIPE_SIZE 512
#define RT_USING_POSIX_MESSAGE_QUEUE
#define RT_USING_POSIX_MESSAGE_SEMAPHORE

/* Socket is in the 'Network' category */


/* Network */

#define RT_USING_SAL

/* Docking with protocol stacks */

#define SAL_USING_LWIP
#define SAL_USING_POSIX
#define RT_USING_NETDEV
#define NETDEV_USING_IFCONFIG
#define NETDEV_USING_PING
#define NETDEV_USING_NETSTAT
#define NETDEV_USING_AUTO_DEFAULT
#define NETDEV_IPV4 1
#define NETDEV_IPV6 0
#define RT_USING_LWIP
#define RT_USING_LWIP212
#define RT_USING_LWIP_VER_NUM 0x20102
#define RT_LWIP_MEM_ALIGNMENT 32
#define RT_LWIP_IGMP
#define RT_LWIP_ICMP
#define RT_LWIP_DNS
#define RT_LWIP_DHCP
#define IP_SOF_BROADCAST 1
#define IP_SOF_BROADCAST_RECV 1

/* Static IPv4 Address */

#define RT_LWIP_IPADDR "192.168.31.55"
#define RT_LWIP_GWADDR "192.168.31.1"
#define RT_LWIP_MSKADDR "255.255.255.0"
#define RT_LWIP_UDP
#define RT_LWIP_TCP
#define RT_LWIP_RAW
#define RT_MEMP_NUM_NETCONN 32
#define RT_LWIP_PBUF_NUM 8192
#define RT_LWIP_RAW_PCB_NUM 32
#define RT_LWIP_UDP_PCB_NUM 32
#define RT_LWIP_TCP_PCB_NUM 32
#define RT_LWIP_TCP_SEG_NUM 1024
#define RT_LWIP_TCP_SND_BUF 8192
#define RT_LWIP_TCP_WND 10240
#define RT_LWIP_TCPTHREAD_PRIORITY 10
#define RT_LWIP_TCPTHREAD_MBOX_SIZE 8192
#define RT_LWIP_TCPTHREAD_STACKSIZE 4096
#define RT_LWIP_ETHTHREAD_PRIORITY 12
#define RT_LWIP_ETHTHREAD_STACKSIZE 4096
#define RT_LWIP_ETHTHREAD_MBOX_SIZE 8192
#define RT_LWIP_REASSEMBLY_FRAG
#define LWIP_NETIF_STATUS_CALLBACK 1
#define LWIP_NETIF_LINK_CALLBACK 1
#define SO_REUSE 1
#define LWIP_SO_RCVTIMEO 1
#define LWIP_SO_SNDTIMEO 1
#define LWIP_SO_RCVBUF 1
#define LWIP_SO_LINGER 0
#define RT_LWIP_NETIF_LOOPBACK
#define LWIP_NETIF_LOOPBACK 1
#define RT_LWIP_STATS
#define RT_LWIP_USING_HW_CHECKSUM
#define RT_LWIP_USING_PING

/* Utilities */

#define RT_USING_ULOG
#define ULOG_OUTPUT_LVL_D
#define ULOG_OUTPUT_LVL 7
#define ULOG_USING_ISR_LOG
#define ULOG_ASSERT_ENABLE
#define ULOG_LINE_BUF_SIZE 128

/* log format */

#define ULOG_USING_COLOR
#define ULOG_OUTPUT_TIME
#define ULOG_OUTPUT_LEVEL
#define ULOG_OUTPUT_TAG
#define ULOG_OUTPUT_THREAD_NAME
#define ULOG_BACKEND_USING_CONSOLE
#define RT_USING_UTEST
#define UTEST_THR_STACK_SIZE 4096
#define UTEST_THR_PRIORITY 20

/* RT-Thread Utestcases */

#define RT_USING_UTESTCASES

/* Utest Self Testcase */

#define UTEST_SELF_PASS_TC

/* Kernel Testcase */

#define UTEST_MEMHEAP_TC
#define UTEST_SMALL_MEM_TC

/* CPP11 Testcase */


/* Utest Serial Testcase */


/* RTT Posix Testcase */


/* RT-Thread online packages */

/* IoT - internet of things */


/* Wi-Fi */

/* Marvell WiFi */


/* Wiced WiFi */


/* IoT Cloud */


/* security packages */


/* language packages */

/* JSON: JavaScript Object Notation, a lightweight data-interchange format */


/* XML: Extensible Markup Language */


/* multimedia packages */

/* LVGL: powerful and easy-to-use embedded GUI library */

#define PKG_USING_LVGL
#define PKG_LVGL_THREAD_PRIO 20
#define PKG_LVGL_THREAD_STACK_SIZE 4096
#define PKG_LVGL_DISP_REFR_PERIOD 16
#define PKG_LVGL_USING_DEMOS
#define PKG_LVGL_USING_V08035
#define PKG_LVGL_VER_NUM 0x08035

/* u8g2: a monochrome graphic library */

#define PKG_USING_WAVPLAYER
#define PKG_WP_USING_PLAY
#define PKG_WP_PLAY_DEVICE "sound0"
#define PKG_WP_USING_RECORD
#define PKG_WP_RECORD_DEVICE "sound0"
#define PKG_USING_WAVPLAYER_LATEST_VERSION

/* tools packages */


/* system packages */

/* enhanced kernel services */


/* acceleration: Assembly language or algorithmic acceleration packages */


/* CMSIS: ARM Cortex-M Microcontroller Software Interface Standard */


/* Micrium: Micrium software products porting for RT-Thread */

#define PKG_USING_RAMDISK
#define PKG_USING_RAMDISK_LATEST_VERSION

/* peripheral libraries and drivers */

/* sensors drivers */

#define PKG_USING_MPU6XXX
#define PKG_USING_MPU6XXX_LATEST_VERSION
#define PKG_USING_MPU6XXX_ACCE
#define PKG_USING_MPU6XXX_GYRO

/* touch drivers */


/* Kendryte SDK */


/* AI packages */


/* Signal Processing and Control Algorithm Packages */


/* miscellaneous packages */

/* project laboratory */

/* samples: kernel and components samples */


/* entertainment: terminal games and other interesting software packages */

#define PKG_USING_OPTPARSE
#define PKG_USING_OPTPARSE_LATEST_VERSION

/* Arduino libraries */


/* Projects and Demos */


/* Sensors */


/* Display */


/* Timing */


/* Data Processing */


/* Data Storage */

/* Communication */


/* Device Control */


/* Other */


/* Signal IO */


/* Uncategorized */

/* Hardware Drivers Config */

/* On-chip Peripheral Drivers */

#define SOC_SERIES_MA35D1
#define BSP_USING_SSPCC
#define BSP_USING_SSMCC
#define BSP_USING_UMCTL2
#define BSP_USING_RTP
#define RTP_USING_AT_STARTUP
#define RT_USING_FPU
#define BSP_USE_STDDRIVER_SOURCE
#define BSP_USING_PDMA
#define BSP_USING_PDMA0
#define BSP_USING_PDMA1
#define NU_PDMA_MEMFUN_ACTOR_MAX 4
#define BSP_USING_GPIO
#define BSP_USING_GMAC
#define BSP_USING_GMAC0
#define BSP_USING_GMAC1
#define BSP_USING_RTC
#define BSP_USING_ADC
#define BSP_USING_ADC_TOUCH
#define BSP_USING_UART
#define BSP_USING_UART0
#define BSP_USING_UART11
#define BSP_USING_UART11_TX_DMA
#define BSP_USING_UART11_RX_DMA
#define BSP_USING_UART12
#define BSP_USING_UART14
#define BSP_USING_UART16
#define BSP_USING_UART16_TX_DMA
#define BSP_USING_UART16_RX_DMA
#define BSP_USING_I2C
#define BSP_USING_I2C0
#define BSP_USING_I2C1
#define BSP_USING_I2C2
#define BSP_USING_I2C3
#define BSP_USING_I2C4
#define BSP_USING_I2C5
#define BSP_USING_SDH
#define BSP_USING_SDH0
#define BSP_USING_SDH1
#define BSP_USING_SPI
#define BSP_USING_SPI0_NONE
#define BSP_USING_SPI1_NONE
#define BSP_USING_SPI2_NONE
#define BSP_USING_SPI3_NONE
#define BSP_USING_I2S
#define BSP_USING_I2S0
#define NU_I2S_DMA_FIFO_SIZE 2048
#define BSP_USING_QSPI
#define BSP_USING_QSPI0
#define BSP_USING_DISP
#define LCM_USING_FW070TFT_WSVGA
#define DISP_USING_LCD_IDX 0
#define BSP_LCD_BPP 32
#define BSP_LCD_WIDTH 1024
#define BSP_LCD_HEIGHT 600
#define DISP_USING_OVERLAY
#define BSP_USING_HWSEM
#define BSP_USING_HWSEM0
#define BSP_USING_WHC
#define BSP_USING_WHC0
#define BSP_USING_VDE
#define BSP_USING_USBH
#define BSP_USING_HSUSBH0
#define BSP_USING_HSUSBH1

/* On-board Peripheral Drivers */

#define BSP_USING_CONSOLE
#define BOARD_USING_NAU8822
#define BOARD_USING_STORAGE_SDCARD
#define BOARD_USING_STORAGE_EMMC
#define BOARD_USING_USBHOST

/* Board extended module drivers */

#define BOARD_USING_LCM
#define BOARD_USING_LCM_FW070TFT_WSVGA
#define BOARD_USING_ADCTOUCH

/* Nuvoton Packages Config */

#define NU_PKG_USING_UTILS
#define NU_PKG_USING_DEMO
#define NU_PKG_USING_NAU8822
#define NU_PKG_USING_ADC_TOUCH
#define NU_PKG_USING_ADC_TOUCH_HW
#define UTEST_CMD_PREFIX "bsp.nuvoton.utest."
#define BOARD_USE_UTEST

#endif
