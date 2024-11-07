# Arquitectura de aplicaciones

---

- Monolítica:
    - Todos dependen de todos
    - Si uno falla, todo falla
- Microservicios:
    - Aplicaciones levemente conectadas
    - Una falla no detiene todo el sistema.

# Amazon Simple Notification Service (SNS)

---

- Los mensajes se publican en temas
- Los suscriptores reciben inmediatamente los mensajes de sus temas.

Publicación de actualizaciones de un solo tema → publicación de actualizaciones de varios temas

# Amazon Simple Queue Service (SQS)

---

- Enviar, almacenar y recibir mensajes entre componentes de software.
- colocar los mensajes en la cola sin necesidad de que otros servicios estén disponibles.

# Servicios de computo sin servidor (Server less)

---

Código ejecutado en servidores

- Ejecute código sin necesidad de aprovisionar o administrar servidores
- pague solo por el tiempo de computo mientras se ejecuta el código
- Utilice otros servicios de AWS para activar automáticamente el código.

Cargar código→ configurar el código para ser activado desde un origen de evento → configurar origen de evento → pagar solo lo que se utilizo

# Servicios de contenedores de AWS

---

Contenedor: Proporciona una manera de empaquetar todo un código.

- Un host con varios contenedores.
- Orquestadores de contenedores.

## Amazon Elastics Container Services (Amazon ECS)

- Ejecutar y escalar aplicaciones de contenedores.
- Utilizar las llamadas api simples para controlar las aplicaciones habilitadas para Docker.

## Amazon Elastic Kubernetes Service (Amazon EKS)

- Ejecutar y escalar aplicaciones de Kubernetes.
- Actualizar fácilmente las aplicaciones con nuevas funciones.

## AWS Fargate

- Ejecute contenedores sin servidor.
    - Amazon ECS.
    - Amazon EKS..
- Pague únicamente los recursos utilizados.