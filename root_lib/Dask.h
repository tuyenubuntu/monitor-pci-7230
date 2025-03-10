#ifndef _DASK_H
#define _DASK_H

#ifdef __cplusplus
extern "C" {
#endif


/*
 * DASK Data Types
 */
typedef unsigned char  U8;
typedef short          I16;
typedef unsigned short U16;
typedef long           I32;
typedef unsigned long  U32;
typedef float          F32;
typedef double         F64;


/*
 * ADLink PCI Card Type
 */
#define PCI_6208V      1
#define PCI_6208A      2
#define PCI_6308V      3
#define PCI_6308A      4
#define PCI_7200       5
#define PCI_7230       6
#define PCI_7233       7
#define PCI_7234       8
#define PCI_7248       9
#define PCI_7249       10
#define PCI_7250       11
#define PCI_7252       12
#define PCI_7296       13
#define PCI_7300A_RevA 14
#define PCI_7300A_RevB 15
#define PCI_7432       16
#define PCI_7433       17
#define PCI_7434       18
#define PCI_8554       19
#define PCI_9111DG     20
#define PCI_9111HR     21
#define PCI_9112       22
#define PCI_9113       23
#define PCI_9114DG     24
#define PCI_9114HG     25
#define PCI_9118DG     26
#define PCI_9118HG     27
#define PCI_9118HR     28
#define PCI_9810       29
#define PCI_9812       30
#define PCI_7396       31
#define PCI_9116       32
#define PCI_7256       33
#define PCI_7258       34
#define PCI_7260       35
#define PCI_7452       36
#define PCI_7442       37
#define PCI_7443       38
#define PCI_7444       39
#define PCI_9221       40
#define PCI_9524       41
#define PCI_6202       42
#define PCI_9222       43
#define PCI_9223       44
#define PCI_7433C      45
#define PCI_7434C      46
#define PCI_922A       47
#define PCI_7350       48
#define PCI_7360       49
#define PCI_7300A_RevC 50
#define PCIe_9524      51
#define PCIe_9101      52
#define PCIe_9121      53
#define PCIe_9141      54
#define PCIe_9103      55
#define PCIe_9146      56
#define PCIe_9147      57
#define PCIe_9126      58
#define PCIe_9161      59
#define PCIe_9163      60
#define PCIe_9164      61
#define PCIe_7350_SPI        62 // For Honprec SPI Model (Derived from 7350)
#define PCIe_7350_PARALLEL   63 // For Honprec Parallel Model (Derived from 7350)

#define MAX_CARD       32

/*
 * Error Number
 */
#define NoError                     0
#define ErrorUnknownCardType       -1
#define ErrorInvalidCardNumber     -2
#define ErrorTooManyCardRegistered -3
#define ErrorCardNotRegistered     -4
#define ErrorFuncNotSupport        -5
#define ErrorInvalidIoChannel      -6
#define ErrorInvalidAdRange        -7
#define ErrorContIoNotAllowed      -8
#define ErrorDiffRangeNotSupport   -9
#define ErrorLastChannelNotZero    -10
#define ErrorChannelNotDescending  -11
#define ErrorChannelNotAscending   -12
#define ErrorOpenDriverFailed      -13
#define ErrorOpenEventFailed       -14
#define ErrorTransferCountTooLarge -15
#define ErrorNotDoubleBufferMode   -16
#define ErrorInvalidSampleRate     -17
#define ErrorInvalidCounterMode    -18
#define ErrorInvalidCounter        -19
#define ErrorInvalidCounterState   -20
#define ErrorInvalidBinBcdParam    -21
#define ErrorBadCardType           -22
#define ErrorInvalidDaRefVoltage   -23
#define ErrorAdTimeOut             -24
#define ErrorNoAsyncAI             -25
#define ErrorNoAsyncAO             -26
#define ErrorNoAsyncDI             -27
#define ErrorNoAsyncDO             -28
#define ErrorNotInputPort          -29
#define ErrorNotOutputPort         -30
#define ErrorInvalidDioPort        -31
#define ErrorInvalidDioLine        -32
#define ErrorContIoActive          -33
#define ErrorDblBufModeNotAllowed  -34
#define ErrorConfigFailed          -35
#define ErrorInvalidPortDirection  -36
#define ErrorBeginThreadError      -37
#define ErrorInvalidPortWidth      -38
#define ErrorInvalidCtrSource      -39
#define ErrorOpenFile              -40
#define ErrorAllocateMemory        -41
#define ErrorDaVoltageOutOfRange   -42
#define ErrorDaExtRefNotAllowed    -43
#define ErrorDIODataWidthError     -44
#define ErrorTaskCodeError         -45
#define ErrortriggercountError     -46
#define ErrorInvalidTriggerMode    -47
#define ErrorInvalidTriggerType    -48
#define ErrorInvalidCounterValue   -50
#define ErrorInvalidEventHandle    -60
#define ErrorNoMessageAvailable    -61
#define ErrorEventMessgaeNotAdded  -62
#define ErrorCalibrationTimeOut    -63
#define ErrorUndefinedParameter    -64
#define ErrorInvalidBufferID       -65
#define ErrorInvalidSampledClock   -66
#define ErrorInvalidOperationMode  -67
#define ErrorAnaTriggerLevel       -68
#define ErrorInvalidDIOMode        -69
#define ErrorInvalidTriggerSource  -70
#define ErrorInvalidPMType         -71
#define ErrorInvalidPMAction       -72
#define ErrorInvalidPMNumber       -73
#define ErrorInvalidPMPattern      -74
#define ErrorInvalidPMControlMode  -75
/*Error number for driver API*/
#define ErrorConfigIoctl           -201
#define ErrorAsyncSetIoctl         -202
#define ErrorDBSetIoctl            -203
#define ErrorDBHalfReadyIoctl      -204
#define ErrorContOPIoctl           -205
#define ErrorContStatusIoctl       -206
#define ErrorPIOIoctl              -207
#define ErrorDIntSetIoctl          -208
#define ErrorWaitEvtIoctl          -209
#define ErrorOpenEvtIoctl          -210
#define ErrorCOSIntSetIoctl        -211
#define ErrorMemMapIoctl           -212
#define ErrorMemUMapSetIoctl       -213
#define ErrorCTRIoctl              -214
#define ErrorGetResIoctl           -215
#define ErrorCalIoctl              -216
#define ErrorPMIntSetIoctl         -217

/* 20191205, added for pci-9116 calibration */
#define ErrorInvalidRefVoltage        -325
#define ErrorCalibrateFailed          -326
#define ErrorInvalidCalData           -327
#define ErrorFlashProgramTimeout      -343
#define ErrorInvalidFlashAddress      -344
#define ErrorFlashProgramVerify       -345

#define ErrorNullPoint                -398
#define ErrorAccessViolationDataCopy  -399
/*
 * AD Range
 */
#define AD_B_10_V     1
#define AD_B_5_V      2
#define AD_B_2_5_V    3
#define AD_B_1_25_V   4
#define AD_B_0_625_V  5
#define AD_B_0_3125_V 6
#define AD_B_0_5_V    7
#define AD_B_0_05_V   8
#define AD_B_0_005_V  9
#define AD_B_1_V      10
#define AD_B_0_1_V    11
#define AD_B_0_01_V   12
#define AD_B_0_001_V  13
#define AD_U_20_V     14
#define AD_U_10_V     15
#define AD_U_5_V      16
#define AD_U_2_5_V    17
#define AD_U_1_25_V   18
#define AD_U_1_V      19
#define AD_U_0_1_V    20
#define AD_U_0_01_V   21
#define AD_U_0_001_V  22
#define AD_B_2_V      23
#define AD_B_0_25_V   24
#define AD_B_0_2_V    25
#define AD_U_4_V      26
#define AD_U_2_V      27
#define AD_U_0_5_V    28
#define AD_U_0_4_V    29


/*------------------*/
/* Common Constants */
/*------------------*/
/* T or F*/
#define TRUE  1
#define FALSE 0

/*Synchronous Mode*/
#define SYNCH_OP  1
#define ASYNCH_OP 2

/*AO Terminate Mode*/
#define DA_TerminateImmediate 0

/*DIO Port Direction*/
#define INPUT_PORT  1
#define OUTPUT_PORT 2
/*DIO Line Direction*/
#define INPUT_LINE  1
#define OUTPUT_LINE 2

/*Clock Mode*/
#define TRIG_SOFTWARE         0
#define TRIG_INT_PACER        1
#define TRIG_EXT_STROBE       2
#define TRIG_HANDSHAKE        3
#define TRIG_CLK_10MHZ        4
#define TRIG_CLK_20MHZ        5
#define TRIG_DO_CLK_TIMER_ACK 6
#define TRIG_DO_CLK_10M_ACK   7
#define TRIG_DO_CLK_20M_ACK   8

/*Virtual Sampling Rate for using external clock as the clock source*/
#define CLKSRC_EXT_SampRate 10000

/*Register by slot*/
#define RegBySlot 0x8000

/*PCI info*/
#define PCILocInfo(bus, dev, fun) \
    RegBySlot|((bus&0xffff)<<8)|((dev&0x1f)<<3)|(fun&0x7)

/*DIO & AFI Voltage Level*/
#define VoltLevel_3R3 0
#define VoltLevel_2R5 1
#define VoltLevel_1R8 2
#define VoltLevel_DisableDO 3

/*---------------------------------------------*/
/* Constants for PCI-6208A/PCI-6308A/PCI-6308V */
/*---------------------------------------------*/
/*Output Mode*/
#define P6208_CURRENT_0_20MA 0
#define P6208_CURRENT_4_20MA 3
#define P6208_CURRENT_5_25MA 1
#define P6308_CURRENT_0_20MA 0
#define P6308_CURRENT_4_20MA 3
#define P6308_CURRENT_5_25MA 1
/*AO Setting*/
#define P6308V_AO_CH0_3      0
#define P6308V_AO_CH4_7      1
#define P6308V_AO_UNIPOLAR   0
#define P6308V_AO_BIPOLAR    1


/*------------------------*/
/* Constants for PCI-7200 */
/*------------------------*/
/*InputMode*/
#define DI_WAITING      0x02
#define DI_NOWAITING    0x00
#define DI_TRIG_RISING  0x04
#define DI_TRIG_FALLING 0x00
#define IREQ_RISING     0x08
#define IREQ_FALLING    0x00
/*Output Mode*/
#define OREQ_ENABLE     0x10
#define OREQ_DISABLE    0x00
#define OTRIG_HIGH      0x20
#define OTRIG_LOW       0x00


/*----------------------------------*/
/* Constants for PCI-7248/7296/7396 */
/*----------------------------------*/
/*Channel & Port*/
#define Channel_P1A  0
#define Channel_P1B  1
#define Channel_P1C  2
#define Channel_P1CL 3
#define Channel_P1CH 4
#define Channel_P1AE 10
#define Channel_P1BE 11
#define Channel_P1CE 12
#define Channel_P2A  5
#define Channel_P2B  6
#define Channel_P2C  7
#define Channel_P2CL 8
#define Channel_P2CH 9
#define Channel_P2AE 15
#define Channel_P2BE 16
#define Channel_P2CE 17
#define Channel_P3A  10
#define Channel_P3B  11
#define Channel_P3C  12
#define Channel_P3CL 13
#define Channel_P3CH 14
#define Channel_P4A  15
#define Channel_P4B  16
#define Channel_P4C  17
#define Channel_P4CL 18
#define Channel_P4CH 19
#define Channel_P5A  20
#define Channel_P5B  21
#define Channel_P5C  22
#define Channel_P5CL 23
#define Channel_P5CH 24
#define Channel_P6A  25
#define Channel_P6B  26
#define Channel_P6C  27
#define Channel_P6CL 28
#define Channel_P6CH 29
/*the following are used for PCI7396*/
#define Channel_P1   30
#define Channel_P2   31
#define Channel_P3   32
#define Channel_P4   33
#define Channel_P1E  34
#define Channel_P2E  35
#define Channel_P3E  36
#define Channel_P4E  37


/*----------------------------------*/
/* Constants for PCI-7442/7443/7444 */
/*----------------------------------*/
/*P7442*/
#define P7442_CH0  0
#define P7442_CH1  1
#define P7442_TTL0 2
#define P7442_TTL1 3
/*P7443*/
#define P7443_CH0  0
#define P7443_CH1  1
#define P7443_CH2  2
#define P7443_CH3  3
#define P7443_TTL0 4
#define P7443_TTL1 5
/*P7444*/
#define P7444_CH0  0
#define P7444_CH1  1
#define P7444_CH2  2
#define P7444_CH3  3
#define P7444_TTL0 4
#define P7444_TTL1 5

/*COS Counter OP*/
#define COS_COUNTER_RESET 0
#define COS_COUNTER_SETUP 1
#define COS_COUNTER_START 2
#define COS_COUNTER_STOP  3
#define COS_COUNTER_READ  4


/*
 * EMG shdn ctrl code
 */
#define EMGSHDN_OFF      0
#define EMGSHDN_ON       1
#define EMGSHDN_RECOVERY 2


/*
 * Hot Reset Hold ctrl code
 */
#define HRH_OFF 0
#define HRH_ON  1


/*-------------------------*/
/* Constants for PCI-7300A */
/*-------------------------*/
/*Wait Status*/
#define P7300_WAIT_NO   0
#define P7300_WAIT_TRG  1
#define P7300_WAIT_FIFO 2
#define P7300_WAIT_BOTH 3

/*Terminator control*/
#define P7300_TERM_OFF 0
#define P7300_TERM_ON  1

/*DI control signals polarity for PCI-7300A Rev. B*/
#define P7300_DIREQ_POS  0x00000000L
#define P7300_DIREQ_NEG  0x00000001L
#define P7300_DIACK_POS  0x00000000L
#define P7300_DIACK_NEG  0x00000002L
#define P7300_DITRIG_POS 0x00000000L
#define P7300_DITRIG_NEG 0x00000004L
/*DO control signals polarity for PCI-7300A Rev. B*/
#define P7300_DOREQ_POS  0x00000000L
#define P7300_DOREQ_NEG  0x00000008L
#define P7300_DOACK_POS  0x00000000L
#define P7300_DOACK_NEG  0x00000010L
#define P7300_DOTRIG_POS 0x00000000L
#define P7300_DOTRIG_NEG 0x00000020L

/*DO Disable mode in DO_AsyncClear*/
#define P7300_DODisableDOEnabled    0
#define P7300_DONotDisableDOEnabled 1


/*----------------------------------------------*/
/* Constants for PCI-7432/7433/7434/7433C/7434C */
/*----------------------------------------------*/
#define PORT_DI_LOW    0
#define PORT_DI_HIGH   1
#define PORT_DO_LOW    0
#define PORT_DO_HIGH   1
#define P7432R_DO_LED  1
#define P7433R_DO_LED  0
#define P7434R_DO_LED  2
#define P7432R_DI_SLOT 1
#define P7433R_DI_SLOT 2
#define P7434R_DI_SLOT 0


/*----------------------------------------------------------------------------*/
/* Dual-Interrupt Source control for PCI-7248/96 & 7432/33 & 7230 & 8554 &    */
/* 7396 & 7256 & 7260 & 7442/43/44 & 7433C                                    */
/*----------------------------------------------------------------------------*/
#define INT1_NC		          -2
#define INT1_DISABLE          -1
#define INT1_COS              0
#define INT1_FP1C0            1
#define INT1_RP1C0_FP1C3      2
#define INT1_EVENT_COUNTER    3
#define INT1_EXT_SIGNAL       1
#define INT1_COUT12           1
#define INT1_CH0              1
#define INT1_COS0             1
#define INT1_COS1             2
#define INT1_COS2             4
#define INT1_COS3             8
#define INT2_NC		          -2
#define INT2_DISABLE          -1
#define INT2_COS              0
#define INT2_FP2C0            1
#define INT2_RP2C0_FP2C3      2
#define INT2_TIMER_COUNTER    3
#define INT2_EXT_SIGNAL       1
#define INT2_CH1              2
#define INT2_WDT              4
#define ManualResetIEvt       0x4000
#define WDT_OVRFLOW_SAFETYOUT 0x8000


/*------------------------*/
/* Constants for PCI-8554 */
/*------------------------*/
/*Clock Source of Cunter N*/
#define ECKN         0
#define COUTN_1      1
#define CK1          2
#define COUT10       3
/*Clock Source of CK1*/
#define CK1_C8M      0
#define CK1_COUT11   1
/*Debounce Clock*/
#define DBCLK_COUT11 0
#define DBCLK_2MHZ   1


/*------------------------*/
/* Constants for PCI-9111 */
/*------------------------*/
/*Dual Interrupt Mode*/
#define P9111_INT1_EOC     0
#define P9111_INT1_FIFO_HF 1
#define P9111_INT2_PACER   0
#define P9111_INT2_EXT_TRG 1
/*Channel Count*/
#define P9111_CHANNEL_DO   0
#define P9111_CHANNEL_EDO  1
#define P9111_CHANNEL_DI   0
#define P9111_CHANNEL_EDI  1
/*EDO function*/
#define P9111_EDO_INPUT    1
#define P9111_EDO_OUT_EDO  2
#define P9111_EDO_OUT_CHN  3
/*Trigger Mode*/
#define P9111_TRGMOD_SOFT  0x00
#define P9111_TRGMOD_PRE   0x01
#define P9111_TRGMOD_POST  0x02
/*AO Setting*/
#define P9111_AO_UNIPOLAR  0
#define P9111_AO_BIPOLAR   1


/*------------------------*/
/* Constants for PCI-9118 */
/*------------------------*/
#define P9118_AI_BiPolar      0x00
#define P9118_AI_UniPolar     0x01

#define P9118_AI_SingEnded    0x00
#define P9118_AI_Differential 0x02

#define P9118_AI_ExtG         0x04

#define P9118_AI_ExtTrig      0x08

#define P9118_AI_DtrgNegative 0x00
#define P9118_AI_DtrgPositive 0x10

#define P9118_AI_EtrgNegative 0x00
#define P9118_AI_EtrgPositive 0x20

#define P9118_AI_BurstModeEn  0x40
#define P9118_AI_SampleHold   0x80
#define P9118_AI_PostTrgEn    0x100
#define P9118_AI_AboutTrgEn   0x200


/*------------------------*/
/* Constants for PCI-9116 */
/*------------------------*/
#define P9116_AI_LocalGND      0x00
#define P9116_AI_UserCMMD      0x01
#define P9116_AI_SingEnded     0x00
#define P9116_AI_Differential  0x02
#define P9116_AI_BiPolar       0x00
#define P9116_AI_UniPolar      0x04

#define P9116_TRGMOD_SOFT      0x00
#define P9116_TRGMOD_POST      0x10
#define P9116_TRGMOD_DELAY     0x20
#define P9116_TRGMOD_PRE       0x30
#define P9116_TRGMOD_MIDL      0x40
#define P9116_AI_TrgPositive   0x00
#define P9116_AI_TrgNegative   0x80
#define P9116_AI_ExtTimeBase   0x100
#define P9116_AI_IntTimeBase   0x000
#define P9116_AI_DlyInSamples  0x200
#define P9116_AI_DlyInTimebase 0x000
#define P9116_AI_ReTrigEn      0x400
#define P9116_AI_MCounterEn    0x800
#define P9116_AI_SoftPolling   0x0000
#define P9116_AI_INT           0x1000
#define P9116_AI_DMA           0x2000

/* 20191205, added for pci-9116 calibration */

#define PCI9116_FLASH_USER_CALIBRATION_BLOCK    0x0000
#define PCI9116_FLASH_VENDOR_CALIBRATION_BLOCK  0x0100 /* bit-8 */

/* Unipolar: Gain x1, x2, x4 and x8 */
#define PCI9116_CALIBRATION_UNIPOLAR_10_V    0
#define PCI9116_CALIBRATION_UNIPOLAR_5_V     1
#define PCI9116_CALIBRATION_UNIPOLAR_2_5_V   2
#define PCI9116_CALIBRATION_UNIPOLAR_1_25_V  3
/* Bipolar: Gain x1, x2, x4 and x8 */
#define PCI9116_CALIBRATION_BIPOLAR_5_V      4
#define PCI9116_CALIBRATION_BIPOLAR_2_5_V    5
#define PCI9116_CALIBRATION_BIPOLAR_1_25_V   6
#define PCI9116_CALIBRATION_BIPOLAR_0_625_V  7

#define PCI9116_CALIBRATION_MODE_MAX         8
#define PCI9116_CALIBRATION_SETTING_MAX      16  /* for Gain x1, x2, x4 and x8 */

#define PCI9116_Cal_Op_Offset             0
#define PCI9116_Cal_Op_Gain               1

/*------------------------*/
/* Constants for PCI-9812 */
/*------------------------*/
/*Trigger Mode*/
#define P9812_TRGMOD_SOFT    0x00
#define P9812_TRGMOD_POST    0x01
#define P9812_TRGMOD_PRE     0x02
#define P9812_TRGMOD_DELAY   0x03
#define P9812_TRGMOD_MIDL    0x04

#define P9812_AIEvent_Manual 0x80

/*Trigger Source*/
#define P9812_TRGSRC_CH0     0x00
#define P9812_TRGSRC_CH1     0x08
#define P9812_TRGSRC_CH2     0x10
#define P9812_TRGSRC_CH3     0x18
#define P9812_TRGSRC_EXT_DIG 0x20

/*Trigger Polarity*/
#define P9812_TRGSLP_POS     0x00
#define P9812_TRGSLP_NEG     0x40

/*Frequency Selection*/
#define P9812_AD2_GT_PCI     0x80
#define P9812_AD2_LT_PCI     0x00

/*Clock Source*/
#define P9812_CLKSRC_INT     0x000
#define P9812_CLKSRC_EXT_SIN 0x100
#define P9812_CLKSRC_EXT_DIG 0x200


/*------------------------*/
/* Constants for PCI-9221 */
/*------------------------*/
/*Input Type*/
#define P9221_AI_SingEnded        0x0
#define P9221_AI_NonRef_SingEnded 0x1
#define P9221_AI_Differential     0x2

/*Trigger Mode*/
#define P9221_TRGMOD_SOFT         0x00
#define P9221_TRGMOD_ExtD         0x08
/*Trigger Source*/
#define P9221_TRGSRC_GPI0         0x00
#define P9221_TRGSRC_GPI1         0x01
#define P9221_TRGSRC_GPI2         0x02
#define P9221_TRGSRC_GPI3         0x03
#define P9221_TRGSRC_GPI4         0x04
#define P9221_TRGSRC_GPI5         0x05
#define P9221_TRGSRC_GPI6         0x06
#define P9221_TRGSRC_GPI7         0x07
/*Trigger Polarity*/
#define P9221_AI_TrgPositive      0x00
#define P9221_AI_TrgNegative      0x10

/*TimeBase Mode*/
#define P9221_AI_IntTimeBase      0x00
#define P9221_AI_ExtTimeBase      0x80
/*TimeBase Source*/
#define P9221_TimeBaseSRC_GPI0    0x00
#define P9221_TimeBaseSRC_GPI1    0x10
#define P9221_TimeBaseSRC_GPI2    0x20
#define P9221_TimeBaseSRC_GPI3    0x30
#define P9221_TimeBaseSRC_GPI4    0x40
#define P9221_TimeBaseSRC_GPI5    0x50
#define P9221_TimeBaseSRC_GPI6    0x60
#define P9221_TimeBaseSRC_GPI7    0x70

/*EEPROM*/
#define EEPROM_DEFAULT_BANK       0
#define EEPROM_USER_BANK1         1


/*---------------*/
/* Timer/Counter */
/*---------------*/
/*Counter Mode(8254)*/
#define TOGGLE_OUTPUT          0
#define PROG_ONE_SHOT          1
#define RATE_GENERATOR         2
#define SQ_WAVE_RATE_GENERATOR 3
#define SOFT_TRIG              4
#define HARD_TRIG              5

/*16-bit binary or 4-decade BCD counter*/
#define BIN 0
#define BCD 1


/*-------------------------------*/
/* General Purpose Timer/Counter */
/*-------------------------------*/
/*Counter Mode*/
#define General_Counter         0x00
#define Pulse_Generation        0x01
/*GPTC clock source*/
#define GPTC_CLKSRC_EXT         0x08
#define GPTC_CLKSRC_INT         0x00
#define GPTC_GATESRC_EXT        0x10
#define GPTC_GATESRC_INT        0x00
#define GPTC_UPDOWN_SELECT_EXT  0x20
#define GPTC_UPDOWN_SELECT_SOFT 0x00
#define GPTC_UP_CTR             0x40
#define GPTC_DOWN_CTR           0x00
#define GPTC_ENABLE             0x80
#define GPTC_DISABLE            0x00


/*-----------------------------------------------------------*/
/* General Purpose Timer/Counter for PCI-922x/6202/PCIe-91xx */
/*-----------------------------------------------------------*/
/*Counter Mode*/
#define SimpleGatedEventCNT       0x01
#define SinglePeriodMSR           0x02
#define SinglePulseWidthMSR       0x03
#define SingleGatedPulseGen       0x04
#define SingleTrigPulseGen        0x05
#define RetrigSinglePulseGen      0x06
#define SingleTrigContPulseGen    0x07
#define ContGatedPulseGen         0x08
#define EdgeSeparationMSR         0x09			// 91xx not support
#define SingleTrigContPulseGenPWM 0x0a
#define ContGatedPulseGenPWM      0x0b
#define CW_CCW_Encoder            0x0c			// 91xx multiplexer not support
#define x1_AB_Phase_Encoder       0x0d			// 91xx multiplexer not support
#define x2_AB_Phase_Encoder       0x0e			// 91xx multiplexer not support
#define x4_AB_Phase_Encoder       0x0f			// 91xx multiplexer not support
#define Phase_Z                   0x10			// 91xx multiplexer  not support

#define CW_CCW_Encoder_AI         0x10c			
#define x1_AB_Phase_Encoder_AI    0x10d			
#define x2_AB_Phase_Encoder_AI    0x10e			
#define x4_AB_Phase_Encoder_AI    0x10f			

#define OnFlyChange_PulseCounters 0x81	//2016/10/19
/*GPTC clock source*/
#define GPTC_CLK_SRC_Ext          0x01
#define GPTC_CLK_SRC_Int          0x00
#define GPTC_GATE_SRC_Ext         0x02
#define GPTC_GATE_SRC_Int         0x00
#define GPTC_UPDOWN_Ext           0x04			// 91xx not support
#define GPTC_UPDOWN_Int           0x00
/*GPTC clock polarity*/
#define GPTC_CLKSRC_LACTIVE       0x01
#define GPTC_CLKSRC_HACTIVE       0x00
#define GPTC_GATE_LACTIVE         0x02
#define GPTC_GATE_HACTIVE         0x00
#define GPTC_UPDOWN_LACTIVE       0x04
#define GPTC_UPDOWN_HACTIVE       0x00
#define GPTC_OUTPUT_LACTIVE       0x08
#define GPTC_OUTPUT_HACTIVE       0x00
/*GPTC OP Parameter*/
#define IntGate                   0x0
#define IntUpDnCTR                0x1
#define IntENABLE                 0x2
/*Z-Phase*/
#define GPTC_EZ0_ClearPhase0      0x0			// 91xx multiplexer not support
#define GPTC_EZ0_ClearPhase1      0x1			// 91xx multiplexer not support
#define GPTC_EZ0_ClearPhase2      0x2			// 91xx multiplexer not support
#define GPTC_EZ0_ClearPhase3      0x3			// 91xx multiplexer not support
/*Z-Mode*/
#define GPTC_EZ0_ClearMode0       0x0			// 91xx multiplexer not support
#define GPTC_EZ0_ClearMode1       0x1			// 91xx multiplexer not support
#define GPTC_EZ0_ClearMode2       0x2			// 91xx multiplexer not support
#define GPTC_EZ0_clearMode3       0x3			// 91xx multiplexer not support


/*----------------*/
/* Watchdog Timer */
/*----------------*/
/*Counter action*/
#define WDT_DISARM      0
#define WDT_ARM         1
#define WDT_RESTART     2
/*Pattern ID*/
#define INIT_PTN        0
#define EMGSHDN_PTN     1
/*Pattern ID for 7442/7444*/
#define INIT_PTN_CH0    0
#define INIT_PTN_CH1    1
#define INIT_PTN_CH2    2
#define INIT_PTN_CH3    3
#define SAFTOUT_PTN_CH0 4
#define SAFTOUT_PTN_CH1 5
#define SAFTOUT_PTN_CH2 6
#define SAFTOUT_PTN_CH3 7


/*----------------------------------------------------------*/
/* Previous renamed functions re-directed for compatibility */
/*----------------------------------------------------------*/
#define AI_VScale AI_VoltScale
#define AO_VScale AO_VoltScale
#define CTR_Reset CTR_Clear


/*--------------------------------------*/
/* DAQ Event type for the event message */
/*--------------------------------------*/
#define AIEnd     0
#define AOEnd     0
#define DIEnd     0
#define DOEnd     0
#define DBEvent   1
#define TrigEvent 2


/*------------------------*/
/* Constants for PCI-9524 */
/*------------------------*/
/*AI Interrupt*/
#define P9524_INT_LC_EOC            0x2 //06/10/08
#define P9524_INT_GP_EOC            0x3 //06/10/08
/*DSP Constants*/
#define P9524_SPIKE_REJ_DISABLE     0x0
#define P9524_SPIKE_REJ_ENABLE      0x1
/*Transfer Mode*/
#define P9524_AI_XFER_POLL          0x0
#define P9524_AI_XFER_DMA           0x1
/*Poll All Channels*/
#define P9524_AI_POLL_ALLCHANNELS   8
#define P9524_AI_POLLSCANS_CH0_CH3  8
#define P9524_AI_POLLSCANS_CH0_CH2  9
#define P9524_AI_POLLSCANS_CH0_CH1  10
/*ADC Sampling Rate*/
#define P9524_ADC_30K_SPS           0
#define P9524_ADC_15K_SPS           1
#define P9524_ADC_7K5_SPS           2
#define P9524_ADC_3K75_SPS          3
#define P9524_ADC_2K_SPS            4
#define P9524_ADC_1K_SPS            5
#define P9524_ADC_500_SPS           6
#define P9524_ADC_100_SPS           7
#define P9524_ADC_60_SPS            8
#define P9524_ADC_50_SPS            9
#define P9524_ADC_30_SPS            10
#define P9524_ADC_25_SPS            11
#define P9524_ADC_15_SPS            12
#define P9524_ADC_10_SPS            13
#define P9524_ADC_5_SPS             14
#define P9524_ADC_2R5_SPS           15
/*ConfigCtrl Constants*/
#define P9524_VEX_Range_2R5V        0x0
#define P9524_VEX_Range_10V         0x1
#define P9524_VEX_Sence_Local       0x0
#define P9524_VEX_Sence_Remote      0x2
#define P9524_AI_AZMode             0x4
#define P9524_AI_BufAutoReset       0x8
#define P9524_AI_EnEOCInt           0x10 //06/10/08
#define P9524_AI_HiSpeed            0x20 //09/29/16
/*Trigger Constants*/
#define P9524_TRGMOD_POST           0x00
#define P9524_TRGSRC_SOFT           0x00
#define P9524_TRGSRC_ExtD           0x01
#define P9524_TRGSRC_SSI            0x02
#define P9524_TRGSRC_QD0            0x03
#define P9524_TRGSRC_PG0            0x04
#define P9524_AI_TrgPositive        0x00
#define P9524_AI_TrgNegative        0x08
/*Group*/
#define P9524_AI_LC_Group           0
#define P9524_AI_GP_Group           1
/*Channel*/
#define P9524_AI_LC_CH0             0
#define P9524_AI_LC_CH1             1
#define P9524_AI_LC_CH2             2
#define P9524_AI_LC_CH3             3
#define P9524_AI_GP_CH0             4
#define P9524_AI_GP_CH1             5
#define P9524_AI_GP_CH2             6
#define P9524_AI_GP_CH3             7
/*Pulse Generation and Quadrature Decoder*/
#define P9524_CTR_PG0               0
#define P9524_CTR_PG1               1
#define P9524_CTR_PG2               2
#define P9524_CTR_QD0               3
#define P9524_CTR_QD1               4
#define P9524_CTR_QD2               5
#define P9524_CTR_INTCOUNTER        6
/*Counter Mode*/
#define P9524_PulseGen_OUTDIR_N     0
#define P9524_PulseGen_OUTDIR_R     1
#define P9524_PulseGen_CW           0
#define P9524_PulseGen_CCW          2
#define P9524_x4_AB_Phase_Decoder   3
#define P9524_Timer                 4
/* AI Monitor Config*/
#define P9524_Monitor_AboveHigh		0
#define P9524_Monitor_BelowLow		1
#define P9524_Monitor_Rising		2
#define P9524_Monitor_Falling		3

/*Counter Op*/
#define P9524_CTR_Enable            0
/*Event Mode*/
#define P9524_Event_Timer           0
/*AO*/
#define P9524_AO_CH0_1              0

/*------------------------*/
/* Constants for PCI-6202 */
/*------------------------*/
/*DIO channel*/
#define P6202_ISO0                0
#define P6202_TTL0                1
/*GPTC/Encoder channel*/
#define P6202_GPTC0               0x00
#define P6202_GPTC1               0x01
#define P6202_ENCODER0            0x02
#define P6202_ENCODER1            0x03
#define P6202_ENCODER2            0x04
/*DA control constant*/
#define P6202_DA_WRSRC_Int        0x00
#define P6202_DA_WRSRC_AFI0       0x01
#define P6202_DA_WRSRC_SSI        0x02
#define P6202_DA_WRSRC_AFI1       0x03
/*DA trigger constant*/
#define P6202_DA_TRGSRC_SOFT      0x00
#define P6202_DA_TRGSRC_AFI0      0x01
#define P6202_DA_TRGSRC_SSI       0x02
#define P6202_DA_TRGSRC_AFI1      0x03
#define P6202_DA_TRGMOD_POST      0x00
#define P6202_DA_TRGMOD_DELAY     0x04
#define P6202_DA_ReTrigEn         0x20
#define P6202_DA_DLY2En           0x100
/*SSI signal code*/
#define P6202_SSI_DA_CONV         0x04
#define P6202_SSI_DA_TRIG         0x40
/*Encoder constant*/
#define P6202_EVT_TYPE_EPT0       0x00
#define P6202_EVT_TYPE_EPT1       0x01
#define P6202_EVT_TYPE_EPT2       0x02
#define P6202_EVT_TYPE_EZC0       0x03
#define P6202_EVT_TYPE_EZC1       0x04
#define P6202_EVT_TYPE_EZC2       0x05

#define P6202_EVT_MOD_EPT         0x00

#define P6202_EPT_PULWIDTH_200us  0x00
#define P6202_EPT_PULWIDTH_2ms    0x01
#define P6202_EPT_PULWIDTH_20ms   0x02
#define P6202_EPT_PULWIDTH_200ms  0x03

#define P6202_EPT_TRGOUT_CALLBACK 0x04
#define P6202_EPT_TRGOUT_AFI      0x08

#define P6202_ENCODER0_LDATA      0x05
#define P6202_ENCODER1_LDATA      0x06
#define P6202_ENCODER2_LDATA      0x07

/*AFI Port*/
#define P6202_AFI_0				0
#define P6202_AFI_1				1

/*AFI Mode*/
#define P6202_AFI_SYNCIntTrigOut	0

/*AFI Trigout Length*/
#define P6202_AFI_SYNCTrig_200ns	0
#define P6202_AFI_SYNCTrig_2ms		1
#define P6202_AFI_SYNCTrig_20ms		2
#define P6202_AFI_SYNCTrig_200ms	3

/*-------------------------*/
/* Constants for PCIe-91xx */
/*-------------------------*/

/*
 * AI Constants
 */
/*Sampling Mode*/
#define MODE_MULT   0
#define MODE_SIMU   1

/*Input Type*/
#define P91xx_AI_SingEnded          0x00
#define P91xx_AI_Differential       0x80
#define P91xx_CH0					0x0
#define P91xx_CH1					0x1
#define P91xx_CH2					0x2
#define P91xx_CH3					0x3
#define P91xx_CH4					0x4
#define P91xx_CH5					0x5
#define P91xx_CH6					0x6
#define P91xx_CH7					0x7
#define P91xx_CH8					0x8
#define P91xx_CH9					0x9
#define P91xx_CH10					0xa
#define P91xx_CH11					0xb
#define P91xx_CH12					0xc
#define P91xx_CH13					0xd
#define P91xx_CH14					0xe
#define P91xx_CH15					0xf
/*For 9103, 9161*/
#define P91xx_CH16					0x10
#define P91xx_CH17					0x11
#define P91xx_CH18					0x12
#define P91xx_CH19					0x13
#define P91xx_CH20					0x14
#define P91xx_CH21					0x15
#define P91xx_CH22					0x16
#define P91xx_CH23					0x17
#define P91xx_CH24					0x18
#define P91xx_CH25					0x19
#define P91xx_CH26					0x1a
#define P91xx_CH27					0x1b
#define P91xx_CH28					0x1c
#define P91xx_CH29					0x1d
#define P91xx_CH30					0x1e
#define P91xx_CH31					0x1f
/*For 9163*/
#define P91xx_CH32					0x20
#define P91xx_CH33					0x21
#define P91xx_CH34					0x22
#define P91xx_CH35					0x23
#define P91xx_CH36					0x24
#define P91xx_CH37					0x25
#define P91xx_CH38					0x26
#define P91xx_CH39					0x27
#define P91xx_CH40					0x28
#define P91xx_CH41					0x29
#define P91xx_CH42					0x2a
#define P91xx_CH43					0x2b
#define P91xx_CH44					0x2c
#define P91xx_CH45					0x2d
#define P91xx_CH46					0x2e
#define P91xx_CH47					0x2f
/*For 9164*/
#define P91xx_CH48					0x30
#define P91xx_CH49					0x31
#define P91xx_CH50					0x32
#define P91xx_CH51					0x33
#define P91xx_CH52					0x34
#define P91xx_CH53					0x35
#define P91xx_CH54					0x36
#define P91xx_CH55					0x37
#define P91xx_CH56					0x38
#define P91xx_CH57					0x39
#define P91xx_CH58					0x3a
#define P91xx_CH59					0x3b
#define P91xx_CH60					0x3c
#define P91xx_CH61					0x3d
#define P91xx_CH62					0x3e
#define P91xx_CH63					0x3f

/*Timbase and conversion settings for AI*/
#define P91xx_AI_TIMEBASE_INT       0x00
#define P91xx_AI_TIMEBASE_EXT       0x10
#define P91xx_AI_CONVSRC_EXT        0x20 
/*Trigger Mode*/
#define P91xx_AI_TRGMOD_POST        0x00
#define P91xx_AI_TRGMOD_DELAY       0x02
#define P91xx_AI_TRGMOD_PRE         0x04
#define P91xx_AI_TRGMOD_MID         0x05              
/*Trigger Source*/
#define P91xx_AI_TRGSRC_SOFT        0x00
#define P91xx_AI_TRGSRC_EXTD        0x10
#define P91xx_AI_TRGSRC_AI          0x20
/*Trigger Polarity*/
#define P91xx_AI_TrgPositive        0x000
#define P91xx_AI_TrgNegative        0x100
/*Delay Trigger with Samples*/
#define P91xx_AI_DlyInTimebase      0x000
#define P91xx_AI_DlyInSamples       0x200
/*Analog Trigger condition constants*/
#define P91xx_Below_Low_level       0x00
#define P91xx_Above_High_Level      0x10
#define P91xx_Inside_Region         0x20
#define P91xx_High_Hysteresis       0x30
#define P91xx_Low_Hysteresis        0x40
/*Analog Trigger Source Channel*/
//* For SingleEnded*//
#define CH0ATRIG	0x0000
#define CH1ATRIG	0x0100
#define CH2ATRIG	0x0200
#define CH3ATRIG	0x0300
#define CH4ATRIG	0x0400
#define CH5ATRIG	0x0500
#define CH6ATRIG	0x0600
#define CH7ATRIG	0x0700
#define CH8ATRIG	0x0800
#define CH9ATRIG	0x0900
#define CH10ATRIG	0x0A00
#define CH11ATRIG	0x0B00
#define CH12ATRIG	0x0C00
#define CH13ATRIG	0x0D00
#define CH14ATRIG	0x0E00
#define CH15ATRIG	0x0F00
#define CH16ATRIG	0x1000
#define CH17ATRIG	0x1100
#define CH18ATRIG	0x1200
#define CH19ATRIG	0x1300
#define CH20ATRIG	0x1400
#define CH21ATRIG	0x1500
#define CH22ATRIG	0x1600
#define CH23ATRIG	0x1700
#define CH24ATRIG	0x1800
#define CH25ATRIG	0x1900
#define CH26ATRIG	0x1A00
#define CH27ATRIG	0x1B00
#define CH28ATRIG	0x1C00
#define CH29ATRIG	0x1D00
#define CH30ATRIG	0x1E00
#define CH31ATRIG	0x1F00
#define CH32ATRIG	0x2000
#define CH33ATRIG	0x2100
#define CH34ATRIG	0x2200
#define CH35ATRIG	0x2300
#define CH36ATRIG	0x2400
#define CH37ATRIG	0x2500
#define CH38ATRIG	0x2600
#define CH39ATRIG	0x2700
#define CH40ATRIG	0x2800
#define CH41ATRIG	0x2900
#define CH42ATRIG	0x2A00
#define CH43ATRIG	0x2B00
#define CH44ATRIG	0x2C00
#define CH45ATRIG	0x2D00
#define CH46ATRIG	0x2E00
#define CH47ATRIG	0x2F00
#define CH48ATRIG	0x3000
#define CH49ATRIG	0x3100
#define CH50ATRIG	0x3200
#define CH51ATRIG	0x3300
#define CH52ATRIG	0x3400
#define CH53ATRIG	0x3500
#define CH54ATRIG	0x3600
#define CH55ATRIG	0x3700
#define CH56ATRIG	0x3800
#define CH57ATRIG	0x3900
#define CH58ATRIG	0x3A00
#define CH59ATRIG	0x3B00
#define CH60ATRIG	0x3C00
#define CH61ATRIG	0x3D00
#define CH62ATRIG	0x3E00
#define CH63ATRIG	0x3F00
//* For Differential*//
#define CH0ATRIG_DIFF	0x8000
#define CH1ATRIG_DIFF	0x8100
#define CH2ATRIG_DIFF	0x8200
#define CH3ATRIG_DIFF	0x8300
#define CH4ATRIG_DIFF	0x8400
#define CH5ATRIG_DIFF	0x8500
#define CH6ATRIG_DIFF	0x8600
#define CH7ATRIG_DIFF	0x8700
#define CH8ATRIG_DIFF	0x8800
#define CH9ATRIG_DIFF	0x8900
#define CH10ATRIG_DIFF	0x8A00
#define CH11ATRIG_DIFF	0x8B00
#define CH12ATRIG_DIFF	0x8C00
#define CH13ATRIG_DIFF	0x8D00
#define CH14ATRIG_DIFF	0x8E00
#define CH15ATRIG_DIFF	0x8F00
#define CH16ATRIG_DIFF	0x9000
#define CH17ATRIG_DIFF	0x9100
#define CH18ATRIG_DIFF	0x9200
#define CH19ATRIG_DIFF	0x9300
#define CH20ATRIG_DIFF	0x9400
#define CH21ATRIG_DIFF	0x9500
#define CH22ATRIG_DIFF	0x9600
#define CH23ATRIG_DIFF	0x9700
#define CH24ATRIG_DIFF	0x9800
#define CH25ATRIG_DIFF	0x9900
#define CH26ATRIG_DIFF	0x9A00
#define CH27ATRIG_DIFF	0x9B00
#define CH28ATRIG_DIFF	0x9C00
#define CH29ATRIG_DIFF	0x9D00
#define CH30ATRIG_DIFF	0x9E00
#define CH31ATRIG_DIFF	0x9F00
/*
 * AO Constants
 */
/*Timbase for AO*/
#define P91xx_AO_TIMEBASE_INT       0x00
#define P91xx_AO_TIMEBASE_EXT       0x01
/*Trigger Mode*/
#define P91xx_AO_TRGMOD_POST        0x00
/*Trigger Source*/
#define P91xx_AO_TRGSRC_SOFT        0x00
#define P91xx_AO_TRGSRC_EXTD        0x10
/*Trigger Polarity*/
#define P91xx_AO_TrgPositive        0x000
#define P91xx_AO_TrgNegative        0x100

/*
 * DI Constants
 */
/*Timbase and conversion settings for DI*/
#define P91xx_DI_TIMEBASE_INT       0x00
#define P91xx_DI_TIMEBASE_EXT       0x01
#define P91xx_DI_CONVSRC_SYNC_IN    0x02
/*Trigger Mode*/
#define P91xx_DI_TRGMOD_POST        0x00
/*Trigger Source*/
#define P91xx_DI_TRGSRC_SOFT        0x00
#define P91xx_DI_TRGSRC_EXTD        0x10
/*Trigger Polarity*/
#define P91xx_DI_TrgPositive        0x000
#define P91xx_DI_TrgNegative        0x100

/*
 * DO Constants
 */
/*Timbase for DO*/
#define P91xx_DO_TIMEBASE_INT       0x00
#define P91xx_DO_TIMEBASE_EXT       0x01
/*Trigger Mode*/
#define P91xx_DO_TRGMOD_POST        0x00
/*Trigger Source*/
#define P91xx_DO_TRGSRC_SOFT        0x00
#define P91xx_DO_TRGSRC_EXTD        0x10
/*Trigger Polarity*/
#define P91xx_DO_TrgPositive        0x000
#define P91xx_DO_TrgNegative        0x100

#define P91xx_INFINITE_RETRIG       0x0

/*
 * Encoder/GPTC Constants
 */
#define P91xx_GPTC0                 0x00
#define P91xx_GPTC1                 0x01
#define P91xx_GPTC2                 0x02
#define P91xx_GPTC3                 0x03
#define P91xx_ENCODER0              0x04
#define P91xx_ENCODER1              0x05
#define P91xx_ENCODER_PM            0x06 // For Encoder Pattern Match

 /*AI DMA with Encoder Feature*/
#define AI_DMA_ENCODER_MODE         0x10

/*Encoder Setting Event Mode*/
#define P91xx_EVT_MOD_EPT           0x00
/*Encoder Setting Event Control*/
#define P91xx_EPT_PULWIDTH_200ns    0x00
#define P91xx_EPT_PULWIDTH_2ms      0x01
#define P91xx_EPT_PULWIDTH_20ms     0x02
#define P91xx_EPT_PULWIDTH_200ms    0x03
#define P91xx_EPT_TRGOUT_GPO        0x04
#define P91xx_EPT_TRGOUT_CALLBACK   0x08
/*Event Type*/
#define P91xx_EVT_TYPE_EPT0         0x00
#define P91xx_EVT_TYPE_EPT1         0x01

/*------------------------*/
/* Constants for PCI-922x */
/*------------------------*/
/*
 * AI Constants
 */
/*Input Type*/
#define P922x_AI_SingEnded          0x00
#define P922x_AI_NonRef_SingEnded   0x01
#define P922x_AI_Differential       0x02
/*Conversion Source*/
#define P922x_AI_CONVSRC_INT        0x00
#define P922x_AI_CONVSRC_GPI0       0x10
#define P922x_AI_CONVSRC_GPI1       0x20
#define P922x_AI_CONVSRC_GPI2       0x30
#define P922x_AI_CONVSRC_GPI3       0x40
#define P922x_AI_CONVSRC_GPI4       0x50
#define P922x_AI_CONVSRC_GPI5       0x60
#define P922x_AI_CONVSRC_GPI6       0x70
#define P922x_AI_CONVSRC_GPI7       0x80
#define P922x_AI_CONVSRC_SSI1       0x90
#define P922x_AI_CONVSRC_SSI        0x90
/*Trigger Mode*/
#define P922x_AI_TRGMOD_POST        0x00
#define P922x_AI_TRGMOD_GATED       0x01
/*Trigger Source*/
#define P922x_AI_TRGSRC_SOFT        0x00
#define P922x_AI_TRGSRC_GPI0        0x10
#define P922x_AI_TRGSRC_GPI1        0x20
#define P922x_AI_TRGSRC_GPI2        0x30
#define P922x_AI_TRGSRC_GPI3        0x40
#define P922x_AI_TRGSRC_GPI4        0x50
#define P922x_AI_TRGSRC_GPI5        0x60
#define P922x_AI_TRGSRC_GPI6        0x70
#define P922x_AI_TRGSRC_GPI7        0x80
#define P922x_AI_TRGSRC_SSI5        0x90
#define P922x_AI_TRGSRC_SSI         0x90
/*Trigger Polarity*/
#define P922x_AI_TrgPositive        0x000
#define P922x_AI_TrgNegative        0x100
/*ReTrigger*/
#define P922x_AI_EnReTigger         0x200

/*
 * AO Constants
 */
/*Conversion Source*/
#define P922x_AO_CONVSRC_INT        0x00
#define P922x_AO_CONVSRC_GPI0       0x01
#define P922x_AO_CONVSRC_GPI1       0x02
#define P922x_AO_CONVSRC_GPI2       0x03
#define P922x_AO_CONVSRC_GPI3       0x04
#define P922x_AO_CONVSRC_GPI4       0x05
#define P922x_AO_CONVSRC_GPI5       0x06
#define P922x_AO_CONVSRC_GPI6       0x07
#define P922x_AO_CONVSRC_GPI7       0x08
#define P922x_AO_CONVSRC_SSI2       0x09
#define P922x_AO_CONVSRC_SSI        0x09
/*Trigger Mode*/
#define P922x_AO_TRGMOD_POST        0x00
#define P922x_AO_TRGMOD_DELAY       0x01
/*Trigger Source*/
#define P922x_AO_TRGSRC_SOFT        0x00
#define P922x_AO_TRGSRC_GPI0        0x10
#define P922x_AO_TRGSRC_GPI1        0x20
#define P922x_AO_TRGSRC_GPI2        0x30
#define P922x_AO_TRGSRC_GPI3        0x40
#define P922x_AO_TRGSRC_GPI4        0x50
#define P922x_AO_TRGSRC_GPI5        0x60
#define P922x_AO_TRGSRC_GPI6        0x70
#define P922x_AO_TRGSRC_GPI7        0x80
#define P922x_AO_TRGSRC_SSI6        0x90
#define P922x_AO_TRGSRC_SSI         0x90
/*Trigger Polarity*/
#define P922x_AO_TrgPositive        0x000
#define P922x_AO_TrgNegative        0x100
#define P922x_AO_EnReTigger         0x200
#define P922x_AO_EnDelay2           0x400

/*
 * DI Constants
 */
/*Conversion Source*/
#define P922x_DI_CONVSRC_INT        0x00
#define P922x_DI_CONVSRC_GPI0       0x01
#define P922x_DI_CONVSRC_GPI1       0x02
#define P922x_DI_CONVSRC_GPI2       0x03
#define P922x_DI_CONVSRC_GPI3       0x04
#define P922x_DI_CONVSRC_GPI4       0x05
#define P922x_DI_CONVSRC_GPI5       0x06
#define P922x_DI_CONVSRC_GPI6       0x07
#define P922x_DI_CONVSRC_GPI7       0x08
#define P922x_DI_CONVSRC_ADCONV     0x09
#define P922x_DI_CONVSRC_DACONV     0x0A
/*Trigger Mode*/
#define P922x_DI_TRGMOD_POST        0x00
/*Trigger Source*/
#define P922x_DI_TRGSRC_SOFT        0x00
#define P922x_DI_TRGSRC_GPI0        0x10
#define P922x_DI_TRGSRC_GPI1        0x20
#define P922x_DI_TRGSRC_GPI2        0x30
#define P922x_DI_TRGSRC_GPI3        0x40
#define P922x_DI_TRGSRC_GPI4        0x50
#define P922x_DI_TRGSRC_GPI5        0x60
#define P922x_DI_TRGSRC_GPI6        0x70
#define P922x_DI_TRGSRC_GPI7        0x80
/*Trigger Polarity*/
#define P922x_DI_TrgPositive        0x000
#define P922x_DI_TrgNegative        0x100
/*ReTrigger*/
#define P922x_DI_EnReTigger         0x200

/*
 * DO Constants
 */
/*Conversion Source*/
#define P922x_DO_CONVSRC_INT        0x00
#define P922x_DO_CONVSRC_GPI0       0x01
#define P922x_DO_CONVSRC_GPI1       0x02
#define P922x_DO_CONVSRC_GPI2       0x03
#define P922x_DO_CONVSRC_GPI3       0x04
#define P922x_DO_CONVSRC_GPI4       0x05
#define P922x_DO_CONVSRC_GPI5       0x06
#define P922x_DO_CONVSRC_GPI6       0x07
#define P922x_DO_CONVSRC_GPI7       0x08
#define P922x_DO_CONVSRC_ADCONV     0x09
#define P922x_DO_CONVSRC_DACONV     0x0A
/*Trigger Mode*/
#define P922x_DO_TRGMOD_POST        0x00
#define P922x_DO_TRGMOD_DELAY       0x01
/*Trigger Source*/
#define P922x_DO_TRGSRC_SOFT        0x00
#define P922x_DO_TRGSRC_GPI0        0x10
#define P922x_DO_TRGSRC_GPI1        0x20
#define P922x_DO_TRGSRC_GPI2        0x30
#define P922x_DO_TRGSRC_GPI3        0x40
#define P922x_DO_TRGSRC_GPI4        0x50
#define P922x_DO_TRGSRC_GPI5        0x60
#define P922x_DO_TRGSRC_GPI6        0x70
#define P922x_DO_TRGSRC_GPI7        0x80
/*Trigger Polarity*/
#define P922x_DO_TrgPositive        0x000
#define P922x_DO_TrgNegative        0x100
#define P922x_DO_EnReTigger         0x200

/*
 * Encoder/GPTC Constants
 */
#define P922x_GPTC0                 0x00
#define P922x_GPTC1                 0x01
#define P922x_GPTC2                 0x02
#define P922x_GPTC3                 0x03
#define P922x_ENCODER0              0x04
#define P922x_ENCODER1              0x05
/*Encoder Setting Event Mode*/
#define P922x_EVT_MOD_EPT           0x00
/*Encoder Setting Event Control*/
#define P922x_EPT_PULWIDTH_200us    0x00
#define P922x_EPT_PULWIDTH_2ms      0x01
#define P922x_EPT_PULWIDTH_20ms     0x02
#define P922x_EPT_PULWIDTH_200ms    0x03
#define P922x_EPT_TRGOUT_GPO        0x04
#define P922x_EPT_TRGOUT_CALLBACK   0x08
/*Event Type*/
#define P922x_EVT_TYPE_EPT0         0x00
#define P922x_EVT_TYPE_EPT1         0x01

/*
 * SSI signal code
 */
#define P922x_SSI_AI_CONV           0x02
#define P922x_SSI_AI_TRIG           0x20
#define P922x_SSI_AO_CONV           0x04
#define P922x_SSI_AO_TRIG           0x40


/*-------------------------*/
/* Constants for PCIe-7350 */
/*-------------------------*/
#define P7350_PortDIO         0
#define P7350_PortAFI         1
/*DIO Port*/
#define P7350_DIO_A           0
#define P7350_DIO_B           1
#define P7350_DIO_C           2
#define P7350_DIO_D           3
/*AFI Port*/
#define P7350_AFI_0           0
#define P7350_AFI_1           1
#define P7350_AFI_2           2
#define P7350_AFI_3           3
#define P7350_AFI_4           4
#define P7350_AFI_5           5
#define P7350_AFI_6           6
#define P7350_AFI_7           7
/*AFI Mode*/
#define P7350_AFI_DIStartTrig 0
#define P7350_AFI_DOStartTrig 1
#define P7350_AFI_DIPauseTrig 2
#define P7350_AFI_DOPauseTrig 3
#define P7350_AFI_DISWTrigOut 4
#define P7350_AFI_DOSWTrigOut 5
#define P7350_AFI_COSTrigOut  6
#define P7350_AFI_PMTrigOut   7
#define P7350_AFI_HSDIREQ     8
#define P7350_AFI_HSDIACK     9
#define P7350_AFI_HSDITRIG    10
#define P7350_AFI_HSDOREQ     11
#define P7350_AFI_HSDOACK     12
#define P7350_AFI_HSDOTRIG    13
#define P7350_AFI_SPI         14
#define P7350_AFI_I2C         15
#define P7350_POLL_DI         16
#define P7350_POLL_DO         17
/*Operation Mode*/
#define P7350_FreeRun         0
#define P7350_HandShake       1
#define P7350_BurstHandShake  2
/*Trigger Status*/
#define P7350_WAIT_NO         0
#define P7350_WAIT_EXTTRG     1
#define P7350_WAIT_SOFTTRG    2
/*Sampled Clock*/
#define P7350_IntSampledCLK   0x00
#define P7350_ExtSampledCLK   0x01
/*Sampled Clock Edge*/
#define P7350_SampledCLK_R    0x00
#define P7350_SampledCLK_F    0x02
/*Enable Export Sample Clock*/
#define P7350_EnExpSampledCLK 0x04
/*Trigger Configuration*/
#define P7350_EnPauseTrig     0x01
#define P7350_EnSoftTrigOut   0x02
/*HandShake & Trigger Polarity*/
#define P7350_DIREQ_POS       0x00
#define P7350_DIREQ_NEG       0x01
#define P7350_DIACK_POS       0x00
#define P7350_DIACK_NEG       0x02
#define P7350_DITRIG_POS      0x00
#define P7350_DITRIG_NEG      0x04
#define P7350_DIStartTrig_POS 0x00
#define P7350_DIStartTrig_NEG 0x08
#define P7350_DIPauseTrig_POS 0x00
#define P7350_DIPauseTrig_NEG 0x10
#define P7350_DOREQ_POS       0x00
#define P7350_DOREQ_NEG       0x01
#define P7350_DOACK_POS       0x00
#define P7350_DOACK_NEG       0x02
#define P7350_DOTRIG_POS      0x00
#define P7350_DOTRIG_NEG      0x04
#define P7350_DOStartTrig_POS 0x00
#define P7350_DOStartTrig_NEG 0x08
#define P7350_DOPauseTrig_POS 0x00
#define P7350_DOPauseTrig_NEG 0x10
/*External Sampled Clock Source*/
#define P7350_ECLK_IN         8
/*Export Sampled Clock*/
#define P7350_ECLK_OUT        8
/*Enable Dynamic Delay Adjust*/
#define P7350_DisDDA          0x0
#define P7350_EnDDA           0x1
/*Dynamic Delay Adjust Mode*/
#define P7350_DDA_Lag         0x0
#define P7350_DDA_Lead        0x2
/*Dynamic Delay Adjust Step*/
#define P7350_DDA_130PS       0
#define P7350_DDA_260PS       1
#define P7350_DDA_390PS       2
#define P7350_DDA_520PS       3
#define P7350_DDA_650PS       4
#define P7350_DDA_780PS       5
#define P7350_DDA_910PS       6
#define P7350_DDA_1R04NS      7
/*Enable Dynamic Phase Adjust*/
#define P7350_DisDPA          0x0
#define P7350_EnDPA           0x1
/*Dynamic Delay Adjust Degree*/
#define P7350_DPA_0DG         0
#define P7350_DPA_22R5DG      1
#define P7350_DPA_45DG        2
#define P7350_DPA_67R5DG      3
#define P7350_DPA_90DG        4
#define P7350_DPA_112R5DG     5
#define P7350_DPA_135DG       6
#define P7350_DPA_157R5DG     7
#define P7350_DPA_180DG       8
#define P7350_DPA_202R5DG     9
#define P7350_DPA_225DG       10
#define P7350_DPA_247R5DG     11
#define P7350_DPA_270DG       12
#define P7350_DPA_292R5DG     13
#define P7350_DPA_315DG       14
#define P7350_DPA_337R5DG     15

/*-------------------------*/
/* Constants for PCIe-7360 */
/*-------------------------*/
#define P7360_PortDIO         0
#define P7360_PortAFI         1
#define P7360_PortECLK		  2
/*DIO Port*/
#define P7360_DIO_A           0
#define P7360_DIO_B           1
#define P7360_DIO_C           2
#define P7360_DIO_D           3
/*AFI Port*/
#define P7360_AFI_0           0
#define P7360_AFI_1           1
#define P7360_AFI_2           2
#define P7360_AFI_3           3
#define P7360_AFI_4           4
#define P7360_AFI_5           5
#define P7360_AFI_6           6
#define P7360_AFI_7           7
/*AFI Mode*/
#define P7360_AFI_DIStartTrig 0
#define P7360_AFI_DOStartTrig 1
#define P7360_AFI_DIPauseTrig 2
#define P7360_AFI_DOPauseTrig 3
#define P7360_AFI_DISWTrigOut 4
#define P7360_AFI_DOSWTrigOut 5
#define P7360_AFI_COSTrigOut  6
#define P7360_AFI_PMTrigOut   7
#define P7360_AFI_HSDIREQ     8
#define P7360_AFI_HSDIACK     9
#define P7360_AFI_HSDITRIG    10
#define P7360_AFI_HSDOREQ     11
#define P7360_AFI_HSDOACK     12
#define P7360_AFI_HSDOTRIG    13
#define P7360_AFI_SPI         14
#define P7360_AFI_I2C         15
#define P7360_POLL_DI         16
#define P7360_POLL_DO         17
/*Operation Mode*/
#define P7360_FreeRun         0
#define P7360_HandShake       1
#define P7360_BurstHandShake  2
#define P7360_BurstHandShake2 3
/*Trigger Status*/
#define P7360_WAIT_NO         0
#define P7360_WAIT_EXTTRG     1
#define P7360_WAIT_SOFTTRG    2
#define P7360_WAIT_PATMATCH	  3
/*Sampled Clock*/
#define P7360_IntSampledCLK   0x00
#define P7360_ExtSampledCLK   0x01
/*Sampled Clock Edge*/
#define P7360_SampledCLK_R    0x00
#define P7360_SampledCLK_F    0x02
/*Enable Export Sample Clock*/
#define P7360_EnExpSampledCLK 0x04
/*Trigger Configuration*/
#define P7360_EnPauseTrig     0x01
#define P7360_EnSoftTrigOut   0x02
/*HandShake & Trigger Polarity*/
#define P7360_DIREQ_POS       0x00
#define P7360_DIREQ_NEG       0x01
#define P7360_DIACK_POS       0x00
#define P7360_DIACK_NEG       0x02
#define P7360_DITRIG_POS      0x00
#define P7360_DITRIG_NEG      0x04
#define P7360_DIStartTrig_POS 0x00
#define P7360_DIStartTrig_NEG 0x08
#define P7360_DIPauseTrig_POS 0x00
#define P7360_DIPauseTrig_NEG 0x10
#define P7360_DOREQ_POS       0x00
#define P7360_DOREQ_NEG       0x01
#define P7360_DOACK_POS       0x00
#define P7360_DOACK_NEG       0x02
#define P7360_DOTRIG_POS      0x00
#define P7360_DOTRIG_NEG      0x04
#define P7360_DOStartTrig_POS 0x00
#define P7360_DOStartTrig_NEG 0x08
#define P7360_DOPauseTrig_POS 0x00
#define P7360_DOPauseTrig_NEG 0x10
/*External Sampled Clock Source*/
#define P7360_ECLK_IN         8
/*Export Sampled Clock*/
#define P7360_ECLK_OUT        8
/*Enable Dynamic Delay Adjust*/
#define P7360_DisDDA          0x0
#define P7360_EnDDA           0x1
/*Dynamic Delay Adjust Mode*/
#define P7360_DDA_Lag         0x0
#define P7360_DDA_Lead        0x2
/*Enable Dynamic Phase Adjust*/
#define P7360_DisDPA          0x0
#define P7360_EnDPA           0x1
/*ECLK output type control*/
#define P7360_ECLKAligned	  0x0
#define P7360_ECLKAlwaysOn	  0x1

/*---------------------------------*/
/* Constants for I Squared C (I2C) */
/*---------------------------------*/
/*I2C Port*/
#define I2C_Port_A 0
/*I2C Control Operation*/
#define I2C_ENABLE 0
#define I2C_STOP   1


/*-------------------------------------------*/
/* Constants for Serial Peripheral Interface */
/*-------------------------------------------*/
/*SPI Port*/
#define SPI_Port_A 0

/* For PCIe-7350 Honpre SPI Model (Port_0~ Port_7 */
#define SPI_Port_0 1
#define SPI_Port_1 2
#define SPI_Port_2 3
#define SPI_Port_3 4
#define SPI_Port_4 5
#define SPI_Port_5 6
#define SPI_Port_6 7
#define SPI_Port_7 8
#define SPI_Port_B 9 // Derived from AFI 4~7 pin
/*-------------------------------------------*/

/*SPI Clock Mode*/
#define SPI_CLK_L  0x00
#define SPI_CLK_H  0x01
/*SPI TX Polarity*/
#define SPI_TX_POS 0x00
#define SPI_TX_NEG 0x02
/*SPI RX Polarity*/
#define SPI_RX_POS 0x00
#define SPI_RX_NEG 0x04
/*SPI Transferred Order*/
#define SPI_MSB    0x00
#define SPI_LSB    0x08
/*SPI Control Operation*/
#define SPI_ENABLE 0

/*-------------------------------------------------------------------*/
/* Constants for PARALLEL Interface (For 7350 Honprec PARALLEL Model)*/
/*-------------------------------------------------------------------*/
/*PARALLEL Port*/
#define PARALLEL_Port_0 0 // Port 0 Indepenent
#define PARALLEL_Port_1 1 // Port 1 Indepenent
#define PARALLEL_Port_2 2 // Port 2 Indepenent
#define PARALLEL_Port_3 3 // Port 3 Indepenent
#define PARALLEL_Port_4 4 // Port 4 Sync to Port 1 CLOCK and I/O DIR
#define PARALLEL_Port_5 5 // Port 5 Sync to Port 2 CLOCK and I/O DIR
#define PARALLEL_Port_6 6 // Port 6 Sync to Port 3 CLOCK and I/O DIR
#define PARALLEL_Port_7 7 // Port 7 Sync to Port 4 CLOCK and I/O DIR
/*PARALLEL Control Operation*/
#define PARALLEL_ENABLE 0

/*-----------------------------*/
/* Constants for Pattern Match */
/*-----------------------------*/
/*Pattern Match Channel Mode*/
#define PATMATCH_CHNDisable 0
#define PATMATCH_CHNEnable  1
/*Pattern Match Channel Type*/
#define PATMATCH_Level_L    0
#define PATMATCH_Level_H    1
#define PATMATCH_Edge_R     2
#define PATMATCH_Edge_F     3
/*Pattern Match Operation*/
#define PATMATCH_STOP       0
#define PATMATCH_START      1
#define PATMATCH_RESTART    2

/*---------------------------------------------*/
/* Constants for Access EEPROM  			   */
/*---------------------------------------------*/
/*for PCI-7230/PCMe-7230*/
#define P7230_EEP_BLK_0	0
#define P7230_EEP_BLK_1	1
/*for PCI-9221/PCI-9222*/
#define P9221_EEP_BLK_0	0
#define P922x_EEP_BLK_0	0

// For PCIe-9146/9147/9126
#define AI_BANDWIDTH    0 

// AI_BandWidth Value Definition
#define BANDWIDTH_DEVICE_DEFAULT 	0	
#define BANDWIDTH_25K   1	
#define BANDWIDTH_220K	2

#define DIO_MODE_0 0
#define DIO_MODE_1 1
#define DIO_MODE_2 2 
#define DIO_MODE_3 3

/*--------------------------------------*/
/* Pattern Match Control with Action    */
/*--------------------------------------*/
// Pattern Match Channel
#define PM_DI        0
#define PM_ENCODER0  1
#define PM_ENCODER1  2
// Pattern Match Action
#define PM_ACTION_NO     0
#define PM_ACTION_AO_POL 1
#define PM_ACTION_AO_DMA 2
#define PM_ACTION_DO_POL 3
#define PM_ACTION_DO_DMA 4
// Pattern Match Control
#define PM_STOP  0
#define PM_START 1
#define PM_CLEAR 2
// Pattern Match Counter Control
#define PM_COUNTER_READ 0
#define PM_COUNTER_CLEAR 1

/*----------------------------------------------------------------------------*/
/* PCIS-DASK Function prototype                                               */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Basic Function */
I16 __stdcall Register_Card(U16 CardType, U16 card_num);

I16 __stdcall Release_Card(U16 CardNumber);

I16 __stdcall GetFPGAVersion(U16 wCardNumber, U32* pdwFPGAVersion);

I16 __stdcall GetFPGADateCode(U16 wCardNumber, U32* pdwFPGADateCode1, U32* pdwFPGADateCode2);

/*----------------------------------------------------------------------------*/
/* AI Function */
I16 __stdcall AI_9111_Config(U16 CardNumber, U16 TrigSource, U16 TrgMode, \
    U16 TraceCnt);

I16 __stdcall AI_9112_Config(U16 CardNumber, U16 TrigSource);

I16 __stdcall AI_9113_Config(U16 CardNumber, U16 TrigSource);

I16 __stdcall AI_9114_Config(U16 CardNumber, U16 TrigSource);

I16 __stdcall AI_9114_PreTrigConfig(U16 CardNumber, U16 PreTrgEn, U16 TraceCnt);

I16 __stdcall AI_9116_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U16 PostCnt, U16 MCnt, U16 ReTrgCnt);

