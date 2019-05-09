#ifndef STRUCTS_H
#define STRUCTS_H

#define TAM 50

typedef struct{
    int id;
    int potencia;
    int avaria;
}carros, *pCarros;

typedef struct {
    int dia;
    int mes;
    int ano;
} data;

typedef struct{
    int id;
    char nome[TAM];
    data dataNascimento;
    int peso;
    float experiencia;
    int impedimento;
}pilotos, *pPilotos;

typedef struct{
    pPilotos piloto;
    pCarros carro;
}par, *pPar;

typedef struct corrida{
    int voltas;
    int comprimento;
    int maxparticipantes;
    pPar lista;
    struct corrida* prox;
}corridas, *pCorridas;

#endif