#include "jogos.h"
#include <stdio.h>
#include "estrutura.h"
#include <string.h>
#include <unistd.h>

Jogo jogos[100];
int totalJogos = 0;

void jogo(int opc) {
    int cont = 0;
    switch (opc) {
        case 1:
            if (totalJogos < 100) {
                printf("Nome do torneio: ");
                scanf(" %[^\n]", jogos[totalJogos].nomeTorneio);
                do{
                    cont++;
                    if (cont > 1) {
                        printf("Erro: Sigla inválida. ");
                    }
                    printf("Sigla da primeira equipe: ");
                    scanf(" %[^\n]", jogos[totalJogos].siglaPrimeiraEquipe);
                } while(strlen(jogos[totalJogos].siglaPrimeiraEquipe) >= 5);
                cont = 0;
                do{
                    cont++;
                    if (cont > 1) {
                        printf("Erro: Sigla inválida. ");
                    }
                    printf("Sigla da segunda equipe: ");
                    scanf(" %[^\n]", jogos[totalJogos].siglaSegundaEquipe);
                } while(strlen(jogos[totalJogos].siglaSegundaEquipe) >= 5);
                cont = 0;
                do{
                    cont++;
                    if (cont > 1) {
                        printf("Erro: Data/hora inválida. ");
                    }
                    printf("Data/hora do jogo no formato “AAAA-MM-DD HH:MM”: ");
                    scanf(" %[^\n]", jogos[totalJogos].dataHora);
                } while(strlen(jogos[totalJogos].dataHora) != 16 || jogos[totalJogos].dataHora[4] != '-' || jogos[totalJogos].dataHora[7] != '-' || jogos[totalJogos].dataHora[10] != ' ' || jogos[totalJogos].dataHora[13] != ':');
                printf("Pontuacao da primeira equipe: ");
                scanf("%d", &jogos[totalJogos].pontuacaoPrimeiroTime);
                printf("Pontuacao da segunda equipe: ");
                scanf("%d", &jogos[totalJogos].pontuacaoSegundoTime);
                char identificador[100];
                sprintf(identificador, "%s x %s %s", jogos[totalJogos].siglaPrimeiraEquipe, jogos[totalJogos].siglaSegundaEquipe, jogos[totalJogos].dataHora);
                strcpy(jogos[totalJogos].identificadorJogo, identificador);
                totalJogos++;
            } else {
                printf("Limite de 10 modalidades alcançado.\n");
            }
            break;
        case 2:
        {
            char identificadorParaRemover[50];
            printf("Digite o identificador do jogo (TIME1xTIME2 AAAA-MM-DD HH:MM) a ser removido: ");
            scanf(" %[^\n]", identificadorParaRemover);

            int jogoEncontrado = 0;
            for (int i = 0; i < totalJogos; i++) {
                if (strcmp(jogos[i].identificadorJogo, identificadorParaRemover) == 0) {
                    jogoEncontrado = 1;
                    // Desloca todos os jogos uma posição para trás
                    for (int j = i; j < totalJogos - 1; j++) {
                        jogos[j] = jogos[j + 1];
                    }
                    totalJogos--; // Decrementa o total de jogos
                    printf("Jogo removido com sucesso.\n");
                    break;
                }
            }

            if (!jogoEncontrado) {
                printf("Erro: Jogo não encontrado.\n");
            }
        }
            break;
        case 3:
        {
            char identificadorParaAtualizar[50];
            printf("Digite o identificador do jogo (TIME1xTIME2 AAAA-MM-DD HH:MM) a ser atualizado: ");
            scanf(" %[^\n]", identificadorParaAtualizar);

            int jogoEncontrado = 0;
            for (int i = 0; i < totalJogos; i++) {
                if (strcmp(jogos[i].identificadorJogo, identificadorParaAtualizar) == 0) {
                    jogoEncontrado = 1;

                    Jogo jogoAtualizado;
                    printf("Atualize o nome do torneio: ");
                    scanf(" %[^\n]", jogoAtualizado.nomeTorneio);
                    do{
                        cont++;
                        if (cont > 1) {
                            printf("Erro: Sigla inválida. ");
                        }
                        printf("Atualize a sigla da primeira equipe: ");
                        scanf(" %[^\n]", jogoAtualizado.siglaPrimeiraEquipe);
                    } while(strlen(jogoAtualizado.siglaPrimeiraEquipe) >= 5);
                    cont = 0;
                    do {
                        cont++;
                        if (cont > 1) {
                            printf("Erro: Sigla inválida. ");
                        }
                        printf("Atualize a sigla da segunda equipe: ");
                        scanf(" %[^\n]", jogoAtualizado.siglaSegundaEquipe);
                    } while(strlen(jogoAtualizado.siglaSegundaEquipe) >= 5);
                    cont = 0;
                    do {
                        cont++;
                        if (cont > 1) {
                            printf("Erro: Data/hora inválida. ");
                        }
                        printf("Atualize a data/hora do jogo no formato “AAAA-MM-DD HH:MM”: ");
                        scanf(" %[^\n]", jogoAtualizado.dataHora);
                    } while(strlen(jogoAtualizado.dataHora) != 16 || jogoAtualizado.dataHora[4] != '-' || jogoAtualizado.dataHora[7] != '-' || jogoAtualizado.dataHora[10] != ' ' || jogoAtualizado.dataHora[13] != ':');
                    printf("Atualize a pontuação da primeira equipe: ");
                    scanf("%d", &jogoAtualizado.pontuacaoPrimeiroTime);
                    printf("Atualize a pontuação da segunda equipe: ");
                    scanf("%d", &jogoAtualizado.pontuacaoSegundoTime);

                    // Atualização confirmada, substituir no array
                    jogos[i] = jogoAtualizado;
                    printf("Jogo atualizado com sucesso.\n");
                    break;
                }
            }
            if (!jogoEncontrado) {
                printf("Erro: Jogo não encontrado.\n");
            }
        }
            break;

        case 4:
        {
            char identificadorBuscado[50];
            printf("Digite o identificador do jogo (AAAA-MM-DD HH:MM) que deseja visualizar: ");
            scanf(" %[^\n]", identificadorBuscado);

            int jogoEncontrado = 0;
            for (int i = 0; i < totalJogos; i++) {
                if (strcmp(jogos[i].identificadorJogo, identificadorBuscado) == 0) {
                    jogoEncontrado = 1;
                    printf("Torneio: %s\n", jogos[i].nomeTorneio);
                    printf("Primeira Equipe: %s\n", jogos[i].siglaPrimeiraEquipe);
                    printf("Segunda Equipe: %s\n", jogos[i].siglaSegundaEquipe);
                    printf("Data/Hora: %s\n", jogos[i].dataHora);
                    printf("Pontuação: %d x %d\n", jogos[i].pontuacaoPrimeiroTime, jogos[i].pontuacaoSegundoTime);
                    printf("Identificador: %s\n", jogos[i].identificadorJogo);
                    break;
                }
            }

            if (!jogoEncontrado) {
                printf("Erro: Jogo não encontrado.\n");
            }
        }
            break;
        case 5:
            printf("\n--- Jogos ---\n");
            for (int i = 0; i < totalJogos; i++) {
                printf("Torneio: %s, Jogo: %s x %s, Data/Hora: %s, Pontuação: %d x %d, Identificador: %s\n",
                       jogos[i].nomeTorneio, jogos[i].siglaPrimeiraEquipe, jogos[i].siglaSegundaEquipe,
                       jogos[i].dataHora, jogos[i].pontuacaoPrimeiroTime, jogos[i].pontuacaoSegundoTime,
                       jogos[i].identificadorJogo);
            }

            sleep(5);

            break;
    }
}