I16 __stdcall AI_9116_CounterInterval(U16 CardNumber, U32 ScanIntrv, \
    U32 SampIntrv);

I16 __stdcall AI_9118_Config(U16 CardNumber, U16 ModeCtrl, U16 FunCtrl, \
    U16 BurstCnt, U16 PostCnt);

I16 __stdcall AI_9221_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    BOOLEAN AutoResetBuf);

I16 __stdcall AI_9221_CounterInterval(U16 CardNumber, U32 ScanIntrv, \
    U32 SampIntrv);

I16 __stdcall AI_9812_Config(U16 CardNumber, U16 TrgMode, U16 TrgSrc, \
    U16 TrgPol, U16 ClkSel, U16 TrgLevel, U16 PostCnt);

I16 __stdcall AI_9812_SetDiv(U16 CardNumber, U32 PacerVal);

I16 __stdcall AI_9524_Config(U16 CardNumber, U16 Group, U16 XMode, \
    U16 ConfigCtrl, U16 TrigCtrl, U32 TrigValue);

I16 __stdcall AI_9524_PollConfig(U16 CardNumber, U16 Group, U16 PollChannel, \
    U16 PollRange, U16 PollSpeed);

I16 __stdcall AI_9524_SetDSP(U16 CardNumber, U16 Channel, U16 Mode, \
    U16 DFStage, U32 SPKRejThreshold);

