#include <stdio.h>
#include "equipe.h"
#include "atleta.h"
#include "modalidade.h"
#include "torneio.h"
#include "jogos.h"
#include "estrutura.h"

int main(void) {
    int sis = 0;
    int opc = 0;

    do {
        printf("1. Sistema de Cadastro de Atletas;\n"
               "2. Sistema de Cadastro de Modalidades;\n"
               "3. Sistema de Cadastro de Equipes;\n"
               "4. Sistema de Cadastro de Torneios;\n"
               "5. Sistema de Cadastro de Jogos;\n"
               "6. Sair do Sistema.\n"
               "Digite a opção desejada: ");
        scanf("%d", &sis);

        if (sis > 0 && sis < 6) {
            if (sis == 4) {
                printf("1. Cadastrar;\n"
                       "2. Excluir;\n"
                       "3. Atualizar;\n"
                       "4. Exibir registro;\n"
                       "5. Exibir todos os registros.\n"
                       "6. Exibir jogos de um torneio.\n");
            } else {
                printf("1. Cadastrar;\n"
                       "2. Excluir;\n"
                       "3. Atualizar;\n"
                       "4. Exibir registro;\n"
                       "5. Exibir todos os registros.\n");
            }

            printf("Digite a opção desejada: ");
            scanf("%d", &opc);

            if (opc > 0 && opc < 6) {
                switch (sis) {
                    case 1:
                        atleta(opc);
                        break;
                    case 2:
                        modalidade(opc);
                        break;
                    case 3:
                        equipe(opc);
                        break;
                    case 4:
                        torneio(opc);
                        break;
                    case 5:
                        jogo(opc);
                        break;
                }
            } else if (sis == 4 && opc == 6) {
                torneio(opc);
            } else {
                printf("Opção inválida.\n");
            }
        } else if (sis != 6) {
            printf("Opção inválida.\n");
        }
    } while (sis != 6);

    printf("Você escolheu sair do sistema, adeus.\n");

    return 0;
}