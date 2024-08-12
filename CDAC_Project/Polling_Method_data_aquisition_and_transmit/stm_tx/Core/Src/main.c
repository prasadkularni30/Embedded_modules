/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * Authors: Prasad Kulkarni,Onkar chougule, Lalit Deshpande,Karan Solanki
  * CDAC ACTS,pune DESD(march 2024)
  * @file           : main.c
  * @brief          : Transmitting ultrasonic data to another node via CAN
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define TRIG_PORT_FRONT  GPIOA
#define TRIG_PIN_FRONT   GPIO_PIN_0
#define ECHO_PIN_FRONT   GPIO_PIN_1
#define TRIG_PORT_REAR	 GPIOD
#define TRIG_PIN_REAR    GPIO_PIN_12
#define ECHO_PIN_REAR  	 GPIO_PIN_13

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan2;
TIM_HandleTypeDef htim2;
/* USER CODE BEGIN PV */
uint8_t distance_message[8];
float distance_front;
float distance_rear;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN2_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN2_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
float getDistance(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_Pin_Trigger, uint16_t GPIO_Pin_Echo);
void CAN_Filter_Config(void);
void CAN2_Tx(float,float);
void Error_Handler(void);
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */

	HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CAN2_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  CAN_Filter_Config();

  if (HAL_CAN_Start(&hcan2) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_TIM_Base_Start(&htim2);  // Start the timer

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  /* receiving front distance from ultrasonic sensor */
	  distance_front = getDistance(TRIG_PORT_FRONT,TRIG_PIN_FRONT,ECHO_PIN_FRONT);
	  /* for optimization , cm conversion dividing it with 2*/
	  distance_front = distance_front/2;

	  /* receiving rear distance from ultrasonic sensor */
	  distance_rear = getDistance(TRIG_PORT_REAR,TRIG_PIN_REAR,ECHO_PIN_REAR);
	  /* for optimization , cm conversion dividing it with 2*/
	  distance_rear = distance_rear/2;

	  /* transmitting front and rear distance to can for transmission*/
	  CAN2_Tx(distance_front,distance_rear);
	  HAL_Delay(500);
	  /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CAN2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN2_Init(void)
{

  /* USER CODE BEGIN CAN2_Init 0 */

  /* USER CODE END CAN2_Init 0 */

  /* USER CODE BEGIN CAN2_Init 1 */

  /* USER CODE END CAN2_Init 1 */
  hcan2.Instance = CAN2;
  hcan2.Init.Prescaler = 24;
  hcan2.Init.Mode = CAN_MODE_NORMAL;
  hcan2.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan2.Init.TimeSeg1 = CAN_BS1_13TQ;
  hcan2.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan2.Init.TimeTriggeredMode = DISABLE;
  hcan2.Init.AutoBusOff = DISABLE;
  hcan2.Init.AutoWakeUp = DISABLE;
  hcan2.Init.AutoRetransmission = DISABLE;
  hcan2.Init.ReceiveFifoLocked = DISABLE;
  hcan2.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN2_Init 2 */

  /* USER CODE END CAN2_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 83;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA1 */
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PD12 */
  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PD13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */



/**
  * @brief This function configures the CAN filter
  * @retval None
  */
void CAN_Filter_Config(void)
{
  CAN_FilterTypeDef can2_filter_init;

  can2_filter_init.FilterActivation = ENABLE;
  can2_filter_init.FilterBank = 0;
  can2_filter_init.FilterFIFOAssignment = CAN_RX_FIFO0;
  can2_filter_init.FilterIdHigh = 0x65D << 5; // Standard ID shifted to 11 bits
  can2_filter_init.FilterIdLow = 0x0000;
  can2_filter_init.FilterMaskIdHigh = 0xFFFF;
  can2_filter_init.FilterMaskIdLow = 0x0000;
  can2_filter_init.FilterMode = CAN_FILTERMODE_IDMASK;
  can2_filter_init.FilterScale = CAN_FILTERSCALE_32BIT;

  if (HAL_CAN_ConfigFilter(&hcan2, &can2_filter_init) != HAL_OK)
  {
    Error_Handler();
  }
}


/**
  * @brief This function sends a CAN message with the distance data
  * @param distance: The distance value to send
  *
  */
void CAN2_Tx(float f_distance,float r_distance)
{
  CAN_TxHeaderTypeDef TxHeader;
  uint32_t TxMailbox;

  /* here we are sending front and rear distance in one single array
   * where first half of array will contain front ultrasonic distance value
   * and second half of array will contain rear ultrasonic distance value*/
  memcpy(&distance_message[0],&f_distance,sizeof(float));
  memcpy(&distance_message[4],&r_distance,sizeof(float));


  TxHeader.DLC = 8;							/* The Data Length Code specifies the length
  	  	  	  	  	  	  	  	  	  	  	 *of the data in the CAN frame */

  TxHeader.StdId = 0x65D; 					/*The Standard Identifier is the unique address used
   	   	   	   	   	   	   	   	   	   	   	 *to identify the CAN message. It’s used for arbitration on
   	   	   	   	   	   	   	   	   	   	   	 *to the CAN bus.*/

  TxHeader.IDE = CAN_ID_STD;				/* The Identifier Extension bit determines whether the CAN message
  	  	  	  	  	  	  	  	  	  	  	 * uses a standard 11-bit identifier (CAN_ID_STD)
  	  	  	  	  	  	  	  	  	  	  	 * or an extended 29-bit identifier (CAN_ID_EXT)*/

  TxHeader.RTR = CAN_RTR_DATA;				/*RTR: Stands for Remote Transmission Request.
   	   	   	   	   	   	   	   	   	   	   	 *CAN_RTR_DATA indicates that the message is a data frame,
   	   	   	   	   	   	   	   	   	   	   	 *CAN_RTR_DATA meaning it contains actual data to be sent*/

  TxHeader.TransmitGlobalTime = DISABLE;	/* This option allows you to include a global timestamp in the CAN frame,
   	   	   	   	   	   	   	   	   	   	   	 * which could be used for synchronization purposes.*/

  /* transmitting the message */
  if (HAL_CAN_AddTxMessage(&hcan2, &TxHeader, distance_message, &TxMailbox) != HAL_OK)
  {
    Error_Handler();
  }

  while (HAL_CAN_IsTxMessagePending(&hcan2, TxMailbox)); // Wait until transmission is complete
}



/**
  * @brief This function gets the distance from the ultrasonic sensor
  * @retval Distance in cm
  */
float getDistance(GPIO_TypeDef *GPIO_PORT, uint16_t GPIO_Pin_Trigger, uint16_t GPIO_Pin_Echo)
{
  float local_time = 0;
  HAL_GPIO_WritePin(GPIO_PORT, GPIO_Pin_Trigger, GPIO_PIN_SET); 	 /* Pull the TRIG pin HIGH 			*/
  HAL_Delay(1);  													 /* Wait for 1 ms 					*/
  HAL_GPIO_WritePin(GPIO_PORT, GPIO_Pin_Trigger, GPIO_PIN_RESET);    /* Pull the TRIG pin low			*/

  while (!(HAL_GPIO_ReadPin(GPIO_PORT, GPIO_Pin_Echo))); 			 /* Wait for the ECHO pin to go high*/

  __HAL_TIM_SET_COUNTER(&htim2, 0); 								 /* Clear the timer counter			*/

  while (HAL_GPIO_ReadPin(GPIO_PORT, GPIO_Pin_Echo));  				 /* Wait for the ECHO pin to go low */

  local_time = __HAL_TIM_GET_COUNTER(&htim2);  						 /* Read the timer counter			*/

  return local_time * 0.34 / 2;  									 /* Convert to distance in cm 		*/

}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
