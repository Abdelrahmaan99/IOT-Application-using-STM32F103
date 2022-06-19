/*
 * main.c
 *
 *  Created on: Aug 30, 2021
 *      Author: Abdelrahman
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "UART_interface.h"

#include "ESP_interface.h"



void main()
{
	u8 Local_u8Data = 0;
	/* Initialize RCC 8Mhz */
	RCC_voidInitSysClock();

	/* Enable GPIOB To set TX*/
	RCC_voidEnableClock(RCC_APB2 , 3);

	/* Enable USART3 */
	RCC_voidEnableClock(RCC_APB1 , 18);

	/* Enable Systick */
	MSTK_voidInit();


	/* B10 = TX out 50MHz*/
	MGPIO_voidSetPinDirection(GPIOB , PIN10 , OUTPUT_SPEED_50MHZ_AFPP);

	/* B11 = RX input Floating */
	MGPIO_voidSetPinDirection(GPIOB , PIN11 , INPUT_FLOATING);

	/* Initialize USART BaudRate = 115200 */
	MUSART3_voidInit();

	/*Set pin0 as output*/
	MGPIO_voidSetPinDirection(GPIOA , PIN0 , OUTPUT_SPEED_50MHZ_PP);

	MGPIO_voidSetPinDirection(GPIOA , PIN1 , OUTPUT_SPEED_50MHZ_PP);

	/*Intialize wifi*/
	ESP_voidInit();
	ESP_VoidConnectToWiFi((u8*)"ABDELRAHMAN 9623" , (u8*)"123456789");

	while(1)
	{
		ESP_VidConnectToSrvTcp((u8*)"162.253.155.226" ,  (u8*)"80" );
		Local_u8Data = ESP_u8ReceiveHttpReq((u8*)"GET http://esp.freeoda.com/status.txt\r\n" , (u8*)"39");
		if(Local_u8Data - 48 == 0)
		{
			MGPIO_voidSetPinValue( GPIOA , PIN0 , LOW);
		}
		else if(Local_u8Data - 48 == 1)
		{
			MGPIO_voidSetPinValue( GPIOA , PIN0 , HIGH);
		}
	}


}
