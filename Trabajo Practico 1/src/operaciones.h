/*
 * operaciones.h
 *
 *  Created on: 27 mar. 2021
 *      Author: Octavio Bill Zito
 */
#ifndef OPERACIONES_H_
#define OPERACIONES_H_
#endif /* OPERACIONES_H_ */


/** \brief suma debe sumar a + b
 *
 *  \param a int primer entero a sumar
 *  \param b int segundo entero a sumar
 *  \return int retorna la suma de a + b
 *
 */
int suma(float a, float b);

/** \brief resta debe restar a - b
 *
 *  \param a int primer entero a restar
 *  \param b int segundo entero a restar
 *  \return int retorna la resta de a - b
 *
 */
int resta(float a, float b);

/** \brief division debe dividir a / b siempre y cuando ninguno de sus valores sea 0
 *
 *  \param a int primer entero a dividir
 *  \param b int segundo entero a dividir
 *  \return int retorna la division de a / b
 *
 */
int division(float a, float b, float* resultado);

/** \brief multiplicacion debe multiplicar a*b
 *
 *  \param a int primer entero a multiplicar
 *  \param b int segundo entero a multiplicar
 *  \return int retorna la multiplicacion de a * b
 *
 */
int multiplicacion(float a, float b);


/** \brief factorial debe sacar el factorial de un numero
 *
 *  \param a int entero a factorizar
 *  \return int retorna el resultado del factorial
 *
 */
int factorial(int a);
