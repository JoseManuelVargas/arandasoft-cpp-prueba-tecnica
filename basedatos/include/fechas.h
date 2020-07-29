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
 * @file fechas.h
 * @brief Define funciones útiles para el módulo
 * @author Jose Manuel Vargas Montero
 * @date julio 28 de 2020
 *
 */

#pragma once

#include <string>
#include <ctime>
#include <chrono>

namespace fechas {
	/**
	 * @brief Convierte el tipo de dato std::tm para fechas a string con formato "%Y-%m-%d %H:%M:%S"
	 * @param datetime: Fecha a convertir
	 * @return int: El string con la fecha
	*/
	std::string ConvertirFechaTMaString(struct std::tm* datetime);
	/**
         * @brief Convierte la fecha actual a string con formato "%Y-%m-%d %H:%M:%S"
         * @return int: El string con la fecha actual
        */
	std::string ConvertirFechaActualAString();
}

