DDRx (Data Direction Register) = Dirección

PORTx = Register OUT

PINx = Register IN

## Consideraciones en Puertos

Para el 328P, el puerto C (PORTC) es de solo 7 bits. Y el bit PINC6 es usado como señal de ~~RESET~~

  

Para leer el PINx, se necesita 1 ciclo más después de escribir en el PORTx para ver el cambio reflejado. Por lo general se hace

```Assembly
out PORTC, r24
nop 
lds r24, PINC
```

![[Untitled 3.png|Untitled 3.png]]