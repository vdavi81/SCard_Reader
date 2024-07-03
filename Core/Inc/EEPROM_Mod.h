/*
 * EEPROM_Mod.h
 *
 *  Created on: Jul 3, 2024
 *      Author: vdavi81
 */

#ifndef INC_EEPROM_MOD_H_
#define INC_EEPROM_MOD_H_

#include <stdint.h>
#include "main.h"

#define EEPROM_INS 0x08080000

extern inline int EEPROM_Read_INs(uint16_t *data)
{
	// In this function I could evoid to return any values, but In near future I can change this driver with a real EEPROM
	int ret = 0x00;

	// For this easy application only one task write on the EEPROM then I didin't insert any MUTEX
	*data = *(uint16_t *)(EEPROM_INS);

	return ret;
}

extern inline int EEPROM_Write_INs(uint16_t data)
{
	// In this function I could evoid to return any values, but In near future I can change this driver with a real EEPROM
	int ret = 0x00;

	HAL_FLASHEx_DATAEEPROM_Unlock();

	// For this easy application only one task write on the EEPROM then I didin't insert any MUTEX
	HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_HALFWORD, EEPROM_INS, data);

	HAL_FLASHEx_DATAEEPROM_Lock();

	return ret;
}

#endif /* INC_EEPROM_MOD_H_ */
