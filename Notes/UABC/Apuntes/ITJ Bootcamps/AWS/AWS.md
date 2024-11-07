# SESIONES

---

[[Sesión 2 (08 - Nov - 22)]]

[[Sesión 3 (09 - Nov - 22)]]

[[Sesión 4 (10 - Nov - 22)]]

## Capex - opex → opex

Capital expenditure (Gasto capital)

Operational expenditure (Gasto operacional

## On premises - nube privada/publica/hibrida

## Regiones

Ubicación física en todo el mundo donde agrupamos los centros de datos.

## Zonas de disponibilidad

Uno o más centros de datos discretos con alimentación, redes y conectividad redundantes en una región de AWS

## Puntos de presencia

# Servicios de cómputo

---

## Amazon EC2

- Capacidad segura y de tamaño modificable.
- Permite:
    - Arrancar instancias en cuestión de minutos [AMI (Amazon Machine Image)].
    - Escalar y reducir verticalmente la capacidad.
- Costo variable
    - Instancias:
        - Bajo demanda.
        - Tipo spot.
        - Reservadas.
- Auto Scaling:
    - Permite:
        - Agregar o eliminar de forma automática instancias según las condiciones definidas por el usuario.
        - Mantener la disponibilidad de las aplicaciones.
        - Beneficiarse del escalado predictivo, programado y dinámico.
    - Se agregan instancias cuando sea necesario.

## Elastic Load Balancing

- Distribuye el trafico entre recursos automáticamente.
- Punto único de contacto.
- Distribuye el trafico entre zonas de disponibilidad.

## Application Load Balancer

- Trafico http/https
- Funciona en nivel capa 7

## Elastic Container Services

**Contenedor: Aplicación que contiene todo lo necesario para funcionar encapsulado.**

- Servicio de aprovisionamiento de contendores altamente escalable y de alto rendimiento.
    - Ejecuta y escala aplicaciones en contenedores AWS.
    - Utiliza llamadas a la API simples con el fin de lanzar y detener aplicaciones habilitadas para Docker.

## AWS Lambda

- Permite ejecutar el código sin necesidad de aprovisionar o administrar servidores.
- Se paga solo por el tiempo de computo en el que se esta ejecutando el código.
- permite utilizar otros servicios para utilizar el código de forma automática.
- Servicio serverless

# Almacenamiento

---

## Amazon S3

**Sistema de almacenamiento orientado a objetos.**

- Los archivos se almacenan en buckets.
- Es compatible con una amplia variedad de casos de uso.
- Permite:
    - Realizar el seguimiento de muchas variantes de algún objeto gracias al control de versiones.
    - Evitar la eliminación accidental de objetos.

## Amazon Elastic Block Storage (EBS)

**Solo se puede accesar mediante una maquina virtual.**

- Almacenamiento de bloque de alto rendimiento.
- Replicación en una zona de disponibilidad con 99.999% de disponibilidad.
- Escalado y reducción vertical en cuestión de minutos.
- Cuatro tipos de volumen para optimizar precio y rendimiento.
- SSD de uso general
- SSD de IOPS provisionadas (IPOS, Input-Output per second)
- HDD de rendimiento optimizado.
- HDD frío.

## Amazon Elastic File System (Amazon EFS / Amazon FSx)

- Constituye un sistema de archivos sencillo, escalable y completamente administrado.
- Pueden escalarse bajo demanda a magnitudes de petabytes sin interrumpir.
- Elasticidad dinámica.
- Almacenamiento de archivos compartidos.
- Rentabilidad.

# Servicios de bases de datos de AWS

---

## Amazon Relational Database Service (Amazon RDS)

**Servicio de base de datos relacional completamente administrado**

- Automatiza la administración de aquellas tareas que requieren mucho tiempo.
- Simple y compatible.
- Fácil de administrar.
- Optimizados para memoria, rendimiento o E/S.
- Tipos de motor de RDS:
    - Amazon Aurora
    - MariaDB
    - PostgreSQL
    - MySQL
    - SQL Server
    - Oracle Database
- Aprovisionamiento:
    - Implementación Multi-AZ para una conmutación por error automatizada e integrada.
    - Alta disponibilidad y fiabilidad
    - uso de replicas de lectura para cargas de trabajo de bases de datos de lectura intensiva.

## Amazon DynamoDB

- Base de datos de documentos y de clave-valor NoSQL rápida y flexible.
- ServerLess.
- Rendimiento de un solo digito a cualquier escala.
- BD multirregión.
- Casos de uso:
    - aplicaciones web sin servidor
    - videojuegos

## AWS Database migration Service (AWS DMS)

- Posibilita la migración de bases de datos

# Servicio de redes y de entrega de contenido AWS

---

## Amazon Virtual Private Cloud (VPC)

Posibilidad de comenzar a construir nuestros servicios.

- Lanzamiento de recursos de AWS en una red virtual.
- Control absoluto del entorno de redes virtuales.
- Creación de subredes y aprovechamiento de varias capas de seguridad.
- Puede comenzar a trabajar de forma rápida y sencilla.
- Pueden usarse otros servicios de Amazon.

## Amazon Route 53

Servicio DNS escalable y de alta disponibilidad con capacidad de ruteo.

- convierte nombres de dominio a IP numérica.
- conecta las solicitudes de los usuarios con infraestructuras que se ejecutan dentro y fuera de AWS.
- dirige el tráfico hacia puntos de enlace
- Registrar nuevos nombres de dominio.

## AWS Direct Connect

Es una conexión de red dedicada desde las instalaciones a AWS

- Reduce los costos de red y aumenta el rendimiento del ancho de banda.
- Divide la conexión en varias interfaces virtuales.

## Amazon CloudFront

Servicio de entrega de contenido

- Rápida entrega de contenido a clientes
- Perfecta integración a AWS
- Sin generación de cargas
- No hay compromisos mínimos
- Se paga solo por lo que se utiliza
- Incluye amplia variedad de casos de usos
    
    [](https://www.notion.soundefined)
    
    - Cache
    - Streaming

# Seguridad

---

Seguridad EN la nube → CLIENTES

Seguridad DE la nube → AWS

![[Untitled.png]]

- Administración de identidad y acceso (IAM)
    - Controlar acceso de usuarios
    - Crear y admin grupos
    - Habilita la autenticación multifactor
    - Usuarios IAM:
        - Entidad o usuario que representa una persona
    - grupos de IAM:
        - Conjunto de usuarios
        - permite administrar con facilidad
        - un usuario puede varios grupos
    - MFA:
        - Proporciona una capa de seguridad adicional para la cuenta AWS
- Controles de detección
- Protección de infraestructura
- Protección de datos
- Conformidad

## Servicios

- Amazon cognito

## Servicios de Protección

- AWS Shield
- AWS Web Application Firewall (WAF)
- AWS Firewall Manager

## Conformidad

### AWS Artifact

Portal de autoservicio para el acceso a los informes de conformidad de AWS