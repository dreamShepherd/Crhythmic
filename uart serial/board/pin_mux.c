/*
 * The Clear BSD License
 * Copyright 2018 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 * that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v4.0
processor: MKL46Z256xxx4
package_id: MKL46Z256VLL4
mcu_data: ksdk2_0
processor_version: 0.0.13
board: FRDM-KL46Z
pin_labels:
- {pin_num: '31', pin_signal: PTE24/TPM0_CH0/I2C0_SCL, label: 'U2[7]/U10[4]/I2C0_SDA', identifier: ACCEL_I2C_SCL}
- {pin_num: '32', pin_signal: PTE25/TPM0_CH1/I2C0_SDA, label: 'U2[6]/U10[6]/I2C0_SDA', identifier: ACCEL_I2C_SDA}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '35', peripheral: UART0, signal: RX, pin_signal: TSI0_CH2/PTA1/UART0_RX/TPM2_CH0}
  - {pin_num: '36', peripheral: UART0, signal: TX, pin_signal: TSI0_CH3/PTA2/UART0_TX/TPM2_CH1}
  - {pin_num: '26', peripheral: TPM0, signal: 'CH, 2', pin_signal: CMP0_IN5/ADC0_SE4b/PTE29/TPM0_CH2/TPM_CLKIN0, identifier: ''}
  - {pin_num: '98', peripheral: TPM0, signal: 'CH, 5', pin_signal: LCD_P45/ADC0_SE6b/PTD5/SPI1_SCK/UART2_TX/TPM0_CH5/LCD_P45_Fault, identifier: ''}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port D Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD);
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    /* PORTA1 (pin 35) is configured as UART0_RX */
    PORT_SetPinMux(BOARD_DEBUG_UART_RX_PORT, BOARD_DEBUG_UART_RX_PIN, kPORT_MuxAlt2);

    /* PORTA2 (pin 36) is configured as UART0_TX */
    PORT_SetPinMux(BOARD_DEBUG_UART_TX_PORT, BOARD_DEBUG_UART_TX_PIN, kPORT_MuxAlt2);

    /* PORTD5 (pin 98) is configured as TPM0_CH5 */
    PORT_SetPinMux(PORTD, 5U, kPORT_MuxAlt4);

    /* PORTE29 (pin 26) is configured as TPM0_CH2 */
    PORT_SetPinMux(PORTE, 29U, kPORT_MuxAlt3);

    SIM->SOPT5 = ((SIM->SOPT5 &
                   /* Mask bits to zero which are setting */
                   (~(SIM_SOPT5_UART0TXSRC_MASK | SIM_SOPT5_UART0RXSRC_MASK)))

                  /* UART0 Transmit Data Source Select: UART0_TX pin. */
                  | SIM_SOPT5_UART0TXSRC(SOPT5_UART0TXSRC_UART_TX)

                  /* UART0 Receive Data Source Select: UART_RX pin. */
                  | SIM_SOPT5_UART0RXSRC(SOPT5_UART0RXSRC_UART_RX));
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_I2C_ConfigurePins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '31', peripheral: I2C0, signal: SCL, pin_signal: PTE24/TPM0_CH0/I2C0_SCL, identifier: '', slew_rate: fast, pull_select: up, pull_enable: enable}
  - {pin_num: '32', peripheral: I2C0, signal: SDA, pin_signal: PTE25/TPM0_CH1/I2C0_SDA, identifier: '', slew_rate: fast, pull_select: up, pull_enable: enable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_I2C_ConfigurePins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_I2C_ConfigurePins(void)
{
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    const port_pin_config_t porte24_pin31_config = {/* Internal pull-up resistor is enabled */
                                                    kPORT_PullUp,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as I2C0_SCL */
                                                    kPORT_MuxAlt5};
    /* PORTE24 (pin 31) is configured as I2C0_SCL */
    PORT_SetPinConfig(PORTE, 24U, &porte24_pin31_config);

    const port_pin_config_t porte25_pin32_config = {/* Internal pull-up resistor is enabled */
                                                    kPORT_PullUp,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as I2C0_SDA */
                                                    kPORT_MuxAlt5};
    /* PORTE25 (pin 32) is configured as I2C0_SDA */
    PORT_SetPinConfig(PORTE, 25U, &porte25_pin32_config);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_Init_I2C_GPIO_pins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '31', peripheral: GPIOE, signal: 'GPIO, 24', pin_signal: PTE24/TPM0_CH0/I2C0_SCL, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '32', peripheral: GPIOE, signal: 'GPIO, 25', pin_signal: PTE25/TPM0_CH1/I2C0_SDA, direction: OUTPUT, gpio_init_state: 'true'}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_Init_I2C_GPIO_pins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_Init_I2C_GPIO_pins(void)
{
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    gpio_pin_config_t ACCEL_I2C_SCL_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTE24 (pin 31)  */
    GPIO_PinInit(BOARD_ACCEL_I2C_SCL_GPIO, BOARD_ACCEL_I2C_SCL_PIN, &ACCEL_I2C_SCL_config);

    gpio_pin_config_t ACCEL_I2C_SDA_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTE25 (pin 32)  */
    GPIO_PinInit(BOARD_ACCEL_I2C_SDA_GPIO, BOARD_ACCEL_I2C_SDA_PIN, &ACCEL_I2C_SDA_config);

    /* PORTE24 (pin 31) is configured as PTE24 */
    PORT_SetPinMux(BOARD_ACCEL_I2C_SCL_PORT, BOARD_ACCEL_I2C_SCL_PIN, kPORT_MuxAsGpio);

    /* PORTE25 (pin 32) is configured as PTE25 */
    PORT_SetPinMux(BOARD_ACCEL_I2C_SDA_PORT, BOARD_ACCEL_I2C_SDA_PIN, kPORT_MuxAsGpio);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