I16 __stdcall AI_9524_GetEOCEvent(U16 CardNumber, U16 Group, HANDLE *hEvent);

I16 __stdcall AI_9524_Monitor_ConfigEx(U16 CardNumber, U16 CH, U16 Range, F64 fSampleRate, U16 Condition, F64 Threshold);

I16 __stdcall AI_9524_Monitor_AlarmClearEx(U16 CardNumber, U16 CH);

I16 __stdcall AI_9524_Monitor_ResetEx(U16 CardNumber, U16 CH);

I16 __stdcall AI_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U32 TriggerCnt, U32 MidOrDlyScans, BOOLEAN AutoResetBuf);

I16 __stdcall AI_9222_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U32 ReTriggerCnt, BOOLEAN AutoResetBuf);

I16 __stdcall AI_CounterInterval(U16 CardNumber, U32 ScanIntrv, \
    U32 SampIntrv);

I16 __stdcall AI_9222_CounterInterval(U16 CardNumber, U32 ScanIntrv, \
    U32 SampIntrv);

I16 __stdcall AI_9223_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U32 ReTriggerCnt, BOOLEAN AutoResetBuf);

I16 __stdcall AI_9223_CounterInterval(U16 CardNumber, U32 ScanIntrv, \
    U32 SampIntrv);

