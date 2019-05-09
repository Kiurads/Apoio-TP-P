#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "pilotos.h"
#include "carros.h"

void mostraMenu();

int main() {
    pCarros vetorCarros;
    pPilotos vetorPilotos;
    pCorridas vetorCorridas;
    int nCarros;
    int nPilotos;
    int nCorridas;
    int op;

    nCarros = 0;
    nPilotos = 0;
    nCorridas = 0;

    vetorCarros = getVetorCarros(&nCarros);
    system("clear");

    vetorPilotos = getVetorPilotos(&nPilotos);
    system("clear");

    if (vetorCarros == NULL || vetorPilotos == NULL) {
        printf("Erro na criação do vetor\n");
        return 1;
    }

    while (op != 4) {
        op = 0;

        mostraMenu();

        scanf("%d", &op);

        system("clear");

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
            printf("Under development\n");
            break;
        case 4:
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
    printf("3 - Monta corrida\n");
    printf("4 - Sair\n");
    printf("\n");
    printf("Opcao: ");
}