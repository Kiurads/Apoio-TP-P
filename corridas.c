#include <stdlib.h>
#include <stdio.h>
#include "corridas.h"
#include "utils.h"

pCorridas novaCorrida() {
    pCorridas v;

    v = NULL;
    v = malloc(sizeof(corridas));

    if(v == NULL) {
        return NULL;
    }

    do {
        printf("Numero de voltas (entre 5 e 10): ");
        scanf("%d", &v[0].voltas);
    } while(v[0].voltas < 5 || v[0].voltas > 10);

    do {
        printf("Comprimento (entre 500 e 1000): ");
        scanf("%d", &v[0].comprimento);
    } while(v[0].comprimento < 500 || v[0].comprimento > 1000);

    do {
        printf("Maximo de participantes: ");
        scanf("%d", &v[0].maxparticipantes);
    } while(v[0].maxparticipantes <= 0);

    v[0].lista = NULL;
    v[0].prox = NULL;

    return v;
}

pPar fazPares(pPilotos vetorPilotos, pCarros vetorCarros, pCorridas corrida, int nPilotos, int nCarros) {
    pPilotos *vPilotos;
    pCarros *vCarros;
    pPar vetorPares;
    int pilotosValidos;
    int carrosValidos;

    initRandom();

    vetorPares = NULL;
    pilotosValidos = 0;
    carrosValidos = 0;

    for (int i = 0; i < nPilotos; i++) {
        if(vetorPilotos[i].impedimento == 0) pilotosValidos++;
    }

    for (int i = 0; i < nCarros; i++) {
        if(vetorCarros[i].avaria == 0) carrosValidos++;
    }

    if(carrosValidos == 0 || pilotosValidos == 0) {
        return NULL;
    }

    corrida->maxparticipantes = getMinimo(corrida->maxparticipantes, pilotosValidos, carrosValidos);

    vPilotos = malloc(sizeof(pilotos) * pilotosValidos);
    vCarros = malloc(sizeof(carros) * carrosValidos);

    int i = 0;

    for (int j = 0; j < nPilotos; j++) {
        if(vetorPilotos[j].impedimento == 0) {
            vPilotos[i] = &vetorPilotos[j];
            i++;
        }
    }

    i = 0;

    for (int j = 0; j < nPilotos; j++) {
        if(vetorCarros[j].avaria == 0) {
            vCarros[i] = &vetorCarros[j];
            i++;
        }
    }

    for (int j = 0; j < corrida->maxparticipantes; j++) {
        int piloto;
        int carro;
        int size;

        size = j + 1;

        piloto = intUniformRnd(0, pilotosValidos - 1);
        carro = intUniformRnd(0, carrosValidos - 1);

        vetorPares = realloc(vetorPares, sizeof(par) * size);

        vetorPares[j].carro = vCarros[carro];
        vetorPares[j].piloto = vPilotos[piloto];

        vPilotos[piloto] = vPilotos[pilotosValidos - 1];
        vCarros[carro] = vCarros[carrosValidos - 1];

        pilotosValidos--;
        carrosValidos--;
    }

    return vetorPares;
}

int getMinimo(int max, int pilotos, int carros) {
    int temp;

    temp = max;

    if(temp > pilotos) temp = pilotos;
    if(temp > carros) temp = carros;

    return temp;
}

void printCorrida(pCorridas c) {
    printf("\nVoltas: %d\n", c->voltas);
    printf("Comprimento: %d metros\n", c->comprimento);
    printf("Maximo participantes: %d\n\n", c->maxparticipantes);
    printf("Participantes:\n");

    for (int i = 0; i < c->maxparticipantes; i++) {
        printf("\t%s - Carro %d\n", c->lista[i].piloto->nome, c->lista[i].carro->id);
    }
}

