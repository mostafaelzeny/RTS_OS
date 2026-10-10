/*
 * os_interface.h
 *
 *  Created on: Oct 9, 2026
 *      Author: mostafa
 */

#ifndef INC_OS_INTERFACE_H_
#define INC_OS_INTERFACE_H_

Std_ReturnType OS_CreateTask(u8 copy_piriority, u16 copy_period, u16 copy_First_Delay, void (*copy_pf)(void));

void os_start_scheduler(void);


#endif /* INC_OS_INTERFACE_H_ */
