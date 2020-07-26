#include <list>

#include "gtest/gtest.h"

#include "nodobinario.h"
#include "arbolbinario.h"

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
    raiz.Agreagar(4);
    EXPECT_EQ(raiz.EsHoja(), respuesta_hoja);
    raiz.Agreagar(7);
    EXPECT_NE(raiz.EsHoja(), respuesta_hoja);
}

TEST(ArbolTest, ValidarArbolVacio)
{
    arboles::ArbolBinario<int> arbol("Arbol1");
    bool respuesta_vacio = true;
    EXPECT_EQ(arbol.EstaVacio(), respuesta_vacio);
    arbol.Agreagar(7);
    EXPECT_NE(arbol.EstaVacio(), respuesta_vacio);
}

TEST(ArbolTest, CaminoANodo1)
{
    arboles::NodoBinario<int> raiz(1);
    raiz.Agreagar(2);
    raiz.Agreagar(3);
    raiz.Agreagar(4);
    raiz.Agreagar(5);
    std::list<int> camino;
    raiz.CalcularCaminoANodo(5, camino);
    bool es_vacio = false;
    size_t camino_tamanio = 5;
    EXPECT_EQ(camino.empty(), es_vacio);
    EXPECT_EQ(camino.size(), camino_tamanio);
}

TEST(ArbolTest, AncestroComun1)
{
    arboles::ArbolBinario<int> arbol("Arbol2");
    arbol.Agreagar(2);
    arbol.Agreagar(3);
    arbol.Agreagar(4);
    arbol.Agreagar(5);
    bool respuesta_vacio = false;
    EXPECT_EQ(arbol.EstaVacio(), respuesta_vacio);
    if (arbol.EstaVacio())
	    return;
    int ancestro = arbol.CalcularAncestroComun(5, 4);
    int ancestro_esperado = 4;
    EXPECT_EQ(ancestro, ancestro_esperado);
}

