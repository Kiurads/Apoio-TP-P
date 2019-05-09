#ifndef CORRIDAS_H
#define CORRIDAS_H

#include "structs.h"

pCorridas novaCorrida();
pPar fazPares(pPilotos vetorPilotos, pCarros vetorCarros, pCorridas corrida, int nPilotos, int nCarros);
int getMinimo(int max, int pilotos, int carros);
void printCorrida(pCorridas c);

#endif
