/*
	* i2c.c
	* I2C Inter-Integrated circuit
   * Se escribe cuando el reloj está en alto
   * Se lee cuando el reloj está en bajo
	* La condicion de inicio / final se identifica ya que es el único momento en el que el bus cambia en SDA mientras SCL está en alto.
   * La transmisión de datos se realiza byte a byte, desde el bit más significativo al menos significativo.
	* Desarrollado por Phillips en 1982
	* 1982:
	*   Direcciones de 7 bits
   *   112 Dispositivos máximos
	*   100KHz
	* 1992:
	*   Direcciones de 10 bits
	*   900KHz
   *
   * Interfaz jerárquica
   *
   * - Controlador: 
   *   - Dirige el reloj del bus
   *   - Direcciona a los periféricos
   *   - Lee y escribe datos de los registros de los periféricos
   * 
   * - Periférico: 
   *   - Responden únicamente cuando son interrogados por el controlador
   *   - Nunca inician ubna transferencia de datos
   *   - Se conectan al bus con pines con colector y drenaje abierto
   * 
   * SCL: Serial Clock Line
   * SDA: Serial Data Line
   *   
   * PASOS:
   *              (Lectura)                       |   (Escritura)               
   * Controlador:                                 |   
   *    1. Envia la dirección del periférico.     |   
   *    2. Envía lectura o escritura.             |
   *    3. Enviar registro a leer o escribir.     |  
   * Periférico:                                  |   4. Enviar Dato (Si es escritura)
   *    4. Enviar Dato (Si es lectura)            |    
   * 
   * Señalizaciones:
   * - Start: Condición de inicio
   *           - El bus pasa de alto a bajo.
   * - Dirección: Dirección del periférico.
   *           - 7 bits para indicar la dirección del periférico.
   * - OP: Bit de Operación (Lectura o escritura).
   *           - 0: Escritura, 1: Lectura
   * - ACK: Acknowledge, el periférico bajó el bus.
   *           - 0: Acknowledge
   * - NACK: Not Acknowledge, el periférico no respondió.
   *           - 1: Not Acknowledge
   * - Stop: Condición de fin.
   *           - El bus pasa de bajo a alto, cuando la señal SDA está en alto. (El bus está en reposo).
   * - Idle: Bus en reposo, SCL y SDA en alto.
   * 
   * Por cada byte de datos, el receptor debe enviar un ACK.
   *
   * Tipos de Frame:
   * - Data Frame:
   *   - 8 bits de datos
   * - Address Frame:
   *  - 7 bits de dirección
   *  - 1 bit de R/W
   * - Control Frame:
   *  - 1 bit de Start / Stop
   *  - 1 bit de ACK / NACK
   * 
*/