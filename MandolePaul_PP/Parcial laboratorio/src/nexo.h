/*
 * nexo.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Paul
 */

#ifndef NEXO_H_
#define NEXO_H_
#include "perros.h"
#include "functions.h"
#include "estadia.h"

int estadia_reservarEstadiaConPerroCargado(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro, int* ultimoId);
int estadia_listarEstadiasConPerros(eEstadia* estadia,int tamEstadia,ePerro* perro,int tamPerro);
void estadia_listarEstadiaConPerro(eEstadia estadia,ePerro perro);




#endif /* NEXO_H_ */
