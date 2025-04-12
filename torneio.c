#include "torneio.h"
#include <stdio.h>
#include <estrutura.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern Jogo jogos[100];
extern int totalJogos;

extern Equipe equipes[100];
extern Modalidade modalidades[10];
extern int totalEquipes, totalModalidades;

Torneio torneios[10];
int totalTorneios = 0;

char nomeModalidadeBusca[50];
int indiceModalidade = -1;

// Função ordena data
int compararDatas(const void *a, const void *b) {
    const Jogo *jogoA = (const Jogo *)a;
    const Jogo *jogoB = (const Jogo *)b;
    return strcmp(jogoA->dataHora, jogoB->dataHora);
}

void torneio(int opc) {
    int opcaoMenuEquipe, i;
    char siglaBusca[6];
    int equipeEncontrada = 0;

    switch (opc) {
        case 1:
            if (totalTorneios < 10) {
                printf("Nome do torneio: ");
                scanf(" %[^\n]", torneios[totalTorneios].nomeTorneio);

                // Busca pela modalidade
                do {
                    printf("Nome da modalidade: ");
                    scanf(" %[^\n]", nomeModalidadeBusca);
                    for (int j = 0; j < totalModalidades; j++) {
                        if (strcmp(modalidades[j].nomeModalidade, nomeModalidadeBusca) == 0) {
                            indiceModalidade = j;
                            break;
                        }
                    }
                    if (indiceModalidade == -1) {
                        printf("Modalidade não encontrada. Por favor, tente novamente.\n");
                    }
                } while (indiceModalidade == -1);

                torneios[totalTorneios].modalidade = modalidades[indiceModalidade];

                int contadorEquipes = 0;
                while (contadorEquipes < 8) {
                    printf("1 - Adicionar equipe\n2 - Finalizar cadastro\n");
                    scanf("%d", &opcaoMenuEquipe);
                    if (opcaoMenuEquipe == 1) {
                        printf("Sigla da equipe: ");
                        scanf(" %[^\n]", siglaBusca);
                        equipeEncontrada = 0;
                        for (i = 0; i < totalEquipes; i++) {
                            if (strcmp(equipes[i].siglaEquipe, siglaBusca) == 0) {
                                torneios[totalTorneios].equipes[contadorEquipes] = equipes[i];
                                contadorEquipes++;
                                equipeEncontrada = 1;
                                printf("Equipe adicionada.\n");
                                break;
                            }
                        }
                        if (!equipeEncontrada) {
                            printf("Erro: Equipe não encontrada.\n");
                        }
                    } else if (opcaoMenuEquipe == 2) {
                        break;
                    }
                    if (contadorEquipes == 8) {
                        printf("Quantidade máxima de equipes alcançada.\n");
                        break;
                    }
                }
                torneios[totalTorneios].qtdEquipesInscritas = contadorEquipes;
                totalTorneios++;
            } else {
                printf("Limite de 10 torneios alcançado.\n");
            }
            break;
        case 2:
        {
            char nomeTorneioParaRemover[100];
            printf("Digite o nome do torneio a ser removido: ");
            scanf(" %[^\n]", nomeTorneioParaRemover);

            int torneioEncontrado = 0;
            for (int i = 0; i < totalTorneios; i++) {
                if (strcmp(torneios[i].nomeTorneio, nomeTorneioParaRemover) == 0) {
                    torneioEncontrado = 1;
                    // Desloca todos os torneios uma posição para trás
                    for (int j = i; j < totalTorneios - 1; j++) {
                        torneios[j] = torneios[j + 1];
                    }
                    totalTorneios--; // Decrementa o total de torneios
                    printf("Torneio removido com sucesso.\n");
                    break;
                }
            }

            if (!torneioEncontrado) {
                printf("Erro: Torneio não encontrado.\n");
            }
        }
            break;
        case 3:
        {
            char nomeTorneioParaAtualizar[100];
            printf("Digite o nome do torneio a ser atualizado: ");
            scanf(" %[^\n]", nomeTorneioParaAtualizar);

            int torneioEncontrado = 0;
            for (int i = 0; i < totalTorneios; i++) {
                if (strcmp(torneios[i].nomeTorneio, nomeTorneioParaAtualizar) == 0) {
                    torneioEncontrado = 1;

                    Torneio torneioAtualizado;
                    printf("Atualize o nome do torneio: ");
                    scanf(" %[^\n]", torneioAtualizado.nomeTorneio);

                    // Busca pela modalidade
                    printf("Atualize o nome da modalidade: ");
                    scanf(" %[^\n]", nomeModalidadeBusca);
                    indiceModalidade = -1;
                    for (int j = 0; j < totalModalidades; j++) {
                        if (strcmp(modalidades[j].nomeModalidade, nomeModalidadeBusca) == 0) {
                            indiceModalidade = j;
                            break;
                        }
                    }
                    if (indiceModalidade == -1) {
                        printf("Erro: Modalidade não encontrada. Atualização cancelada.\n");
                        break;
                    }
                    torneioAtualizado.modalidade = modalidades[indiceModalidade];

                    // Atualização das equipes
                    torneioAtualizado.qtdEquipesInscritas = 0;
                    int contadorEquipes = 0, equipeEncontrada = 0;
                    while (contadorEquipes < 8) {
                        printf("1 - Adicionar equipe\n2 - Finalizar atualização\n");
                        int opcaoMenuEquipe;
                        scanf("%d", &opcaoMenuEquipe);
                        if (opcaoMenuEquipe == 1) {
                            printf("Sigla da equipe: ");
                            char siglaBusca[6];
                            scanf(" %[^\n]", siglaBusca);
                            equipeEncontrada = 0;
                            for (int k = 0; k < totalEquipes; k++) {
                                if (strcmp(equipes[k].siglaEquipe, siglaBusca) == 0) {
                                    torneioAtualizado.equipes[contadorEquipes] = equipes[k];
                                    contadorEquipes++;
                                    equipeEncontrada = 1;
                                    printf("Equipe adicionada.\n");
                                    break;
                                }
                            }
                            if (!equipeEncontrada) {
                                printf("Erro: Equipe não encontrada. Atualização cancelada.\n");
                                break;
                            }
                        } else if (opcaoMenuEquipe == 2) {
                            break;
                        }
                    }
                    if (!equipeEncontrada) {
                        break;
                    }
                    torneioAtualizado.qtdEquipesInscritas = contadorEquipes;

                    // Atualização confirmada, substituir no array
                    torneios[i] = torneioAtualizado;
                    printf("Torneio atualizado com sucesso.\n");
                    break;
                }
            }
            if (!torneioEncontrado) {
                printf("Erro: Torneio não encontrado.\n");
            }
        }
            break;
        case 4:
        {
            char nomeTorneioBuscado[100];
            printf("Digite o nome do torneio que deseja visualizar: ");
            scanf(" %[^\n]", nomeTorneioBuscado);

            int torneioEncontrado = 0;
            for (int i = 0; i < totalTorneios; i++) {
                if (strcmp(torneios[i].nomeTorneio, nomeTorneioBuscado) == 0) {
                    torneioEncontrado = 1;
                    printf("Nome do Torneio: %s\n", torneios[i].nomeTorneio);
                    printf("Modalidade: %s\n", torneios[i].modalidade.nomeModalidade);
                    printf("Equipes Inscritas: %d\n", torneios[i].qtdEquipesInscritas);
                    printf("Equipes Participantes:\n");
                    for (int j = 0; j < torneios[i].qtdEquipesInscritas; j++) {
                        printf("  %s (%s)\n", torneios[i].equipes[j].nomeEquipe, torneios[i].equipes[j].siglaEquipe);
                    }
                    break;
                }
            }

            if (!torneioEncontrado) {
                printf("Erro: Torneio não encontrado.\n");
            }
        }
            break;
        case 5:
            printf("\n--- Torneios ---\n");
            for (int i = 0; i < totalTorneios; i++) {
                printf("Nome do Torneio: %s, Modalidade: %s, Equipes Inscritas: %d\n",
                       torneios[i].nomeTorneio, torneios[i].modalidade.nomeModalidade, torneios[i].qtdEquipesInscritas);
                printf("Equipes Participantes:\n");
                for (int j = 0; j < torneios[i].qtdEquipesInscritas; j++) {
                    printf("  %s (%s)\n", torneios[i].equipes[j].nomeEquipe, torneios[i].equipes[j].siglaEquipe);
                }
            }

            sleep(10);

            break;
        case 6:
        {
            char nomeTorneioBusca[100];
            printf("Digite o nome do torneio para visualizar seus jogos: ");
            scanf(" %[^\n]", nomeTorneioBusca);

            Jogo jogosTorneio[100];
            int totalJogosTorneio = 0;

            // Filtrar jogos pelo nome do torneio
            for (int i = 0; i < totalJogos; i++) {
                if (strcmp(jogos[i].nomeTorneio, nomeTorneioBusca) == 0) {
                    jogosTorneio[totalJogosTorneio++] = jogos[i];
                }
            }

            // Ordenar jogos do torneio por data/hora
            qsort(jogosTorneio, totalJogosTorneio, sizeof(Jogo), compararDatas);

            // Verificar se encontramos jogos para o torneio
            if (totalJogosTorneio > 0) {
                printf("\n--- Jogos do Torneio: %s (Ordenados por Data/Hora) ---\n", nomeTorneioBusca);
                for (int i = 0; i < totalJogosTorneio; i++) {
                    printf("Jogo: %s x %s, Data/Hora: %s, Pontuação: %d x %d, Identificador: %s\n",
                           jogosTorneio[i].siglaPrimeiraEquipe, jogosTorneio[i].siglaSegundaEquipe,
                           jogosTorneio[i].dataHora, jogosTorneio[i].pontuacaoPrimeiroTime, jogosTorneio[i].pontuacaoSegundoTime,
                           jogosTorneio[i].identificadorJogo);
                }
            } else {
                printf("Erro: Torneio não encontrado ou sem jogos.\n");
            }
        }
            sleep(5);
            break;
    }
}