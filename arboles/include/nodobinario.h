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
 * @file nodobinario.h
 * @brief Crea la clase NodoBinario<T> que hereda de Nodo<T>
 * @author Jose Manuel Vargas Montero
 * @date julio 25 de 2020
 *
 */

#pragma once

#include <list>
#include <memory>
#include <queue>

#include "nodo.h"

namespace arboles {
	/**
	* @brief Clase que modela los nodos binarios e implementa los métodos
	*	abstractos de la clase padre Nodo
	* @ejemplo
	NodoBinario<int> raiz(4);
	raiz.Agregar(7);
	*/
	template <typename T>
	class NodoBinario : public Nodo<T> {
	public:
		/**
		 * @brief Constructor desde el valor del nodo actual
		 * @param dato: Dato usado para asignar al nodo
		 */
		NodoBinario(const T& dato);
		/**
		 * @brief Agregar el valor a alguno de sus nodos hijos.
		 *	Se creará un nuevo nodo en alguna de las hojas que corresponda.
		 *	o no se hará nada en caso que el valor esté repetido.
		 * @param dato: Dato usado para asignar al nodo
		 * @return void
		 */
		void Agregar(const T& dato) override;
		/**
		 * @brief Responde verdadero si el nodo es una hoja, es decir no tiene nodos hijos.
		 *	Falso en caso contrario.
		 * @return bool
		 */
		bool EsHoja() override;
		/**
		 * @brief Calcula el camino para llegar al nodo con valor igual a dato.
		 *	Retorna verdadero si el valor fue encontrado.
		 *	Falso en caso contrario.
		 * @param dato: Dato usado para buscar al nodo
		 * @param camino: Lista que almacenará los valores que definen el camino encontrado
		 * @return bool
		 */
		bool CalcularCaminoANodo(const T& dato, std::vector<T>& camino) override;
	private:
		// Almacena el puntero inteligente del nodo derecho. Puede almacenar nulo
		std::unique_ptr<Nodo<T>> nodo_der;
		// Almacena el puntero inteligente del nodo izquierdo. Puede almacenar nulo
		std::unique_ptr<Nodo<T>> nodo_izq;
	};

	template<typename T>
	NodoBinario<T>::NodoBinario(const T& dato) 
		: arboles::Nodo<T>(dato), nodo_der(nullptr), nodo_izq(nullptr)
	{
	}

	template<typename T>
	void NodoBinario<T>::Agregar(const T& dato)
	{
		std::queue<NodoBinario<T>*> cola;
		cola.push(this);

		while (!cola.empty())
		{
			NodoBinario<T>* nodo = cola.front();
			cola.pop();

			if (nodo->nodo_izq == nullptr) {
				nodo->nodo_izq = std::make_unique<NodoBinario<T>>(dato);
				break;
			}
			else
				cola.push(static_cast<NodoBinario<T>*>(nodo->nodo_izq.get()));

			if (nodo->nodo_der == nullptr) {
                                nodo->nodo_der = std::make_unique<NodoBinario<T>>(dato);
                                break;
                        }
                        else
                                cola.push(static_cast<NodoBinario<T>*>(nodo->nodo_der.get()));
		}
	}

	template<typename T>
	bool NodoBinario<T>::EsHoja()
	{
		return nodo_der == nullptr && nodo_izq == nullptr;
	}

	template<typename T>
	bool NodoBinario<T>::CalcularCaminoANodo(const T& dato, std::vector<T>& camino)
	{
		camino.push_back(this->ObtenerValor());
		if (dato == this->ObtenerValor())
			return true;
		if ((nodo_izq != nullptr && nodo_izq->CalcularCaminoANodo(dato, camino)) || (nodo_der != nullptr && nodo_der->CalcularCaminoANodo(dato, camino)))
			return true;
		camino.pop_back();
		return false;
	}
}

