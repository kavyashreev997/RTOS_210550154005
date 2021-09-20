//question 1 rtos exam 
//KAVYA SHREE V 210550154005

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

QueueHandle_t msgmq;

//task 1
void task1(void *data)
{
    while(1)
    {
        printf("task1 created\n");
        //periodicity 1000ms
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
}

//task 2
void task2(void *data)
{
    while(1)
    {
        printf("task2 created\n");
        //periodicity 2000ms
        vTaskDelay(2000 / portTICK_PERIOD_MS);

    }
}

//task 3
void task3(void *data)
{
    while(1)
    {
        printf("task3 created\n");
        //periodicity 5000ms
        vTaskDelay(5000 / portTICK_PERIOD_MS);

    }
}

//task 4 sender task
void task4(void *data)
{
    int message = 0;
    while(1)
    {
        printf("task4 created\n");
        message++;
        //sending message 
        xQueueSend(msgmq,&message,0);
        printf("task4 ended\n");
        vTaskDelay(500 / portTICK_PERIOD_MS);

    }
}


//task 5 receiver task
void task5(void *data)
{
    while(1)
    {
        printf("task5 created\n");
        int intbuff;
        //receiving message 
        xQueueReceive(msgmq,&intbuff,0);
        printf("INTEGER DATA[task5]:%d\n",intbuff);
        printf("task5 ended\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}


void app_main(void)
{
//create a message queue
msgmq = xQueueCreate(5,sizeof(int));

//create a tasks
xTaskCreate(task1,"p_tk1",2048,NULL,10,NULL);
xTaskCreate(task2,"p_tk1",2048,NULL,20,NULL);
xTaskCreate(task3,"p_tk1",2048,NULL,30,NULL);
xTaskCreate(task4,"p_tk1",2048,NULL,40,NULL);
xTaskCreate(task5,"p_tk2",2048,NULL,50,NULL);
while(1)
{
    
    vTaskDelay(2000 / portTICK_PERIOD_MS);

}
}


        
        
    
