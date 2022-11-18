/*
 * main.h
 *
 *  Created on: Nov 12, 2022
 *      Author: LENOVO
 */

#ifndef HEADERS_MAIN_H_
#define HEADERS_MAIN_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <Windows.h>

#define GET_VERSION_LEN 6
#define CMD_GET_VERSION 51

void GET_VERSION_Handler();
uint8_t read_bootloader_reply(uint8_t command);
void serial_port_config();


void decode_command(uint8_t command);
uint8_t word_to_byte(uint32_t addr, uint8_t index, uint8_t lowerfirst);
uint32_t get_crc(uint8_t *buff, uint32_t len);
void send_to_serial_port(uint8_t *pData, uint32_t len);
uint32_t read_serial_port(uint8_t *pData, uint32_t len);

#endif /* HEADERS_MAIN_H_ */
