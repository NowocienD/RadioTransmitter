// config
#define CONFIG_REG      0x00
#define MASK_RX_DR  6
#define MASK_TX_DS  5
#define MASK_MAX_RT 4
#define EN_CRC      3
#define CRCO        2
#define PWR_UP      1
#define PRIM_RX     0

// Enhanced ShockBurst
#define EN_AA       0x01
#define ENAA_P5     5
#define ENAA_P4     4
#define ENAA_P3     3
#define ENAA_P2     2
#define ENAA_P1     1
#define ENAA_P0     0

// Enabled RX Addresses
#define EN_RXADDR   0x02
#define ERX_P5      5
#define ERX_P4      4
#define ERX_P3      3
#define ERX_P2      2
#define ERX_P1      1
#define ERX_P0      0

// Setup of Address Widths
#define SETUP_AW    0x03
#define AW          0

// Setup of Automatic Retransmission
#define SETUP_RETR  0x04
#define ARD         4
#define ARC         0

// RF Channel
#define RF_CH       0x05

// RF Setup Register
#define RF_SETUP    0x06
#define CONT_WAVE   7
#define RF_DR_LOW	5
#define PLL_LOCK    4
#define RF_DR_HIGH  3
#define RF_PWR      1
       
// Status Register
#define STATUS      0x07
#define RX_DR       6
#define TX_DS       5
#define MAX_RT      4
#define RX_P_NO     1
#define TX_FULL     0

// Transmit observe register
#define OBSERVE_TX  0x08
#define PLOS_CNT    4
#define ARC_CNT     0

// Received Power Detector (CD)
#define RPD          0x09

// Receive address data pipe 0-5
#define RX_ADDR_P0  0x0A
#define RX_ADDR_P1  0x0B
#define RX_ADDR_P2  0x0C
#define RX_ADDR_P3  0x0D
#define RX_ADDR_P4  0x0E
#define RX_ADDR_P5  0x0F

// Transmit address
#define TX_ADDR     0x10

//Data transmit length
#define RX_PW_P0    0x11
#define RX_PW_P1    0x12
#define RX_PW_P2    0x13
#define RX_PW_P3    0x14
#define RX_PW_P4    0x15
#define RX_PW_P5    0x16

// FIFO Status 
#define FIFO_STATUS 0x17
#define TX_REUSE    6
#define FIFO_FULL   5
#define TX_EMPTY    4
#define RX_FULL     1
#define RX_EMPTY    0

// Enable dynamic payload length
#define	DYNPD		0x1C
#define DPL_P5		5
#define DPL_P4		4
#define DPL_P3		3
#define DPL_P2		2
#define DPL_P1		1
#define DPL_P0		0

// Feature Register
#define FEATURE		0x1D
#define DPL_P4		4
#define EN_DPL		2
#define EN_ACK_PAY	1
#define EN_DYN_ACK	0


/* Instruction Mnemonics */
#define R_REGISTER			0x00
#define W_REGISTER			0x20
#define R_RX_PAYLOAD		0x61
#define W_TX_PAYLOAD		0xA0
#define FLUSH_TX			0xE1
#define FLUSH_RX			0xE2
#define REUSE_TX_PL			0xE3
#define R_RX_PL_WID			0x60
#define W_TX_PAYLOAD_NO		0x0B0
#define NOP					0xFF

#define REGISTER_MASK 0x1F


#define DATA_RATE_1MBPS		(0<<RF_DR_LOW) | (0<<RF_DR_HIGH)
#define DATA_RATE_2MBPS		(0<<RF_DR_LOW) | (1<<RF_DR_HIGH)
#define DATA_RATE_250KBPS	(1<<RF_DR_LOW) | (0<<RF_DR_HIGH)

#define OUTPUT_POWER_ULTRALOW	(0<<RF_PWR)
#define OUTPUT_POWER_LOW		(1<<RF_PWR)
#define OUTPUT_POWER_HIGH		(2<<RF_PWR)
#define OUTPUT_POWER_ULTRAHIGH	(3<<RF_PWR)

