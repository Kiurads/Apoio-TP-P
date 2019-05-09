#include <stdlib.h>
#include <stdio.h>
#include "corridas.h"
#include "utils.h"

pCorridas novaCorrida(pCorridas vetorCorridas, int *nCorridas) {
    pCorridas v;

    v = vetorCorridas;

    (*nCorridas)++;

    v = realloc(v, sizeof(corridas) * (*nCorridas));

    if(v == NULL) {
        return vetorCorridas;
    }

    do {
        printf("Numero de voltas (entre 5 e 10): ");
        scanf("%d", &v[(*nCorridas) - 1].voltas);
    } while(v[(*nCorridas) - 1].voltas < 5 || v[(*nCorridas) - 1].voltas > 10);
    
    do {
        printf("Comprimento (entre 500 e 1000): ");
        scanf("%d", &v[(*nCorridas) - 1].comprimento);
    } while(v[(*nCorridas) - 1].comprimento < 500 || v[(*nCorridas) - 1].comprimento > 1000);
    
    do {
        printf("Maximo de participantes: ");
        scanf("%d", &v[(*nCorridas) - 1].maxparticipantes);
    } while(v[(*nCorridas) - 1].maxparticipantes <= 0);

    v[(*nCorridas) - 1].lista = NULL;

    return v;
}

pPar fazPares(pPilotos vetorPilotos, pCarros vetorCarros, pCorridas corrida, int nPilotos, int nCarros) {
    pPilotos vPilotos;
    pCarros vCarros;
    pPar listaPares;
    pPar atual;
    int pilotosValidos;
    int carrosValidos;

    initRandom();

    pilotosValidos = 0;
    carrosValidos = 0;

    corrida->maxparticipantes = getMinimo(corrida->maxparticipantes, nPilotos, nCarros);

    for (int i = 0; i < nPilotos; i++) {
        if(vetorPilotos[i].impedimento == 0) pilotosValidos++;
    }

    for (int i = 0; i < nCarros; i++) {
        if(vetorCarros[i].avaria == 0) carrosValidos++;
    }

    if(carrosValidos == 0 || pilotosValidos == 0) {
        return NULL;
    }

    printf("Teste");

    vPilotos = malloc(sizeof(pilotos) * pilotosValidos);
    vCarros = malloc(sizeof(carros) * carrosValidos);

    int i = 0;

    for (int j = 0; j < nPilotos; j++) {
        if(vetorPilotos[j].impedimento == 0) {
            vPilotos[i] = vetorPilotos[j];
            i++;
        }
    }

    i = 0;

    for (int j = 0; j < nPilotos; j++) {
        if(vetorCarros[j].avaria == 0) {
            vCarros[i] = vetorCarros[j];
            i++;
        }
    }

    atual = listaPares;

    for (int j = 0; j < corrida->maxparticipantes; i++) {
        int piloto;
        int carro;

        atual = malloc(sizeof(par));
        atual->prox = NULL;

        piloto = intUniformRnd(0, pilotosValidos - 1);
        carro = intUniformRnd(0, carrosValidos - 1);

        atual->piloto = &vPilotos[piloto];
        atual->carro = &vCarros[carro];

        atual = atual->prox;
    }

    free(vCarros);
    free(vPilotos);

    return listaPares;
}

int getMinimo(int max, int pilotos, int carros) {
    int temp;

    temp = max;

    if(temp > pilotos) temp = pilotos;
    if(temp > carros) temp = carros;

    return temp;
}

void printCorrida(corridas c) {
    pPar atual;

    atual = c.lista;

    printf("\nVoltas: %d\n", c.voltas);
    printf("Comprimento: %d metros\n", c.comprimento);
    printf("Maximo participantes: %d\n\n", c.maxparticipantes);
    printf("Participantes:\n");

    while (atual != NULL) {
        printf("\t%s - Carro %d", atual->piloto->nome, atual->carro->id);

        atual = atual->prox;
    }
}

