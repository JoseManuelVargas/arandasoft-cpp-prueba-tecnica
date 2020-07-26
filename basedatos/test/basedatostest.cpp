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
 * @file basedatostest.cpp
 * @brief Archivo que implementa las pruebas unitarias para la base de datos
 * y el mapeo de árbol binario
 * @author Jose Manuel Vargas Montero
 * @date julio 26 de 2020
 *
 */

#include <vector>
#include <string>
#include <fstream>

#include "gtest/gtest.h"

#include "conexionbd.h"
#include "mapeadorarbolbinario.h"

TEST(BaseDeDatos, PruebaConexion)
{
    std::string nombre_archivo("basedatos_pruebas.db");
    basedatos::ConexionBD conexion(nombre_archivo);
    std::ifstream archivo(nombre_archivo);
    bool valor_good_esperado = true;
    bool valor_good_real = archivo.good();
    archivo.close();
    EXPECT_EQ(valor_good_real, valor_good_esperado);
    if (valor_good_real)
        std::remove(nombre_archivo.c_str());
}

TEST(BaseDatos, MapeoArbolBinario)
{
    std::string nombre_archivo("bd_pruebas.db");
    basedatos::ConexionBD conexion(nombre_archivo);
    std::ifstream archivo(nombre_archivo);
    bool valor_good_real = archivo.good();
    archivo.close();
    std::string nombre_arbol("Arbol prueba");
    std::vector<int> valores({ 4, 7, 2, 9, 10, 1, 14 });
    basedatos::MapeadorArbolBinario mapeador(conexion);
    long id_arbol = mapeador.GuardarArbol(nombre_arbol, valores);
    long id_minimo = 1;
    EXPECT_GE(id_arbol, id_minimo);
    std::unique_ptr<arboles::ArbolBinario<int>> arbol = mapeador.ConsultarArbolPorID(id_arbol);
    bool es_nulo = arbol == nullptr;
    bool esperado_nulo = false;
    EXPECT_EQ(es_nulo, esperado_nulo);
    if (!es_nulo)
        EXPECT_EQ(nombre_arbol, arbol->ObtenerNombre());
    if (valor_good_real)
        std::remove(nombre_archivo.c_str());
}

