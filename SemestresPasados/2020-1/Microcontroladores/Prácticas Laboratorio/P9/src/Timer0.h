#ifndef _TIMER0_H
#define _TIMER0_H
#include <inttypes.h>

/* Función para inicializar el Timer0 y generar */
/* La temporización de 1 Sec. */
void Timer0_Ini(void);

/* Función para verificar bandera del segundo */
uint64_t millis(void);

#endif /* _TIMER0_H */