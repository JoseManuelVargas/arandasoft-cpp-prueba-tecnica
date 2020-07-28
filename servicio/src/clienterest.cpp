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
 * @file clienterest.cpp
 * @brief Archivo que implementa los códigos de la clase ClienteREST
 * @author Jose Manuel Vargas Montero
 * @date julio 27 de 2020
 *
 */

#include "clienterest.h"

/*
* Para las URI la uri_base no debe tener más que la dirección IP y el puerto
*/
servicio::ClienteREST::ClienteREST()
	: uri_base(U("http://localhost:5000")), cliente(uri_base),
	uri_creacion(web::http::uri_builder(uri_base).append_path(U("/arbolbinario/crear")).to_uri()),
	uri_ancestro(web::http::uri_builder(uri_base).append_path(U("/arbolbinario/ancestrocomun")).to_uri())
{
}

long servicio::ClienteREST::CrearArbol(const utility::string_t& nombre, std::vector<int>& valores)
{
	// TODO: Lanzar excepción en caso de error reportado por el servidor
	web::http::http_request peticion;
	peticion.set_method(web::http::methods::POST);
	peticion.set_request_uri(uri_creacion);
	std::vector<web::json::value> valores_json;
	valores_json.reserve(valores.size());
	for (int valor : valores)
		valores_json.push_back(valor);
	web::json::value cuerpo_json;
	cuerpo_json[U("nombre")] = web::json::value(nombre, false);
	cuerpo_json[U("valores")] = web::json::value::array(valores_json);
	peticion.set_body(cuerpo_json);
	web::http::http_response respuesta = cliente.request(peticion).get();
	try
	{
		web::json::value respuesta_json = respuesta.extract_json().get();
		if (respuesta_json.has_field(U("id")))
			return respuesta_json[U("id")].as_integer();
		ucout << "Respuesta no tiene ID: " << respuesta_json.as_string() << std::endl;
	}
	catch (std::exception& error)
	{
		ucout << "Error solicitando creación de árboles: " << error.what() << std::endl;
	}
	return -1;
}

int servicio::ClienteREST::ConsultarAncestroComun(int id_arbol, int nodo1, int nodo2)
{
	// TODO: Lanzar excepción si el árbol no existe
	web::http::http_request peticion;
	peticion.set_method(web::http::methods::POST);
	peticion.set_request_uri(uri_ancestro);
	web::json::value cuerpo_json;
	cuerpo_json[U("id")] = id_arbol;
	cuerpo_json[U("nodo1")] = nodo1;
	cuerpo_json[U("nodo2")] = nodo2;
	peticion.set_body(cuerpo_json);
	web::http::http_response respuesta = cliente.request(peticion).get();
	try
	{
		web::json::value respuesta_json = respuesta.extract_json().get();
		if (respuesta_json.has_field(U("ancestro")))
			return respuesta_json[U("ancestro")].as_integer();
		ucout << "Respuesta no tiene ancestro: " << respuesta_json.as_string() << std::endl;
	}
	catch (std::exception& error)
	{
		ucout << "Error solicitando ancestro: " << error.what() << std::endl;
	}
	return -1;
}


