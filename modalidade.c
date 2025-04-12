#include "modalidade.h"
#include <stdio.h>
#include "estrutura.h"
#include <string.h>
#include <unistd.h>

Modalidade modalidades[10];
int totalModalidades = 0;

void modalidade(int opc) {
    switch (opc) {
        case 1:
            if (totalModalidades < 10) {
                printf("Nome da modalidade: ");
                scanf(" %[^\n]", modalidades[totalModalidades].nomeModalidade);
                printf("Indique a quatindade de atletas por equipe: ");
                scanf("%d", &modalidades[totalModalidades].qtdAtletasPorEquipe);
                totalModalidades++;
            } else {
                printf("Limite de 10 modalidades alcançado.\n");
            }
            break;
        case 2:
        {
            char nomeModalidadeParaRemover[50];
            printf("Digite o nome da modalidade a ser removida: ");
            scanf(" %[^\n]", nomeModalidadeParaRemover);

            int modalidadeEncontrada = 0;
            for (int i = 0; i < totalModalidades; i++) {
                if (strcmp(modalidades[i].nomeModalidade, nomeModalidadeParaRemover) == 0) {
                    modalidadeEncontrada = 1;
                    // Desloca todas as modalidades uma posição para trás
                    for (int j = i; j < totalModalidades - 1; j++) {
                        modalidades[j] = modalidades[j + 1];
                    }
                    totalModalidades--; // Decrementa o total de modalidades
                    printf("Modalidade removida com sucesso.\n");
                    break;
                }
            }

            if (!modalidadeEncontrada) {
                printf("Erro: Modalidade não encontrada.\n");
            }
        }
            break;
        case 3:
        {
            char nomeModalidadeParaAtualizar[50];
            printf("Digite o nome da modalidade a ser atualizada: ");
            scanf(" %[^\n]", nomeModalidadeParaAtualizar);

            int modalidadeEncontrada = 0;
            for (int i = 0; i < totalModalidades; i++) {
                if (strcmp(modalidades[i].nomeModalidade, nomeModalidadeParaAtualizar) == 0) {
                    modalidadeEncontrada = 1;

                    Modalidade modalidadeAtualizada;
                    printf("Atualize o nome da modalidade: ");
                    scanf(" %[^\n]", modalidadeAtualizada.nomeModalidade);
                    printf("Atualize a quantidade de atletas por equipe: ");
                    scanf("%d", &modalidadeAtualizada.qtdAtletasPorEquipe);

                    // Atualização confirmada, substituir no array
                    modalidades[i] = modalidadeAtualizada;
                    printf("Modalidade atualizada com sucesso.\n");
                    break;
                }
            }
            if (!modalidadeEncontrada) {
                printf("Erro: Modalidade não encontrada.\n");
            }
        }
            break;
        case 4:
        {
            char nomeModalidadeBuscada[50];
            printf("Digite o nome da modalidade que deseja visualizar: ");
            scanf(" %[^\n]", nomeModalidadeBuscada);

            int modalidadeEncontrada = 0;
            for (int i = 0; i < totalModalidades; i++) {
                if (strcmp(modalidades[i].nomeModalidade, nomeModalidadeBuscada) == 0) {
                    modalidadeEncontrada = 1;
                    printf("Nome da Modalidade: %s\n", modalidades[i].nomeModalidade);
                    printf("Quantidade de Atletas por Equipe: %d\n", modalidades[i].qtdAtletasPorEquipe);
                    break;
                }
            }

            if (!modalidadeEncontrada) {
                printf("Erro: Modalidade não encontrada.\n");
            }
        }
            break;
        case 5:
            printf("\n--- Modalidades ---\n");
            for (int i = 0; i < totalModalidades; i++) {
                printf("Nome da Modalidade: %s, Qtd Atletas por Equipe: %d\n",
                       modalidades[i].nomeModalidade, modalidades[i].qtdAtletasPorEquipe);
            }

            sleep(5);

            break;
    }
}