I16 __stdcall AI_922A_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U32 ReTriggerCnt, BOOLEAN AutoResetBuf);

I16 __stdcall AI_922A_CounterInterval(U16 CardNumber, U32 ScanIntrv, \
    U32 SampIntrv);

I16 __stdcall AI_AsyncCheck(U16 CardNumber, BOOLEAN *Stopped, U32 *AccessCnt);

I16 __stdcall AI_AsyncClear(U16 CardNumber, U32 *AccessCnt);

I16 __stdcall AI_AsyncDblBufferHalfReady(U16 CardNumber, BOOLEAN *HalfReady, \
    BOOLEAN *StopFlag);

I16 __stdcall AI_AsyncDblBufferMode(U16 CardNumber, BOOLEAN Enable);

I16 __stdcall AI_AsyncDblBufferTransfer(U16 CardNumber, U16 *Buffer);

I16 __stdcall AI_AsyncDblBufferOverrun(U16 CardNumber, U16 op, \
    U16 *overrunFlag);

I16 __stdcall AI_AsyncDblBufferHandled(U16 CardNumber);

I16 __stdcall AI_AsyncDblBufferToFile(U16 CardNumber);

I16 __stdcall AI_AsyncReTrigNextReady(U16 CardNumber, BOOLEAN *Ready, \
    BOOLEAN *StopFlag, U16 *RdyTrigCnt);

