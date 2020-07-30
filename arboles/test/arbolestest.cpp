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
 * @file arbolestest.cpp
 * @brief Archivo Que implementa las pruebas unitarias para el módulo de árboles y nodos
 * @author Jose Manuel Vargas Montero
 * @date julio 25 de 2020
 *
 */

#include <vector>
#include <fstream>
#include <memory>
#include <iostream>

#include "gtest/gtest.h"

#include "nodobinario.h"
#include "arbolbinario.h"

std::unique_ptr<arboles::ArbolBinario<int>> CrearArbol(std::ifstream& archivo)
{
	std::cout << "Probando nuevo árbol binario en conjunto" << std::endl;
    	archivo.ignore();
    	if (archivo.peek() == ',') {
		archivo.ignore();
    	}
    	if (archivo.peek() == '\n') {
		archivo.ignore();
    	}
    	return std::make_unique<arboles::ArbolBinario<int>>("Arbol1");
}

TEST(ArbolTest, ConjuntoDatos)
{
	std::ifstream archivo("conjuntoarboles.dat");
	if (!archivo) {
		std::cout << "No se encontró archivo para la prueba de árboles con conjunto de datos" << std::endl;
		return;
	}
    	char caracter;
    	int i;
	std::vector<int> nodos;
    	nodos.reserve(3);
	bool respuesta_vacio = true;
    	bool creando_arbol = true;
	int ancestro;
    	std::unique_ptr<arboles::ArbolBinario<int>> arbol = nullptr;
    	if (archivo.peek() == 'a') {
		creando_arbol = true;
		arbol = CrearArbol(archivo);
		EXPECT_EQ(arbol->EstaVacio(), respuesta_vacio);
    	}
    	while (!archivo.eof()) {
		while (archivo >> i) {
	    		if (creando_arbol) {
				arbol->Agregar(i);
	    		}
	    		else
				nodos.push_back(i);
	    		if (archivo.peek() == ',') {
				archivo.ignore();
	    		}
	    		if (archivo.peek() == '\n') {
				archivo.ignore();
				if (nodos.size() == 3) {
		    			ancestro = arbol->CalcularAncestroComun(nodos.at(0), nodos.at(1));
					EXPECT_EQ(ancestro, nodos.at(2));
				}
				creando_arbol = false;
				nodos.clear();
	    		}
	    		if (archivo.peek() == 'a') {
				creando_arbol = true;
				arbol = CrearArbol(archivo);
	    			EXPECT_EQ(arbol->EstaVacio(), respuesta_vacio);
	    		}
		}
    	}
    	archivo.close();
}

TEST(ArbolTest, CreacionArbol)
{
    arboles::NodoBinario<int> raiz(4);
    int dato = 6;
    int id1 = -1;
    int id2 = 5;
    arboles::NodoBinario<int> raiz2(dato);
    std::string nombre1("Arbol1");
    std::string nombre2("Arbol2");
    arboles::ArbolBinario<int> arbol("Arbol1");
    arboles::ArbolBinario<int> arbol2(nombre2, 5);
    EXPECT_EQ(raiz.ObtenerValor(), 4);
    EXPECT_EQ(raiz2.ObtenerValor(), dato);
    EXPECT_EQ(arbol.ObtenerNombre(), nombre1);
    EXPECT_EQ(arbol2.ObtenerNombre(), nombre2);
    EXPECT_EQ(arbol.ObtenerID(), id1);
    EXPECT_EQ(arbol2.ObtenerID(), id2);
}

TEST(ArbolTest, ValidarHoja)
{
    arboles::NodoBinario<int> raiz(4);
    bool respuesta_hoja = true;
    EXPECT_EQ(raiz.EsHoja(), respuesta_hoja);
    raiz.Agregar(4);
    respuesta_hoja = false;
    EXPECT_EQ(raiz.EsHoja(), respuesta_hoja);
    raiz.Agregar(7);
    EXPECT_EQ(raiz.EsHoja(), respuesta_hoja);
}

TEST(ArbolTest, ValidarArbolVacio)
{
    arboles::ArbolBinario<int> arbol("Arbol1");
    bool respuesta_vacio = true;
    EXPECT_EQ(arbol.EstaVacio(), respuesta_vacio);
    arbol.Agregar(7);
    EXPECT_NE(arbol.EstaVacio(), respuesta_vacio);
}

TEST(ArbolTest, CaminoANodo1)
{
    arboles::NodoBinario<int> raiz(1);
    raiz.Agregar(2);
    raiz.Agregar(3);
    raiz.Agregar(4);
    raiz.Agregar(5);
    std::vector<int> camino;
    raiz.CalcularCaminoANodo(5, camino);
    bool es_vacio = false;
    size_t camino_tamanio = 3;
    EXPECT_EQ(camino.empty(), es_vacio);
    EXPECT_EQ(camino.size(), camino_tamanio);
}

TEST(ArbolTest, AncestroComun1)
{
    arboles::ArbolBinario<int> arbol("Arbol2");
    arbol.Agregar(2);
    arbol.Agregar(3);
    arbol.Agregar(4);
    arbol.Agregar(5);
    bool respuesta_vacio = false;
    EXPECT_EQ(arbol.EstaVacio(), respuesta_vacio);
    if (!arbol.EstaVacio()) {
    	int ancestro = arbol.CalcularAncestroComun(5, 4);
    	int ancestro_esperado = 2;
    	EXPECT_EQ(ancestro, ancestro_esperado);
    }
}

