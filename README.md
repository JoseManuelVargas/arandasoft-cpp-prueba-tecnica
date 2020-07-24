# Prueba técnica para postulación de cargo de desarrollador C++
Repositorio para el desarrollo de la prueba

# Información general

## Proyecto
Se debe realizar un servicio REST que permite crear árboles binarios y consultar los ancestros de un árbol dado.
La información técnica se encuentra en el siguiete [documento](prueba_tecnica_cpp.pdf).

## Carpetas
Se usan las siguientes carpetas para los usos señalados más abajo:

* docs: Esta carpeta almacena todo lo relaciona a documentación, diseño y demás archivos que hagan parte del diseño arquitectónico.
* benchmark: Se crearán archivos para pruebas de desempeño, tales como tiempos de respuesta, capacidad de resolver número de peticiones y manejo de concurrencia.
* www: Se almacenarán archivos HTML relacionados con documentación e información general del proyecto y sus módulos presentada como página HTML.
* cmake: Carpeta donde se almacenan archivos de configuración para cmake.
* [Módulo]: Cada módulo desarrolado tendrá una carpeta propia.
* build y build_*: Estas carpetas se usan para construir la solución. No se agregan al repositorio

## Ramas
Se proponen las siguientes ramas para el manejo del proyecto

* master: Rama principal para producción
* desarrollo: Rama usada para crear módulosy código nuevo. Dentro de esta rama se manejarán los diferentes módulos y funcionalidades.
* errores: Se tendrán ramas por errores reportados

