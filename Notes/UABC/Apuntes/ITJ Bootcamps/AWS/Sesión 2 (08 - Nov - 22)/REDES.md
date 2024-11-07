# Amazon Virtual Private cloud (Amazon VPC)

---

Permite lanzar recursos de AWS en una red virtual

## Subredes

- Sección de una VPC en la que puede colocar grupos de recursos aislados .
- Una subred puede ser publica o privada.
- Gateway de internet:
    - Conexión entre una VPC e internet.
- Gateway privado virtual:
    - Conexión entre una VPC e internet con una capa de protección adicional.
- AWS Direct Connect:
    - Conexión dedicada entre una VPC y un centro de datos (on premises).

## Trafico de red en una VPC

Cliente → Paquete → Internet → Gateway → ACL → VPC → Subred publica → Grupos de seguridad → Instancias de Amazon EC2

## Listas de control de acceso

Firewall virtual para una subred.

- La ACL de red predeterminada permite el trafico entrante y saliente.
- Las ACL de red personalizadas deniegan todo el trafico entrante y saliente.
- Las ACL realizan el filtrado de paquetes sin estado.
- Antes de que un paquete pueda salir de una subred, debe compararse con las reglas de salida.

## Grupos de seguridad

Firewall virtual para una instancia de Amazon EC2

- Los grupos de seguridad realizan el filtrado de paquetes con estado.
- Recuerdan decisiones anteriores que se tomaron para los paquetes entrantes.
- De forma predeterminada:
    - Deniega todo el tráfico entrante.
    - Permite todo el tráfico saliente.

# Interacción con la red global de AWS

---

# Sistema de Nombres de Dominio (DNS)

Cliente → Resolución DNS del cliente → Servidor DNS de la empresa

## Road 53

Servicio web de DNS

- Enruta a los usuarios a aplicaciones de internet.
- Conecta las solicitudes de los usuarios a la infraestructura dentro y fuera de AWS.
- Administra los registros de DNS de los nombres de dominio.