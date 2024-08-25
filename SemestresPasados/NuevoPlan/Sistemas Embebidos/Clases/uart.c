
/*
   UART: Universal Asynchronous Receiver/Transmitter (Receptor/Transmisor Universal Asíncrono).
      UART es conexion uno a uno, los datos se transmiten del bit menos significativo al más significativo (LSB)
   Asíncrono: La transmisión de datos no está sincronizada con el reloj del sistema.
      ---> Baudrate: El número de bits por segundo, los valores más comunes son 9600, 19200, 38400, 57600, 115200.
      ---> Serial: La transmisión de datos se realiza bit a bit.
   Conecciones: 
      Full Duplex: Recepción, transmisión y tierra.
      Half Duplex: Recepción y transmisión comparten el mismo cable.
   Estados: 
      Idle: El bus está en reposo.
      Start bit: Inicio de la transmisión, el bus pasa de alto a bajo.
      Data bits: Transmisión de datos (5 a 9 bits).
      Parity bit: Comprobación de paridad (par o impar).
      Stop bit: Fin de la transmisión, el bus pasa de bajo a alto. (Algunos dispositivos necesitan 2 bits de parada).

   1. Baud rate
   2. Data bits

   Ventajas:
      - Fácil de implementar.
      - Bajo costo.
      - No necesita reloj.
      - No necesita sincronización.
      - No necesita un cable de tierra. (Half Duplex)

   Desventajas:
      - No es posible conectar más de dos dispositivos.
      - No es posible conectar dispositivos a larga distancia

   Formulas:
      - Baud rate = Fosc / ("8 ó 16" * UARTDIV) // Depende del oversampling
      - USARTDIV = Fosc / ("8 ó 16" * Baud rate)


   Oversampling: 
      - Sirve para mejorar la precisión de la recepción de datos.
      - 8x: 8 muestras por bit.
      - 16x: 16 muestras por bit.
      Bits | Bandera de Ruido | Valor
      000  | 0                | 0
      001  | 1                | 0
      010  | 1                | 0
      011  | 1                | 1
      100  | 1                | 0
      101  | 1                | 1
      110  | 1                | 1
      111  | 1                | 1
   


   Configuración STM32
   Baudrate     = 115200
   Fosc         = 16MHz
   OverSampling = 8x

   UARTDIV = 16MHz / (115200 * 8) = 17.36
   El valor entero es almacenado en 12 bits 
   La parte fraccionaria es almacenada en 4 bits -> 0.36 * 8 = 2.88 -> 3
   UARTDIV = 0x113

----------------------------------------------------------------------------------------------------------------
   
   Configuración STM32 ej 2
   Baudrate     = 9600
   Fosc         = 16MHz 
   OverSampling = 16x

   UARTDIV = 16MHz / (9600 * 16) = 104.166
   Parte entera = 104
   Parte fraccionaria = 0.166 * 16 = 2.66 -> 3
   UARTDIV = 0x683

*/