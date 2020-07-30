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
 * @file serviciostest.cpp
 * @brief Archivo que implementa las pruebas unitarias para el servicio
 * REST y aplicativo conjunto
 * @author Jose Manuel Vargas Montero
 * @date julio 28 de 2020
 *
 */

#include <vector>
#include <string>
#include <memory>

#include "gtest/gtest.h"

#include "mapeadorarbolbinario.h"
#include "arbolbinario.h"
#include "clienterest.h"
#include "servidorrest.h"

TEST(BaseDeDatos, PruebaConexion)
{
    basedatos::ConexionBD conexion;
    std::ifstream archivo(basedatos::ConexionBD::kArchivoPorDefecto);
    bool valor_good_esperado = true;
    bool valor_good_real = archivo.good();
    archivo.close();
    EXPECT_EQ(valor_good_real, valor_good_esperado);
    // Segunda prueba
    servicio::ServidorREST servidor;
    servidor.Abrir();
    std::string nombre_arbol("Arbol prueba");
    std::vector<int> valores({ 4, 7, 2, 9, 10, 1, 14 });
    basedatos::MapeadorArbolBinario mapeador(conexion);
    int id_arbol = mapeador.GuardarArbol(nombre_arbol, valores);
    servicio::ClienteREST cliente;
    int ancestro1 = cliente.ConsultarAncestroComun(id_arbol, 10, 2);
    int ancestro1_esperado = 4;
    EXPECT_EQ(ancestro1, ancestro1_esperado);
    id_arbol = cliente.CrearArbol(U("Arbol 1"), valores);
    int id_minimo = 0;
    EXPECT_GT(id_arbol, id_minimo);
    int ancestro2 = cliente.ConsultarAncestroComun(id_arbol, 7, 2);
    int ancestro2_esperado = 4;
    EXPECT_EQ(ancestro2, ancestro2_esperado);
    ancestro1 = cliente.ConsultarAncestroComun(id_arbol, 9, 14);
    std::unique_ptr<arboles::ArbolBinario<int>> arbol = mapeador.ConsultarArbolPorID(id_arbol);
    bool es_nulo = arbol == nullptr;
    bool esperado_nulo = false;
    EXPECT_EQ(es_nulo, esperado_nulo);
    if (!es_nulo) {
	    ancestro1_esperado = arbol->CalcularAncestroComun(9, 14);
	    EXPECT_EQ(ancestro1, ancestro1_esperado);
    }
    if (valor_good_real)
        std::remove(basedatos::ConexionBD::kArchivoPorDefecto.c_str());
    servidor.Cerrar();
}

