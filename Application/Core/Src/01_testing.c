/**
  ******************************************************************************
  * @Program            : Testing All Pins
  * @create            	: 1 Februari 2022
  ******************************************************************************
  * - Log	: 1 Februari 2022
  * 			a) Configure ST-link
  * 			   - Awalnya dicoba pake mikroe-2, --> data read error --> Cube programmer (RDP set to AA)  --> bisa
  * 			   - Di jajal pake mikroe-1 sama --> dan bisa.
  * 			   - Update stlink FW ga bisa, tapi bisa udh buat upload & debug
  * 			b) Testing all pins
  * 			   - All worked dude!!!
  *
  ******************************************************************************
  */
#include "main.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);


int main(void)
{

  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();

  while (1)
  {
	  // -------- Block selatan all fine (dari USB)-----------
	  /* HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1); //1
	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0); //2
	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13); //3
	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5); //4 -- redup? = change resistor
	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_4); //5
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9); //6
	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_8); //7
	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9); //8
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8); //9
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_2); //10
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_1); //11
	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12); //12 -- redup? = SPI1-ss
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_0); //13
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3); //14 -- redup? = 47K - change resistor
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2); //15
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1); //16 -- redup? = 17K - change resistor
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0); //17 */

	  // -------- Block utara all fine (dari USB)-----------
	  /*	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	  	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6); //1
	  	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7); //2
	  	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); //3
	  	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4); //4
	  	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_14); //5
	  	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_13); //6
	  	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_4); //7
	  	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_5); //8
	  	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_15); //9
	  	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3); //10
	  	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10); //11
	  	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_11); //12
	  	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7); //13
	  	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_6); //14
	  	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_15); //15
	  	  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14); //16
	  	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_11); //17
	  	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_10); //18 */

  }

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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2
                          |GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_8, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_13|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 PC0 PC1 PC2
                           PC9 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2
                          |GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA8 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB13 PB4
                           PB5 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_13|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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

