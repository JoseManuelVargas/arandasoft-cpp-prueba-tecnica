/**********************************************************************************
MIT License

Copyright (c) 2020 JoseManuelVargas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
**********************************************************************************/

/**
 * @file servidorrest.h
 * @brief Define la clase para el servidor REST. Con el fin de
	exponer las funcionalidades del sistema como un API REST
 * @author Jose Manuel Vargas Montero
 * @date julio 27 de 2020
 *
 */

#pragma once

#include <cpprest/http_listener.h>
#include <cpprest/filestream.h>

#include "controladorrest.h"

namespace servicio
{
	/**
	* @brief Clase para exponer servicio API REST
	* Ejemplo
	servicio::ServidorREST servidor;
	servidor.Abrir();
	std::cin.get();
	servidor.Cerrar();
	*/
	class ServidorREST
	{
	public:
		/**
		* @brief Constructor que inicializa las URIs y el controlador
		*/
		ServidorREST();
		/**
		* @brief Destructor para detener el servidor
		*/
		~ServidorREST();
		/**
		* @brief Inicia el servidor esperando arranque completamente
		* @return void:
		*/
		void Abrir();
		/**
		* @brief Cierrar el servidor esperando se detenga completamente
		* @return void:
		*/
		void Cerrar();
	private:
		// URL en la que escuchará el servidor
		web::http::uri uri_base;
		// Objeto HTTP listener de la librería
		web::http::experimental::listener::http_listener servidor;		
		// Bandera para saber si se está escuchando en la dirección
		bool esta_escuchando;
		ControladorREST controlador;
	};
}

