/*
 * main.c
 *
 *  Created on: Nov 12, 2022
 *      Author: LENOVO
 */


#include "main.h"



int main(){
	printf("\n\n +==========================================+");
	printf("\n MIKROE-1476 Bootloader Host Application   ");
	printf("\n +==========================================+\n");

	serial_port_config();
	while(1){
		printf("\n\nChoose the Bootloader Command\n");
		printf("0. Exit\n");
		printf("1. Get Version\n");
		uint8_t command;
		scanf("%d", (int*)&command);
		decode_command(command);

	}
}

void decode_command(uint8_t command){
	uint8_t data_buf[200];
	uint32_t crc32;
	int ret_value=0;


	switch(command){
	case 0:
		printf("\nExit the bootloader host application\n");
		exit(0);

	case 1:
		data_buf[0] = GET_VERSION_LEN-1;
		data_buf[1] = CMD_GET_VERSION;
		crc32       = get_crc(data_buf,GET_VERSION_LEN-4);
		data_buf[2] = word_to_byte(crc32,1,1);
		data_buf[3] = word_to_byte(crc32,2,1);
		data_buf[4] = word_to_byte(crc32,3,1);
		data_buf[5] = word_to_byte(crc32,4,1);

		//1. Send the data to the Bootloader
		/*HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)*/
		send_to_serial_port(&data_buf[0], 1); /* Length to follow*/
		send_to_serial_port(&data_buf[1], data_buf[0]); /* Command */

		//2. Read the reply from Bootloader
		/* Read ACK & Bootloader Version
		 * */
		ret_value = read_bootloader_reply(data_buf[1]);
		break;
	default :
		printf("Invalid Command! Please input command according to the number above\n");
		break;

	}
	if(ret_value==-2){
		printf("Timeout!\n");
	}


}

uint32_t get_crc(uint8_t *buff, uint32_t len)
{
    uint32_t i;

    uint32_t Crc = 0XFFFFFFFF;

    for(uint32_t n = 0 ; n < len ; n++ )
    {
        uint32_t data = buff[n];
        Crc = Crc ^ data;
        for(i=0; i<32; i++)
        {

        if (Crc & 0x80000000)
            Crc = (Crc << 1) ^ 0x04C11DB7; // Polynomial used in STM32
        else
            Crc = (Crc << 1);
        }

    }

  return(Crc);
}

uint8_t word_to_byte(uint32_t addr, uint8_t index, uint8_t lowerfirst)
{
      uint8_t value = (addr >> ( 8 * ( index -1)) & 0x000000FF );
      return value;
}

