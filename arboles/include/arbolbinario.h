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
 * @brief  Crea la clase ArbolBInario<T> que hereda de Arbol<T>
 * @author Jose Manuel Vargas Montero
 * @date julio 25 de 2020
 *
 */

#pragma once

#include <memory>
#include <string>

#include "arbol.h"
#include "nodobinario.h"

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
	class ArbolBinario : public Arbol<T> {
	public:
		/**
		 * @brief Constructor desde valores de nombre y ID conocidos
		 * @param nomb: Nombre asignado al árbol
		 * @param id_bd: id asignado en la base de datos
		 */
		ArbolBinario(const std::string& nomb, const int& id_bd);
		/**
		 * @brief Constructor desde el nombre. ID desconocido o
		 *	árbol no almacenado en base de datos
		 * @param nomb: Nombre asignado al árbol
		 */
		ArbolBinario(const std::string& nomb);
		/**
		 * @brief Agregar el valor a alguno de sus nodos.
		 *	Se usará el nodo raíz para esto
		 * @param dato: Dato usado para asignar al nodo
		 * @return void
		 */
		void Agregar(const T& dato);
		/**
		 * @brief Calcula el ancestro común a dos nodos con valores
		 *	dato1 y dato2. A menos que el árbol esté vacío, siempre devolverá un valor
		 *	incluyendo el de el nodo raíz. Se debe validar que el árbol no esté vacío.
		 * @param dato: Dato usado para asignar al nodo
		 * @return void
		 */
		T CalcularAncestroComun(const T& dato1, const T& dato2);
	};

	template<typename T>
	ArbolBinario<T>::ArbolBinario(const std::string& nomb, const int& id_bd) 
		: Arbol<T>::Arbol(nomb, id_bd)
	{
	}

	template<typename T>
	ArbolBinario<T>::ArbolBinario(const std::string& nomb)
		: Arbol<T>::Arbol(nomb)
	{
	}

	template<typename T>
	void ArbolBinario<T>::Agregar(const T& dato)
	{
		if (this->raiz == nullptr)
			this->raiz = std::make_unique<NodoBinario<T>>(dato);
		else
			this->raiz->Agregar(dato);
	}

	template<typename T>
	T ArbolBinario<T>::CalcularAncestroComun(const T& dato1, const T& dato2)
	{
		std::vector<T> camino1, camino2;
		if (!this->raiz->CalcularCaminoANodo(dato1, camino1) || !this->raiz->CalcularCaminoANodo(dato2, camino2))
			return T(-1);
		int i;
		for (i = 0; i < camino1.size() && i < camino2.size(); i++) {
			if (camino1[i] != camino2[i])
				break;
		}
		return camino1[i];
	}
}

