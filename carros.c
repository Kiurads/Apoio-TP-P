#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carros.h"

pCarros getVetorCarros(int *nCarros) {
    char buffer[TAM];
    FILE *fCarros;
    pCarros v;
    int id;
    int potencia;
    int avaria;

    v = NULL;

    printf("Escreva o nome do ficheiro de carros: ");
    scanf("%s", buffer);

    fCarros = fopen(buffer, "r");

    if(fCarros == NULL) {
        printf("Ficheiro nao aberto!\n");
        return NULL;
    }

    while(fscanf(fCarros, "%d  %d  %d\n\n", &id, &potencia, &avaria) > 0) {
        (*nCarros)++;

        v = realloc(v, sizeof(carros) * (*nCarros));

        if(v == NULL) {
            return v;
        }

        v[(*nCarros) - 1].id = id;
        v[(*nCarros) - 1].potencia = potencia;
        v[(*nCarros) - 1].avaria = avaria;
    }

    fclose(fCarros);
    
    return v;
}

void printCarro(carros c) {
    printf("ID: %d\n", c.id);
    printf("Potencia: %d\n", c.potencia);
    printf("Avaria: %d\n\n", c.avaria);
}