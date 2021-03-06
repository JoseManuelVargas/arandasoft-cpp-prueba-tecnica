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
 * @file mapeadorarbolbinario.cpp
 * @brief Archivo que implementa los códigos de la clase MapeadorArbolBinario
 * @author Jose Manuel Vargas Montero
 * @date julio 25 de 2020
 *
 */

#include "fechas.h"
#include "mapeadorarbolbinario.h"

#include <string>
#include <ctime>
#include <chrono>


basedatos::MapeadorArbolBinario::MapeadorArbolBinario(ConexionBD& con)
	: conexion(con), sesion_sql(con.ObtenerSession())
{
}

std::unique_ptr<arboles::ArbolBinario<int>> basedatos::MapeadorArbolBinario::ConsultarArbolPorID(long id)
{
	std::string nombre;
	sesion_sql << "SELECT nombre FROM arbolbinario WHERE id = " << id, soci::into(nombre);
	std::unique_ptr<arboles::ArbolBinario<int>> arbol = std::make_unique<arboles::ArbolBinario<int>>(nombre, id);
	soci::rowset<soci::row> conjunto_filas = (sesion_sql.prepare << "SELECT valor FROM nodo WHERE arbol_id = " << id);
	for (soci::row const & f : conjunto_filas)
		arbol->Agregar(f.get<int>(0));
	return std::move(arbol);
}

long basedatos::MapeadorArbolBinario::GuardarArbol(const std::string& nombre, std::vector<int>& valores)
{
	sesion_sql << "INSERT INTO arbolbinario (creacion, nombre) "
		"VALUES (:crea, :nomb);",
		soci::use(fechas::ConvertirFechaActualAString(), "crea"),
		soci::use(nombre, "nomb");
	long ultimo_id;
	sesion_sql << "SELECT last_insert_rowid();", soci::into(ultimo_id);
	for (auto& valor: valores)
		sesion_sql << "INSERT INTO nodo (arbol_id, valor) "
			"VALUES (:arbol, :valor);",
			soci::use(ultimo_id, "arbol"),
			soci::use(valor, "valor");
	return ultimo_id;
}

