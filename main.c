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
    pCorridas nova;
    pCorridas atual;
    pCorridas ultima;
    int nCarros;
    int nPilotos;
    int nCorridas;
    int op;


    listaCorridas = NULL;
    nCarros = 0;
    nPilotos = 0;
    nCorridas = 0;

    system("clear");

    vetorCarros = getVetorCarros(&nCarros);
    system("clear");

    vetorPilotos = getVetorPilotos(&nPilotos);
    system("clear");

    if (vetorCarros == NULL || vetorPilotos == NULL) {
        printf("Erro na criação do vetor\n");
        return 1;
    }

    while (op != 5) {
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
            ultima = listaCorridas;
            
            nova = novaCorrida();
            nova->lista = fazPares(vetorPilotos, vetorCarros, nova, nPilotos, nCarros);

            if (listaCorridas == NULL)
                listaCorridas = nova;
            else {
                while(ultima->prox != NULL) 
                    ultima = ultima->prox;

                ultima->prox = nova;
            }
            
            nCorridas++;
            
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
