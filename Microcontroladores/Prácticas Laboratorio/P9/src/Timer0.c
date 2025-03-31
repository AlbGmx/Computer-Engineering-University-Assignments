#include <avr/interrupt.h>
#include <inttypes.h>

static volatile uint64_t milisT0;

void Timer0_Ini(void) {
	TCNT0	 = 0x00;								/* Initialize value for Timer0 */
	TCCR0A = (1 << WGM01);					/* Initialize Timer0 in CTC mode */
	OCR0A	 = (0.001 * F_CPU) / 64;		/* Set the compare register */
	TCCR0B = (1 << CS01) | (1 << CS00); /* Initialize with internal oscillator and prescaler 64 */
	TIMSK0 = (1 << OCIE0A);					/* Enable Timer0 compare interrupt */
	sei();										/* Enable global interrupts */
}

ISR(TIMER0_COMPA_vect) { /* TIMER0_COMPA_vect */
	milisT0++;				 /* Increment millisecond counter */
}

uint64_t millis(void) { return milisT0; }
