/*
 * os_program.c
 *
 *  Created on: Oct 9, 2026
 *      Author: mostafa
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "STK_INTERFACE.h"
#include "os_config.h"
#include "os_interface.h"
#include "os_private.h"

static TCP_t os_tasks[NUMBER_OF_TASKS];
volatile u32 TickCount = 0;

static void os_scheduler(void);

Std_ReturnType OS_CreateTask(u8 copy_piriority, u16 copy_period, u16 copy_First_Delay, void (*copy_pf)(void)) {
  Std_ReturnType Local_functionStatus = E_NOT_OK;
  if (copy_piriority < NUMBER_OF_TASKS && copy_pf != NULL) {
    os_tasks[copy_piriority].period = copy_period;
    os_tasks[copy_piriority].First_Delay = copy_First_Delay;
    os_tasks[copy_piriority].pf = copy_pf;

    Local_functionStatus = E_OK;
  } else {
    Local_functionStatus = E_NOT_OK;
  }
  return Local_functionStatus;
}

void os_start_scheduler(void) {
  // Init STK.
  MCAL_STK_vInit();

  // Run Scheduler each 1 ms.
  MCAL_STK_SetIntervalPeriodic(TICK_MICROSECONDS, os_scheduler);
}

static void os_scheduler(void) {
  for (u8 count = 0; count < NUMBER_OF_TASKS; count++) {
    if (os_tasks[count].pf != NULL && os_tasks[count].period != 0) {
      if (os_tasks[count].First_Delay > 0) {
        os_tasks[count].First_Delay--;
      } else {
        os_tasks[count].pf();
        os_tasks[count].First_Delay =
            (os_tasks[count].period) - 1; // as we start from 0.
      }
    }
  }
}