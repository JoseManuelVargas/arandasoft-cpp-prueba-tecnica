# Prueba técnica para postulación de cargo de desarrollador C++
Repositorio para el desarrollo de la prueba

# Información general

## Proyecto
Se debe realizar un servicio REST que permite crear árboles binarios y consultar los ancestros de un árbol dado.
La información técnica se encuentra en el siguiete [documento](prueba_tecnica_cpp.pdf).

## Requisitos
* Se debe contar con SQLite3 instalado en el computador. Se requieren los archivos include y de librerías para ser utilizados al momento de construir SOCI.
* Se debe contar con [cpprestsdk](https://github.com/microsoft/cpprestsdk) instalado. Para Windows se asume ha sido instalado usando VCPKG. Este se asume que está en el directorio c:/dev/vcpkg. En caso de no ser así se puede establecer la ruta con -DVCPKG_ROOT. Se puede incluir esta librería manualmente una vez corrida la sentencia cmake [opciones] .. abriendo el proyecto de Visual Studio e instalando la librería con el administrador de paquetes Nuget.

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
* Se cambia las guarda de los archivos .h por la línea #pragma once.
* Se crea archivo de plantilla para usarlos como guía
* Se usarán clases para definiciones que requieran jerarquía y herencia, mientras que se usarán structs para definiciones que solo requieran encapsulamiento. Aplican excepciones.

## Módulos
El proyecto cuenta con diferentes módulos, cada uno estará en su propia carpeta con su propio archivo CMakeLists.txt. Todos los módulos deben definir su propio namespace. Algunos módulos son librerias, frameworks y/ SDK de terceros. Estos últimos son incorporados al proyecto como submódulos. Los módulos son los siguientes:

* googletest: Para poder haces pruebas unitarias. Se toma del [repositorio](https://github.com/google/googletest)
* json: Para el manejo de objetos tipo json, necesario para el manejo de peticiones y respuestas. Se toma del siguiente [repositorio](https://github.com/nlohmann/json)
* soci: ORM para bases de datos para lenguaje de programación C++. En este caso se integra con SQLite como gestor de base de datos. Se toma del [repositorio](https://github.com/SOCI/soci)
* arboles: Define las clases e implementa la lógica para el manejo de árboles binarios.
* basedatos: Define las clases necesarias para conectar una base de datos SQLite usando SOCI. También define los mapeados necesarios para consultar y almacenar los objetos.
* servicio: Define el cliente y servidor REST. El servidor se encargará de exponer el API REST, mientras que el cliente se usa para realizar pruebas unitarias al servicio. Define el controlador y las clases del servicio, para validar errores en las solicitudes y responder con el mensaje adecuado.

## Pruebas
Cada módulo cuenta con su conjunto de pruebas unitarias.
Adicionalmente se crea un código en python que realiza pruebas unitarias de manera externa, ubicado en www/pruebs.py Para ejecutarlo se debe correr la aplicación y  luego ejecutarla usando python3 www/pruebas.py


