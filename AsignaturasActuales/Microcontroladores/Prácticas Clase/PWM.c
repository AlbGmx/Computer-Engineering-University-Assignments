#include <avr/io.h>

void delay(){
   volatile uint32_t counter = 0xFFFFFFFF;
   while (counter--);
}

int main() {
   int8_t direction = 1;
   // init LED
   DDRB |= (1 << PB7);


   // init PWM OC0A
   // 25% duty cycle
   OCR0A = 256/4;  
   
   // Fast PWM, TOP = 0xFF
   TCCR0A = (3 << WGM00) | (2 << COM0A0);
   
   // Prescaler = 1
   TCCR0B = 1 << CS00;

   
   while (1)
   {
      // Change Intensity
      if (OCR0A == 0xFF && direction == 1) {
         direction = -1;
      } else if (OCR0A == 0x00 && direction == -1) {
         direction = 1;
      }

      OCR0A += direction;
      delay();

   }
   
}