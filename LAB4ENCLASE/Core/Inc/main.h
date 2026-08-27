/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_J2_2_Pin GPIO_PIN_0
#define LED_J2_2_GPIO_Port GPIOC
#define LED_J2_1_Pin GPIO_PIN_1
#define LED_J2_1_GPIO_Port GPIOC
#define LED_J1_1_Pin GPIO_PIN_0
#define LED_J1_1_GPIO_Port GPIOA
#define LED_J1_2_Pin GPIO_PIN_1
#define LED_J1_2_GPIO_Port GPIOA
#define LED_J1_3_Pin GPIO_PIN_4
#define LED_J1_3_GPIO_Port GPIOA
#define botonInicio_Pin GPIO_PIN_5
#define botonInicio_GPIO_Port GPIOA
#define botonInicio_EXTI_IRQn EXTI9_5_IRQn
#define botonj2_Pin GPIO_PIN_7
#define botonj2_GPIO_Port GPIOA
#define botonj2_EXTI_IRQn EXTI9_5_IRQn
#define LED_J1_4_Pin GPIO_PIN_0
#define LED_J1_4_GPIO_Port GPIOB
#define SEG_E_Pin GPIO_PIN_10
#define SEG_E_GPIO_Port GPIOB
#define SEG_F_Pin GPIO_PIN_8
#define SEG_F_GPIO_Port GPIOA
#define SEG_G_Pin GPIO_PIN_9
#define SEG_G_GPIO_Port GPIOA
#define SEG_A_Pin GPIO_PIN_10
#define SEG_A_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SEG_B_Pin GPIO_PIN_3
#define SEG_B_GPIO_Port GPIOB
#define SEG_D_Pin GPIO_PIN_4
#define SEG_D_GPIO_Port GPIOB
#define SEG_C_Pin GPIO_PIN_5
#define SEG_C_GPIO_Port GPIOB
#define botonj1_Pin GPIO_PIN_6
#define botonj1_GPIO_Port GPIOB
#define botonj1_EXTI_IRQn EXTI9_5_IRQn
#define LED_J2_4_Pin GPIO_PIN_8
#define LED_J2_4_GPIO_Port GPIOB
#define LED_J2_3_Pin GPIO_PIN_9
#define LED_J2_3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
