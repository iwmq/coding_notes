#include <SoftwareSerial.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#define RED_LED 12
#define PUSH_BUTTON 2
#define INTERRUPT_BUTTON 3
#define LED_DELAY_MS 1000

SemaphoreHandle_t interruptSemaphore;

void interrupt_handler()
{
  xSemaphoreGiveFromISR(interruptSemaphore, NULL);
}

void xTaskBlink(void* pvParameter)
{
  pinMode(LED_BUILTIN, OUTPUT);
  while (true)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(LED_DELAY_MS / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(LED_DELAY_MS / portTICK_PERIOD_MS);
  }
}

void xTaskBlink2(void* pvParameter)
{
  int state = 0;
  pinMode(RED_LED, OUTPUT);
  while (true)
  {
    if (xSemaphoreTake(interruptSemaphore, portMAX_DELAY) == pdPASS)
    {
      state = 1 - state;
      digitalWrite(RED_LED, state);
    }
  }
}

void xTaskDigitalReadSerial(void* pvParamter)
{
  int state = 0;
  pinMode(PUSH_BUTTON, INPUT);
  Serial.begin(9600);

  while (true)
  {
    state = digitalRead(PUSH_BUTTON);
    Serial.println(state);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  xTaskCreate(xTaskBlink, "blink", 128, NULL, configMAX_PRIORITIES - 2, NULL);
  xTaskCreate(xTaskBlink2, "blink2", 128, NULL, configMAX_PRIORITIES - 2, NULL);
  xTaskCreate(xTaskDigitalReadSerial, "read", 128, NULL, configMAX_PRIORITIES - 1, NULL);
  
  interruptSemaphore = xSemaphoreCreateBinary();
  if (interruptSemaphore != NULL)
  {
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_BUTTON), interrupt_handler, FALLING);
  }
}

void loop() {}
