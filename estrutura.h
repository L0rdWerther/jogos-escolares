// Estrutura para Atleta
typedef struct {
    char nome[100];
    char cpf[15];
    char sexo;
    char instituicao[100];
    char dataNascimento[11];
} Atleta;

// Estrutura para Modalidade
typedef struct {
    char nomeModalidade[50];
    int qtdAtletasPorEquipe;
} Modalidade;

// Estrutura para Equipe
typedef struct {
    char nomeEquipe[100];
    char siglaEquipe[6];
    Modalidade modalidade;
    Atleta atletas[20];
} Equipe;

// Estrutura para Torneio
typedef struct {
    char nomeTorneio[100];
    Modalidade modalidade;
    int qtdEquipesInscritas;
    Equipe equipes[8];
} Torneio;

// Estrutura para Jogos
typedef struct {
    char nomeTorneio[100];
    char siglaPrimeiraEquipe[6];
    char siglaSegundaEquipe[6];
    char dataHora[17];
    int pontuacaoPrimeiroTime;
    int pontuacaoSegundoTime;
    char identificadorJogo[50];
} Jogo;