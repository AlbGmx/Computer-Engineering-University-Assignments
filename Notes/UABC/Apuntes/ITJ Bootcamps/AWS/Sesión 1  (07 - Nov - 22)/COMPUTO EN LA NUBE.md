# Amazon Elastic Compute Cloud (Amazon EC2)

- Utilice una capacidad de computo segura y de tamaño modificable
- Inicie instancias (Maquinas Virtuales) en minutos
- Pago solo por lo que se utiliza

Lanzamiento de una instancia utilizando una plantilla AMI (Amazon Machine Image) → Conexión a la instancia → Uso de la instancia

# Tipos de instancias

## De proposito general

- Equilibran los recursos de cómputo, memoria y redes.
- Son adecuadas para un rango de cargas de trabajo.

## Optimizadas para computo

- Ofrecen procesadores de alto rendimiento.
- son ideales para las aplicaciones que requieren gran cantidad de recursos de computo y las cargas de trabajo de procesamiento por lotes.

## Optimizadas de memoria

Ofrecen un rendimiento rápido para las cargas de trabajo que requieren un uso intensivo de memoria.

Son adecuadas para las bases de datos de alto rendimiento.

## De cómputo acelerado

- Utilizan aceleradores de hardware para agilizar el procesamiento de datos .
- son ideales para gráficos y streaming de aplicaciones.

## Optimizadas de almacenamiento

- Ofrecen baja latencia y gran cantidad de operaciones entrada/salida por segundo (IOPS)
- Son adecuadas para sistemas de archivos distribuidos y aplicaciones de almacenamiento de datos.

# Precios de Amazon EC2

## Opciones de precios de las instancias de Amazon EC2

- Bajo demanda:
    - No se aplican costo iniciales ni contratos mínimos.
    - Es ideal para las cargas de trabajo irregulares de corto plazo.
    - Se ejecuta continuamente hasta que sea detenida.
    - No se recomienda para cargas de trabajo extensas (1 año o mas).
- Spot:
    - Es ideal para las cargas de trabajo con tiempos de inicio y finalización flexibles.
    - Ofrece ahorros en precios bajo demanda.
- Reservadas:
    - Proporciona un descuento de facturación sobre los precios bajo demanda.
    - Requiere comprometerse por plazos de 1 o 3 años.
- Compute Saving Plans:
    - Ofrece hasta un 66% de ahorro en comparación con los costos bajo demanda para un uso uniforme de cómputo.
    - Requiere comprometerse por plazos de 1 o 3 años.
- Instancia dedicada:
    - Una instancia EC2 que se ejecuta en una VPC en hardware para un solo cliente.
    - Mayor costo en comparación con las instancias de Amazon EC2 Standard
- Servidor dedicado:
    
    - Un servidor físico con capacidad de instancias EC2 para un único cliente.
    - La opción mas costosa de Amazon EC2.
    
    # Amazon EC2 Auto Scaling
    
    - Escale la capacidad a medida que cambien los requisitos informáticos
    - Utilice el escalado dinamico y el escalado predictivo.
    - Escalado dinámico:
        - Instancias:
            - Mínima
            - Deseada
            - Máxima
        - Escalado predictivo: Utilizando machine learning observa el patrón de demanda de las instancias y realiza cambios dependiendo de lo aprendido.
    
    # Elastic Load Balancing
    
    - Distribuye el trafico entre recursos automáticamente.
    - Punto único de contacto.
    - Distribuye el trafico entre zonas de disponibilidad.