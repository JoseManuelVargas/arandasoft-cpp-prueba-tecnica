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
 * @file utilidadesservicio.cpp
 * @brief Archivo que implementa los códigos de la clase ServicioArboles
 * @author Jose Manuel Vargas Montero
 * @date julio 28 de 2020
 *
 */

#include <cpprest/http_client.h>

#include "utilidadesservicio.h"

using namespace web;

bool servicio::UtilidadesServicio::ValidarLlaveJSON(web::http::http_request& mensaje, web::json::value& datos,
	const utility::string_t& llave, int id_error)
{
	if (!datos.has_field(llave)) {
		json::value mensaje_respuesta;
		mensaje_respuesta[U("error")] = id_error;
		utility::string_t texto_error = U("No se encontró la llave en el JSON: ");
		texto_error.append(llave);
		json::value texto(texto_error, false);
		mensaje_respuesta[U("mensaje")] = texto;
		mensaje.reply(http::status_codes::BadRequest, mensaje_respuesta);
		return false;
	}
	return true;
}

bool servicio::UtilidadesServicio::ValidarTipoJSON(web::http::http_request& mensaje, web::json::value& datos,
	const utility::string_t& llave, web::json::value::value_type tipo, int id_error)
{
	bool es_tipo_correcto = false;
	utility::string_t nombre_tipo = U("Desconocido");
	if (tipo == json::value::value_type::Array) {
		es_tipo_correcto = datos[llave].is_array();
		nombre_tipo = U("arreglo");
	}
	else if (tipo == json::value::value_type::Boolean) {
		es_tipo_correcto = datos[llave].is_boolean();
		nombre_tipo = U("booleano");
	}
	else if (tipo == json::value::value_type::Null) {
		es_tipo_correcto = datos[llave].is_null();
		nombre_tipo = U("nulo");
	}
	else if (tipo == json::value::value_type::Number) {
		es_tipo_correcto = datos[llave].is_number();
		nombre_tipo = U("número");
	}
	else if (tipo == json::value::value_type::Object) {
		es_tipo_correcto = datos[llave].is_object();
		nombre_tipo = U("objeto");
	}
	else if (tipo == json::value::value_type::String) {
		es_tipo_correcto = datos[llave].is_string();
		nombre_tipo = U("cadena de carácteres");
	}
	if (!es_tipo_correcto) {
		json::value mensaje_respuesta;
		mensaje_respuesta[U("error")] = id_error;
		utility::string_t texto_error = U("El campo ");
		texto_error.append(llave).append(U(" debe ser un ")).append(nombre_tipo);
		json::value texto(texto_error, false);
		mensaje_respuesta[U("mensaje")] = texto;
		mensaje.reply(http::status_codes::BadRequest, mensaje_respuesta);
		return false;
	}
	return true;
}

bool servicio::UtilidadesServicio::ValidarTipoArregloJSON(web::http::http_request& mensaje, const web::json::array& datos,
	web::json::value::value_type tipo, int id_error, bool b_vacio)
{
	if (b_vacio && datos.size() == 0) {
		json::value mensaje_respuesta;
		mensaje_respuesta[U("error")] = id_error;
		utility::string_t texto_error = U("El arreglo de valores no debe ser vacío");
		json::value texto(texto_error, false);
		mensaje_respuesta[U("mensaje")] = texto;
		mensaje.reply(http::status_codes::BadRequest, mensaje_respuesta);
		return false;
	}
	std::function<bool(const json::value)> funcion_tipo = std::bind(&json::value::is_double, std::placeholders::_1);
	utility::string_t nombre_tipo = U("Desconocido");
	if (tipo == json::value::value_type::Array) {
		funcion_tipo = std::bind(&json::value::is_array, std::placeholders::_1);
		nombre_tipo = U("arreglo");
	}
	else if (tipo == json::value::value_type::Boolean) {
		funcion_tipo = std::bind(&json::value::is_boolean, std::placeholders::_1);
		nombre_tipo = U("booleano");
	}
	else if (tipo == json::value::value_type::Null) {
		funcion_tipo = std::bind(&json::value::is_null, std::placeholders::_1);
		nombre_tipo = U("nulo");
	}
	else if (tipo == json::value::value_type::Number) {
		funcion_tipo = std::bind(&json::value::is_number, std::placeholders::_1);
		nombre_tipo = U("número");
	}
	else if (tipo == json::value::value_type::Object) {
		funcion_tipo = std::bind(&json::value::is_object, std::placeholders::_1);
		nombre_tipo = U("objeto");
	}
	else if (tipo == json::value::value_type::String) {
		funcion_tipo = std::bind(&json::value::is_string, std::placeholders::_1);
		nombre_tipo = U("cadena de carácteres");
	}
	for (auto& dato : datos) {
		bool es_tipo_correcto = funcion_tipo(dato);
		if (!es_tipo_correcto) {
			json::value mensaje_respuesta;
			mensaje_respuesta[U("error")] = id_error;
			utility::string_t texto_error = U("El elemento ");
			texto_error.append(dato.as_string()).append(U(" debe ser un ")).append(nombre_tipo);
			json::value texto(texto_error, false);
			mensaje_respuesta[U("mensaje")] = texto;
			mensaje.reply(http::status_codes::BadRequest, mensaje_respuesta);
			return false;
		}
	}
	return true;
}

