/*
   * Proceso de Escritura
   *  El controlador envía la dirección del dispositivo (7 bits).
   *  El octavo bit es la opción (WR: 0).
   *  El dispositivo responde con un ACK.
   *  El controlador envía el registro (8 Bits).
   *  El dispositivo responde con un ACK.
   *  El controlador coloca los datos a escribir, por cada byte se requiere un ACK del dispositivo.
   *  El controlador hace la condición de fin.
   * 
   * Proceso de Lectura
   *  El controlador envía la dirección del dispositivo (7 bits).
   *  El octavo bit es la opción (WR: 0).
   *  El dispositivo responde con un ACK.
   *  El controlador envía el registro (8 Bits).
   *  El dispositivo responde con un ACK.
   *  El controlador envía una condición de inicio repetida (Mandar una condición de inicio .
   *  El controlador envía la dirección del dispositivo (7 bits).
   *  El octavo bit es la opción (RD: 1).
   *  El dispositivo coloca un ACK.
   *  El dispositivo escribe el valor del registro a leer, por cada byte se requiere un ACK del controlador.
   *  El controlador no envía un ACK cuando no se requieren más datos.
   * 
   * La condición de inicio repetida es 
   * 
   * El periférico puede tomar control de la linea SCL para extender el tiempo de lectura.
   *  
   * 
   * 
*/