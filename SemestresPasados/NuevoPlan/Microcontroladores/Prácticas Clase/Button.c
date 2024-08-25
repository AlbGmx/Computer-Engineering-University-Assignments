// Switch on board between PK1 (Interrupt)  and PF6 
void ButtonInit() {
   //PK1 IN, PF6 OUT (GND)
   DDRF |= (1 << PF6);
   DDRK &= ~(1 << PK1);
   PORTK |= (1 << PK1);
   PORTF &= ~(1 << PF6);

   // Enable group 2 interrupts
   PCICR |= (1 << PCIE2);

   sei();
}

ISR(PCINT2_vect) {
   //Execute Interrupt Code
}