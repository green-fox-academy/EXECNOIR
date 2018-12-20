#include "stm32f7xx_hal.h"
#include "stm32746g_discovery.h"
#include <string.h>
#include "stm32f7xx_hal_rng.h"

#define LCD_FRAME_BUFFER SDRAM_DEVICE_ADDR
#define RGB565_BYTE_PER_PIXEL 4
#define ARBG8888_BYTE_PER_PIXEL 2
#define UART_PUTCHAR int __io_putchar(int ch)

static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

GPIO_InitTypeDef led1;
GPIO_InitTypeDef led2;
GPIO_InitTypeDef led3;
GPIO_InitTypeDef button;
GPIO_InitTypeDef button2;
UART_HandleTypeDef uart_handle;
RNG_HandleTypeDef random;

typedef enum state {
	WELCOME, WAITING, GAME, RESULT, RESULT2, END,
} state_t;

int main(void) {

	/* Configure the MPU attributes as Write Through */
	MPU_Config();

	/* Enable the CPU Cache */
	CPU_CACHE_Enable();

	HAL_Init();

	/* Configure the System clock to have a frequency of 216 MHz */
	SystemClock_Config();

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();

	led1.Pin = GPIO_PIN_0;
	led1.Mode = GPIO_MODE_OUTPUT_PP;
	led1.Pull = GPIO_PULLDOWN;
	led1.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOA, &led1);

	led2.Pin = GPIO_PIN_9;
	led2.Mode = GPIO_MODE_OUTPUT_PP;
	led2.Pull = GPIO_PULLDOWN;
	led2.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &led2);

	led3.Pin = GPIO_PIN_7;
	led3.Mode = GPIO_MODE_OUTPUT_PP;
	led3.Pull = GPIO_PULLDOWN;
	led3.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &led3);

	button2.Pin = GPIO_PIN_8;
	button2.Mode = GPIO_MODE_INPUT;
	button2.Pull = GPIO_PULLDOWN;
	button2.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &button2);

	button.Pin = GPIO_PIN_10;
	button.Mode = GPIO_MODE_INPUT;
	button.Pull = GPIO_PULLDOWN;
	button.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &button);

	__HAL_RCC_USART1_CLK_ENABLE()
	;
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);

	__HAL_RCC_RNG_CLK_ENABLE()
	;
	random.Instance = RNG;
	HAL_RNG_Init(&random);

	state_t gamestate = WELCOME;

	int start_time = 0;
	int end_time = 0;
	int gameres = 0;
	int readyplayer1 = 0;
	int player1score = 0;
	int player2score = 0;
	int readyplayer2 = 0;
	int roundcounter = 1;
	printf("Welcome to the Reaction Tester Game\r\n");
	printf("The game starts when both players pressed their buttons!\r\n");
	while (1) {
		switch (gamestate) {
		case WELCOME:
			if (HAL_GetTick() % 500 == 0) {
				HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_7);
				HAL_Delay(1);
			}

			if (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_8)) {
				readyplayer1 = 1;
				HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
				printf("Player 1 is ready!\r\n");
				HAL_Delay(300);
			}
			if (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_10)) {
				readyplayer2 = 1;
				printf("Player 2 is ready!\r\n");
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
				HAL_Delay(300);
			}
			if(readyplayer1 == 1 && readyplayer2 == 1){
				gamestate = WAITING;
				break;
			}
			break;
		case WAITING:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
			printf(
					"The game will start in a few seconds! The first player to press their button after the led is lit wins!\n");
			uint32_t randomnumber;
			HAL_RNG_GenerateRandomNumber(&random, &randomnumber);
			HAL_Delay(randomnumber % 10000 + 1);
			gamestate = GAME;
			break;
		case GAME:
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
			if (start_time == 0) {
				start_time = HAL_GetTick();
			}
			if (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_10)) {
				end_time = HAL_GetTick();
				gamestate = RESULT2;
			}
			if (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_8)) {
				end_time = HAL_GetTick();
				gamestate = RESULT;
			}
			break;
		case RESULT:
			player1score++;
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
			gameres = end_time - start_time;
			printf("Player 1 wins! Your reaction time is %d milliseconds\r\n", gameres);
			printf("The score is: Player 1 - %d, Player 2 - %d\r\n", player1score, player2score);
			printf("The game will restart in a few seconds!\r\n");
			HAL_Delay(1000);
			gamestate = END;
			break;
		case RESULT2:
			player2score++;
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
			gameres = end_time - start_time;
			printf("Player 2 wins! Your reaction time is %d milliseconds\r\n", gameres);
			printf("The score is: Player 1 - %d, Player 2 - %d\r\n", player1score, player2score);
			printf("The game will restart in a few seconds!\r\n");
			HAL_Delay(5000);
			gamestate = END;
			break;
		case END:
			start_time = 0;
			end_time = 0;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
			roundcounter++;
			readyplayer1 = 0;
			readyplayer2 = 0;
			HAL_Delay(2000);
			printf("Time for round %d!\r\n", roundcounter);
			printf("The game starts when both players pressed their buttons!\r\n");
			gamestate = WELCOME;
			break;
		}
	}
}
UART_PUTCHAR {
	HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}
static void SystemClock_Config(void) {
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 25;
	RCC_OscInitStruct.PLL.PLLN = 432;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/* activate the OverDrive to reach the 216 Mhz Frequency */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void) {
	/* User may add here some code to deal with this error */
	while (1) {
	}
}

/**
 * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
 * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
 *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
 * @param  None
 * @retval None
 */
static void MPU_Config(void) {
	MPU_Region_InitTypeDef MPU_InitStruct;

	/* Disable the MPU */
	HAL_MPU_Disable();

	/* Configure the MPU attributes as WT for SRAM */
	MPU_InitStruct.Enable = MPU_REGION_ENABLE;
	MPU_InitStruct.BaseAddress = 0x20010000;
	MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
	MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
	MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
	MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
	MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
	MPU_InitStruct.Number = MPU_REGION_NUMBER0;
	MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
	MPU_InitStruct.SubRegionDisable = 0x00;
	MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

	HAL_MPU_ConfigRegion(&MPU_InitStruct);

	/* Enable the MPU */
	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
 * @brief  CPU L1-Cache enable.
 * @param  None
 * @retval None
 */
static void CPU_CACHE_Enable(void) {
	/* Enable I-Cache */
	SCB_EnableICache();

	/* Enable D-Cache */
	SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
