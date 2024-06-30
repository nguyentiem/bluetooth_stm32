/*
 * bluetask.c
 *
 *  Created on: Jun 30, 2024
 *      Author: TiemNV1
 */

#include"bluetask.h"
#include "cmsis_os.h"

extern osMessageQueueId_t BlueQueueHandle;

/* USER CODE BEGIN Header_BlueTask */
/**
  * @brief  Function implementing the bluetoohTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_BlueTask */
void BlueTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}
