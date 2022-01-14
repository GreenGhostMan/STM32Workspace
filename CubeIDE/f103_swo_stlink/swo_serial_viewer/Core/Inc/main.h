/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ultrasound1_Pin GPIO_PIN_14
#define ultrasound1_GPIO_Port GPIOC
#define ultrasound1C15_Pin GPIO_PIN_15
#define ultrasound1C15_GPIO_Port GPIOC
#define ultrasound2_Pin GPIO_PIN_0
#define ultrasound2_GPIO_Port GPIOC
#define ultrasound2C1_Pin GPIO_PIN_1
#define ultrasound2C1_GPIO_Port GPIOC
#define ultrasound3_Pin GPIO_PIN_2
#define ultrasound3_GPIO_Port GPIOC
#define ultrasound3C3_Pin GPIO_PIN_3
#define ultrasound3C3_GPIO_Port GPIOC
#define TIM5_CH1_motorC_enc1_Pin GPIO_PIN_0
#define TIM5_CH1_motorC_enc1_GPIO_Port GPIOA
#define TIM5_CH2_motorC_enc2_Pin GPIO_PIN_1
#define TIM5_CH2_motorC_enc2_GPIO_Port GPIOA
#define TIM2_CH3_motorD_enc1_Pin GPIO_PIN_2
#define TIM2_CH3_motorD_enc1_GPIO_Port GPIOA
#define TIM2_CH4_motorD_enc2_Pin GPIO_PIN_3
#define TIM2_CH4_motorD_enc2_GPIO_Port GPIOA
#define TIM3_CH1_motorA_ENC1_Pin GPIO_PIN_6
#define TIM3_CH1_motorA_ENC1_GPIO_Port GPIOA
#define TIM3_CH2_motorA_ENC2_Pin GPIO_PIN_7
#define TIM3_CH2_motorA_ENC2_GPIO_Port GPIOA
#define AIN2_Pin GPIO_PIN_4
#define AIN2_GPIO_Port GPIOC
#define AIN1_Pin GPIO_PIN_5
#define AIN1_GPIO_Port GPIOC
#define BIN1_Pin GPIO_PIN_0
#define BIN1_GPIO_Port GPIOB
#define BIN2_Pin GPIO_PIN_1
#define BIN2_GPIO_Port GPIOB
#define MOTORA_PWM_Pin GPIO_PIN_6
#define MOTORA_PWM_GPIO_Port GPIOC
#define MOTORC_PWM_Pin GPIO_PIN_7
#define MOTORC_PWM_GPIO_Port GPIOC
#define MOTORD_PWM_Pin GPIO_PIN_8
#define MOTORD_PWM_GPIO_Port GPIOC
#define MOTORB_PWM_Pin GPIO_PIN_9
#define MOTORB_PWM_GPIO_Port GPIOC
#define usart1_tx_for_microusb_Pin GPIO_PIN_9
#define usart1_tx_for_microusb_GPIO_Port GPIOA
#define usart1_rx_for_microusb_Pin GPIO_PIN_10
#define usart1_rx_for_microusb_GPIO_Port GPIOA
#define AIN2A12_Pin GPIO_PIN_12
#define AIN2A12_GPIO_Port GPIOA
#define AIN1D2_Pin GPIO_PIN_2
#define AIN1D2_GPIO_Port GPIOD
#define BIN1B4_Pin GPIO_PIN_4
#define BIN1B4_GPIO_Port GPIOB
#define BIN2B5_Pin GPIO_PIN_5
#define BIN2B5_GPIO_Port GPIOB
#define TIM4_CH1_motorB_ENC1_Pin GPIO_PIN_6
#define TIM4_CH1_motorB_ENC1_GPIO_Port GPIOB
#define TIM4_CH2_motorB_ENC2_Pin GPIO_PIN_7
#define TIM4_CH2_motorB_ENC2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
