#include <Arduino_FreeRTOS.h>
#include <time.h>
#include <stdlib.h>
#include <semphr.h>


const int MAX_SIZE = 100;
int *value;
typedef struct Monitor // To do the Monitor
{

   SemaphoreHandle_t mutex;
   SemaphoreHandle_t bufFullSem;
   SemaphoreHandle_t bufEmptySem;
   int buffer[MAX_SIZE];
   int index = 0;
} MyMonitor;

MyMonitor *mon;         // the monitor name is mon 

void setup() {
 Serial.begin(9600);

srand(time(NULL));   // Initialization, should only be called once, i.e., in setup()
mon = malloc(sizeof (MyMonitor)); //to allocate a block of memory dynamically
init(mon);

xTaskCreate(producer_1,"p1",128,NULL,1,NULL); //First task for first producer

xTaskCreate(producer_2,"p2",128,NULL,1,NULL); //Second task for second producer

xTaskCreate(consumer_1,"c1",128,NULL,1,NULL); //First task for first consumer

xTaskCreate(consumer_2,"c2",128,NULL,1,NULL); //Second task for second consumer 
 

}
//------------------

void init(MyMonitor* monitor)         // initializes the monitor, e.g.,  initialize semaphores.   
{
monitor->mutex = xSemaphoreCreateMutex();
monitor->bufFullSem = xSemaphoreCreateCounting(MAX_SIZE, MAX_SIZE);
monitor-> bufEmptySem = xSemaphoreCreateCounting(MAX_SIZE, 0);
}

void Read(MyMonitor* monitor, int* x)   //reads and removes the number from the top of the queue if it is not empty.
                                        // If the queue is empty the caller task will block.  

{
xSemaphoreTake(monitor->bufEmptySem, portMAX_DELAY);
xSemaphoreTake(monitor->mutex, portMAX_DELAY);
*x = monitor->buffer[--(monitor->index)];
xSemaphoreGive(monitor->mutex);
xSemaphoreGive(monitor->bufFullSem);
}
void add(MyMonitor* monitor, int x)   //adds a number to the end of the queue if it is not full, If the queue is full the caller task will block.
{

xSemaphoreTake(monitor->bufFullSem, portMAX_DELAY);
xSemaphoreTake(monitor->mutex, portMAX_DELAY);
monitor->buffer[monitor->index++] = x;
xSemaphoreGive(monitor->mutex);
xSemaphoreGive(monitor->bufEmptySem);
}


//////B//////

void producer_1(void*s){        //producer tasks periodically add random numbers to the monitor
  while(1){
	*value = rand()%100;
	Serial.println(*value);
    add(mon,*value);// rand nr 0-99
    }
  
  }

void producer_2(){          //producer tasks periodically add random numbers to the monitor
  
  while(1){
	*value = rand()%100;
	Serial.println(*value);
    add(mon,value);// rand nr 0-99
    }
  }

void consumer_1(){        //the consumer tasks read the numbers from the monitor. 
  
  while(1){
    Read(mon,value);
    }
  }


void consumer_2(){      //the consumer tasks read the numbers from the monitor. 
   while(1){
    Read(mon,value); 
    }
  
  }


void loop() {
  // put your main code here, to run repeatedly:
//Serial.println(*value);
}
