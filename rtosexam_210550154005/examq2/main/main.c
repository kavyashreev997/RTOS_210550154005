//question 2 rtos exam
//KAVYA SHREE V 210550154005

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

TimerHandle_t tt_handle;
void *const tt_timerid;

void tt_timer_handler(TimerHandle_t xTimer)
{
    printf("Timer fired\n");
}

//task1
void task1(void *data)
{
    
    while(1)
    {
        printf("task1 created\n");
        // periodicity 1000ms
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        
    }
}

//task2
void task2(void *data)
{
    while(1)
    {
        printf("task2 created\n");
        //periodicity 2000ms
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        
    }
}

//task3
void task3(void *data)
{
    tt_handle = xTimerCreate("tt_timer",pdMS_TO_TICKS(10000),pdFALSE,&tt_timerid,tt_timer_handler);
    xTimerStart(tt_handle,0);
    while(1)
    {
        printf("task3 created\n");
       //periodicity 5000ms
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        
    }
}

void app_main(void)
{
    int i = 0;
    xTaskCreate(task1,"p_tk1",2048,NULL,10,NULL);
    xTaskCreate(task2,"p_tk1",2048,NULL,20,NULL);
    xTaskCreate(task3,"p_tk1",2048,NULL,30,NULL);

    while (1) 
    {
        printf("[%d] Hello world!\n", i);
        i++;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
