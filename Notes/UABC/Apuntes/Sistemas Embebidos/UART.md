UART0 usado para depuración

UART1 Requiere reasignar puertos

UART2

| UART  | RX    | TX     | CTS (Clear to Send) | RTS (Request to Send) |
| ----- | ----- | ------ | ------------------- | --------------------- |
| UART0 | GPIO3 | GPIO1  |                     |                       |
| UART1 | GPIO9 | GPIO10 |                     |                       |
| UART2 | GPIO7 | GPIO8  |                     |                       |

UART FIFO 128 bytes fixed (Ring buffer optional)
