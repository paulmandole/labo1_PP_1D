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
}ePerro;


#endif /* PERROS_H_ */
