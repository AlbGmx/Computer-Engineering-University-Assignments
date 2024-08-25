#include <stdio.h>
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
#define TIMG1_T0CONFIG_REG  0x3FF6F000
#define TIMG1_T0LO_REG      0x3FF6F004
#define TIMG1_T0HI_REG      0x3FF6F008
#define TIMG1_T0UPDATE_REG  0x3FF6F00C
#define TIMG1_T0LOADLO_REG  0x3FF6F018
#define TIMG1_T0LOADHI_REG  0x3FF6F01C
#define TIMG1_T0LOAD_REG    0x3FF6F020
#define TIMG1_T0ALARMLO_REG 0x3FF6F010
#define TIMG1_T0ALARMHI_REG 0x3FF6F014

#define SEED     100  // Seed can be changed
#define CAPTURES 16   // Number of chars shown

static long holdrand = 1L;

uint32_t *TIMG0_configurationRegister = (uint32_t *)TIMG0_T0CONFIG_REG;
uint32_t *TIMG0_loadLowToRegister     = (uint32_t *)TIMG0_T0LOADLO_REG;
uint32_t *TIMG0_loadHighToRegister    = (uint32_t *)TIMG0_T0LOADHI_REG;
uint32_t *TIMG0_loadRegisters         = (uint32_t *)TIMG0_T0LOAD_REG;
uint32_t *TIMG0_updateValueRegister   = (uint32_t *)TIMG0_T0UPDATE_REG;
uint32_t *TIMG0_loadAlarmLowRegister  = (uint32_t *)TIMG0_T0ALARMLO_REG;
uint32_t *TIMG0_loadAlarmHighRegister = (uint32_t *)TIMG0_T0ALARMHI_REG;

uint32_t *TIMG1_configurationRegister = (uint32_t *)TIMG1_T0CONFIG_REG;
uint32_t *TIMG1_loadLowToRegister     = (uint32_t *)TIMG1_T0LOADLO_REG;
uint32_t *TIMG1_loadHighToRegister    = (uint32_t *)TIMG1_T0LOADHI_REG;
uint32_t *TIMG1_loadRegisters         = (uint32_t *)TIMG1_T0LOAD_REG;
uint32_t *TIMG1_updateValueRegister   = (uint32_t *)TIMG1_T0UPDATE_REG;
uint32_t *TIMG1_loadAlarmLowRegister  = (uint32_t *)TIMG1_T0ALARMLO_REG;
uint32_t *TIMG1_loadAlarmHighRegister = (uint32_t *)TIMG1_T0ALARMHI_REG;

void srand(unsigned int seed) { holdrand = (long)SEED; }
int rand(void) { return (((holdrand = holdrand * 214013L + 2531011L) >> 16) & 0x7fff); }
void clrscr() { printf("\e[1;1H\e[2J"); }
// implement getchar

void DelayTwoSeconds() {
   // Disable the timer (31th bit) and the alarm (10th bit) in case they were activated
   *TIMG0_configurationRegister &= ~((1 << 31) | (1 << 10));

   // Set timer to increase (30th bit)
   *TIMG0_configurationRegister |= 1 << 30;

   // Set prescaler (13th to 28th bits) to 8,000 to count one each .10 ms
   *TIMG0_configurationRegister |= 8000 << 13;

   // Clear autoreload (29th) bit
   *TIMG0_configurationRegister &= ~(1 << 29);

   // Clear current values in timer
   *TIMG0_loadLowToRegister  = 0;
   *TIMG0_loadHighToRegister = 0;
   *TIMG0_loadRegisters      = 0;

   // Set alarm values
   // If ms is bigger than 2^32, we need to split it in two registers, consider that each count is .10 ms
   *TIMG0_loadAlarmLowRegister  = 20000;
   *TIMG0_loadAlarmHighRegister = 0;

   // Enable the timer (31st bit) and the alarm (10th bit)
   *TIMG0_configurationRegister |= (1 << 31) | (1 << 10);
   *TIMG0_updateValueRegister = 1;

   // Actual delay (Wait for the alarm bit)
   while (*TIMG0_configurationRegister & (1 << 10))
      ;

   // Disable the timer (31st bit)
   *TIMG0_configurationRegister &= ~(1 << 30);
}

void initialiseTimer() {
   // Disable the timer (31th bit) and the alarm (10th bit) in case they were activated
   *TIMG1_configurationRegister &= ~((1 << 31) | (1 << 10));

   // Set timer to increase (30th bit)
   *TIMG1_configurationRegister |= 1 << 30;

   // Set prescaler (13th to 28th bits) to 8,000 to count one each .10 ms
   *TIMG1_configurationRegister |= 8000 << 13;

   // Clear autoreload (29th) bit
   *TIMG1_configurationRegister &= ~(1 << 29);

   // Clear current values in timer
   *TIMG1_loadLowToRegister  = 0;
   *TIMG1_loadHighToRegister = 0;
   *TIMG1_loadRegisters      = 0;

   // Enable the timer (31st bit) and the alarm (10th bit)
   *TIMG1_configurationRegister |= (1 << 31) | (1 << 10);
}

long currentTime() {
   // Update the current value of the timer
   *TIMG1_updateValueRegister = 1;
   // Read the current values from the timg1 timer
   long low  = (long)*TIMG1_loadLowToRegister;
   long high = (long)*TIMG1_loadHighToRegister;

   // Return the current time in ms
   return (high << 16) | low;
}

void startGame(float *avg, float *max, float *min) {
   char chars[25] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   float values[CAPTURES];
   int i = 0, j = 0;
   char keyStroke = 0;
   float reactionTime, startTime;
   clrscr();
   printf("Presiona la siguiente tecla en cuanto aparezcan\n");

   for (i = 0; i < CAPTURES; i++) {
      j = rand();
      printf("\n%c: ", chars[j]);
      startTime    = currentTime();
      keyStroke    = getchar();
      reactionTime = currentTime() - startTime;
      if (chars[j] == keyStroke && reactionTime > 2000) {
         i--;
         printf("\nCaptura no valida, intenta de nuevo\n");
      } else {
         values[i] = reactionTime;
         printf("\n");
      }
      DelayTwoSeconds();
   }
   // Calculate values
   *avg = 0;
   *max = 0;
   *min = values[0];
   for (i = 0; i < CAPTURES; i++) {
      *avg += values[i];
      if (values[i] > *max) *max = values[i];
      if (values[i] < *min) *min = values[i];
   }
   *avg /= CAPTURES;
}

void app_main() {
   float avg = 0, max = 0, min = 0;
   srand(SEED);
   char keepPlaying = 0;

   clrscr();
   do {
      startGame(&avg, &max, &min);

      printf("Resultados: \n\tPromedio: %3.1fms\n\tMayor:%3.1f\n\tMenor: %3.1f\n", avg, max, min);
      printf("Volver a jugar? (y/n)");
      keepPlaying = getchar();
   } while (keepPlaying == 'y' || keepPlaying == 'Y');
}
