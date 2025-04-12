#include "equipe.h"
#include <stdio.h>
#include <string.h>
#include "estrutura.h"
#include <unistd.h>

extern Atleta atletas[1000];
extern Modalidade modalidades[10];
extern int totalAtletas, totalModalidades;

Equipe equipes[100];
int totalEquipes = 0;

void equipe(int opc) {
    int cont = 0;
    int opcaoMenuAtleta, i, j;
    char cpfBusca[15];
    char nomeModalidadeBusca[50];
    int indiceModalidade = -1;

    switch (opc) {
        case 1:
            if (totalEquipes < 100) {
                printf("Nome da equipe: ");
                scanf(" %[^\n]", equipes[totalEquipes].nomeEquipe);

                do{
                    cont++;
                    if (cont > 1) {
                        printf("Erro: Sigla inválida. ");
                    }
                    printf("Sigla da equipe: ");
                    scanf(" %[^\n]", equipes[totalEquipes].siglaEquipe);
                } while(strlen(equipes[totalEquipes].siglaEquipe) >= 5);
                cont = 0;
                // Busca pela modalidade
                do {
                    printf("Nome da modalidade: ");
                    scanf(" %[^\n]", nomeModalidadeBusca);
                    for (j = 0; j < totalModalidades; j++) {
                        if (strcmp(modalidades[j].nomeModalidade, nomeModalidadeBusca) == 0) {
                            indiceModalidade = j;
                            break;
                        }
                    }
                    if (indiceModalidade == -1) {
                        printf("Modalidade não encontrada. Por favor, tente novamente.\n");
                    }
                } while (indiceModalidade == -1);

                equipes[totalEquipes].modalidade = modalidades[indiceModalidade];

                int contadorAtletas = 0;
                int maxAtletas = modalidades[indiceModalidade].qtdAtletasPorEquipe;
                while (contadorAtletas < maxAtletas) {
                    printf("1 - Adicionar atleta\n2 - Finalizar cadastro\n");
                    scanf("%d", &opcaoMenuAtleta);
                    if (opcaoMenuAtleta == 1) {
                        do{
                            cont++;
                            if (cont > 1) {
                                printf("Erro: CPF inválido. ");
                            }
                            printf("CPF(“XXX.XXX.XXX-XX”) do atleta: ");
                            scanf(" %[^\n]", cpfBusca);
                        } while(strlen(cpfBusca) != 14 || cpfBusca[3] != '.' || cpfBusca[7] != '.' || cpfBusca[11] != '-');
                        cont = 0;
                        int atletaEncontrado = 0;
                        for (i = 0; i < totalAtletas; i++) {
                            if (strcmp(atletas[i].cpf, cpfBusca) == 0) {
                                equipes[totalEquipes].atletas[contadorAtletas] = atletas[i];
                                contadorAtletas++;
                                atletaEncontrado = 1;
                                printf("Atleta adicionado.\n");
                                break;
                            }
                        }
                        if (!atletaEncontrado) {
                            printf("Erro: Atleta não encontrado.\n");
                        }
                    } else if (opcaoMenuAtleta == 2) {
                        break;
                    }
                    if (contadorAtletas == maxAtletas) {
                        printf("Quantidade máxima de atletas alcançada.\n");
                        break;
                    }
                }
                totalEquipes++;
            } else {
                printf("Limite de 100 equipes alcançado.\n");
            }
            break;
        case 2:
        {
            char siglaParaRemover[6];
            do{
                cont++;
                if (cont > 1) {
                    printf("Erro: Sigla inválida. ");
                }
                printf("Digite a sigla da equipe a ser removida: ");
                scanf(" %[^\n]", siglaParaRemover);
            } while(strlen(siglaParaRemover) >= 5);
            int equipeEncontrada = 0;
            for (int i = 0; i < totalEquipes; i++) {
                if (strcmp(equipes[i].siglaEquipe, siglaParaRemover) == 0) {
                    equipeEncontrada = 1;
                    // Desloca todas as equipes uma posição para trás
                    for (int j = i; j < totalEquipes - 1; j++) {
                        equipes[j] = equipes[j + 1];
                    }
                    totalEquipes--; // Decrementa o total de equipes
                    printf("Equipe removida com sucesso.\n");
                    break;
                }
            }

            if (!equipeEncontrada) {
                printf("Erro: Equipe não encontrada.\n");
            }
        }
            break;
        case 3:
        {
            char siglaParaAtualizar[6];
            do {
                cont++;
                if (cont > 1) {
                    printf("Erro: Sigla inválida. ");
                }
                printf("Digite a sigla da equipe a ser atualizada: ");
                scanf(" %[^\n]", siglaParaAtualizar);
            } while(strlen(siglaParaAtualizar) >= 5);
            cont = 0;

            int equipeEncontrada = 0;
            for (int i = 0; i < totalEquipes; i++) {
                if (strcmp(equipes[i].siglaEquipe, siglaParaAtualizar) == 0) {
                    equipeEncontrada = 1;

                    Equipe equipeAtualizada;
                    printf("Atualize o nome da equipe: ");
                    scanf(" %[^\n]", equipeAtualizada.nomeEquipe);
                    do{
                        cont++;
                        if (cont > 1) {
                            printf("Erro: Sigla inválida. ");
                        }
                        printf("Atualize a sigla da equipe: ");
                        scanf(" %[^\n]", equipeAtualizada.siglaEquipe);
                    } while(strlen(equipeAtualizada.siglaEquipe) >= 5);

                    // Busca pela modalidade atualizada
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
                    equipeAtualizada.modalidade = modalidades[indiceModalidade];

                    equipes[i] = equipeAtualizada;
                    printf("Equipe atualizada com sucesso.\n");
                    break;
                }
            }
            if (!equipeEncontrada) {
                printf("Erro: Equipe não encontrada.\n");
            }
        }
            break;
        case 4:
        {
            char siglaBuscada[6];
            do{
                cont++;
                if (cont > 1) {
                    printf("Erro: Sigla inválida. ");
                }
                printf("Digite a sigla da equipe que deseja visualizar: ");
                scanf(" %[^\n]", siglaBuscada);
            } while(strlen(siglaBuscada) >= 5);

            int equipeEncontrada = 0;
            for (int i = 0; i < totalEquipes; i++) {
                if (strcmp(equipes[i].siglaEquipe, siglaBuscada) == 0) {
                    equipeEncontrada = 1;
                    printf("Nome da Equipe: %s\n", equipes[i].nomeEquipe);
                    printf("Sigla: %s\n", equipes[i].siglaEquipe);
                    printf("Modalidade: %s\n", equipes[i].modalidade.nomeModalidade);
                    printf("Atletas da Equipe:\n");
                    for (int j = 0; j < 20; j++) {
                        if (strlen(equipes[i].atletas[j].nome) > 0) { // Verifica se o nome do atleta não está vazio
                            printf("  %s\n", equipes[i].atletas[j].nome);
                        }
                    }
                    break;
                }
            }

            if (!equipeEncontrada) {
                printf("Erro: Equipe não encontrada.\n");
            }
        }
            break;
        case 5:
            printf("\n--- Equipes ---\n");
            for (int i = 0; i < totalEquipes; i++) {
                printf("Nome da Equipe: %s, Sigla: %s, Modalidade: %s\n",
                       equipes[i].nomeEquipe, equipes[i].siglaEquipe, equipes[i].modalidade.nomeModalidade);
                printf("Atletas da Equipe:\n");
                for (int j = 0; j < 20; j++) {
                    if (strlen(equipes[i].atletas[j].nome) > 0) { // Verifica se o nome do atleta não está vazio
                        printf("  %s\n", equipes[i].atletas[j].nome);
                    }
                }
            }

            sleep(5);

            break;
    }
}