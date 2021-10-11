/*
 * estadia.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Paul
 */

#ifndef ESTADIA_H_
#define ESTADIA_H_
#define TAMSTRING 35
typedef struct
{
	int id;
	char nombreDuenio[TAMSTRING];
	int telefonoContacto;
	int idPerro;
	char fecha[10];

}eEstadia;


#endif /* ESTADIA_H_ */
