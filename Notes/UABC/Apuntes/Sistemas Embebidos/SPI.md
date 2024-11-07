Desarollada por Motorola para proveer comunicación serial; síncrona full-duplex entre controladores y periféricos

Comúnmente utilzada para comunicación con memorias flash, sesnsores, real-time clocks, ADCs, entre otros

Los datos del controlador y periférico son sincronizados en el flanco ascendente o descendente del reloj

El controlador y el periférico pueden transmitir datos al mismo tiempo

La interfaza SPI puede ser de 3 o 4 líneas

## Interfaz de 4 líneas

- Líneas de comunicación:
  - Clock (CLK)
  - Chip Select (CS)
  - Salida del controlador, entrada del periférico (MOSI)
  - Entrada del controlador, salida del periférico (MISO)
- El controlador genera la señal del reloj
- Dispositivos SPI soportan frecuencias de reloj más altas comparados con interfaces I2C
- Interfaces SPI solo pueden tener un controlador y uno o más periféricos
- La señal CS es utilizada para seleccionar el periférico. Normalmente se activa en bajo y se pone en alto para desconectar el periférico
- Se requiere una línea individual de CS para cada periférico conectado al controlador
- Para iniciar la comunicación, el controlador envía la señal del reloj y selecciona el periférico por medio de CS
- Deebido a que SPI es full-duplex, tanto el controlador como el periférico pueden enviar datos al mismo tiempo por medio de MISO y MOSI
- El flanco del reloj serial sincroniza el envío y muestreo de los datos
- SPI permite al usuario seleccionar el flanco ascendente o descendente para el envío o nmuestreo de los datos

## Polaridad y fase del reloj

- El controlador selecciona la polaridad y fase del reloj dependiendo los requerimientos del periférico
- El bit CPHA selecciona l a fase del reloj. Decide en cual flanco de reloj el periférico debe muestrear el dato
- El bot CPOL configura la polaridd del reloj durante el estado de inactividad
- El estado de inactividad es el periodo en que ~CS está en alto y pasa a bajo en el inicio de la transmisión. Y cuando ~CS está en bajo y pasa alto al final de la transmisión
- Si CPHA =1, el segundo flanco del reloj captura el primer bit de datos transmisido (en el flanco descendente si CPOL = 0, o en el flanco ascendente si CPOL = 1)
- Si CPHA =0, el primer flanco del reloj captura el primer bit de datos transmitido )en el flanco descendiente si CPOL = 1, o en flanco ascendente si CPOL = 0)
- Por default, CPHA = 0 y CPOL = 0

## Configuración con múltiples periféricos

- Multiples periféricos se pueden conectar a un controlador
- Los periféricos pueden conectarse en modo regular o en daisy-chain

### Daisy-Chain

- Los periféricos están configurados de manera que la misma línea ~CS está conectada a todos los periféricos y los datos se propagan de un periférico al siguiente
- Los datos son conectados directamente al primer periférico y éste provee datos al siguiente y así sucesivamente
- Todos los periféricos reciben el mismo reloj al mismo tiempo
- Conforme los datos se propagan de un periférico al siguiente, el número de ciclos de reloj requeridos para transmitir datos es proporcional a la posición del periférico en la daisy-chain

## QUAD SPI (QSPI)

- Especialmente diseñado para comunicación con chips de memoria
- El código en la memoria externa se podría ejecutar casi tan rápido como el de la memoria interna
- Útil en aplicaciones que involucran transferencias intensivas de datos de memora
- Se puede usar para almacenar código en una memoria externa al microcontrolador
- ¿Porqué usar QSPI en lugar de SPI para chips de memoria?
  - Las memorias lash son baratas y una buena opción para sistemas embebidos. Sin embargo, son lentas lo cual puede causar cuellos de botella en la aplicación
  - Aunque SPI es veloz, pudiendo alcanzar 16Mbps, los chips de memoria flash no son capaces de transferir datos a esa velocidad a través de una sola línea
  - A diferencia de SPI que usa líneas separadas para las entradas y salidas. QSPI configura las líneas de datos en el aire
  - Usa 4 líneas para transferir información: I0, I1, I2, I3

# Code

ESP32

- Tiene 4 SPI:
  - SPI0 y SPI1 son dos periféricos que comparten el mismo bus SPI (misma señales y E/S). La diferencia es que CS0 está conectado a la memoria flash principal para el almacenamiento del firmware y CS1 está conectado a PSRAM. No son usbles para interfaces SPI generales.
  - SPI2 y SPI3 son SPI de propósito general que están disponibles para que utilicen los clientes
  SPI2_HOST → HSPI
  SPI3_HOST → VSPI
  |             |         |                  |
  | ----------- | ------- | ---------------- |
  | Controlador | Función | GPIO por default |
  | HSPI        | MOSI    | 13               |
  |             | MISO    | 12               |
  |             | SCLK    | 14               |
  |             | CS0[1]  | 15               |
  | VSPI        | MOSI    | 23               |
  |             | MISO    | 19               |
  |             | SCLK    | 18               |
  |             | CS0[1]  | 5                |

> [!info] SPI Master Driver - ESP32 - — ESP-IDF Programming Guide v5.3.1 documentation  
> SPI Master driver is a program that controls ESP32's General Purpose SPI (GP-SPI) peripheral(s) when it functions as a master.  
> [https://docs.espressif.com/projects/esp-idf/en/v5.3.1/esp32/api-reference/peripherals/spi_master.html](https://docs.espressif.com/projects/esp-idf/en/v5.3.1/esp32/api-reference/peripherals/spi_master.html)

> [!info] SPI Slave Driver - ESP32 - — ESP-IDF Programming Guide v5.3.1 documentation  
> SPI Slave driver is a program that controls ESP32's General Purpose SPI (GP-SPI) peripheral(s) when it functions as a slave.  
> [https://docs.espressif.com/projects/esp-idf/en/v5.3.1/esp32/api-reference/peripherals/spi_slave.html](https://docs.espressif.com/projects/esp-idf/en/v5.3.1/esp32/api-reference/peripherals/spi_slave.html)
