/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "SEGGER_SYSVIEW.h"
#include "Disc_F407.h"
#define mutex
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart4;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_UART4_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
// some common variables to use for each task
// 128 * 4 = 512 bytes
//(recommended min stack size per task)

#define STACK_SIZE 128

void TaskA( void * argument);
void TaskB( void* argumet );
void TaskC( void* argumet );


//create storage for a pointer to a mutex (this is the same container as a semaphore)
SemaphoreHandle_t mutexPtr = NULL;
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
  MX_UART4_Init();
  /* USER CODE BEGIN 2 */
	SEGGER_SYSVIEW_Conf();
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);	//ensure proper priority grouping for freeRTOS

	//create a mutex - note this is just a special case of a binary semaphore
	/*mutexes are simply binary semaphores with one (very important) difference: priority inheritance. In the previous example, we saw the highest-priority task waiting on two lower-priority tasks to complete, which caused a priority inversion. Mutexes address this issue with something called priority inheritance.
	When a higher-priority task attempts to take a mutex and is blocked, the scheduler will elevate the priority of the task that holds the mutex to the same level as the blocked task. This guarantees that the high-priority task will acquire the mutex and run as soon as possible.

	There are only two significant differences in this example:
	1. We'll use xSemaphoreCreateMutex() instead of xSemaphoreCreateBinarySemaphore().
	2. No initial xSemaphoreGive() call is required since the mutex will be initialized with a value of 1. Mutexes are designed to be taken only when needed and then given back.
	*/
	//initializing mutex
	mutexPtr = xSemaphoreCreateMutex();
	assert_param(mutexPtr != NULL);

	//creating tasks
	assert_param(xTaskCreate(TaskA, "TaskA", STACK_SIZE, NULL, tskIDLE_PRIORITY +2, NULL) == pdPASS);
	assert_param(xTaskCreate(TaskB, "TaskB", STACK_SIZE, NULL, tskIDLE_PRIORITY  , NULL) == pdPASS);
//	assert_param(xTaskCreate(TaskC, "TaskC", STACK_SIZE, NULL, tskIDLE_PRIORITY , NULL) == pdPASS);

	//start the scheduler - shouldn't return unless there's a problem
	vTaskStartScheduler();

	//if you've wound up here, there is likely an issue with overrunning the freeRTOS heap
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
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
  * @brief UART4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */

  /* USER CODE END UART4_Init 1 */
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 115200;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART4_Init 2 */

  /* USER CODE END UART4_Init 2 */

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
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PD12 PD13 PD14 PD15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

//task A with low priority
void TaskA( void* argument )
{
	char msg[]="Hello From Task 1 !\n\r";
	while(1)
	{
#ifdef mutex
		SEGGER_SYSVIEW_PrintfHost("attempt to take mutex");
		//mutex lock
		if(xSemaphoreTake(mutexPtr, 200/portTICK_PERIOD_MS) == pdPASS)
		{
#endif
			SEGGER_SYSVIEW_PrintfHost("mutex taken by Task A");
			RedLed.Off();
			//transmitting message via UART
			HAL_UART_Transmit(&huart4,(const uint8_t *) &msg, strlen(msg), 10);
			BlueLed.On();
#ifdef mutex
			//mutex unlock
			xSemaphoreGive(mutexPtr);
#endif
			vTaskDelay(500/portTICK_PERIOD_MS);
			BlueLed.Off();
			vTaskDelay(500/portTICK_PERIOD_MS);
#ifdef mutex
		}
		else
		{
			SEGGER_SYSVIEW_PrintfHost("FAILED to take "
			                           "mutex in time");
			RedLed.On();

		}
#endif
	}
}


void TaskB( void* argument )
{
	char msg[]="Hello From Task 2 !\n\r";
	while(1)
	{
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)==1)
		{
#ifdef mutex
			//mutex lock
			if(xSemaphoreTake(mutexPtr, 200/portTICK_PERIOD_MS) == pdPASS)
			{
#endif
					SEGGER_SYSVIEW_PrintfHost("mutex taken by task 2");
					GreenLed.On();
					RedLed.Off();
					//transmitting via UART
					HAL_UART_Transmit(&huart4,(const uint8_t *) &msg, strlen(msg), 10);
#ifdef mutex
					//mutex unlock
					xSemaphoreGive(mutexPtr);
			}
			else
			{
				SEGGER_SYSVIEW_PrintfHost("task 2 FAILED to take mutex in time");
				RedLed.On();
			}
			vTaskDelay(1000/portTICK_PERIOD_MS);
		}
#endif
#ifndef mutex
		}
		vTaskDelay(1000/portTICK_PERIOD_MS);
#endif

		GreenLed.Off();
	//	vTaskDelay(500/portTICK_PERIOD_MS);
	}
}

void TaskC( void* argument )
{
	char msg[]="Hello From Task 3 !\n\r";
	while(1)
	{
		SEGGER_SYSVIEW_PrintfHost("attempt to take mutex");
		//mutex lock
		if(xSemaphoreTake(mutexPtr, 200/portTICK_PERIOD_MS) == pdPASS)
		{
			SEGGER_SYSVIEW_PrintfHost("mutex taken");
			RedLed.Off();
			OrangeLed.On();
			//Transmit via UART
			HAL_UART_Transmit(&huart4,(const uint8_t *) &msg, strlen(msg), 10);
			//mutex unlock
			xSemaphoreGive(mutexPtr);
			vTaskDelay(750/portTICK_PERIOD_MS);
			OrangeLed.Off();
			vTaskDelay(750/portTICK_PERIOD_MS);

		}
		else
		{

			SEGGER_SYSVIEW_PrintfHost("FAILED to take "
			                           "mutex in time");
			RedLed.On();

		}

	}
}


/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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
	SEGGER_SYSVIEW_PrintfHost("Assertion Failed:file %s on line %d\r\n", file, line);
	while(1);
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
