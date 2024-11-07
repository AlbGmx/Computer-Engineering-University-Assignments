Una función en C debe estar definida como externa para que pueda ser vista por el ensamblador

```C
.extern my_C_function
```

Una rutina en ensamblador debe ser declarada como global para que pueda ser vista por el compilador C

```Assembly
.global my_assembly_function
```

Un archivo C que pretenda llamar código ensamblador deberá tener la función prototipo declarada como externa

```C
extern unsigned char my_assembly_function(unsigned char, unsigned int)
```

---

## Uso de Registros

|Registro|Descripción|Ensamblador llamado desde C|Ensamblador que llama a C|
|---|---|---|---|
|r0|Temporal|Guardar y restaurar si es usado|Guardar y restaurar si es usado|
|r1|Siempre es 0|Debe ser borrado antes de retornar función|Debe ser borrado antes de retornar función|
|r2-r17|"Cal-saved”|Guardar y restaurar si es usado|Puede usarse libremente|
|r28|"Cal-saved”|Guardar y restaurar si es usado|Puede usarse libremente|
|r29|"Cal-saved”|Guardar y restaurar si es usado|Puede usarse libremente|
|r18-r27|"Call-used”|Puede usarse libremente|Guardar y restaurar si es usado|
|r0|"Call-used”|Puede usarse libremente|Guardar y restaurar si es usado|
|r31|"Call-used”|Puede usarse libremente|Guardar y restaurar si es usado|

**Call saved:** Llamar estas funciones en C deja los registros sin modificar. Una rutina de ensamblador llamada desde C que use estos registros, deberá guardar y restaurar los contenidos de los registros que use.

**Call used:** Significa que los registros son disponibles para cualquier uso. Un código ensamblador que llame una función en C deberá guardar cualquiera de los registros que use ya que el código compilado no los guardará.

---

## Paso de parámetros

|Registro|r19|r18|r21|r20|r23|r22|r25|r24|
|---|---|---|---|---|---|---|---|---|
|Order de los bytes|b7|b6|b5|b4|b3|b2|b1|b0|

---

## Standard RS-232

1 lógico es un voltaje negativo, 0 lógico es un voltaje positivo (desde -3v hasta 3v)

La transmisión termina con el envío del último bit (Bit de paro) que siempre es 1 lógico

PE0 es recepción

---

### USART

UART BAUDRATE REGISTER (UBRR): 16 bits

$BAUD = \frac{f_{osc}}{16*UBRR}$

UDR TRANSMIT(Siempre va a estar vacío): Al pasar el valor a TRANSMIT SHIFT REGISTER se borra el UDR

UDR RECIEVE (BUFFER DE 1 BYTE)

IDLE: 1 Lógico

Start bit: 0 Lógico

Data bits: 0 a 8

P: Paridad

El 9no bit se usa para distinguir si es payload o comando

SP1 [sp2]: stop bit; SP1 obligatorio [sp2 opcional (delay)]: 0 Lógico

Paquete mínimo para 8 bits (Payload: 8 bits; Start bit: 1; Stop bit: 1) 10 bits en total

  

Doble velocidad síncrona ofrece menor porcentaje de error

$%-symbol ]= \frac{BaudRate_$

## USART

UARTDR is empty: Bandera spameada, se setea cuando se quiera mandar, borrar cuando no sea utilizada

$(Error \%)$