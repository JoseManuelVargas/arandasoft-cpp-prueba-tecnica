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

## Documentación

* Se tiene el modela hecho de acuerdo a UML. Para ello se guardan en archivos XML para facilitar el versionamiento. Sin embargo se usará la siguiente carpeta de [drive](https://drive.google.com/drive/folders/1Nn47Xoq1NjK3ruurDJm0apEtBZ9_Y2KP?usp=sharing) para subir los archivos de Enterprise Architect.
* Para la gestión de tareas y actividades se usa el siguiente [tablero](https://trello.com/b/imyAlWAY/prueba-t%C3%A9cnica) en [trello](https://trello.com/es).
* Para visualizar la descripción de los endpoints se debe abrir el [archivo](docs/ENDPOINTS/swagger.yaml) y pegar el contenido en el editor de [swagger](https://editor.swagger.io/).

## Estilo del código
* Se adopta el estilo de código para C++ recomendado por google en el [documento](https://google.github.io/styleguide/cppguide.html).
* El código y comentarios se desarrollará en español.
* Una excepción para no usar español es el encabezado de licencia, dependiendo de cuál se adopte.

## Módulos
El proyecto cuenta con diferentes módulos, cada uno estará en su propia carpeta con su propio archivo CMakeLists.txt. Algunos módulos son librerias, frameworks y/ SDK de terceros. Estos últimos son incorporados al proyecto como submódulos. Los módulos son los siguientes:

* googletest: Para poder haces pruebas unitarias. Se toma del [repositorio](https://github.com/google/googletest)
* json: Para el manejo de objetos tipo json, necesario para el manejo de peticiones y respuestas. Se toma del siguiente [repositorio](https://github.com/nlohmann/json)
* soci: ORM para bases de datos para lenguaje de programación C++. En este caso se integra con SQLite como gestor de base de datos. Se toma del [repositorio](https://github.com/SOCI/soci)



