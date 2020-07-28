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
 * @file servicioarboles.cpp
 * @brief Archivo que implementa los códigos de la clase ServicioArboles
 * @author Jose Manuel Vargas Montero
 * @date julio 28 de 2020
 *
 */

#include <vector>

#include "servicioarboles.h"

using namespace web;

void servicio::ServicioArboles::CrearArbolBinario(web::http::http_request& mensaje)
{
	json::value datos = mensaje.extract_json().get();
	for (auto& llave : { U("nombre"), U("valores") }) {
		if (!ValidarLlaveJSON(mensaje, datos, llave, 21))
			return;
	}
	if (!ValidarTipoJSON(mensaje, datos, U("nombre"), json::value::value_type::String, 23))
		return;
	if (!ValidarTipoJSON(mensaje, datos, U("valores"), json::value::value_type::Array, 24))
		return;
	const utility::string_t& wnombre = datos[U("nombre")].as_string();
	std::string nombre(wnombre.begin(), wnombre.end());
	const json::array& valores_json = datos[U("valores")].as_array();
	if (!ValidarTipoArregloJSON(mensaje, valores_json, json::value::value_type::Number, 25, true))
		return;
	std::vector<int> valores;
	valores.reserve(valores_json.size());
	for (auto& valor : valores_json)
		valores.push_back(valor.as_integer());
	json::value mensaje_respuesta;
	mensaje_respuesta[U("id")] = 2;
	json::value texto_nombre(wnombre, false);
	mensaje_respuesta[U("nombre")] = texto_nombre;
	mensaje.reply(http::status_codes::OK, mensaje_respuesta);
}

void servicio::ServicioArboles::CalcularAncestroComun(web::http::http_request& mensaje)
{
	json::value datos = mensaje.extract_json().get();
	for (auto& llave : { U("id"), U("nodo1"), U("nodo2") }) {
		if (!ValidarLlaveJSON(mensaje, datos, llave, 31))
			return;
	}
	for (auto& llave : { U("nodo1"), U("nodo2") }) {
		if (!ValidarTipoJSON(mensaje, datos, llave, json::value::value_type::Number, 33))
			return;
	}
	int id_arbol = datos[U("id")].as_integer();
	int nodo1 = datos[U("nodo1")].as_integer();
	int nodo2 = datos[U("nodo2")].as_integer();
	json::value mensaje_respuesta;
	mensaje_respuesta[U("ancestro")] = 2;
	mensaje.reply(http::status_codes::OK, mensaje_respuesta);
}


