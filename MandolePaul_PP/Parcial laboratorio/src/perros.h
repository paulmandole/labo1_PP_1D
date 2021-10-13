/*
 * perros.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Paul
 */

#ifndef PERROS_H_
#define PERROS_H_
#define TAMCHAR 21
typedef struct
{
	int id;
	char nombre[TAMCHAR];
	char raza[TAMCHAR];
	int edad;
	int vacio;
}ePerro;


/**
 * @fn int perro_buscarPerroCargado(ePerro*, int, int*, int)
 * @brief busca un perro cargado a partir de un id y devuelve el indice del array donde se encuantra el perro o -1 si no lo encuentra
 *
 * @param perro recive un array de perros
 * @param tam recive el tamanio del array de perros
 * @param indice recive un puntero al que devolver el indice
 * @param idPerro recive el id del perro a buscar
 * @return retorna 0 si pudo realizar su funcion bien o -1 si el puntero a eperro es NULL o el tam es < a 0
 */
int perro_buscarPerroCargado(ePerro* perro,int tam,int* indice,int idPerro);

/**
 * @fn int perro_ListarPerros(ePerro*, int)
 * @brief muestra una lista de perros
 *
 * @param perro recive un array de perros
 * @param tam recive el tam del array de perros
 * @return retorna 0 si pudo realizar su funcion bien o -1 si el puntero a eperro es NULL o el tam es < a 0
 */
int perro_ListarPerros(ePerro* perro,int tam);

/**
 * @fn void perro_ListarPerro(ePerro)
 * @brief muestra un perro
 *
 * @param perro recive un perro
 */
void perro_ListarPerro(ePerro perro);

/**
 * @fn int perro_ListarPromedioEdadPerros(ePerro*, int)
 * @brief muestra el promedio de edad de los perros cargados
 *
 * @param perro recive un array de perros
 * @param tam recive el tamanio del array de perros
 * @return retorna 0 si pudo realizar su funcion bien o -1 si el puntero a eperro es NULL o el tam es < a 0
 */
int perro_ListarPromedioEdadPerros(ePerro* perro,int tam);

#endif /* PERROS_H_ */
