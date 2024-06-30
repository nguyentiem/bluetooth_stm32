#include"screentask.h"
#include "cmsis_os.h"

extern osMessageQueueId_t ScreenQueueHandle;

static int x=0;
static int y = heigh;

static void hienthi(char c){
//	clearDisplay();
	if(c<32||c>126){
		drawChars(&x,&y,"invalid char");
		return;
	}
	drawChar(x,y,c);
	if (x + width >= WIDTH)
	  {
	    if ((y + heigh >= HEIGHT))
	    {
	      x = 0;
	      y = heigh;
	    }
	    else
	    {
	      y += heigh;
	     x = 0;
	    }
	  }else{
		   x += width;
	  }
}

/* USER CODE BEGIN Header_ScreenTask */
/**
* @brief Function implementing the screenTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_ScreenTask */
void ScreenTask(void *argument)
{
  /* USER CODE BEGIN ScreenTask */
	char a;
  /* Infinite loop */
  for(;;)
  {
	  osStatus_t res =  osMessageQueueGet(ScreenQueueHandle, &a, 0, 0);
	  if(res == 0 ){
		  hienthi(a);
	  }
    osDelay(1);
  }
  /* USER CODE END ScreenTask */
}
