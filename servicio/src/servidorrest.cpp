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
 * @file servidorrest.cpp
 * @brief Archivo que implementa los códigos de la clase ServicioArboles
 * @author Jose Manuel Vargas Montero
 * @date julio 28 de 2020
 *
 */

#include "servidorrest.h"

servicio::ServidorREST::ServidorREST()
	:uri_base(U("http://localhost:5000")), servidor(uri_base),
	esta_escuchando(false), controlador()
{
	servidor.support(web::http::methods::POST, std::bind(&ControladorREST::ProcesarPeticionPOST, &controlador, std::placeholders::_1));
	servidor.support(web::http::methods::GET, std::bind(&ControladorREST::ProcesarPeticionGET, &controlador, std::placeholders::_1));
	servidor.support(std::bind(&ControladorREST::ProcesarPeticionGeneral, &controlador, std::placeholders::_1));
}

servicio::ServidorREST::~ServidorREST()
{
	Cerrar();
}

void servicio::ServidorREST::Abrir()
{
	if (!esta_escuchando) {
		servidor.open().get();
		esta_escuchando = true;
	}
}

void servicio::ServidorREST::Cerrar()
{
	if (esta_escuchando) {
		servidor.close().get();
		esta_escuchando = false;
	}
}

