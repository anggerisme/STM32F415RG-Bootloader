/*
 * readPort.c
 *
 *  Created on: Nov 12, 2022
 *      Author: LENOVO
 */


#include "main.h"


uint8_t read_bootloader_reply(uint8_t command){
	uint8_t ack[2]={0};
	int ret_value = -2;
	uint32_t len_to_follow;

	read_serial_port(ack, 2);
	if(ack[0]==0x55){
		len_to_follow = ack[1];
//		printf("\n\n   CRC : SUCCESS Len : %d\n",len_to_follow);
		switch(command){
		case CMD_GET_VERSION:
			GET_VERSION_Handler(len_to_follow);
			break;

		default:
			printf("Invalid Command\n");
		}
		ret_value = 0;
	}
	else if(ack[0]==0x99){
		printf("Bootloader send NACK!\n");
		ret_value = -1;
	}
	return ret_value;

}

void GET_VERSION_Handler(uint32_t len){
	/*uint32_t read_serial_port(uint8_t *pBuffer, uint32_t len)*/
	uint8_t version;
	read_serial_port(&version, len);
	printf("\n\nBootloader version : %d\n", (int)version);
}
