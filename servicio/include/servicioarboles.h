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
 * @file servicioarboles.h
 * @brief Define la clase para el Servicio REST de árboles binarios. Con el fin de
	manejar las funciones referentes a árboles binarios
 * @author Jose Manuel Vargas Montero
 * @date julio 27 de 2020
 *
 */

#pragma once

#include <cpprest/http_client.h>

#include "utilidadesservicio.h"

namespace servicio
{
	/**
	* @brief Clase para manejar los servicios de árboles binarios.
	* Ejemplo
	ServicioArboles servicio;
	servicio.CrearArbolBinario(mensaje);
	*/
	class ServicioArboles : public UtilidadesServicio
	{
	public:
		/**
		* @brief Constructor 
		*/
		ServicioArboles() = default;
		/**
		* @brief El método procesa la creación de árbol binario
		* @return void: El método se encarga de responder el mensaje HTTP
		*/
		void CrearArbolBinario(web::http::http_request& mensaje);
		/**
		* @brief Procesa el cálculo de ancestro común a dos nodos
		* @return void: El método se encarga de responder el mensaje HTTP
		*/
		void CalcularAncestroComun(web::http::http_request& mensaje);
	};
}

