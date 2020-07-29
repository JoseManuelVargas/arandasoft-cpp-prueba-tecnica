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
 * @file clienterest.h
 * @brief Define la clase para el cliente REST. Con el fin de 
	ser utilizado en pruebas unitarias.
 * @author Jose Manuel Vargas Montero
 * @date julio 27 de 2020
 *
 */

#pragma once

#include <string>
#include <vector>

#include <cpprest/http_client.h>

namespace servicio
{
	/**
	* @brief Clase para utilizar los servicios del aplicativo, para pruebas.
	* Ejemplo
	servicio::ClienteREST cliente;
    std::vector<int> valores = { 11, 15, 2, 19, 5 };
    long arbol_id = cliente.CrearArbol(U("Arbol 1"), valores);
    ucout << "Arbol creado: " << arbol_id << std::endl;
    long ancestro = cliente.ConsultarAncestroComun(arbol_id, 11, 2);
    ucout << "Ancestro común: " << ancestro << std::endl;
	*/
	class ClienteREST
	{
	public:
		/**
		* @brief Constructor que inicializa las URIs y el cliente HTTP.
		*	Por defecto utiliza la URI base localhost:5000
		*/
		ClienteREST();
		/**
		* @brief Envía la petición para crear un árbol binario.
		* @param nombre: El nombre que se asignará al árbol
		* @param valores: Vector con los valores de los nodos del árbol
		* @return long: El ID del árbol creado
		*/
		long CrearArbol(const utility::string_t& nombre, std::vector<int>& valores);
		/**
		* @brief Envía la petición para calcular el ancestro común a dos nodos
		* @param id_arbol: El ID del árbol retornado en CrearArbol(...)
		* @param nodo1: El valor del nodo1
		* @param nodo2: El valor del nodo2
		* @return int: El valor del ancestro común
		*/
		int ConsultarAncestroComun(int id_arbol, int nodo1, int nodo2);
	private:
		// URL base. Por defecto http://localhost:5000
		web::http::uri uri_base;
		// Cliente HTTP de la librería cpprestsdk
		web::http::client::http_client cliente;
		// URL para la creación de árboles binarios: /arbolbinario/crear
		web::http::uri uri_creacion;
		// URL para consultar ancestro común: /arbolbinario/ancestrocomun
		web::http::uri uri_ancestro;
	};
}

