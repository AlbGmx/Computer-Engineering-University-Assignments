#include <avr/io.h>
#include <inttypes.h>

extern void Delay(uint8_t); /* Prototipo de la función Delay */

int main(void) {
   int i = 0;



   /* Configurar el bit 5 del PORTB como salida para controlar el LED en D13 */
   DDRB |= (1 << DDB5); /* DDRB = 00100000 */

   /* Establecer el valor inicial en el puerto para apagar el LED */
   PORTB &= ~(1 << PORTB5); /* PORTB = 0xxxxxx0 */

   while (1) {
      PORTB &= ~(1 << PORTB5); /* encender LED PC4 = 0 */

      for (i = 0; i < 100; i++) {
         Delay(10);
      }
      printf("1s delay");
      PORTB |= (1 << PORTB5); /* apagar LED PC4 = 1 */
      for (i = 0; i < 10; i++) {
         Delay(100);
      }
      printf("1s delay");
   }
}
