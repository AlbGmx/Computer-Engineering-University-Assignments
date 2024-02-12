/*
   *
   * T = 1ms
   * #ticks = 16MHz / 64 = 250
   * 
   * 
*/


// Using Timer0 to generate a 1ms interrupt with normal mode
void Timer0_Init(void) {
   TCNT0 = 6;              // Start counting from 6
   TCCR0A = 0;             // Normal, no output control
   TCCR0B = (3 << CS00);   // Prescaler 64
   TIMSK0 = (1 << TOIE0);  // Enable overflow interrupt
   sei();                  // Enable global interrupts
}

ISR(TIMER0_OVF_vect) {
   TCNT0 += 6;                               // We need to add 6 to TCNT0 because we are counting to 250 not 256 and we dont want to miss a tick
   volatile static uint16_t mSecCounter = 0; // Using 16 bits to avoid overflow
   mSecCounter++; 

   if (mSecCounter == 1000) { 
      mSecCounter = 0;
      secFlag = 1;      
   }
}

// Using Timer0 to generate a 1ms interrupt with CTC mode
void Timer0_InitCTC(void){
   TCNT0 = 0;              // Start counting from 0
   TCRR0A = (2 << WGM00);  // CTC mode
   TCRR0B = (3 << CS00);   // Prescaler 64
   OCR0A = 250 - 1;        // 250 minus 1 because 
   TIMSK0 = (1 << OCIE0A); // Enable CTC interrupt
   sei();                  // Enable global interrupts   
}

// volatile: The compiler will not optimize this variable
// static: The variable will only be visible in this file
volatile static uint8_t secFlag = 0;

uint8_t Timer0_SecFlag(void) {
   if (secFlag) {
      secFlag = 0;
      return 1;
   }

   return 0
}

ISR(TIMER0_COMPA_vect) {
   volatile static uint16_t mSecCounter = 0; // Using 16 bits to avoid overflow
   mSecCounter++; 

   if (mSecCounter == 1000) { 
      mSecCounter = 0;
      secFlag = 1;      
   }
}

// Exam Example
/*
   * Using Timer0 to generate a 5ms interrupt 
   * 
   * # Ticks = 16Mhz / PS * T = 16Mhz / 1024 * 5ms = 78.125 - 1 = 77
*/

void delayHW_5ms(void) {
   // Using CTC
   TCRR0B = 0;             // Stop the timer
   TIFR0 |= (1 << OCF0A);  // Clear the flag
   TCNT0 = 0;              // Start counting from 0
   TCRR0A = (2 << WGM00);  // CTC mode, no output control
   OCR0A = 78 - 1;
   TCRR0B = (5 << CS00);   // Prescaler 1024
   
   while ( !((TIFR0 >> OCF0A) & 1)); // Wait for the flag to be set
}