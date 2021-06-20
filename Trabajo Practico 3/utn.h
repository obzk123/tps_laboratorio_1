#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#endif // UTN_H_INCLUDED


/** \brief obtiene un entero
 *
 * \param mensaje char*
 * \param pResultado int*
 * \return int
 *
 */
int getInt(char* mensaje, int* pResultado);

/** \brief
 *
 * \param mensaje char*
 * \param pResultado float*
 * \return int
 *
 */
int getFloat(char* mensaje, float* pResultado);

/** \brief
 *
 * \param mensaje char*
 * \param pResultado[] char
 * \return int
 *
 */
int getString(char* mensaje, char pResultado[]);
