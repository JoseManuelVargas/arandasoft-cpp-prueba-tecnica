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
 * @file mapeadorarbolbinario.h
 * @brief Define la clase MapeadorArbolBinario que se encarga de convertir 
 *	entre objeto de ArbolBinario a registros de base de datos
 * @author Jose Manuel Vargas Montero
 * @date julio 25 de 2020
 *
 */

#pragma once

#include <string>
#include <memory>
#include <vector>

#include <soci/soci.h>

#include "conexionbd.h"
#include "arbolbinario.h"

namespace basedatos {
	/**
	* @brief Clase que modela las funcionalidades para mapear objetos de árbol binario 
	*	a registros de base de datos.
	* Ejemplo
	MapeadorArbolBinario mapeador(conexion);
	unique_ptr<ArbolBinario> arbol = mapeador.ConsultarArbolPorID(3);
	mapeador.GuardarArbol("Nombre arbol", valores);
	*/
	class MapeadorArbolBinario {
	public:
		/**
		 * @brief Constructor desde conexión a base de datos
		 * @param dato: Conexión a base de datos ya creada
		 */
		MapeadorArbolBinario(ConexionBD& con);
		/**
		 * @brief Retorna un puntero inteligente hacia el árbol binario cargado
		 *	desde la base de datos. El puntero inteligente apuntará a nullptr
		 *	si no se encontró árbol.
		 * @param id: ID de la base de datos del árbol binario
		 * @return std::unique_ptr<arboles::ArbolBinario<int>>: Puntero inteligente al árbol binario
		 */
		std::unique_ptr<arboles::ArbolBinario<int>> ConsultarArbolPorID(long id);
		/**
		 * @brief Almacena en base de datos un árbol binario con el nombre dato
		 *	y la lista de valores enteros
		 * @param nombre: Nombre del árbol binario asignado
		 * @param valores: Vector con valores para los nodos del árbol.
		 * @return long: ID asignado al árbol
		 */
		long GuardarArbol(const std::string& nombre, std::vector<int>& valores);
	private:
		// Almacena la sesión SOCI
		soci::session& sesion_sql;
		// Referencia a una conexión de base de datos
		ConexionBD& conexion;
	};
}

