## Arquitecturas

![[Untitled 2.png|Untitled 2.png]]

Diagrama generico de una microcomputadora

![[Untitled 1.png]]

Diagrama generico de un microcontrolador

  

Se tienen dos arquitecturas:

- **Von Neumann  
      
    **La arquitectura Von Neumann es el diseño básico de las computadoras modernas, que consta de una CPU que ejecuta instrucciones almacenadas en memoria, junto con una unidad de control y E/S para operar con datos y dispositivos externos. La característica clave es que tanto las instrucciones como los datos se almacenan en la misma memoria.
- **Arquitectura Hardvard  
      
    **La arquitectura Harvard es un diseño de computadora que utiliza dos buses de datos separados para instrucciones y datos, lo que permite un acceso simultáneo y más eficiente a la memoria. Harvard se encuentra comúnmente en microcontroladores y procesadores embebidos. Harvard suele ser más rápida para ejecutar código, pero más compleja de implementar.

  

## Complex Instruction Set vs Reduced Instruction Set

Complex Instruction Set Computing (CISC) y Reduced Instruction Set Computing (RISC) son dos enfoques diferentes en la arquitectura de computadoras que se centran en cómo se ejecutan las instrucciones en un procesador:

1. **CISC (Complex Instruction Set Computing):**
    - **Complejidad:** Los procesadores CISC tienen un conjunto de instrucciones más grande y complejo que incluye una variedad de operaciones complejas.
    - **Instrucciones:** Pueden ejecutar instrucciones que realizan múltiples operaciones en una sola instrucción, lo que las hace más poderosas y menos frecuentes.
    - **Memoria:** Suelen acceder a la memoria de manera más eficiente, ya que pueden hacer más en una sola instrucción.
    - **Pipeline:** Los procesadores CISC a menudo tienen tuberías (pipelines) profundas para manejar la complejidad de las instrucciones.
2. **RISC (Reduced Instruction Set Computing):**
    - **Simplicidad:** Los procesadores RISC tienen un conjunto de instrucciones más pequeño y simple, generalmente con un número limitado de operaciones básicas.
    - **Instrucciones:** Cada instrucción RISC realiza una tarea simple y específica. Se promueve la ejecución de múltiples instrucciones simples en lugar de instrucciones complejas.
    - **Memoria:** Los procesadores RISC pueden requerir más acceso a memoria para completar una tarea debido a la simplicidad de las instrucciones individuales.
    - **Pipeline:** Los procesadores RISC a menudo tienen pipelines más cortos y simples, lo que facilita la ejecución de múltiples instrucciones en paralelo.

La principal diferencia radica en la filosofía de diseño. CISC se enfoca en proporcionar un conjunto de instrucciones más rico y complejo para reducir la cantidad de instrucciones necesarias para realizar una tarea, mientras que RISC se centra en la simplicidad y la ejecución eficiente de instrucciones simples en grandes cantidades. La elección entre CISC y RISC depende de las necesidades específicas de rendimiento y eficiencia de un sistema y puede variar según la aplicación.