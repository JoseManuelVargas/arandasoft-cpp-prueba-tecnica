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
 * @file controladorrest.h
 * @brief Define la clase para el controlador REST. Con el fin de
	redireccionar las peticiones a los diferentes servicios
 * @author Jose Manuel Vargas Montero
 * @date julio 27 de 2020
 *
 */

#pragma once

#include <cpprest/http_client.h>

#include "servicioarboles.h"

namespace servicio
{
	/**
	* @brief Clase para redirigir las peticiones a los diferentes servicios.
	* Ejemplo
	ControladorRest controlador;
	servidor.support(web::http::methods::POST,
		std::bind(&ControladorREST::ProcesarPeticionPOST, &controlador, std::placeholders::_1));
	*/
	class ControladorREST
	{
	public:
		/**
		* @brief Constructor que inicializa los objetos de los servicios
		*/
		ControladorREST() = default;
		/**
		* @brief Recibe peticiones con método POST
		* @return void: El método se encarga de responder el mensaje HTTP
		*/
		void ProcesarPeticionPOST(web::http::http_request mensaje);
		/**
		* @brief Recibe peticiones con método GET
		* @return void: El método se encarga de responder el mensaje HTTP
		*/
		void ProcesarPeticionGET(web::http::http_request mensaje);
		/**
		* @brief Recibe peticiones de todos los métodos para redirigir
		* @return void: El método se encarga de responder el mensaje HTTP
		*/
		void ProcesarPeticionGeneral(web::http::http_request mensaje);
	private:
		ServicioArboles servicio_arboles;
	};
}

