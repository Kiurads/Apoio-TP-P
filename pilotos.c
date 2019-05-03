#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

struct pilotos* getVetor(int *nPilotos);
void printPiloto(struct pilotos p);

struct data {
    int dia;
    int mes;
    int ano;
};

struct pilotos {
    int id;
    char nome[TAM];
    struct data dataNascimento;
    int peso;
    float experiencia;
    int impedimento;
};

int main() {
    struct pilotos *vetorPilotos;
    int nPilotos;

    nPilotos = 0;

    vetorPilotos = getVetor(&nPilotos);

    if (vetorPilotos == NULL) {
        printf("Erro na criação do vetor\n");
        return 1;
    }
    return 0;
}

struct pilotos* getVetor(int *nPilotos) {
    char buffer[TAM];
    FILE *fPilotos;
    struct pilotos *v;

    v = NULL;

    printf("Escreva o nome do ficheiro: ");
    scanf("%s", buffer);

    fPilotos = fopen(buffer, "r");

    if(fPilotos == NULL) {
        printf("Ficheiro nao aberto!\n");
        return NULL;
    }

    while(fscanf(fPilotos, "%[^\n]s", buffer) > 0) {
        (*nPilotos)++;

        v = realloc(v, sizeof(struct pilotos) * (*nPilotos));

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

        printPiloto(v[(*nPilotos) - 1]);
    }

    fclose(fPilotos);
    return v;
}

void printPiloto(struct pilotos p) {
    printf("Nome: %s\n", p.nome);
    printf("ID: %d\n", p.id);
    printf("Data de Nascimento: %d %d %d\n", p.dataNascimento.dia, p.dataNascimento.mes, p.dataNascimento.ano);
    printf("Peso: %d\n", p.peso);
    printf("Experiencia: %f\n", p.experiencia);
    printf("Impedimento: %d\n\n\n", p.impedimento);
}