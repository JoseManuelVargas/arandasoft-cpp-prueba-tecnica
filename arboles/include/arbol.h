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
 * @file  arbol.h
 * @brief  Crea la clase abstracta Arbol<T>
 * @author Jose Manuel Vargas Montero
 * @date julio 25 de 2020
 *
 */

#pragma once

#include <memory>
#include <string>

#include "nodo.h"

namespace arboles {
	/**
	* @brief Clase que modela la clase abstracta para ser utilizada por diferentes tipos de árboles.
	*	Funciona con template para permitir definir diferentes tipos que almacenan los nodos
	* Ejemplo
	Arbol<int> arbol(4);
	arbol.Agregar(7);
	* Recordar la clase no se puede ejemplificar.
	*/
	template <typename T>
	class Arbol {
	public:
		/**
		 * @brief Constructor desde valores de nombre y ID conocidos
		 * @param nomb: Nombre asignado al árbol
		 * @param id_bd: id asignado en la base de datos
		 */
		Arbol(const std::string& nomb, const int& id_bd);
		/**
		 * @brief Constructor desde el nombre. ID desconocido o 
		 *	árbol no almacenado en base de datos
		 * @param nomb: Nombre asignado al árbol
		 */
		Arbol(const std::string& nomb);
		/**
		 * @brief Retorna una copia del valor del nombre del árbol
		 * @return string: Referencia al nombre
		 */
		const std::string& ObtenerNombre();
		/**
		 * @brief Retorna el valor del ID de la base de datos
		 * @return int: Valor del ID
		 */
		int ObtenerID();
		/**
		 * @brief Agregar el valor a alguno de sus nodos.
		 *	Se usará el nodo raíz para esto
		 * @param dato: Dato usado para asignar al nodo
		 * @return void
		 */
		virtual void Agreagar(const T& dato) = 0;
		/**
		 * @brief Responde verdadero si el árbol está vacío, es decir no tiene nodos
		 *	Falso en caso contrario.
		 * @return bool
		 */
		bool EstaVacio();
	protected:
		// Almacena el puntero inteligente al nodo raiz. Puede ser nulo para un árbol vacío
		std::unique_ptr<Nodo<T>> raiz;
	private:
		// Almacena el valor del id para la base de datos. Valor por defecto -1
		long id;
		// Almacena el nombre asignado en la creación
		std::string nombre;
	};

	template<typename T>
	Arbol<T>::Arbol(const std::string& nomb, const int& id_bd) 
		: raiz(nullptr), id(id_bd), nombre(nomb)
	{
	}

	template<typename T>
	Arbol<T>::Arbol(const std::string& nomb) 
		: Arbol<T>::Arbol(nomb, -1)
	{
	}

	template<typename T>
	const std::string& Arbol<T>::ObtenerNombre()
	{
		return nombre;
	}

	template<typename T>
	int Arbol<T>::ObtenerID()
	{
		return id;
	}

	template<typename T>
	bool Arbol<T>::EstaVacio()
	{
		return true;
	}
}

