#include <stdio.h>
#include <stdlib.h>
#include "pilotos.h"
#include "carros.h"
#include "corridas.h"

void mostraMenu();

int main() {
    pCarros vetorCarros;
    pPilotos vetorPilotos;
    pCorridas listaCorridas;
    pCorridas atual;
    int nCarros;
    int nPilotos;
    int nCorridas;
    int op;


    listaCorridas = NULL;
    nCarros = 0;
    nPilotos = 0;
    nCorridas = 0;

    system("cls");

    vetorCarros = getVetorCarros(&nCarros);
    system("cls");

    vetorPilotos = getVetorPilotos(&nPilotos);
    system("cls");

    if (vetorCarros == NULL || vetorPilotos == NULL) {
        printf("Erro na criação do vetor\n");
        return 1;
    }

    while (op != 5) {
        op = 0;

        mostraMenu();

        scanf("%d", &op);

        system("cls");

        switch (op) {
        case 1:
            for (int i = 0; i < nPilotos; i++) {
                printPiloto(vetorPilotos[i]);
            }
            break;
        case 2:
            for (int i = 0; i < nCarros; i++) {
                printCarro(vetorCarros[i]);
            }
            break;
        case 3:
            atual = listaCorridas;

            while(atual != NULL) {
                atual = atual->prox;
            }

            atual = novaCorrida(listaCorridas, &nCorridas);

            atual->lista = fazPares(vetorPilotos, vetorCarros, atual, nPilotos, nCarros);

            atual->prox = listaCorridas;

            listaCorridas = atual;

            break;
        case 4:
            atual = listaCorridas;

            while (atual != NULL) {
                printCorrida(atual);
                atual = atual->prox;
            }

            break;
        case 5:
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    }

    return 0;
}

void mostraMenu() {
    printf("1 - Mostra pilotos\n");
    printf("2 - Mostra carros\n");
    printf("3 - Nova corrida individual\n");
    printf("4 - Mostra corridas\n");
    printf("5 - Sair\n");
    printf("\n");
    printf("Opcao: ");
}
