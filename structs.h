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

typedef struct par{
    pPilotos piloto;
    pCarros carro;
    struct par *prox;
}par, *pPar;

typedef struct{
    int voltas;
    int comprimento;
    int maxcarros;
    pPar lista;
}corridas, *pCorridas;

#endif