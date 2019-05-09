#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilotos.h"

pPilotos getVetorPilotos(int *nPilotos) {
    char buffer[TAM];
    FILE *fPilotos;
    pPilotos v;

    v = NULL;

    printf("Escreva o nome do ficheiro de pilotos: ");
    scanf("%s", buffer);

    fPilotos = fopen(buffer, "r");

    if(fPilotos == NULL) {
        printf("Ficheiro nao aberto!\n");
        return NULL;
    }

    while(fscanf(fPilotos, "%[^\n]s", buffer) > 0) {
        (*nPilotos)++;

        v = realloc(v, sizeof(pilotos) * (*nPilotos));

        if(v == NULL) {
            return v;
        }

        strcpy(v[(*nPilotos) - 1].nome, buffer);

        fscanf(fPilotos, "%d  %d  %d  %d  %d  %f  %d\n\n", 
            &v[(*nPilotos) - 1].id, 
            &v[(*nPilotos) - 1].dataNascimento.dia, 
            &v[(*nPilotos) - 1].dataNascimento.mes,
            &v[(*nPilotos) - 1].dataNascimento.ano,
            &v[(*nPilotos) - 1].peso, 
            &v[(*nPilotos) - 1].experiencia, 
            &v[(*nPilotos) - 1].impedimento);
    }

    fclose(fPilotos);

    v = verificaPilotos(v, nPilotos);

    return v;
}

pPilotos verificaPilotos(pPilotos v, int *nPilotos) {
    for(int i = 0; i < (*nPilotos); i++) {
        if (!verificaData(v[i].dataNascimento.dia, v[i].dataNascimento.mes, v[i].dataNascimento.ano) ||
            v[i].impedimento < 0 || v[i].impedimento > 3 ||
            v[i].peso <= 0) {
            for(int j = i; j < (*nPilotos) - 1; j++) {
                v[j] = v[j + 1];
            }

            (*nPilotos)--;

            v = realloc(v, sizeof(pilotos) * (*nPilotos));
        }
    }

    return v;
}

int verificaData(int dia, int mes, int ano) {
    int diasDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int valido = 0;

    if(ano % 400 == 0 || (ano % 100 != 0 && ano % 4 == 0))
        diasDoMes[1] = 29;

    if (mes < 13) {
        if(dia <= diasDoMes[mes - 1])
        valido = 1;
    }

    return valido;
}

void printPiloto(pilotos p) {
    printf("Nome: %s\n", p.nome);
    printf("ID: %d\n", p.id);
    printf("Data de Nascimento: %d %d %d\n", p.dataNascimento.dia, p.dataNascimento.mes, p.dataNascimento.ano);
    printf("Peso: %d\n", p.peso);
    printf("Experiencia: %f\n", p.experiencia);
    printf("Impedimento: %d\n\n\n", p.impedimento);
}