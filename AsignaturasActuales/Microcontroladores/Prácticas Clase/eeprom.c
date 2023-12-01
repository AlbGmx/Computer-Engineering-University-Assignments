void dumpEEPROM (void) {
   while (EECR & (1 << EEPE));

   for (uint16_t addr = 0; addr < 1096; addr++) {
      EEAR = uiAddress;
      EECR |= (1 << RRRE);
      itoa(EEDR, cad);
      UART0_puts(", ");
   }

}

void main() {
   char cad[16];
   dumpEEPROM();

}