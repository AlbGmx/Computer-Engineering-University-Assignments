# Importancia de los sleep modes

## Modos de operación:

- Active: El radio está encendido. El chip puede recibir, transmisitr o escuchar.
- Modem-sleep mode: CPU operacional, WiFi/Bluetooth deshabilitado por momento.
- Light-sleep mode:
- Deep-sleep mode:

| Modo          | Consumo típico |
| ------------- | -------------- |
| Activo        | 95 - 240 mA    |
| Modem         | 3 - 20 mA      |
| Light         | 0.8mA          |
| Deep          | 10uA - 0.15mA  |
| Hibernación ? | 2.5uA          |

## Modem-sleep mode

Disponible solo en modo estación

## Light-sleep mode

- La mayor parte del sistema está en modo operacional
- El sistema regresa a modo normal rápidamente cuando ocurre un evento para despertar
- El CPU está suspendido, no ejecuta código
- El

## Deep-sleep mode

- Es uno de los modos de ahorro de energía mas profundos
- El CPU está suspendido, no ejecuta ninguna instrucción
- La mayor parte del sistema entra en un estado de suspención
-
