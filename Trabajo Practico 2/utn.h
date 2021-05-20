#ifndef UTN_H_
#define UTN_H_
#endif


/** \brief getInt debe validar y modifcar el valor pasado por referencia
 *
 *  \param mensaje char recibe el mensaje a mostrar
 *  \param pResultado float recibe la direccion de memoria de la variable a modificar
 *  \return float retorna -1 si fallo la funcion y 0 si todo esta bien
 *
 */
int getInt(char mensaje[], int *pResultado);


/** \brief getString debe validar y modifcar el valor pasado por referencia
 *
 *  \param mensaje char recibe el mensaje a mostrar
 *  \param pResultado float recibe la direccion de memoria de la variable a modificar
 *  \return float retorna -1 si fallo la funcion y 0 si todo esta bien
 *
 */
int getString(char mensaje[], char* pVariable, int tam);


/** \brief getFloat debe validar y modifcar el valor pasado por referencia
 *
 *  \param mensaje char recibe el mensaje a mostrar
 *  \param pResultado float recibe la direccion de memoria de la variable a modificar
 *  \return float retorna -1 si fallo la funcion y 0 si todo esta bien
 *
 */
int getFloat(char mensaje[], float *pResultado);
