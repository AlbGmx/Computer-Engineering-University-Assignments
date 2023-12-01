#include <avr/io.h>

void adc_init() {
   ADMUX = (1 << REFS0) | (5 << MUX0);
   ADCSRB = 0;
   ADCSRA = (1 << ADEN) | (7 << ADPS2);
   DIDR0 = (1 << ADC5D);
}

uint16_t adc_read() {
   ADCSRA |= (1 << ADSC);
   while (ADCSRA & (1 << ADSC));
   return ADCH:ADCL;
}