I16 __stdcall AI_ContReadChannel(U16 CardNumber, U16 Channel, U16 AdRange, \
    U16 *Buffer, U32 ReadCount, F64 SampleRate, U16 SyncMode);

I16 __stdcall AI_ContReadMultiChannels(U16 CardNumber, U16 NumChans, \
    U16 *Chans, U16 *AdRanges, U16 *Buffer, U32 ReadCount, F64 SampleRate, \
    U16 SyncMode);

I16 __stdcall AI_ContScanChannels(U16 CardNumber, U16 Channel, U16 AdRange, \
    U16 *Buffer, U32 ReadCount, F64 SampleRate, U16 SyncMode);

I16 __stdcall AI_ContReadChannelToFile(U16 CardNumber, U16 Channel, \
    U16 AdRange, U8 *FileName, U32 ReadCount, F64 SampleRate, U16 SyncMode);

I16 __stdcall AI_ContReadMultiChannelsToFile(U16 CardNumber, U16 NumChans, \
    U16 *Chans, U16 *AdRanges, U8 *FileName, U32 ReadCount, F64 SampleRate, \
    U16 SyncMode);

I16 __stdcall AI_ContScanChannelsToFile(U16 CardNumber, U16 Channel, \
    U16 AdRange, U8 *FileName, U32 ReadCount, F64 SampleRate, U16 SyncMode);

