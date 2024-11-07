- Opera en la banda ISM (Industrial, Scientific and Medical) de 2.4 GHz
- Rango de 10 a 100 metros
- Bluetooth Basic Rate/Enhanced data rate (BR/EDR)
- Bluetooth Low Energy

# Protocol Stack

- Bluedroid -> VHCI (VIrtual Host Controller Interface) -> Bluetooth Controller
- Apache

## Componentes comúnes

--- start-multi-column: ID_h74y

```column-settings
Number of Columns: 2
Largest Column: standard
```

- Bajo nivel
  - RF
    - Capa física.
      - Transmisión por radiofrecuencia
      - Classic:
        - Se comparten seed
        - Se comparten clock
        - Generan siguiente spot
        - Cambia de canal 1600 veces por segundo

--- column-break ---

- Alto nivel
  - Protocolo Link Manager
  - Host Controller Interface
- SDP: Service Discovery Protocol
  - Que servicios ofrece un dispositivo
- RFCOMM:
  - Emular puerto serie sobre Bluetooth
- OBEX:
  - Intercambiar objetos como archivos y contactos sobre bluetooth
- TCS:
  - Protocolo de llamadas sobre bluetooth
- PPP:
  - Protocolo de IP sobre bluetooth

--- end-multi-column

# Redes Bluetooth (Piconets)

- Modelo Master / Slave para controlar cuando los dispositivos pueden enviar datos
- Un master se puede conectar a 7 slaves
- Los slaves se pueden conectar solo a un master

# Redes Scatternet (Varias piconets)

- Un dispositivo puede ser master en una piconet y slave en otra
- Puede ser slave en ambas
- No puede ser master de ambas

# Direcciones y Nombres

- A la dirección se le denomina BD_ADDR
- Cada dispositivo Bluetooth tiene una dirección única de 48 bits
- Los 24 bits más significativos (OUI) son el identificador único de la organización que lo manufacturó
- Los 24 bits menos significativos son la parte única de la dirección
- El nombre amigable puede ser de hasta 248 bytes y no tiene que ser único

# Conexión

Proceso que involucra tres estados progresivos

- Para que 2 dispositivos puedan comunicarse deben realizar el proceso de comunicación:
  - Petición de Consulta:
    - Si dos dispositivos no se conocen, uno debe realizar una consulta para descubrir al otro. Un dispositivo envía la solicitud de consulta y cualquier dispositivo que escuche responderá con su dirección y posiblemente su nombre y otra información
  - Localización(Conexión):
    - es la formación de la conexión entre dos dispositivos
  - Conexión:
    - Después del proceso de paginación, el dispositivo ingresa al estado de conexión. Mientras está conectado, puede participar activamente o puede ponerse en modo de suspensión de bajo consumo

# Estados de conexión

- Activo:
  - Es el modo regular donde el dispositivo activamente transmite o recibe datos
- Sniff:
  - Es un modo de ahorro de energía, el dispositivo está menos activo. Se duerme y solo escucha por datos a un cierto intervalo
- Hold:
  - Es un modo temporal de ahorro de energía, el dispositivo se duerme por un periodo definido y después retorna a modo activo
- Park:
  - Es el modo de sueño más profundo. El master indica al slave que duerma, el slave va a estar inactivo hasta que el master indique que despierte

# Perfiles de Bluetooth

Depende de las capas (SDP, RFCOMM, ETC)

- HFP: Hands Free Profile
- PBAC: Process-Based Access Control
- A2DP: Advance Audio Distribution Profile
- AVRCP: Audio Video Reome Control Profile
- MAP: Messaging Access Protocol
