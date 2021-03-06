/******************************************************/
/* Author      : Abdelrahman Moustafa                 */
/* Date        : 30 August 2021                       */
/* Version     : V01                                  */
/* Description : ESP                                  */
/******************************************************/


/******************************************************/
/* guard of file will call one time in .c  			  */
/******************************************************/

#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_H

void ESP_voidInit(void);
void ESP_VoidConnectToWiFi(u8 *Copy_name , u8 *Copy_pass);
void ESP_VidConnectToSrvTcp (u8 *Copy_u8Domain , u8 *Copy_u8Port);
u8   ESP_u8ReceiveHttpReq(u8 *Copy_u8ChannelID , u8 *Copy_u8Length);
#endif
