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
 * @file conexionbd.cpp
 * @brief Archivo que implementa los códigos de la clase ConexionBD
 * @author Jose Manuel Vargas Montero
 * @date julio 25 de 2020
 *
 */

#include "conexionbd.h"

bool basedatos::ConexionBD::estan_creadas_tablas = false;

basedatos::ConexionBD::ConexionBD(const std::string& archivo)
	: sesion_sql(*soci::factory_sqlite3(), archivo)
{
}

soci::session& basedatos::ConexionBD::ObtenerSession()
{
    return sesesion_sql;
}

void basedatos::ConexionBD::CrearTablas()
{
	if (estan_creadas_tablas)
		return;
	estan_creadas_tablas = true;
	CrearTablaArbolesBinarios();
	CrearTablaNodosBinarios();
}

void basedatos::ConexionBD::CrearTablaArbolesBinarios()
{
	try {
		sql << " CREATE TABLE ArbolBinario ( "
			"id BIGINT NOT NULL PRIMARY KEY, "
			"creacion TEXT, "
			"nombre TEXT "
			");";
	}
	catch (soci::soci_error const & error) {
		std::cerr << "Error creando tabla de arboles binario: " << error.what() << std::endl;
	}
}

void basedatos::ConexionBD::CrearTablaNodosBinarios()
{
	try {
		sql << " CREATE TABLE Nodo ( "
			"arbol_id BIGINT NOT NULL, "
			"valor INTEGER, "
			"FOREIGN KEY(arbol_id) REFERENCES ArbolBinario(id) "
			"); "
			"CREATE INDEX nodo_arbol_id_index ON Nodo(arbol_id);";
	}
	catch (soci::soci_error const & error) {
		std::cerr << "Error creando tabla de nodos binarios: " << error.what() << std::endl;
	}
}