I16 __stdcall AI_ContStatus(U16 CardNumber, U16 *Status);

I16 __stdcall AI_ContBufferSetup(U16 CardNumber, void *Buffer, U32 ReadCount, \
    U16 *BufferId);

I16 __stdcall AI_ContBufferReset(U16 CardNumber);

I16 __stdcall AI_EventCallBack(U16 CardNumber, I16 mode, I16 EventType, \
    U32 callbackAddr);

I16 __stdcall AI_InitialMemoryAllocated(U16 CardNumber, U32 *MemSize);

I16 __stdcall AI_ReadChannel(U16 CardNumber, U16 Channel, U16 AdRange, \
    U16 *Value);

I16 __stdcall AI_ReadChannel32(U16 CardNumber, U16 Channel, U16 AdRange, \
    U32 *Value);

I16 __stdcall AI_VReadChannel(U16 CardNumber, U16 Channel, U16 AdRange, \
    F64 *voltage);

I16 __stdcall AI_ScanReadChannels(U16 CardNumber, U16 Channel, U16 AdRange, \
    U16 *Buffer);

I16 __stdcall AI_ScanReadChannels32(U16 CardNumber, U16 Channel, U16 AdRange, \
    U32 *Buffer);

I16 __stdcall AI_ReadMultiChannels(U16 CardNumber, U16 NumChans, U16 *Chans, \
    U16 *AdRanges, U16 *Buffer);

I16 __stdcall AI_VoltScale(U16 CardNumber, U16 AdRange, I16 reading, \
    F64 *voltage);

I16 __stdcall AI_VoltScale32(U16 CardNumber, U16 adRange, I32 reading, \
    F64 *voltage);

I16 __stdcall AI_ContVScale(U16 CardNumber, U16 adRange, void *readingArray, \
    F64 *voltageArray, I32 count);

I16 __stdcall AI_SetTimeOut(U16 CardNumber, U32 TimeOut);

I16 __stdcall AI_AnalogTrig_Config(U16 CardNumber, U16 TrigCtrl, U16 H_TrgLevel, U16 L_TrgLevel);

I16 __stdcall AI_AnalogTrig_Config_ByVoltage(U16 CardNumber, U16 TrigCtrl, F64 H_TrgLevel_V, F64 L_TrgLevel_V, U16 adRange);

I16 __stdcall AI_CH_Param_Config(U16 CardNumber, U16 Channel, U16 Param, U16 Value);

/*----------------------------------------------------------------------------*/
/* AO Function */
I16 __stdcall AO_relay_EN(USHORT wCardNumber, USHORT enable);

I16 __stdcall AO_6202_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U32 ReTrgCnt, U32 DLY1Cnt, U32 DLY2Cnt, BOOLEAN AutoResetBuf);

I16 __stdcall AO_6208A_Config(U16 CardNumber, U16 V2AMode);

I16 __stdcall AO_6308A_Config(U16 CardNumber, U16 V2AMode);

I16 __stdcall AO_6308V_Config(U16 CardNumber, U16 Channel, U16 OutputPolarity, \
    F64 refVoltage);

I16 __stdcall AO_9111_Config(U16 CardNumber, U16 OutputPolarity);

I16 __stdcall AO_9112_Config(U16 CardNumber, U16 Channel, F64 refVoltage);

I16 __stdcall AO_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U32 TriggerCnt, BOOLEAN AutoResetBuf);

I16 __stdcall AO_9222_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U32 ReTrgCnt, U32 DLY1Cnt, U32 DLY2Cnt, BOOLEAN AutoResetBuf);

I16 __stdcall AO_9223_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U32 ReTrgCnt, U32 DLY1Cnt, U32 DLY2Cnt, BOOLEAN AutoResetBuf);

I16 __stdcall AO_AsyncCheck(U16 CardNumber, BOOLEAN *Stopped, U32 *AccessCnt);

I16 __stdcall AO_AsyncClear(U16 CardNumber, U32 *AccessCnt, U16 stop_mode);

I16 __stdcall AO_AsyncDblBufferHalfReady(U16 CardNumber, BOOLEAN *bHalfReady);

I16 __stdcall AO_AsyncDblBufferMode(U16 CardNumber, BOOLEAN Enable);

I16 __stdcall AO_ContBufferCompose(U16 CardNumber, U16 TotalChnCount, \
    U16 ChnNum, U32 UpdateCount, void *ConBuffer, void *Buffer);

I16 __stdcall AO_ContBufferReset(U16 CardNumber);

I16 __stdcall AO_ContBufferSetup(U16 CardNumber, void *Buffer, U32 WriteCount, \
    U16 *BufferId);

I16 __stdcall AO_ContStatus(U16 CardNumber, U16 *Status);

I16 __stdcall AO_ContWriteChannel(U16 CardNumber, U16 Channel, U16 BufId, \
    U32 WriteCount, U32 Iterations, U32 CHUI, U16 definite, U16 SyncMode);

I16 __stdcall AO_ContWriteMultiChannels(U16 CardNumber, U16 NumChans, \
    U16 *Chans, U16 BufId, U32 WriteCount, U32 Iterations, U32 CHUI, \
    U16 definite, U16 SyncMode);

I16 __stdcall AO_EventCallBack(U16 CardNumber, I16 mode, I16 EventType, \
    U32 callbackAddr);

I16 __stdcall AO_InitialMemoryAllocated(U16 CardNumber, U32 *MemSize);

I16 __stdcall AO_SetTimeOut(U16 CardNumber, U32 TimeOut);

I16 __stdcall AO_SimuVWriteChannel(U16 CardNumber, U16 Group, F64 *VBuffer);

I16 __stdcall AO_SimuWriteChannel(U16 CardNumber, U16 Group, I16 *Buffer);

I16 __stdcall AO_VoltScale(U16 CardNumber, U16 Channel, F64 Voltage, \
    I16 *binValue);

I16 __stdcall AO_VWriteChannel(U16 CardNumber, U16 Channel, F64 Voltage);

I16 __stdcall AO_WriteChannel(U16 CardNumber, U16 Channel, I16 Value);

I16 __stdcall AO_WriteChannels(U16 CardNumber, U16 wNumChans, U16* Chans, I16* Buffer);

I16 __stdcall AO_VWriteChannels(U16 CardNumber, U16 wNumChans, U16* Chans, double* Buffer);

I16 __stdcall AO_AsyncReTrigNextReady(U16 CardNumber, BOOLEAN *Ready, \
    BOOLEAN *StopFlag, U16 *RdyTrigCnt);
/*----------------------------------------------------------------------------*/
/* DI Function */
I16 __stdcall DI_7200_Config(U16 CardNumber, U16 TrigSource, U16 ExtTrigEn, \
    U16 TrigPol, U16 I_REQ_Pol);

I16 __stdcall DI_7233_ForceLogic(U16 CardNumber, U16 ConfigCtrl);

I16 __stdcall DI_7300A_Config(U16 CardNumber, U16 PortWidth, U16 TrigSource, \
    U16 WaitStatus, U16 Terminator, U16 I_REQ_Pol, BOOLEAN clear_fifo, \
    BOOLEAN disable_di);

I16 __stdcall DI_7300B_Config(U16 CardNumber, U16 PortWidth, U16 TrigSource, \
    U16 WaitStatus, U16 Terminator, U16 I_Cntrl_Pol, BOOLEAN clear_fifo, \
    BOOLEAN disable_di);

I16 __stdcall DI_7350_Config(U16 CardNumber, U16 DIPortWidth, U16 DIMode, \
    U16 DIWaitStatus, U16 DIClkConfig);

I16 __stdcall DI_7350_ExportSampCLKConfig(U16 CardNumber, U16 CLK_Src, \
    U16 CLK_DPAMode, U16 CLK_DPAVlaue);

I16 __stdcall DI_7350_ExtSampCLKConfig(U16 CardNumber, U16 CLK_Src, \
    U16 CLK_DDAMode, U16 CLK_DPAMode, U16 CLK_DDAVlaue, U16 CLK_DPAVlaue);

I16 __stdcall DI_7350_SoftTriggerGen(U16 CardNumber);

I16 __stdcall DI_7350_TrigHSConfig(U16 CardNumber, U16 TrigConfig, U16 DI_IPOL, \
    U16 DI_REQSrc, U16 DI_ACKSrc, U16 DI_TRIGSrc, U16 StartTrigSrc, \
    U16 PauseTrigSrc, U16 SoftTrigOutSrc, U32 SoftTrigOutLength, U32 TrigCount);

I16 __stdcall DI_7350_BurstHandShakeDelay(U16 CardNumber, U8 Delay);

I16 __stdcall DI_7360_Config(U16 CardNumber, U16 DIPortWidth, U16 DIMode, \
    U16 DIWaitStatus, U16 DIClkConfig);

I16 __stdcall DI_7360_ExportSampCLKConfig(U16 CardNumber, U16 CLK_Src, \
    U16 CLK_DPAMode, U16 CLK_DPAVlaue);

I16 __stdcall DI_7360_ExtSampCLKConfig(U16 CardNumber, U16 CLK_Src, \
    U16 CLK_DDAMode, U16 CLK_DPAMode, U16 CLK_DDAVlaue, U16 CLK_DPAVlaue);

I16 __stdcall DI_7360_SoftTriggerGen(U16 CardNumber);

I16 __stdcall DI_7360_TrigHSConfig(U16 CardNumber, U16 TrigConfig, U16 DI_IPOL, \
    U16 DI_REQSrc, U16 DI_ACKSrc, U16 DI_TRIGSrc, U16 StartTrigSrc, \
    U16 PauseTrigSrc, U16 SoftTrigOutSrc, U32 SoftTrigOutLength, U32 TrigCount);

I16 __stdcall DI_7360_BurstHandShakeDelay(U16 CardNumber, U8 Delay);

I16 __stdcall DI_7360_HighSpeedMode(U16 CardNumber, U16 wEnable);

I16 __stdcall DI_7360_SetDelayStep(U16 CardNumber, U32 Step);

I16 __stdcall DI_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U32 TriggerCnt, BOOLEAN AutoResetBuf);

I16 __stdcall DI_9222_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U32 ReTriggerCnt, BOOLEAN AutoResetBuf);

I16 __stdcall DI_9223_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U32 ReTriggerCnt, BOOLEAN AutoResetBuf);

I16 __stdcall DI_AsyncCheck(U16 CardNumber, BOOLEAN *Stopped, U32 *AccessCnt);

I16 __stdcall DI_AsyncClear(U16 CardNumber, U32 *AccessCnt);

I16 __stdcall DI_AsyncDblBufferHalfReady(U16 CardNumber, BOOLEAN *HalfReady);

I16 __stdcall DI_AsyncDblBufferHandled(U16 CardNumber);

I16 __stdcall DI_AsyncDblBufferMode(U16 CardNumber, BOOLEAN Enable);

