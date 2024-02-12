#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t timer_flag = 0;

// Timer0 compare match interrupt handler
ISR(TIMER0_COMPA_vect) {
    // Toggle a GPIO pin (e.g., LED) to indicate the interrupt occurred
    PORTB ^= (1 << PB0);
    timer_flag = 1; // Set a flag to indicate the interrupt
}

int main() {
    // Initialize the LED pin (PB0) as an output
    DDRB |= (1 << PB0);

    // Initialize Timer0
    TCCR0A = (1 << WGM01); // CTC mode
    TCCR0B = (1 << CS02); // Set timer prescaler to 256
    OCR0A = 156; // Set compare value for a 1Hz interrupt at 16MHz clock

    // Enable Timer0 compare match interrupt
    TIMSK0 |= (1 << OCIE0A);

    // Enable global interrupts
    sei();

    while (1) {
        if (timer_flag) {
            // Your code to be executed when the interrupt occurs
            // Reset the flag
            timer_flag = 0;
        }
    }

    return 0;
}
