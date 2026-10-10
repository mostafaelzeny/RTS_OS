/*
 * os_private.h
 *
 *  Created on: Oct 9, 2026
 *      Author: mostafa
 */

#ifndef INC_OS_PRIVATE_H_
#define INC_OS_PRIVATE_H_

typedef struct
{
	u8 Pirority;
	u16 First_Delay;
	u16 period;
    void (*pf)(void);
} TCP_t;


#endif /* INC_OS_PRIVATE_H_ */