I16 __stdcall DI_AsyncDblBufferToFile(U16 CardNumber);

I16 __stdcall DI_AsyncDblBufferTransfer(U16 CardNumber, void *Buffer);

I16 __stdcall DI_AsyncDblBufferOverrun(U16 CardNumber, U16 op, \
    U16 *overrunFlag);

I16 __stdcall DI_AsyncMultiBuffersHandled(U16 CardNumber, U16 bufcnt, \
    U16* bufs);

I16 __stdcall DI_AsyncMultiBufferNextReady(U16 CardNumber, BOOLEAN *NextReady, \
    U16 *BufferId);

I16 __stdcall DI_AsyncReTrigNextReady(U16 CardNumber, BOOLEAN *Ready, \
    BOOLEAN *StopFlag, U16 *RdyTrigCnt);

I16 __stdcall DI_ContBufferReset(U16 CardNumber);

I16 __stdcall DI_ContBufferSetup(U16 CardNumber, void *Buffer, U32 ReadCount, \
    U16 *BufferId);

I16 __stdcall DI_ContMultiBufferSetup(U16 CardNumber, void *Buffer, \
    U32 ReadCount, U16 *BufferId);

I16 __stdcall DI_ContMultiBufferStart(U16 CardNumber, U16 Port, F64 SampleRate);

I16 __stdcall DI_ContReadPort(U16 CardNumber, U16 Port, void *Buffer, \
    U32 ReadCount, F64 SampleRate, U16 SyncMode);

I16 __stdcall DI_ContReadPortToFile(U16 CardNumber, U16 Port, U8 *FileName, \
    U32 ReadCount, F64 SampleRate, U16 SyncMode);

I16 __stdcall DI_ContStatus(U16 CardNumber, U16 *Status);

I16 __stdcall DI_EventCallBack(U16 CardNumber, I16 mode, I16 EventType, \
    U32 callbackAddr);

I16 __stdcall DI_InitialMemoryAllocated(U16 CardNumber, U32 *DmaSize);

I16 __stdcall DI_ReadLine(U16 CardNumber, U16 Port, U16 Line, U16 *State);

I16 __stdcall DI_ReadPort(U16 CardNumber, U16 Port, U32 *Value);

I16 __stdcall DI_SetTimeOut(U16 CardNumber, U32 TimeOut);

/*----------------------------------------------------------------------------*/
/* DO Function */
I16 __stdcall DO_7200_Config(U16 CardNumber, U16 TrigSource, U16 OutReqEn, \
    U16 OutTrigSig);

I16 __stdcall DO_7300A_Config(U16 CardNumber, U16 PortWidth, U16 TrigSource, \
    U16 WaitStatus, U16 Terminator, U16 O_REQ_Pol);

I16 __stdcall DO_7300B_Config(U16 CardNumber, U16 PortWidth, U16 TrigSource, \
    U16 WaitStatus, U16 Terminator, U16 O_Cntrl_Pol, U32 FifoThreshold);

I16 __stdcall DO_7300B_SetDODisableMode(U16 CardNumber, U16 Mode);

I16 __stdcall DO_7350_Config(U16 CardNumber, U16 DOPortWidth, U16 DOMode, \
    U16 DOWaitStatus, U16 DOClkConfig);

I16 __stdcall DO_7350_ExportSampCLKConfig(U16 CardNumber, U16 CLK_Src, \
    U16 CLK_DPAMode, U16 CLK_DPAVlaue);

I16 __stdcall DO_7350_ExtSampCLKConfig(U16 CardNumber, U16 CLK_Src, \
    U16 CLK_DDAMode, U16 CLK_DPAMode, U16 CLK_DDAVlaue, U16 CLK_DPAVlaue);

I16 __stdcall DO_7350_SoftTriggerGen(U16 CardNumber);

I16 __stdcall DO_7350_TrigHSConfig(U16 CardNumber, U16 TrigConfig, U16 DO_IPOL, \
    U16 DO_REQSrc, U16 DO_ACKSrc, U16 DO_TRIGSrc, U16 StartTrigSrc, \
    U16 PauseTrigSrc, U16 SoftTrigOutSrc, U32 SoftTrigOutLength, U32 TrigCount);

I16 __stdcall DO_7350_BurstHandShakeDelay(U16 CardNumber, U8 Delay);

I16 __stdcall DO_7360_Config(U16 CardNumber, U16 DOPortWidth, U16 DOMode, \
    U16 DOWaitStatus, U16 DOClkConfig);

I16 __stdcall DO_7360_ExportSampCLKConfig(U16 CardNumber, U16 CLK_Src, \
    U16 CLK_Mode, U16 CLK_DPAMode, U16 CLK_DPAVlaue);

I16 __stdcall DO_7360_ExtSampCLKConfig(U16 CardNumber, U16 CLK_Src, \
    U16 CLK_DDAMode, U16 CLK_DPAMode, U16 CLK_DDAVlaue, U16 CLK_DPAVlaue);

I16 __stdcall DO_7360_SoftTriggerGen(U16 CardNumber);

I16 __stdcall DO_7360_TrigHSConfig(U16 CardNumber, U16 TrigConfig, U16 DO_IPOL, \
    U16 DO_REQSrc, U16 DO_ACKSrc, U16 DO_TRIGSrc, U16 StartTrigSrc, \
    U16 PauseTrigSrc, U16 SoftTrigOutSrc, U32 SoftTrigOutLength, U32 TrigCount);

I16 __stdcall DO_7360_BurstHandShakeDelay(U16 CardNumber, U8 Delay);

I16 __stdcall EDO_9111_Config(U16 CardNumber, U16 EDO_Fun);

I16 __stdcall DO_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U32 TriggerCnt, BOOLEAN AutoResetBuf);

I16 __stdcall DO_9222_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U32 ReTrgCnt, U32 DLY1Cnt, U32 DLY2Cnt, BOOLEAN AutoResetBuf);

I16 __stdcall DO_9223_Config(U16 CardNumber, U16 ConfigCtrl, U16 TrigCtrl, \
    U32 ReTrgCnt, U32 DLY1Cnt, U32 DLY2Cnt, BOOLEAN AutoResetBuf);

I16 __stdcall DO_AsyncCheck(U16 CardNumber, BOOLEAN *Stopped, U32 *AccessCnt);

I16 __stdcall DO_AsyncClear(U16 CardNumber, U32 *AccessCnt);

I16 __stdcall DO_AsyncMultiBufferNextReady(U16 CardNumber, BOOLEAN *NextReady, \
    U16 *BufferId);

I16 __stdcall DO_ContBufferReset(U16 CardNumber);

I16 __stdcall DO_ContBufferSetup(U16 CardNumber, VOID *Buffer, U32 WriteCount,
    U16 *BufferId);

I16 __stdcall DO_ContMultiBufferSetup(U16 CardNumber, void *Buffer, \
    U32 WriteCount, U16 *BufferId);

I16 __stdcall DO_ContMultiBufferStart(U16 CardNumber, U16 Port, \
    double fSampleRate);

I16 __stdcall DO_ContStatus(U16 CardNumber, U16 *Status);

I16 __stdcall DO_ContWritePort(U16 CardNumber, U16 Port, void *Buffer, \
    U32 WriteCount, U16 Iterations, F64 SampleRate, U16 SyncMode);

I16 __stdcall DO_ContWritePortEx(U16 CardNumber, U16 Port, void *Buffer, \
    U32 WriteCount, U16 Iterations, F64 SampleRate, U16 SyncMode);

I16 __stdcall DO_EventCallBack(U16 CardNumber, I16 mode, I16 EventType, \
    U32 callbackAddr);

I16 __stdcall DO_InitialMemoryAllocated(U16 CardNumber, U32 *MemSize);

I16 __stdcall DO_PGStart(U16 CardNumber, void *Buffer, U32 WriteCount, \
    F64 SampleRate);

I16 __stdcall DO_PGStop(U16 CardNumber);

I16 __stdcall DO_ReadLine(U16 CardNumber, U16 Port, U16 Line, U16 *Value);

I16 __stdcall DO_ReadPort(U16 CardNumber, U16 Port, U32 *Value);

I16 __stdcall DO_ResetOutput(U16 CardNumber, U16 reset);

I16 __stdcall DO_SetTimeOut(U16 CardNumber, U32 TimeOut);

I16 __stdcall DO_SimuWritePort(U16 CardNumber, U16 NumChans, U32 *Buffer);

I16 __stdcall DO_WriteExtTrigLine(U16 CardNumber, U16 Value);

I16 __stdcall DO_WriteLine(U16 CardNumber, U16 Port, U16 Line, U16 Value);

I16 __stdcall DO_WritePort(U16 CardNumber, U16 Port, U32 Value);

I16 __stdcall DO_AsyncDblBufferMode(U16 CardNumber, BOOLEAN Enable);

I16 __stdcall DO_AsyncReTrigNextReady(U16 CardNumber, BOOLEAN *Ready, \
    BOOLEAN *StopFlag, U16 *RdyTrigCnt);
    
I16 __stdcall DO_AsyncDblBufferHalfReady(U16 CardNumber, BOOLEAN *HalfReady);

/*----------------------------------------------------------------------------*/
/* DIO Function */
I16 __stdcall DIO_7300SetInterrupt(U16 CardNumber, I16 AuxDIEn, I16 T2En, \
    HANDLE *Event);

I16 __stdcall DIO_7350_AFIConfig(U16 CardNumber, U16 AFI_Port, U16 AFI_Enable, \
    U16 AFI_Mode, U32 AFI_TrigOutLen);

I16 __stdcall DIO_7360_AFIConfig(U16 CardNumber, U16 AFI_Port, U16 AFI_Enable, \
    U16 AFI_Mode, U32 AFI_TrigOutLen);

I16 __stdcall DIO_AUXDI_EventMessage(U16 CardNumber, I16 AuxDIEn, \
    HANDLE windowHandle, U32 message, void *callbackAddr());

I16 __stdcall DIO_COSInterruptCounter(U16 CardNumber, U16 Counter_Num, \
    U16 Counter_Mode, U16 DI_Port, U16 DI_Line, U32 *Counter_Value);

I16 __stdcall DIO_GetCOSLatchData(U16 CardNumber, U16 *CosLData);

I16 __stdcall DIO_GetCOSLatchData32(U16 CardNumber, U8 Port, U32 *CosLData);

I16 __stdcall DIO_GetCOSLatchDataInt32(U16 CardNumber, U8 Port, U32 *CosLData);

I16 __stdcall DIO_GetPMLatchData32(U16 CardNumber, U16 Port, U32 *PMLData);

I16 __stdcall DIO_INT1_EventMessage(U16 CardNumber, I16 Int1Mode, \
    HANDLE windowHandle, U32 message, void *callbackAddr());

I16 __stdcall DIO_INT2_EventMessage(U16 CardNumber, I16 Int2Mode, \
    HANDLE windowHandle, U32 message, void *callbackAddr());

I16 __stdcall DIO_INT_Event_Message(U16 CardNumber, I16 mode, HANDLE evt, \
    HANDLE windowHandle, U32 message, U32 callbackAddr);

I16 __stdcall DIO_LineConfig(U16 CardNumber, U16 Port, U16 Line, U16 Direction);

I16 __stdcall DIO_LinesConfig(U16 CardNumber, U16 Port, U16 Linesdirmap);

I16 __stdcall DIO_PortConfig(U16 CardNumber, U16 Port, U16 Direction);

I16 __stdcall DIO_PMConfig(U16 CardNumber, U16 Channel, U16 PM_ChnEn, \
    U16 PM_ChnType);

I16 __stdcall DIO_PMControl(U16 CardNumber, U16 Port, U16 PM_Start, \
    HANDLE *hEvent, BOOLEAN ManualReset);

I16 __stdcall DIO_SetCOSInterrupt(U16 CardNumber, U16 Port, U16 ctlA, U16 ctlB,\
    U16 ctlC);

I16 __stdcall DIO_SetCOSInterrupt32(U16 CardNumber, U8 Port, U32 ctl, \
    HANDLE *Event, BOOLEAN ManualReset);

I16 __stdcall DIO_SetPMInterrupt32(U16 CardNumber, U16 Port, U32 Ctrl, \
    U32 Pattern1, U32 Pattern2, HANDLE *hEvent, BOOLEAN ManualReset);

I16 __stdcall DIO_SetDualInterrupt(U16 CardNumber, I16 Int1Mode, I16 Int2Mode, \
    HANDLE *Event);

I16 __stdcall DIO_T2_EventMessage(U16 CardNumber, I16 T2En, \
    HANDLE windowHandle, U32 message, void *callbackAddr());

I16 __stdcall DIO_VoltLevelConfig(U16 CardNumber, U16 PortType, U16 VoltLevel);

I16 __stdcall DIO_AFIConfig(U16 wCardNumber, U16 wAFI_Port, \
	U16 wAFI_Enable, U16 wAFI_Mode, U32 dwAFI_TrigOutLen);

I16 __stdcall DIO_Mode_Config(U16 CardNumber, U16 Mode);

/*----------------------------------------------------------------------------*/
/* Pattern Match Function */
I16 __stdcall PM_EventCallBack(U16 CardNumber, I16 mode, I16 EventType, U32 callbackAddr);
	
/*----------------------------------------------------------------------------*/
/* Timer/Counter Function */
I16 __stdcall CTR_8554_CK1_Config(U16 CardNumber, U16 ClockSource);

I16 __stdcall CTR_8554_ClkSrc_Config(U16 CardNumber, U16 Ctr, U16 ClockSource);

I16 __stdcall CTR_8554_Debounce_Config(U16 CardNumber, U16 DebounceClock);

I16 __stdcall CTR_Clear(U16 CardNumber, U16 Ctr, U16 State);

I16 __stdcall CTR_Read(U16 CardNumber, U16 Ctr, U32 *Value);

I16 __stdcall CTR_Read_All(U16 CardNumber, U16 CtrCnt, U16 *Ctr, U32 *Value);

I16 __stdcall CTR_Setup(U16 CardNumber, U16 Ctr, U16 Mode, U32 Count, \
    U16 BinBcd);

I16 __stdcall CTR_Setup_All(U16 CardNumber, U16 CtrCnt, U16 *Ctr, U16 *Mode, \
    U32 *Count, U16 *BinBcd);

I16 __stdcall CTR_Status(U16 CardNumber, U16 Ctr, U32 *Value);

I16 __stdcall CTR_Update(U16 CardNumber, U16 Ctr, U32 Count);

