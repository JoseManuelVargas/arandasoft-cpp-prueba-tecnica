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
 * @file fechas.cpp
 * @brief Archivo que implementa las funciones de la librería fechas
 * @author Jose Manuel Vargas Montero
 * @date julio 28 de 2020
 *
 */

#include "fechas.h"

std::string fechas::ConvertirFechaTMaString(struct std::tm* datetime) {
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", datetime);
	std::string datetime_str(buffer);
	return datetime_str;

}

std::string fechas::ConvertirFechaActualAString() {
	std::time_t now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	return fechas::ConvertirFechaTMaString(std::localtime(&now_time));
}

