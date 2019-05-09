#ifndef PILOTOS_H
#define PILOTOS_H

#include "structs.h"

pPilotos getVetorPilotos(int *nPilotos);
void printPiloto(pilotos p);
pPilotos verificaPilotos(pPilotos v, int *nPilotos);
int verificaData(int dia, int mes, int ano);

#endif