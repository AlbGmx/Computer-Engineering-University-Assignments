/*
 * Autor: Emmanuel Alberto Gómez Cárdenas
 * Fecha: 21/04/2023
 * Descripcion: Taller 7a, Uso de timers en ESP32 
 *    mediante registros sin el uso de interrupciones
 * Taller de la clase Microcontroladores
 */ 

#include <stdio.h>
#include <time.h>  //To test the Delay25mS() function

// Define the timer registers addresses
#define TIMG0_T0CONFIG_REG 0x3FF5F000
#define TIMG0_T0LO_REG     0x3FF5F004
#define TIMG0_T0HI_REG     0x3FF5F008
#define TIMG0_T0UPDATE_REG 0x3FF5F00C
#define TIMG0_T0LOADLO_REG 0x3FF5F018
#define TIMG0_T0LOADHI_REG 0x3FF5F01C
#define TIMG0_T0LOAD_REG   0x3FF5F020
#define TESTRUNS               100

void Delay25mS() {
   // Define all registers as uint32_t pointers
   uint32_t *configurationRegister =    (uint32_t *) TIMG0_T0CONFIG_REG;
   uint32_t *currentLowValueRegister =  (uint32_t *) TIMG0_T0LO_REG;
   uint32_t *currentHighValueRegister = (uint32_t *) TIMG0_T0HI_REG;
   uint32_t *loadLowToRegister =        (uint32_t *) TIMG0_T0LOADLO_REG;
   uint32_t *loadHighToRegister =       (uint32_t *) TIMG0_T0LOADHI_REG;
   uint32_t *loadRegisters =            (uint32_t *) TIMG0_T0LOAD_REG;
   uint32_t *updateValueRegister =      (uint32_t *) TIMG0_T0UPDATE_REG;

   // Disable the timer (31th bit) in case it was activated
   *configurationRegister &= ~(1 << 30);

   // Set prescaler (13th to 28th bits) to 80,000 to count each ms
   *configurationRegister |= (80000 << 12);

   // Clear autoreload (29th) bit
   *configurationRegister &= ~(1 << 29);

   // Clear current values in timer
   *loadLowToRegister = 0;
   *loadHighToRegister = 0;
   *loadRegisters = 0;
   *updateValueRegister = 1;

   // Enable the timer (31st bit)
   *configurationRegister |= (1 << 30);

   // Actual Delay
   while (*currentLowValueRegister < 25) {
      *updateValueRegister = 1;
      printf(" ");  // TO DO, function breaks when this line is removed
   }

   // Disable the timer (31st bit)
   *configurationRegister &= ~(1 << 30);
}
void app_main() {
   clock_t start;
   double sum = 0;
   for (int i = 0; i < TESTRUNS; i++) {
      start = clock();  // Record the start time
      Delay25mS();      // Call the function to be timed
      sum += (double)(clock() - start) / CLOCKS_PER_SEC;
      printf("The time of run %d is %f seconds\n", i, (double)(clock() - start) / CLOCKS_PER_SEC);
   }

   printf("The average time is %f seconds\n", sum / TESTRUNS);
}
