/*
 * Autor: Emmanuel Alberto Gómez Cárdenas
 * Fecha: 24/04/2023
 * Descripcion: Taller 7a, Uso de timers en ESP32
 *    mediante el uso de registros
 * Taller de la clase Microcontroladores
 */

#include <stdio.h>

#include "esp_timer.h"  //To test the Delay25mS() function

// Define the timer registers addresses
#define TIMG0_T0CONFIG_REG  0x3FF5F000
#define TIMG0_T0LO_REG      0x3FF5F004
#define TIMG0_T0HI_REG      0x3FF5F008
#define TIMG0_T0UPDATE_REG  0x3FF5F00C
#define TIMG0_T0LOADLO_REG  0x3FF5F018
#define TIMG0_T0LOADHI_REG  0x3FF5F01C
#define TIMG0_T0LOAD_REG    0x3FF5F020
#define TIMG0_T0ALARMLO_REG 0x3FF5F010
#define TIMG0_T0ALARMHI_REG 0x3FF5F014

void Delay25mS() {
   /* This function assumes this values are already defined within the program */

   // Define the TIMG0_T0 registers addresses
   // #define TIMG0_T0CONFIG_REG 0x3FF5F000
   // #define TIMG0_T0LO_REG 0x3FF5F004
   // #define TIMG0_T0HI_REG 0x3FF5F008
   // #define TIMG0_T0UPDATE_REG 0x3FF5F00C
   // #define TIMG0_T0LOADLO_REG 0x3FF5F018
   // #define TIMG0_T0LOADHI_REG 0x3FF5F01C
   // #define TIMG0_T0LOAD_REG 0x3FF5F020
   // #define TIMG0_T0ALARMLO_REG 0x3FF5F010
   // #define TIMG0_T0ALARMHI_REG 0x3FF5F014

   /* Setup the timers registers */
   // Define all registers as uint32_t pointers
   uint32_t *configurationRegister = (uint32_t *) TIMG0_T0CONFIG_REG;
   uint32_t *loadLowToRegister =     (uint32_t *) TIMG0_T0LOADLO_REG;
   uint32_t *loadHighToRegister =    (uint32_t *) TIMG0_T0LOADHI_REG;
   uint32_t *loadRegisters =         (uint32_t *) TIMG0_T0LOAD_REG;
   uint32_t *updateValueRegister =   (uint32_t *) TIMG0_T0UPDATE_REG;
   uint32_t *loadAlarmLowRegister =  (uint32_t *) TIMG0_T0ALARMLO_REG;
   uint32_t *loadAlarmHighRegister = (uint32_t *) TIMG0_T0ALARMHI_REG;

   // Disable the timer (31th bit) in case it was activated
   *configurationRegister &= ~(1 << 31);
   // Disable the alarm (10th bit) in case it was activated
   *configurationRegister &= ~(1 << 10);
   // Set timer to increase (30th bit)
   *configurationRegister |= 1 << 30;
   // Set prescaler (13th to 28th bits) to 8,000 to count one each .10 ms
   // 80 000 would give us a ms but is out of the 16 bit range
   *configurationRegister |= 8000 << 13;
   // Clear autoreload (29th) bit
   *configurationRegister &= ~(1 << 29);

   // Clear current values in timer
   *loadLowToRegister = 0;
   *loadHighToRegister = 0;
   *loadRegisters = 0;

   // Set alarm values
   *loadAlarmLowRegister = 250;
   *loadAlarmHighRegister = 0;

   // Enable the timer (31st bit) and the alarm (10th bit)
   *configurationRegister |= (1 << 31) | (1 << 10);
   *updateValueRegister = 1;

   // Actual delay (Wait for the alarm bit)
   while (*configurationRegister & (1 << 10));

   // Disable the timer (31st bit)
   *configurationRegister &= ~(1 << 30);
}
void app_main() {
   const uint64_t start = esp_timer_get_time();  // Get current time in microseconds
   Delay25mS();                                  // Call the function to be timed
   printf("\n\n\nThe time of run is %.3f microseconds\n", (double)(esp_timer_get_time() - start) / 1000);  // Divide by 1000 to get milliseconds
}
