#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

struct carros* getVetor(int *nCarros);
void printCarro(struct carros c);

struct carros {
    int id;
    int potencia;
    int avaria;
};

int main() {
    struct carros *vetorCarros;
    int nCarros;

    nCarros = 0;

    vetorCarros = getVetor(&nCarros);

    if (vetorCarros == NULL) {
        printf("Erro na criação do vetor\n");
        return 1;
    }
    return 0;
}

struct carros* getVetor(int *nCarros) {
    char buffer[TAM];
    FILE *fCarros;
    struct carros *v;
    int id;
    int potencia;
    int avaria;

    v = NULL;

    printf("Escreva o nome do ficheiro: ");
    scanf("%s", buffer);

    fCarros = fopen(buffer, "r");

    if(fCarros == NULL) {
        printf("Ficheiro nao aberto!\n");
        return NULL;
    }

    while(fscanf(fCarros, "%d  %d  %d\n\n", &id, &potencia, &avaria) > 0) {
        (*nCarros)++;

        v = realloc(v, sizeof(struct carros) * (*nCarros));

        if(v == NULL) {
            return v;
        }

        v[(*nCarros) - 1].id = id;
        v[(*nCarros) - 1].potencia = potencia;
        v[(*nCarros) - 1].avaria = avaria;

        printCarro(v[(*nCarros) - 1]);
    }

    fclose(fCarros);
    return v;
}

void printCarro(struct carros c) {
    printf("ID: %d\n", c.id);
    printf("Potencia: %d\n", c.potencia);
    printf("Avaria: %d\n\n", c.avaria);
}