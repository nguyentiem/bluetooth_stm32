/*
 * maintask.c
 *
 *  Created on: Jun 30, 2024
 *      Author: TiemNV1
 */

#include"maintask.h"
#include "cmsis_os.h"
#include "config.h"

extern osMessageQueueId_t MainQueueHandle;;


/* USER CODE BEGIN Header_MainTask */
/**
* @brief Function implementing the mainTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_MainTask */
void MainTask(void *argument)
{
  /* USER CODE BEGIN MainTask */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(INDICATOR_LED_PORT, INDICATOR_LED_PIN);
    osDelay(1000);
  }
  /* USER CODE END MainTask */
}