I16 __stdcall GCTR_Clear(U16 CardNumber, U16 GCtr);

I16 __stdcall GCTR_Read(U16 CardNumber, U16 GCtr, U32 *Value);

I16 __stdcall GCTR_Setup(U16 CardNumber, U16 GCtr, U16 GCtrCtrl, U32 Count);

I16 __stdcall GPTC_9524_PG_Config(U16 CardNumber, U16 GCtr, U32 PulseGenNum);

I16 __stdcall GPTC_Clear(U16 CardNumber, U16 GCtr);

I16 __stdcall GPTC_Control(U16 CardNumber, U16 GCtr, U16 ParamID, U16 Value);

I16 __stdcall GPTC_EventCallBack(U16 CardNumber, I16 Enabled, I16 EventType, \
    U32 callbackAddr);

I16 __stdcall GPTC_EventSetup(U16 CardNumber, U16 GCtr, U16 Mode, U16 Ctrl, \
    U32 LVal_1, U32 LVal_2);

I16 __stdcall GPTC_Read(U16 CardNumber, U16 GCtr, U32 *Value);

I16 __stdcall GPTC_Setup(U16 CardNumber, U16 GCtr, U16 Mode, U16 SrcCtrl, \
    U16 PolCtrl, U32 LReg1_Val, U32 LReg2_Val);

I16 __stdcall GPTC_Status(U16 CardNumber, U16 GCtr, U16 *Value);

I16 __stdcall GPTC_9524_GetTimerEvent(U16 CardNumber, U16 GCtr, HANDLE *hEvent);

I16 __stdcall GPTC_9524_SetCombineEcdData(U16 CardNumber, BOOLEAN enable);

I16 __stdcall WDT_Control(U16 CardNumber, U16 Ctr, U16 action);

I16 __stdcall WDT_Reload(U16 CardNumber, U16 Ctr, F32 ovflowSec, \
    F32 *actualSec);

I16 __stdcall WDT_Setup(U16 CardNumber, U16 Ctr, F32 ovflowSec, \
    F32 *actualSec, HANDLE *Event);

I16 __stdcall WDT_Status(U16 CardNumber, U16 Ctr, U32 *Value);

/*----------------------------------------------------------------------------*/
/* Get Event or View Function */
I16 __stdcall AI_GetEvent(U16 CardNumber, HANDLE *Event);

I16 __stdcall AO_GetEvent(U16 CardNumber, HANDLE *Event);

I16 __stdcall DI_GetEvent(U16 CardNumber, HANDLE *Event);

I16 __stdcall DO_GetEvent(U16 CardNumber, HANDLE *Event);

I16 __stdcall AI_GetView(U16 CardNumber, U32 *View);

I16 __stdcall DI_GetView(U16 CardNumber, U32 *View);

I16 __stdcall DO_GetView(U16 CardNumber, U32 *View);

/*---------------------------------------------------------------------------*/
/* Common Function */
I16 __stdcall GetActualRate(U16 CardNumber, F64 SampleRate, F64 *ActualRate);

I16 __stdcall GetActualRate_9524(U16 CardNumber, U16 Group, F64 SampleRate, \
    F64 *ActualRate);

I16 __stdcall GetBaseAddr(U16 CardNumber, U32 *BaseAddr, U32 *BaseAddr2);

I16 __stdcall GetCardIndexFromID(U16 CardNumber, U16 *cardType, U16 *cardIndex);

I16 __stdcall GetCardType(U16 CardNumber, U16 *cardType);

I16 __stdcall GetLCRAddr(U16 CardNumber, U32 *LcrAddr);

I16 __stdcall PCI_EEPROM_LoadData(U16 CardNumber, U16 block, U16 *data);

I16 __stdcall PCI_EEPROM_SaveData(U16 CardNumber, U16 block, U16 data);

void * __stdcall PCI_Buffer_Alloc (U16 CardNumber, size_t BufferSize);

I16 __stdcall PCI_Buffer_Free (U16 CardNumber, void *BufferAddr);

I16 __stdcall PCI_GetSerialNumber(U16 wCardNumber, U8 *SerialString, U8 numberOfElements, U8* actualread);

I16 __stdcall PCI_GetSerialNumberUser(U16 wCardNumber, U8 *SerialString, U8 numberOfElements, U8* actualread);

I16 __stdcall PCI_SetSerialNumberUser(U16 wCardNumber, U8 *SerialString, U8 numberOfElements);

/*----------------------------------------------------------------------------*/
/* Safety Control Function */
I16 __stdcall EMGShutDownControl(U16 CardNumber, U8 ctrl);

I16 __stdcall EMGShutDownStatus(U16 CardNumber, U8 *sts);

I16 __stdcall GetInitPattern(U16 CardNumber, U8 patID, U32 *pattern);

I16 __stdcall HotResetHoldControl(U16 CardNumber, U8 enable);

I16 __stdcall HotResetHoldStatus(U16 CardNumber, U8 *sts);

I16 __stdcall IdentifyLED_Control(U16 CardNumber, U8 ctrl);

I16 __stdcall SetInitPattern(U16 CardNumber, U8 patID, U32 pattern);

/*----------------------------------------------------------------------------*/
/* Calibration Function */
I16 __stdcall PCI9116_Calibration(U16 wCardNumber, U16 wOperation, U16 wCalibrateMode, \
    F64 fReferVoltage, U16* pCalData );

I16 __stdcall PCI9116_Flash_SaveData(U16 wCardNumber, U16 *pCalData );

I16 __stdcall PCI9116_Flash_LoadData(U16 wCardNumber, U16 *pCalData, U16 wFlashBlock );

I16 __stdcall PCI9524_Acquire_AD_CalConst(U16 CardNumber, U16 Group, \
    U16 ADC_Range, U16 ADC_Speed, U32 *CalDate, F32 *CalTemp, U32 *ADC_offset, \
    U32 *ADC_gain, F64 *Residual_offset, F64 *Residual_scaling);

I16 __stdcall PCI9524_Acquire_DA_CalConst(U16 CardNumber, U16 Channel, \
    U32 *CalDate, F32 *CalTemp, U8 *DAC_offset, U8 *DAC_linearity, \
    F32 *Gain_factor);

I16 __stdcall PCI9524_Read_EEProm(U16 CardNumber, U16 ReadAddr, U8 *ReadData);

I16 __stdcall PCI9524_Read_RemoteSPI(U16 CardNumber, U16 Addr, U8 *RdData);

I16 __stdcall PCI9524_Write_EEProm(U16 CardNumber, U16 WriteAddr, U8 *WriteData);

I16 __stdcall PCI9524_Write_RemoteSPI(U16 CardNumber, U16 Addr, U8 WrtData);

I16 __stdcall PCI_DB_Auto_Calibration_ALL(U16 CardNumber);

I16 __stdcall PCI_DB_Calibration_FactoryReset(U16 CardNumber);

I16 __stdcall PCI_EEPROM_CAL_Constant_Update(U16 CardNumber, U16 bank);

I16 __stdcall PCI_Load_CAL_Data(U16 CardNumber, U16 bank);

/*----------------------------------------------------------------------------*/
/* SSI Function */
I16 __stdcall SSI_SourceConn(U16 CardNumber, U16 sigCode);

I16 __stdcall SSI_SourceDisConn(U16 CardNumber, U16 sigCode);

I16 __stdcall SSI_SourceClear(U16 CardNumber);

/*----------------------------------------------------------------------------*/
/* PWM Function */
I16 __stdcall PWM_Output(U16 CardNumber, U16 Channel, U32 high_interval, \
    U32 low_interval);

I16 __stdcall PWM_Stop(U16 CardNumber, U16 Channel);

/*----------------------------------------------------------------------------*/
/* I2C Function */
I16 __stdcall I2C_Setup(U16 CardNumber, U16 I2C_Port, U16 I2C_Config, \
    U32 I2C_SetupValue1, U32 I2C_SetupValue2);

I16 __stdcall I2C_Control(U16 CardNumber, U16 I2C_Port, U16 I2C_CtrlParam, \
    U32 I2C_CtrlValue);

I16 __stdcall I2C_Status(U16 CardNumber, U16 I2C_Port, U32 *I2C_Status);

I16 __stdcall I2C_Read(U16 CardNumber, U16 I2C_Port, U16 I2C_SlaveAddr, \
     U16 I2C_CmdAddrBytes, U16 I2C_DataBytes, U32 I2C_CmdAddr, U32 *I2C_Data);

I16 __stdcall I2C_Write(U16 CardNumber, U16 I2C_Port, U16 I2C_SlaveAddr, \
     U16 I2C_CmdAddrBytes, U16 I2C_DataBytes, U32 I2C_CmdAddr, U32 I2C_Data);
I16 __stdcall PCI_I2C_PhaseShift_Set(USHORT wCardNumber, U8 bEnable);
I16 __stdcall PCI_I2C_PhaseShift_Check(USHORT wCardNumber, U8 *bEnable);

/*----------------------------------------------------------------------------*/
/* SPI Function */
I16 __stdcall SPI_Setup(U16 CardNumber, U16 SPI_Port, U16 SPI_Config, \
    U32 SPI_SetupValue1, U32 SPI_SetupValue2);

I16 __stdcall SPI_Control(U16 CardNumber, U16 SPI_Port, U16 SPI_CtrlParam, \
    U32 SPI_CtrlValue);

I16 __stdcall SPI_Status(U16 CardNumber, U16 SPI_Port, U32 *SPI_Status);

I16 __stdcall SPI_Read(U16 CardNumber, U16 SPI_Port, U16 SPI_SlaveAddr, \
    U16 SPI_CmdAddrBits, U16 SPI_DataBits, U16 SPI_FrontDummyBits, \
    U32 SPI_CmdAddr, U32 *SPI_Data);

I16 __stdcall SPI_Write(U16 CardNumber, U16 SPI_Port, U16 SPI_SlaveAddr, \
    U16 SPI_CmdAddrBits, U16 SPI_DataBits, U16 SPI_FrontDummyBits, \
    U16 SPI_TailDummyBits, U32 SPI_CmdAddr, U32 SPI_Data);

/*----------------------------------------------------------------------------*/
/* SPI Function SYNC */
I16 __stdcall SPI_Setup_SYNC(U16 CardNumber, U16 wNumPorts, U16 *SPI_Port, U16 *SPI_Config, \
    U32 SPI_SetupValue1, U32 *SPI_SetupValue2);

I16 __stdcall SPI_Control_SYNC(U16 CardNumber, U16 wNumPorts, U16 *SPI_Port, U16 *SPI_CtrlParam, \
    U32 *SPI_CtrlValue);

I16 __stdcall SPI_Status_SYNC(U16 CardNumber, U16 wNumPorts, U16 *SPI_Port, U32* SPI_Status);

I16 __stdcall SPI_Read_SYNC(U16 CardNumber, U16 wNumPorts, U16 *SPI_Port, U16 *SPI_SlaveAddr, \
    U16 *SPI_CmdAddrBits, U16 *SPI_DataBits, U16 *SPI_FrontDummyBits, \
    U32 *SPI_CmdAddr, U32* SPI_Data);

I16 __stdcall SPI_Write_SYNC(U16 CardNumber, U16 wNumPorts, U16 *SPI_Port, U16 *SPI_SlaveAddr, \
    U16 *SPI_CmdAddrBits, U16 *SPI_DataBits, U16 *SPI_FrontDummyBits, \
    U16 *SPI_TailDummyBits, U32 *SPI_CmdAddr, U32 *SPI_Data);

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Parallel Function */ // For PCIe-7350 Honprec Parallel Model
I16 __stdcall Parallel_Setup(U16 CardNumber, U16 Parallel_Port, \
    U32 Parallel_SetupValue1, U32 Parallel_SetupValue2);

I16 __stdcall Parallel_Control(U16 CardNumber, U16 Parallel_Port, U16 Parallel_CtrlParam, \
    U32 Parallel_CtrlValue);

I16 __stdcall Parallel_Read(U16 CardNumber, U16 Parallel_Port, U32 Parallel_Addr, U32* Parallel_Data);

//I16 __stdcall Parallel_Write(U16 CardNumber, U16 Parallel_Port, U16 Parallel_SlaveAddr, \
//    U16 Parallel_CmdAddrBits, U16 Parallel_DataBits, U16 Parallel_FrontDummyBits, \
//    U16 Parallel_TailDummyBits, U32 Parallel_CmdAddr, U32 Parallel_Data);

/*----------------------------------------------------------------------------*/
/* Parallel Function */ // For PCIe-7350 Honprec Parallel Model Synchronously
I16 __stdcall Parallel_Setup_SYNC(U16 CardNumber, U16 wNumPorts, U16* Parallel_Port, \
    U32 Parallel_SetupValue1, U32* Parallel_SetupValue2);

I16 __stdcall Parallel_Control_SYNC(U16 CardNumber, U16 wNumPorts, U16* Parallel_Port, U16* Parallel_CtrlParam, \
    U32* Parallel_CtrlValue);

I16 __stdcall Parallel_Read_SYNC(U16 CardNumber, U16 wNumPorts, U16* Parallel_Port, U32* Parallel_Addr, U32* Parallel_Data);

//I16 __stdcall Parallel_Write(U16 CardNumber, U16 Parallel_Port, U16 Parallel_SlaveAddr, \
//    U16 Parallel_CmdAddrBits, U16 Parallel_DataBits, U16 Parallel_FrontDummyBits, \
//    U16 Parallel_TailDummyBits, U32 Parallel_CmdAddr, U32 Parallel_Data);

/*----------------------------------------------------------------------------*/

I16 __stdcall Get_PLL_Lock_Status(U16 wCardNumber, U32* dwValue);
I16 __stdcall AI_Set_Sampling_Mode(U16 wCardNumber, U32 dwValue);
I16 __stdcall AI_Get_Sampling_Mode(U16 wCardNumber, U32 *dwValue);

I16 __stdcall PM_Setup(U16 wCardNumber, U16 wType, U16 wAction, U16 wNumOfPattern, U32 *dwPatternArray);
I16 __stdcall PM_Control(U16 wCardNumber, U16 wType, U16 wMode);
I16 __stdcall PM_Control(U16 wCardNumber, U16 wType, U16 wMode);
I16 __stdcall PM_EventCallBack_x64(U16 wCardNumber,I16 mode, I16 EventType, U32 callbackAddr);

#ifdef __cplusplus
}
#endif

#endif
