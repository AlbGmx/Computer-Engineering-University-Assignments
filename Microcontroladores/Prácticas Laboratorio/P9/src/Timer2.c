#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>

static uint8_t Flag;
static volatile uint64_t counter;

void Timer2_Ini(uint8_t baseT) {
	/* Configurar Timer2 para usar cristal externo según */

	/* secuencia dada por la hoja de especificaciones    */

	//  1. Disable the Timer/Counter2 interrupts by clearing OCIE2x and TOIE2.
	TIMSK2 = 0;

	//  2. Select clock source by setting AS2 as appropriate.
	ASSR |= (1 << AS2);

	//  3. Write new values to TCNT2, OCR2x, and TCCR2x.
	TCNT2	 = 0x00;							 /* Initialize value for Timer0 */
	TCCR2A = (1 << WGM01);				 /* Initialize Timer0 in CTC mode */
	OCR2A	 = (0.001 * 32768) * baseT; /* Set the compare register */
	TCCR2B = (1 << CS20);				 // Initialize with external oscilator and no prescaler

	//  4. To switch to asynchronous operation: Wait for TCN2UB, OCR2xUB, and TCR2xUB.
	while ((ASSR & ((1 << TCN2UB) | (1 << OCR2AUB) | (1 << TCR2AUB))) != 0)
		;

	//  5. Clear the Timer/Counter2 Interrupt Flags.
	TIFR2 = 0;

	//  6. Enable interrupts, if needed.
	TIMSK2 = (1 << OCIE2A);
	sei();
}

uint8_t Timer2_Flag(void) {
	if (Flag) {
		Flag = 0;
		return 1;
	} else {
		return 0;
	}
}

/* Rutina de Servicio de Interrupción para atender la interrupción */
/* por Comparación del Timer2 (TCNT2 y OCR2 son iguales) */
ISR(TIMER2_COMPA_vect) {
	counter++;
	if (counter % 1000 == 0) {
		Flag = 1; /* Activa Bandera para indicar los 1 segundos */
	}

} /* fin de la rutina de servicio de Interrupción (RSI) */

uint64_t counterT2(void) { return counter; }