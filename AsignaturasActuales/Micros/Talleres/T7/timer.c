/*
 * Autor: Emmanuel Alberto Gómez Cárdenas
 * Fecha: 21/04/2023
 * Descripcion: Taller 7a - TIMG
 * Taller de la clase Microcontroladores
 */

// Define the timer registers addresses
#define TIMG0_T0CONFIG_REG *(uint32_t *)0x3FF5F000
#define TIMG0_T0LO_REG *(uint32_t *)0x3FF5F004
#define TIMG0_T0HI_REG *(uint32_t *)0x3FF5F008
#define TIMG0_T0UPDATE_REG *(uint32_t *)0x3FF5F00C
#define TIMG0_T0ALARMLO_REG *(uint32_t *)0x3FF5F010
#define TIMG0_T0ALARMHI_REG *(uint32_t *)0x3FF5F014
#define TIMG0_T0LOADLO_REG *(uint32_t *)0x3FF5F018
#define TIMG0_T0LOADHI_REG *(uint32_t *)0x3FF5F01C
#define TIMG0_T0LOAD_REG *(uint32_t *)0x3FF5F020

void setup() {
   // Show current config after boot
   printCurrentTIMG0_T0_Values();

   // Set prescaler to divide clock by 80,000,000
   TIMG0_T0CONFIG_REG |= (79999999 << 12);

   // Set reload value to 1
   TIMG0_T0LOAD_REG = 1;

   // Clear autoreload bit
   TIMG0_T0CONFIG_REG &= ~(1 << 29);

   // Clear current timer
   TIMG0_T0LOADLO_REG = 0;
   TIMG0_T0LOADHI_REG = 0;
   TIMG0_T0LOAD_REG = 0;

   // Show current config after configuration
   printCurrentTIMG0_T0_Values();

   // Enable the timer
   TIMG0_T0CONFIG_REG |= (1 << 31);
   printf("\n\nStart counting\n");
   Delay();
}

/* Función de retardo 25ms */
void loop() {
}

void Delay() {
   while (true) {
      TIMG0_T0UPDATE_REG = 0;
      printf("Actual TIMG0 0x%08x %08x\n", TIMG0_T0HI_REG, TIMG0_T0LO_REG);

      // when alarm is triggered exit function
      if (TIMG0_T0HI_REG) {
         printf("\nEND counting\n");
         printCurrentTIMG0_T0_Values();
         return;
      }
   }
}

void printCurrentTIMG0_T0_Values() {
   TIMG0_T0UPDATE_REG = 0;
   printf("\n\nActual TIMG0 config, 0x%08x\n", TIMG0_T0CONFIG_REG);
   printf("Actual TIMG0 LO, 0x%08x\n", TIMG0_T0LO_REG);
   printf("Actual TIMG0 HI, 0x%08x\n", TIMG0_T0HI_REG);
   printf("Actual TIMG0 UPDATE, 0x%08x\n", TIMG0_T0UPDATE_REG);
   printf("Actual TIMG0 ALARMLO, 0x%08x\n", TIMG0_T0ALARMLO_REG);
   printf("Actual TIMG0 ALARMHI, 0x%08x\n", TIMG0_T0ALARMHI_REG);
   printf("Actual TIMG0 LOADLO, 0x%08x\n", TIMG0_T0LOADLO_REG);
   printf("Actual TIMG0 LOADLO, 0x%08x\n", TIMG0_T0LOADHI_REG);
   printf("Actual TIMG0 LOAD, 0x%08x\n\n", TIMG0_T0LOAD_REG);
}