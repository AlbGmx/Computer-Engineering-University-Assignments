/*
    * Autor: Emmanuel Alberto Gómez Cárdenas
    * Fecha: 13/02/2023
    * Descripcion: Practica 1, Enmascaramiento
    * Laboratorio de la clase Microcontroladores
*/

/******************************************************************************
Examples code
*******************************************************************************/

#include <stdio.h>
#include <inttypes.h>
/*
  Ejercicios de enmascaramientos.
  Lo que se busca es que imprima el valor que esta comentado,
  alterando unicamente el valor anterior utilizando los operadores bitwise.
  Todas las conversiones deberian ser posibles con una sola operacion
*/
int main()
{
    uint16_t a = 0;
    printf("\na = %X", a);
    //  Como ejemplo se da el analisis de la primera operacion

    // 1 B0B0
    //        hex           bin
    //   a = 0000 = 0000 0000 0000 0000  (valor original)
    //       B0B0 = 1011 0000 1011 0000  (valor que se desea)
    //   Observamos que todas las diferencias radica en que los bits tienen que estar habilitados,
    //   por lo tanto usaremos el operador OR (|) para convertir esos bits en '1's

    //    0000 0000 0000 0000  (valor original)
    // OR 1011 0000 1011 0000  (mascara para lograrlo) = (1<<15) | (3<<12) | (1<<7) | (3<<4)
    //------------------------------------------------
    //    1011 0000 1011 0000  (valor que se desea)
    a |= (1 << 15) | (3 << 12) | (1 << 7) | (3 << 4);
    printf("\na = %X", a);

    // 2 BABA
    a |= (1 << 11) | (1 << 9) | (1 << 3) | (1 << 1);
    printf("\na = %X", a);

    // 3 BEBE
    a |= (0x1 << 10) | (1 << 7) | (0x1 << 2);
    printf("\na = %X", a);

    // 4 FE00
    a ^= (1 << 14) | (1 << 7) | (0xF << 2) | (1 << 1);
    printf("\na = %X", a);

    // 5. FEAA
    a |= (1 << 7) | (1 << 5) | (1 << 3) | (1 << 1);
    printf("\na = %X", a);

    // 6. 0155
    a ^= ~0;
    printf("\na = %X", a);

    // 7. 0001
    a &= (1);
    printf("\na = %X", a);

    // 8. 0100
    a ^= (1 << 8) | 1;
    printf("\na = %X", a);

    return 0;
}
