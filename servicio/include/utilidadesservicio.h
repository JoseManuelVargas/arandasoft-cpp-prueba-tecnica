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
 * @file utilidadesservicio.h
 * @brief Define la clase padre común a servicios. De manera que se 
 *	re utilizan funcionalidades comunes
 * @author Jose Manuel Vargas Montero
 * @date julio 28 de 2020
 *
 */

#pragma once

#include <cpprest/http_client.h>

namespace servicio
{
	/**
	* @brief Clase para definir utilidades comunes a los servicios
	* Ejemplo
	Se recomienda utilizar heredando la clase
	*/
	class UtilidadesServicio
	{
	protected:
		/**
		* @brief Valida que el json tenga la llave. En caso contrario retorna mensaje de error
		* @param mensaje: Mensaje HTTP para enviar respuesta de error
		* @param mensaje: Datos con el objeto json
		* @param llave: Llave que se va a buscar en los datos json
		* @param id_error: id del mensaje de error
		* @return bool: Verdadero si tiene la llave
		*/
		bool ValidarLlaveJSON(web::http::http_request& mensaje, web::json::value& datos,
			const utility::string_t& llave, int id_error);
		/**
		* @brief Valida que el json sea del tipo adecuado. Retorna mensaje de error a la petición
		* @param mensaje: Mensaje HTTP para enviar respuesta de error
		* @param mensaje: Datos con el objeto json
		* @param llave: Llave que se va a buscar en los datos json
		* @param tipo: Tipo de json a validar
		* @param id_error: id del mensaje de error
		* @return bool: Verdadero si es del tipo correcto
		*/
		bool ValidarTipoJSON(web::http::http_request& mensaje, web::json::value& datos,
			const utility::string_t& llave, web::json::value::value_type tipo, int id_error);
		/**
		* @brief Valida que los elementos del arreglo json sean del tipo adecuado.
		*	Retorna mensaje de error a la petición
		* @param mensaje: Mensaje HTTP para enviar respuesta de error
		* @param mensaje: Datos con el arreglo de json
		* @param tipo: Tipo de json a validar
		* @param id_error: id del mensaje de error
		* @param b_vacio: Valida que no sea vacío el arreglo si el parámetros es true
		* @return bool: Verdadero si todos los elementos son del tipo correcto
		*/
		bool ValidarTipoArregloJSON(web::http::http_request& mensaje, const web::json::array& datos,
			web::json::value::value_type tipo, int id_error, bool b_vacio);
	};
}

