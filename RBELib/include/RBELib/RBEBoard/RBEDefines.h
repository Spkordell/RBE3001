/**
 * @file RBEDefines.h
 *
 *  Created on: Sep 5, 2010
 *  @author hephaestus
 *
 * @author Eric Willcox
 * @date August 20, 2013
 */

#ifndef RBEDEFINES_H_
#define RBEDEFINES_H_
#include "RBELib/reg_structs.h"

/**
 * @brief  Motor 0 Potentiometer (ADC 2)
 */
#define M0POT 2
/**
 * @brief  Motor 1 Potentiometer(ADC 3)
 */
#define M1POT 3
/**
 * @brief  Motor 2 Potentiometer (ADC 4)
 */
#define M2POT 4
/**
 * @brief  Motor 3 Potentiometer (ADC 5)
 */
#define M3POT 5



/**
 * @brief  SPI MISO
 */
#define SPI_MISO		PORTBbits._P6
/**
 * @brief  SPI MISO
 */
#define SPI_MISO_DDR	DDRBbits._P6

/**
 * @brief  SPI MOSI
 */
#define SPI_MOSI		PORTBbits._P5
/**
 * @brief  SPI MOSI
 */
#define SPI_MOSI_DDR	DDRBbits._P5

/**
 * @brief  SPI Clock
 */
#define SPI_SCK			PORTBbits._P7
/**
 * @brief  SPI Clock
 */
#define SPI_SCK_DDR		DDRBbits._P7



/**
 * @brief  SPI Slave Select Encoder 0
 */
#define ENCODER_SS_0 	 PORTCbits._P5
/**
 * @brief  SPI Slave Select Encoder 1
 */
#define ENCODER_SS_1 	 PORTCbits._P4
/**
 * @brief  SPI Slave Select Encoder 2
 */
#define ENCODER_SS_2 	 PORTCbits._P3
/**
 * @brief  SPI Slave Select Encoder 3
 */
#define ENCODER_SS_3 	 PORTCbits._P2

/**
 * @brief  SPI Slave Select DAC 1
 */
#define DAC_SS 			 PORTDbits._P4
/**
 * @brief  SPI Slave Select DAC 2
 */
#define AUX_DAC_SS 		 PORTCbits._P6
/**
 * @brief  SPI Slave Co-Processor
 */
#define COPROC_SS 		 PORTCbits._P1
/**
 * @brief  SPI Slave Select Busy Co-Processor
 */
#define COPROC_BUSY		 PINCbits._P0
/**
 * @brief  SPI Slave Select Unuesd
 */
#define SPARE_SS 		 PORTCbits._P0

/**
 * @brief  SPI Slave Select Encoder 0
 */
#define ENCODER_SS_0_ddr DDRCbits._P5
/**
 * @brief  SPI Slave Select Encoder 1
 */
#define ENCODER_SS_1_ddr DDRCbits._P4
/**
 * @brief  SPI Slave Select Encoder 2
 */
#define ENCODER_SS_2_ddr DDRCbits._P3
/**
 * @brief  SPI Slave Select Encoder 3
 */
#define ENCODER_SS_3_ddr DDRCbits._P2

/**
 * @brief  SPI Slave Select DAC 1
 */
#define DAC_SS_ddr 		 DDRDbits._P4
/**
 * @brief  SPI Slave Select DAC 2
 */
#define AUX_DAC_SS_ddr 	 DDRCbits._P6
/**
 * @brief  SPI Slave Select Co-Processor
 */
#define COPROC_SS_ddr	 DDRCbits._P1
/**
 * @brief  SPI Slave Select busy Co-Processor
 */
#define COPROC_BUSY_ddr	 DDRCbits._P0
/**
 * @brief  SPI Slave Select Unused
 */
#define SPARE_SS_ddr	 DDRCbits._P0

/**
 * @brief  Interrupt line for all encoders
 */
#define ENCODER_IRQ		PORTBbitd._P2
/**
 * @brief  Interrupt line for all encoders
 */
#define ENCODER_IRQ_ddr	DDRBbitd._P2


#endif /* RBEDEFINES_H_ */
