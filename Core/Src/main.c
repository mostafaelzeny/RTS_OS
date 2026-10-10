#include "main.h"

#include "STD_TYPES.h"
#include "os_interface.h"

volatile uint32_t Task1_Count = 0;
volatile uint32_t Task2_Count = 0;
volatile uint32_t Task3_Count = 0;

void Task1(void);
void Task2(void);
void Task3(void);

void Task1(void) {
  Task1_Count++;
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
}

void Task2(void) {
  Task2_Count++;
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
}

void Task3(void) {
  Task3_Count++;
  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
}

static void GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* Enable peripheral clocks */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  /* Configure PA0 and PA1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  /* Configure PC13 (onboard LED) */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

int main(void) {

  GPIO_Init();
  /* Create 3 test tasks: OS_CreateTask(Priority, Period in ms, TaskFunc) */
  OS_CreateTask(0, 100, 0, Task1); /* Task 1: Priority 0, Period = 100 ms */
  OS_CreateTask(1, 500, 0, Task2); /* Task 2: Priority 1, Period = 500 ms */
  OS_CreateTask(2, 1000, 0, Task3); /* Task 3: Priority 2, Period = 1000 ms (1s) */

  /* Start the OS Scheduler */
  os_start_scheduler();

  while (1) {
  }
}
