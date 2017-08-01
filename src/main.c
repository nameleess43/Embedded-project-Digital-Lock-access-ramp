/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f4xx.h"
#include "stm32469i_discovery.h"
#include "stm32469i_discovery_ts.h"
#include "stm32469i_discovery_lcd.h"
#include "stm32f4xx_hal_gpio.h"

#define button_radius 50

void RampOpen();
void RampClose();
void GPIO_Init_pins();
void DrawScreen();
void SystemClock_Config_OdDisplej();
int main(void) {

	uint8_t lcd_status = LCD_OK;
	uint8_t pritisnato, enterstisnat = 0, clearstisnat = 0;
	uint8_t array_test[6];
	uint8_t k = 0;
	uint16_t i = 0, j = 0;
	uint32_t broj, time, passcheck = 0;
	GPIO_InitTypeDef GPIO_InitStruct;
	uint8_t s;
	uint8_t rampisopen = 0;
	TS_StateTypeDef TS_State = { 0 };
	uint32_t ts_status = TS_OK;
	sFONT fontot;

	SystemClock_Config_OdDisplej();

	GPIO_Init_pins();

	BSP_TS_Init(480, 800);
	//BSP_TS_ITConfig();

	lcd_status = BSP_LCD_InitEx(LCD_ORIENTATION_PORTRAIT);
	BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER_BACKGROUND,
	LCD_FB_START_ADDRESS);

	BSP_LCD_Clear(LCD_COLOR_BLACK);

	lcd_status = BSP_LCD_InitEx(LCD_ORIENTATION_PORTRAIT);

	BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER_BACKGROUND,
	LCD_FB_START_ADDRESS);
	//BSP_LCD_Clear(LCD_COLOR_WHITE);

	DrawScreen();

	while (1) {
		s = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3);
		BSP_TS_GetState(&TS_State);

		BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
		BSP_LCD_SetTextColor(LCD_COLOR_CYAN);

		if (TS_State.touchDetected && k < 6) {
			if (TS_State.touchX[0] > (120 - button_radius)
					&& TS_State.touchX[0] < (120 + button_radius)
					&& TS_State.touchY[0] > (424 - 50 - button_radius)
					&& TS_State.touchY[0] < (424 - 50 + button_radius)) //za #1
							{
				array_test[k] = 1;

				BSP_LCD_DisplayStringAt(30 + k * 20, 150, "1", LEFT_MODE);
				HAL_Delay(200);
				k++;
			} else if (TS_State.touchX[0] > (120 - button_radius)
					&& TS_State.touchX[0] < (120 + button_radius)
					&& TS_State.touchY[0] > (530 - 50 - button_radius)
					&& TS_State.touchY[0] < (530 - 50 + button_radius)) //za #2
							{
				array_test[k] = 4;
				BSP_LCD_DisplayStringAt(30 + k * 20, 150, "4", LEFT_MODE);
				HAL_Delay(200);
				k++;
			} else if (TS_State.touchX[0] > (120 - button_radius)
					&& TS_State.touchX[0] < (120 + button_radius)
					&& TS_State.touchY[0] > (636 - 50 - button_radius)
					&& TS_State.touchY[0] < (636 - 50 + button_radius)) //za #3
							{
				array_test[k] = 7;
				BSP_LCD_DisplayStringAt(30 + k * 20, 150, "7", LEFT_MODE);
				HAL_Delay(200);
				k++;
			} else if (TS_State.touchX[0] > (240 - button_radius)
					&& TS_State.touchX[0] < (240 + button_radius)
					&& TS_State.touchY[0] > (424 - 50 - button_radius)
					&& TS_State.touchY[0] < (424 - 50 + button_radius)) //za #4
							{
				array_test[k] = 2;
				BSP_LCD_DisplayStringAt(30 + k * 20, 150, "2", LEFT_MODE);
				HAL_Delay(200);
				k++;
			} else if (TS_State.touchX[0] > (240 - button_radius)
					&& TS_State.touchX[0] < (240 + button_radius)
					&& TS_State.touchY[0] > (530 - 50 - button_radius)
					&& TS_State.touchY[0] < (530 - 50 + button_radius)) //za #5
							{
				array_test[k] = 5;
				BSP_LCD_DisplayStringAt(30 + k * 20, 150, "5", LEFT_MODE);
				HAL_Delay(200);
				k++;
			} else if (TS_State.touchX[0] > (240 - button_radius)
					&& TS_State.touchX[0] < (240 + button_radius)
					&& TS_State.touchY[0] > (636 - 50 - button_radius)
					&& TS_State.touchY[0] < (636 - 50 + button_radius)) //za #6
							{
				array_test[k] = 8;
				BSP_LCD_DisplayStringAt(30 + k * 20, 150, "8", LEFT_MODE);
				HAL_Delay(200);
				k++;
			} else if (TS_State.touchX[0] > (360 - button_radius)
					&& TS_State.touchX[0] < (360 + button_radius)
					&& TS_State.touchY[0] > (424 - 50 - button_radius)
					&& TS_State.touchY[0] < (424 - 50 + button_radius)) //za #7
							{
				array_test[k] = 3;
				BSP_LCD_DisplayStringAt(30 + k * 20, 150, "3", LEFT_MODE);
				HAL_Delay(200);
				k++;
			} else if (TS_State.touchX[0] > (360 - button_radius)
					&& TS_State.touchX[0] < (360 + button_radius)
					&& TS_State.touchY[0] > (530 - 50 - button_radius)
					&& TS_State.touchY[0] < (530 - 50 + button_radius)) //za #8
							{
				array_test[k] = 6;
				BSP_LCD_DisplayStringAt(30 + k * 20, 150, "6", LEFT_MODE);
				HAL_Delay(200);
				k++;
			} else if (TS_State.touchX[0] > (360 - button_radius)
					&& TS_State.touchX[0] < (360 + button_radius)
					&& TS_State.touchY[0] > (636 - 50 - button_radius)
					&& TS_State.touchY[0] < (636 - 50 + button_radius)) //za #9
							{
				array_test[k] = 9;
				BSP_LCD_DisplayStringAt(30 + k * 20, 150, "9", LEFT_MODE);
				HAL_Delay(200);
				k++;

			} else if (TS_State.touchX[0] > (240 - button_radius)
					&& TS_State.touchX[0] < (240 + button_radius)
					&& TS_State.touchY[0] > (742 - 50 - button_radius)
					&& TS_State.touchY[0] < (742 - 50 + button_radius)) //za #0
							{
				array_test[k] = 0;
				BSP_LCD_DisplayStringAt(30 + k * 20, 150, "0", LEFT_MODE);
				HAL_Delay(200);
				k++;
			}
		}

		if (TS_State.touchDetected) {
			if (TS_State.touchX[0] > (360 - button_radius)
					&& TS_State.touchX[0] < (360 + button_radius)
					&& TS_State.touchY[0] > (742 - 50 - button_radius)
					&& TS_State.touchY[0] < (742 - 50 + button_radius)) //za #enter
							{
				enterstisnat = 1;
				BSP_LCD_DisplayStringAt(0, 200, " enter ", CENTER_MODE);
				HAL_Delay(300);
				BSP_LCD_Clear(LCD_COLOR_BLACK);
				DrawScreen();
			} else if (TS_State.touchX[0] > (120 - button_radius)
					&& TS_State.touchX[0] < (120 + button_radius)
					&& TS_State.touchY[0] > (742 - 50 - button_radius)
					&& TS_State.touchY[0] < (742 - 50 + button_radius)) //za #clear
							{
				for (i = 0; i < 6; i++) {
					array_test[i] = 0;
				}
				k = 0;
				BSP_LCD_DisplayStringAt(0, 200, " clear ", CENTER_MODE);
				clearstisnat = 1;

				HAL_Delay(300);
				BSP_LCD_Clear(LCD_COLOR_BLACK);
				DrawScreen();
				//				if (TS_State.touchDetected) {
				//					HAL_Delay(500);
				//					k++;
			}
		}

		if ((s == 1) && (rampisopen != 0) && (time + 3000 < HAL_GetTick())) {
			RampClose();
			rampisopen = 0;

		}
		if (passcheck == 123456) {

			if ((s == 0) && (rampisopen == 0)) {
				RampOpen();
				rampisopen = 1;
				time = HAL_GetTick();
				passcheck = 0;

			}
			BSP_LCD_Clear(LCD_COLOR_BLACK);
			DrawScreen();
		}
		if (enterstisnat) {

			for (broj = 0; broj < 6; broj++) {
				passcheck = 10 * passcheck + array_test[broj];
				array_test[broj] = 0;
			}
			k = 0;
			if (passcheck != 123456) {

				BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
				BSP_LCD_SetTextColor(LCD_COLOR_CYAN);
				BSP_LCD_DisplayStringAt(5, 250, "password invalid",
						CENTER_MODE);
				HAL_Delay(100);
				BSP_LCD_Clear(LCD_COLOR_BLACK);
				DrawScreen();
				passcheck=0;
			}
			enterstisnat = 0;
			//HAL_Delay(1500);
		}
		if (clearstisnat) {
			for (broj = 0; broj < 6; broj++) {
				array_test[broj] = 0;
				k = 0;
			}
			clearstisnat = 0;
			passcheck=0;
		}
	}

}
void GPIO_Init_pins() {
	GPIO_InitTypeDef GPIO_InitStruct;
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Pin = GPIO_PIN_1;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	__HAL_RCC_GPIOC_CLK_ENABLE()
	;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Pin = GPIO_PIN_2;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void DrawScreen() {

	uint8_t i = 0, j = 0;
	char* text = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'C', '0', 'E' };
	for (i = 1; i <= 3; i++) {
		for (j = 4; j < 8; j++) {

			BSP_LCD_SetTextColor(LCD_COLOR_CYAN);
			BSP_LCD_FillCircle(i * 120, (j * 106) - 50, button_radius);

			BSP_LCD_SetFont(&Font24);
			BSP_LCD_SetBackColor(LCD_COLOR_CYAN);
			BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
			BSP_LCD_DisplayChar((i * 120) - 6, (j * 106) - 50 - 6,
					(text + (j - 4) * 3 + i - 1));
		}

		BSP_LCD_DisplayChar(120 - 6, 742 - 6 - 50, 'C');
		BSP_LCD_DisplayChar(240 - 6, 742 - 6 - 50, '0');
		BSP_LCD_DisplayChar(360 - 6, 742 - 6 - 50, 'E');
	}
}
void RampOpen() {
	int i;
	for (i = 0; i < 7; i++) {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
		HAL_Delay(200);
	}

}
void RampClose() {
	int i;
	for (i = 0; i < 7; i++) {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
		HAL_Delay(200);
	}
}

void SystemClock_Config_OdDisplej(void) {
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;
	HAL_StatusTypeDef ret = HAL_OK;

	/* Enable Power Control clock */
	__HAL_RCC_PWR_CLK_ENABLE()
	;

	/* The voltage scaling allows optimizing the power consumption when the device is
	 clocked below the maximum system frequency, to update the voltage scaling value
	 regarding system frequency refer to product datasheet.  */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
#if defined(USE_STM32469I_DISCO_REVA)
	RCC_OscInitStruct.PLL.PLLM = 25;
#else
	RCC_OscInitStruct.PLL.PLLM = 8;
#endif /* USE_STM32469I_DISCO_REVA */
	RCC_OscInitStruct.PLL.PLLN = 360;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	RCC_OscInitStruct.PLL.PLLR = 6;

	ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
	if (ret != HAL_OK) {
		while (1) {
			;
		}
	}

	/* Activate the OverDrive to reach the 180 MHz Frequency */
	ret = HAL_PWREx_EnableOverDrive();
	if (ret != HAL_OK) {
		while (1) {
			;
		}
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
	if (ret != HAL_OK) {
		while (1) {
			;
		}
	}
}

