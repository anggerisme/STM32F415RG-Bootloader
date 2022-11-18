/*
 * serialPort.c
 *
 *  Created on: Nov 12, 2022
 *      Author: LENOVO
 */


#include "main.h"

HANDLE hComm;

void serial_port_config(){
	char comPortName[]="COM8";
	BOOL Status;

	hComm = CreateFile(comPortName,
			GENERIC_READ | GENERIC_WRITE,
			0,
			NULL,
			OPEN_EXISTING,
			0,
			NULL);

	if(hComm == INVALID_HANDLE_VALUE){
		printf("Error! Port %s can't be opened\n", comPortName);
		exit(-1);
	}
	else{
		printf("Port %s opened succesfully!", comPortName);
	}

	/*------------------------------- Setting the Parameters for the SerialPort ------------------------------*/

	DCB dcbSerialParams = { 0 };                        // Initializing DCB structure
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	Status = GetCommState(hComm, &dcbSerialParams);     //retreives  the current settings

	if (Status == FALSE)
		printf("\n   Error! in GetCommState()");

	dcbSerialParams.BaudRate = 115200;      // Setting BaudRate = 9600
	dcbSerialParams.ByteSize = 8; // Setting ByteSize = 8
	dcbSerialParams.fBinary = 1;
	dcbSerialParams.StopBits = ONESTOPBIT;    // Setting StopBits = 1
	dcbSerialParams.Parity   = NOPARITY;      // Setting Parity = None

	Status = SetCommState(hComm, &dcbSerialParams);  //Configuring the port according to settings in DCB

	if (Status == FALSE)
	{
		printf("\n   Error! in Setting DCB Structure");
	}
	else
	{
		printf("\nSetting DCB Structure Successfull\n");
		printf("\n       Baudrate = %ld", dcbSerialParams.BaudRate);
		printf("\n       ByteSize = %d", dcbSerialParams.ByteSize);
		printf("\n       StopBits = %d", dcbSerialParams.StopBits);
		printf("\n       Parity   = %d", dcbSerialParams.Parity);
	}

}

uint32_t read_serial_port(uint8_t *pData, uint32_t len){
	uint32_t no_of_bytes_rcv;
	ReadFile(hComm, pData, len, (DWORD*)&no_of_bytes_rcv, NULL);
	return no_of_bytes_rcv;
}


void send_to_serial_port(uint8_t *pData, uint32_t len){
	DWORD no_of_bytes_written=0;
	BOOL Status;

	Status = WriteFile(hComm,
						pData,
						len,
						&no_of_bytes_written,
						NULL);

	if(Status == TRUE){
		printf("\n   Sending Command:\n");
		for(uint32_t i = 0 ; i < len ; i++)
		{
			printf("   0x%2.2x ",pData[i]);
			if( i % 8 == 7)
			{
				printf("\n");
			}
		}
	}
	else
		printf("Error in writing to serial port!\n");
}
