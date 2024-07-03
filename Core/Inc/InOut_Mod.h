/*
 * InOut_Mod.h
 *
 *  Created on: Jul 2, 2024
 *      Author: vdavi81
 */

#ifndef INC_INOUT_MOD_H_
#define INC_INOUT_MOD_H_

#include <stdint.h>

typedef struct inout_str1
{
	uint8_t IN1;
	uint8_t IN2;
} iomod_Input_t;

typedef enum
{
	EQUALS,
	NOT_EQUALS
} iomod_Compare_state;

void iomod_ScanINs(iomod_Input_t*);
iomod_Compare_state iomod_Compare_Input_ste(iomod_Input_t,iomod_Input_t);
void iomod_UpdateOutput(iomod_Input_t);

#endif /* INC_INOUT_MOD_H_ */
