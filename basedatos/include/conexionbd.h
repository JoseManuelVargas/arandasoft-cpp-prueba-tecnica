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
 * @file conexionbd.h
 * @brief Define la clase ConexionBD para establecer conexión con la
 *	base de datos usando SOCI y SQLite
 * @author Jose Manuel Vargas Montero
 * @date julio 25 de 2020
 *
 */

#pragma once

#include <string>

#include <soci/soci.h>

namespace basedatos {
	/**
	* @brief Clase que modela la conexión con base de datos y la creación de tablas
	* Ejemplo
	ConexionBD("basedatos.db") base;
	session& sesion_sql = base.ObtenerSesion();
	* Se usa la sesión de SOCI.
	*/
	class ConexionBD {
	public:
		/**
		 * @brief Constructor para crear el archivo sqlite si no existe
		 * @param archivo: Nombre del archivo que será creado para SQLite
		 */
		ConexionBD(const std::string& archivo);
		/**
		 * @brief Retorna una copia de la sesión de SOCI creada
		 * @return session&: La sesión SOCI
		 */
		soci::session& ObtenerSession();
	private:
		// Almacena la sesión SOCI
		soci::session sesion_sql;
		// Bandera que indica que las tablas ya se crearon una vez
		static bool estan_creadas_tablas; 
		/**
		 * @brief Crea las tablas requeridas para la aplicación.
		 *	Valida la bandera para evitar crear nuevamente las tablas
		 * @return void
		 */
		void CrearTablas();
		/**
		 * @brief Crea la tabla para los árboles binarios.
		 * @return void
		 */
		void CrearTablaArbolesBinarios();
		/**
		 * @brief Crea la tabla para los nodos binarios.
		 *	Debe ser creada después de la tabla de árboles binarios.
		 * @return void
		 */
		void CrearTablaNodosBinarios();
	};
}

