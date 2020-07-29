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
 * @file controladorrest.cpp
 * @brief Archivo que implementa los códigos de la clase ControladorREST
 * @author Jose Manuel Vargas Montero
 * @date julio 28 de 2020
 *
 */

#include "controladorrest.h"

void servicio::ControladorREST::ProcesarPeticionPOST(web::http::http_request mensaje)
{
	using namespace web;
	ucout << mensaje.to_string() << std::endl;
	json::value mensaje_error;
	try
	{
		std::vector<utility::string_t> rutas = http::uri::split_path(http::uri::decode(mensaje.relative_uri().path()));
		if (rutas.size() == 0) {
			json::value texto(U("No se encontró ruta para redirigir el servicio. Ej: arbolbinario/..."), false);
			mensaje_error[U("mensaje")] = texto;
			mensaje_error[U("id")] = 11;
			mensaje.reply(web::http::status_codes::BadRequest, mensaje_error);
			return;
		}
		if (rutas[0] == U("arbolbinario")) {
			if (rutas.size() == 1) {
				json::value texto(U("No se encontró ruta para árbol binario. Ej: arbolbinario/crear"), false);
				mensaje_error[U("mensaje")] = texto;
				mensaje_error[U("id")] = 12;
				mensaje.reply(web::http::status_codes::BadRequest, mensaje_error);
				return;
			}
			utility::string_t& ruta_arbol = rutas[1];
			if (ruta_arbol == U("crear")) {
				servicio_arboles.CrearArbolBinario(mensaje);
				return;
			}
			if (ruta_arbol == U("ancestrocomun")) {
				servicio_arboles.CalcularAncestroComun(mensaje);
				return;
			}
		}
		mensaje.reply(web::http::status_codes::NotFound);
	}
	catch (std::exception& error)
	{
		ucout << "Excepción en método POST controlador: " << error.what() << std::endl;
		json::value texto(U("Error interno desconocido"), false);
		mensaje_error[U("mensaje")] = texto;
		mensaje_error[U("id")] = 13;
		mensaje.reply(web::http::status_codes::InternalError, mensaje_error);
	}
}

void servicio::ControladorREST::ProcesarPeticionGET(web::http::http_request mensaje)
{
	ucout << mensaje.to_string() << std::endl;
	web::json::value mensaje_error;
	web::json::value texto_error(U("No se soporta el método HTTP"), false);
	mensaje_error[U("mensaje")] = texto_error;
	mensaje_error[U("error")] = 15;
	mensaje.reply(web::http::status_codes::BadRequest, mensaje_error);
}

void servicio::ControladorREST::ProcesarPeticionGeneral(web::http::http_request mensaje)
{
	const web::http::method& metodo_http = mensaje.method();
	if (metodo_http == web::http::methods::POST)
		ProcesarPeticionPOST(mensaje);
	else if (metodo_http == web::http::methods::GET)
		ProcesarPeticionGET(mensaje);
	else {
		web::json::value mensaje_error;
		web::json::value texto_error(U("No se soporta el método HTTP"), false);
		mensaje_error[U("mensaje")] = texto_error;
		mensaje_error[U("error")] = 15;
		mensaje.reply(web::http::status_codes::BadRequest, mensaje_error);
	}
}


