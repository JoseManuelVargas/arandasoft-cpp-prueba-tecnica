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
 * @file plantilla.h
 * @brief Define la clase abstracta Nodo<T>
 * @author Jose Manuel Vargas Montero
 * @date julio 25 de 2020
 *
 */

#pragma once

#include <vector>

namespace arboles {
	/**
	* @brief Clase que modela la clase abstracta para ser utilizada por diferentes tipos de nodos.
	*	Funciona con template para permitir definir diferentes tipos que almacena el nodo
	* Ejemplo
	Nodo<int> raiz(4);
	raiz.Agregar(7);
	* Recordar la clase no se puede ejemplificar.
	*/
	template <typename T>
	class Nodo {
	public:
		/**
		 * @brief Constructor desde el valor del nodo actual
		 * @param dato: Dato usado para asignar al nodo
		 */
		Nodo(const T& dato);
		/**
		 * @brief Retorna una copia del valor del nodo
		 * @return T: El valor
		 */
		const T& ObtenerValor();
		/**
		 * @brief Agregar el valor a alguno de sus nodos hijos.
		 *	Se creará un nuevo nodo en alguna de las hojas que corresponda.
		 *	o no se hará nada en caso que el valor esté repetido.
		 * @param dato: Dato usado para asignar al nodo
		 * @return void
		 */
		virtual void Agregar(const T& dato) = 0;
		/**
		 * @brief Responde verdadero si el nodo es una hoja, es decir no tiene nodos hijos.
		 *	Falso en caso contrario.
		 * @return bool
		 */
		virtual bool EsHoja() = 0;
		/**
		 * @brief Calcula el camino para llegar al nodo con valor igual a dato. 
		 *	Retorna verdadero si el valor fue encontrado.
		 *	Falso en caso contrario.
		 * @param dato: Dato usado para buscar al nodo
		 * @param camino: Lista que almacenará los valores que definen el camino encontrado
		 * @return bool
		 */
		virtual bool CalcularCaminoANodo(const T& dato, std::vector<T>& camino) = 0;
	private:
		// Almacena el valor del nodo actual
		T valor;
	};

	template<typename T>
	Nodo<T>::Nodo(const T& dato) : valor(dato)
	{
	}

	template<typename T>
	const T& Nodo<T>::ObtenerValor()
	{
		return valor;
	}
}

