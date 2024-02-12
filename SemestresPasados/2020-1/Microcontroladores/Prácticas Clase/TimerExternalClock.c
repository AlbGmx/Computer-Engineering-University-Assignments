#include <avr/io.h>
/*
   * F = 32768hz
   * Configure el Timer2 para generar una interrupción cada segundo.
   * #ticks = (32768hz / PS) * 1s = (32768 / 1024) * 1 = 32 - 1
*/

void Timer2_init() {
   TIMSK2 = 0; //Disable Timer2 interrupts

   // 2. Select clock source by setting AS2 as appropriate
   ASSR |= (1 << AS2);

   // 3. Write new values to TCNT2, OCR2x, and TCCR2x.
   TCNT2 = 0;
   OCR2A = 32 - 1;
   TCCR2A = 2 << WGM20; // CTC mode
   TCCR2B = 5 << CS20; // 1024 prescaler

   // 4. To switch to asynchronous operation: Wait for TCN2UB, OCR2xUB, and TCR2xUB.
   while (ASSR & ((1 << TCN2UB) | (1 << OCR2AUB) | (1 << TCR2AUB)));

   // 5. Clear the Timer/Counter2 Interrupt Flags.
   TIFR2 = 7; 
  
   // 6. Enable interrupts, if needed.
   TIMSK2 |= (1 << OCIE2A);
}

ISR(TIMER2_COMPA_vect) {
   SecFlag = 1;
}

