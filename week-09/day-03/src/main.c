#include "stm32f7xx_hal.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include <string.h>

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
GPIO_InitTypeDef led4;
UART_HandleTypeDef uart_handle;

int main(void) {

	/* Configure the MPU attributes as Write Through */
	MPU_Config();

	/* Enable the CPU Cache */
	CPU_CACHE_Enable();

	HAL_Init();

	/* Configure the System clock to have a frequency of 216 MHz */
	SystemClock_Config();
	BSP_LED_Init(LED1);
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FRAME_BUFFER);
	BSP_LCD_SetLayerVisible(LTDC_ACTIVE_LAYER, ENABLE);
	BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
	BSP_LCD_Clear(LCD_COLOR_BLACK);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DisplayOn();
	char text[500];
	sprintf(text, "Hello~!");
	BSP_LCD_DisplayStringAtLine(0, (uint8_t *) text);

	__HAL_RCC_USART1_CLK_ENABLE();
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);

	char hello[100] = "Hello~\r\n";
	HAL_StatusTypeDef status = HAL_UART_Transmit(&uart_handle, (uint8_t*) hello, strlen(hello), 0xFFFF);
	char buffer[100];
	char c[1];
	int led = 0;

	while (1) {
		c[0] = '\0';
		for(int i = 0; i < strlen(buffer); i++){
		      buffer[i] = ' ';
		}
		int cnt = 0;
		do
		{
		    HAL_UART_Receive(&uart_handle, (uint8_t*)c, 1, 20000);
		    if(c[0] != '\n'){
		    buffer[cnt] = c[0];
		    buffer[cnt+1] = '\0';
		    cnt++;}
		    else if(c[0] == '\n'){
		    	break;
		    }
		}while(1);
		if(strcmp("on", buffer) == 0){
			BSP_LCD_Clear(LCD_COLOR_BLACK);
			BSP_LCD_DisplayStringAtLine(0, (uint8_t *) "Green LED ON!");
			BSP_LED_On(LED1);
		}else if(strcmp("off", buffer) == 0){
			BSP_LCD_Clear(LCD_COLOR_BLACK);
			BSP_LCD_DisplayStringAtLine(0, (uint8_t *) "Green LED OFF!");
			BSP_LED_Off(LED1);
		}else{
			BSP_LCD_Clear(LCD_COLOR_BLACK);
			sprintf(text, buffer);
			BSP_LCD_DisplayStringAtLine(0, (uint8_t *) text);
		}

		printf("%s\r\n", buffer);
		HAL_Delay(500);
	}

}
UART_PUTCHAR
{
    HAL_UART_Transmit(&uart_handle, (uint8_t*)&ch, 1, 0xFFFF);
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
