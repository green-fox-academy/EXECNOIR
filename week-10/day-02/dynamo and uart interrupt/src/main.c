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
GPIO_InitTypeDef button;
GPIO_InitTypeDef button2;
GPIO_InitTypeDef led4;
GPIO_InitTypeDef led5;
UART_HandleTypeDef uart_handle;
RNG_HandleTypeDef random;
TIM_HandleTypeDef tim_handle1;
TIM_HandleTypeDef tim_handle2;
TIM_HandleTypeDef tim_handle3;
TIM_HandleTypeDef tim_handle4;

TIM_OC_InitTypeDef tim_oc;
TIM_OC_InitTypeDef tim_oc2;

char c[1];
char buffer[100];
int counter = 0;


typedef enum state {
	ENABLED, DISABLED
} state_t;

state_t gamestate = ENABLED;

typedef enum pwmstate {
	INC, DEC
} pwm_state_t;

typedef enum ledtimer {
	FLASHING, ON, OFF
} ledtimer_t;

ledtimer_t ledstate = FLASHING;

int brightness = 100;

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
	__HAL_RCC_GPIOG_CLK_ENABLE();


	led1.Pin = GPIO_PIN_0;
	led1.Mode = GPIO_MODE_OUTPUT_PP;
	led1.Pull = GPIO_PULLDOWN;
	led1.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOA, &led1);

	button.Pin = GPIO_PIN_10;
	button.Mode = GPIO_MODE_IT_RISING;
	button.Pull = GPIO_PULLDOWN;
	button.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOF, &button);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0x01, 0x00);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);





	__HAL_RCC_GPIOB_CLK_ENABLE();
	led4.Pin = GPIO_PIN_4;
	led4.Mode = GPIO_MODE_AF_PP;
	led4.Pull = GPIO_PULLDOWN;
	led4.Speed = GPIO_SPEED_HIGH;
	led4.Alternate = GPIO_AF2_TIM3;
	HAL_GPIO_Init(GPIOB, &led4);

	__HAL_RCC_GPIOI_CLK_ENABLE();
	led5.Pin = GPIO_PIN_0;
	led5.Mode = GPIO_MODE_AF_PP;
	led5.Pull = GPIO_PULLDOWN;
	led5.Speed = GPIO_SPEED_HIGH;
	led5.Alternate = GPIO_AF2_TIM5;
	HAL_GPIO_Init(GPIOI, &led5);

	__HAL_RCC_TIM3_CLK_ENABLE();
	tim_handle2.Instance               = TIM3;
	tim_handle2.Init.Period            = 100;
	tim_handle2.Init.Prescaler         = 1;
	tim_handle2.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	tim_handle2.Init.CounterMode       = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&tim_handle2);
	tim_oc.OCMode = TIM_OCMODE_PWM1;
	tim_oc.Pulse = 10;
	HAL_TIM_PWM_ConfigChannel(&tim_handle2, &tim_oc, TIM_CHANNEL_1);
	HAL_TIM_Base_Start(&tim_handle2);
	HAL_TIM_PWM_Start(&tim_handle2, TIM_CHANNEL_1);

	__HAL_RCC_TIM5_CLK_ENABLE();
	tim_handle4.Instance               = TIM5;
	tim_handle4.Init.Period            = 100;
	tim_handle4.Init.Prescaler         = 1;
	tim_handle4.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	tim_handle4.Init.CounterMode       = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&tim_handle4);
	tim_oc2.OCMode = TIM_OCMODE_PWM1;
	tim_oc2.Pulse = 10;
	HAL_TIM_PWM_ConfigChannel(&tim_handle4, &tim_oc2, TIM_CHANNEL_4);
	HAL_TIM_Base_Start(&tim_handle4);
	HAL_TIM_PWM_Start(&tim_handle4, TIM_CHANNEL_4);


	__HAL_RCC_TIM2_CLK_ENABLE();
	tim_handle1.Instance               = TIM2;
	tim_handle1.Init.Period            = 500;
	tim_handle1.Init.Prescaler         = 10800;
	tim_handle1.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	tim_handle1.Init.CounterMode       = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&tim_handle1);

	HAL_NVIC_SetPriority(TIM2_IRQn, 0x02, 0x00);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	HAL_TIM_Base_Start_IT(&tim_handle1);

	__HAL_RCC_TIM4_CLK_ENABLE();
	tim_handle3.Instance               = TIM4;
	tim_handle3.Init.Period            = 5000;
	tim_handle3.Init.Prescaler         = 10800;
	tim_handle3.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	tim_handle3.Init.CounterMode       = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&tim_handle3);
	HAL_NVIC_SetPriority(TIM4_IRQn, 0x04, 0x00);
	HAL_NVIC_EnableIRQ(TIM4_IRQn);
	HAL_TIM_Base_Start_IT(&tim_handle3);

	__HAL_RCC_USART1_CLK_ENABLE()
	;
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	HAL_NVIC_SetPriority(USART1_IRQn, 0x03, 0x00);
	HAL_NVIC_EnableIRQ(USART1_IRQn);



	BSP_COM_Init(COM1, &uart_handle);
	HAL_UART_Receive_IT(&uart_handle, c, 1);

	__HAL_RCC_RNG_CLK_ENABLE();
	random.Instance = RNG;
	HAL_RNG_Init(&random);

	int brightness2 = 100;
	int incdec = 0;

	pwm_state_t pwm_state = INC;
	printf("start\r\n");
	while (1) {
		__HAL_TIM_SET_COMPARE(&tim_handle2, TIM_CHANNEL_1, brightness);

	}
}
UART_PUTCHAR {
	HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}


void EXTI15_10_IRQHandler()
{
    HAL_GPIO_EXTI_IRQHandler(button.Pin);
}


void EXTI9_5_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(button2.Pin);
}



void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(brightness <= 100){
    	brightness += 5;
    }

}

void TIM2_IRQHandler()
{
    HAL_TIM_IRQHandler(&tim_handle1);
}

void TIM4_IRQHandler()
{
    HAL_TIM_IRQHandler(&tim_handle3);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2){
		if(brightness >= 1){
			brightness --;
		}else{
			brightness ++;
		}
	}else if(htim->Instance == TIM4){
		if(ledstate == FLASHING){
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
		}else if(ledstate == ON){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, SET);
		}else if(ledstate == OFF){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, RESET);
		}
	}
}

void USART1_IRQHandler()
{


    HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{


	if(c[0] == '\n'){
		c[0] = '\0';
		buffer[counter] = c[0];
		if(strcmp("on", buffer) == 0){
			printf("led is on\r\n");
			ledstate = ON;
			counter = 0;
			printf("buffer: %s", buffer);
		}else if(strcmp("off", buffer) == 0){
			printf("led is off\r\n");
			ledstate = OFF;
			counter = 0;
			printf("buffer: %s", buffer);
		}else if(strcmp("flashing", buffer) == 0){
			ledstate = FLASHING;
			counter = 0;
			printf("buffer: %s", buffer);
		}

	}else{
		buffer[counter] = c[0];
		counter ++;
	}

	HAL_UART_Receive_IT(&uart_handle, c, 1);
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
