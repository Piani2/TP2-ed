#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Definições de constantes
#define MAX_PACIENTES 100 // Defina o número máximo de pacientes
#define MAX_EXAMES 1000   // Defina o número máximo de exames
#define TEMPO_TOTAL_SIMULACAO 43200 // 43.200 unidades de tempo
#define MAX_EXAMES_FILA 100 // Defina o tamanho máximo da fila de exames // Estrutura para representar a fila de exames a serem laudados
#define MAX_EXAMES_PARA_LAUDO 100 // Defina o tamanho máximo da fila de exames para laudo
#define MAX_EXAMES_LAUDADOS 100 // Defina o tamanho máximo da fila de exames laudados

// Estrutura para representar um paciente
typedef struct {
    char nome[50];
    char cpf[12];
    int idade;
    int id;
} Paciente;

// Estrutura para representar um exame
typedef struct {
    int id_paciente;
    int instante_tempo;
    int condicao; // 1 para normal, 2 para bronquite, etc.
} Exame;

// Estrutura para representar a fila de exames
typedef struct {
    Paciente exames[MAX_EXAMES_FILA];
    int tamanho;
} FilaExames;

// Estrutura para representar um exame realizado
typedef struct {
    int idPaciente;
} ExameRealizado;

typedef struct {
    ExameRealizado examesParaLaudo[MAX_EXAMES_PARA_LAUDO];
    int tamanho;
} FilaExamesParaLaudo;

// Estrutura para representar um laudo médico
typedef struct {
    int idExame;
} LaudoMedico;

typedef struct {
    LaudoMedico examesLaudados[MAX_EXAMES_LAUDADOS];
    int quantidade;
} FilaExamesLaudados;

// Função para simular a chegada de pacientes ao hospital
int chegadaPaciente() {
    // Gerar um número aleatório entre 0 e 99
    int chance = rand() % 100;

    // Se o número gerado for menor ou igual a 20, considera-se que um paciente chegou (20% de chance)
    if (chance <= 20) {
        return 1; // Paciente chegou
    } else {
        return 0; // Paciente não chegou
    }
}

// Função para criar um novo paciente
Paciente novopacientefunc(int id, const char *nome, const char *cpf, int idade) {
    Paciente novo;
    novo.id = id;
    snprintf(novo.nome, sizeof(novo.nome), "%s", nome); 
    snprintf(novo.cpf, sizeof(novo.cpf), "%s", cpf); 
    novo.idade = idade;
    return novo;
}

void adicionarPacienteNaFilaExame(FilaExames *fila, Paciente paciente) {
    if (fila->tamanho < MAX_EXAMES_FILA) {
        fila->exames[fila->tamanho++] = paciente;
        printf("Paciente adicionado à fila de exames.\n");
    } else {
        printf("A fila de exames está cheia. Não é possível adicionar mais pacientes.\n");
    }
}

// Função para realizar os exames
void realizarExames(FilaExames *fila) {
    // Simula a realização de exames para os pacientes na fila de exames
    if (fila->tamanho > 0) {
        printf("Realizando exames para pacientes na fila de exames...\n");
        for (int i = 0; i < fila->tamanho; ++i) {
            printf("Exame realizado para o paciente %d.\n", fila->exames[i].id);
            // Lógica para realizar o exame (simulado aqui)
            // Pode incluir geração de resultado, envio para laudo, etc.
        }
        fila->tamanho = 0; // Zera a fila após realizar os exames
        printf("Todos os exames foram realizados.\n");
    } else {
        printf("Não há pacientes na fila de exames para realizar exames.\n");
    }
}

// Função para alocar exames para laudo
void alocarExamesParaLaudo(FilaExames *filaExames, FilaExamesParaLaudo *filaLaudo) {
    // Simula a alocação dos exames para laudo
    if (filaExames->tamanho > 0) {
        printf("Alocando exames para laudo...\n");
        for (int i = 0; i < filaExames->tamanho; ++i) {
            // Simula a alocação do exame para laudo
            ExameRealizado exame = {filaExames->exames[i].id};
            filaLaudo->examesParaLaudo[filaLaudo->tamanho++] = exame;
        }
        filaExames->tamanho = 0; // Zera a fila de exames após alocar para laudo
        printf("Exames alocados para laudo.\n");
    } else {
        printf("Não há exames para alocar para laudo.\n");
    }
}

// Função para verificar a fila de exames para laudo
void verificarFilaParaLaudo(FilaExamesParaLaudo *filaLaudo, FilaExamesLaudados *filaLaudados) {
    // Simula a verificação da fila de exames para laudo
    if (filaLaudo->tamanho > 0) {
        printf("Realizando laudo para exames alocados...\n");
        for (int i = 0; i < filaLaudo->tamanho; ++i) {
            // Simula a realização do laudo
            LaudoMedico laudo = {filaLaudo->examesParaLaudo[i].idPaciente};
            filaLaudados->examesLaudados[filaLaudados->quantidade++] = laudo;
        }
        filaLaudo->tamanho = 0; // Zera a fila de exames laudados após realizar os laudos
        printf("Laudo finalizado para os exames alocados.\n");
    } else {
        printf("Não há exames para realizar o laudo.\n");
    }
}

// Função principal de simulação do processo
void simularProcesso() {
    int tempoAtual = 0;
    FilaExames filaExames; 
    FilaExamesParaLaudo filaLaudo; 
    FilaExamesLaudados filaLaudados; 

    while (tempoAtual <= TEMPO_TOTAL_SIMULACAO) {
        // Verifica a chegada de pacientes ao hospital
        if (chegadaPaciente()) {
            Paciente novopaciente = novopacientefunc(123, "NomePaciente", "12345678901", 30); // Função para criar um novo paciente
            adicionarPacienteNaFilaExame(&filaExames, novopaciente); // Adiciona o paciente à fila de exames
        }

        // Realização de exames
        realizarExames(&filaExames); // Função para realizar os exames

        // Alocação de exames para laudo
        alocarExamesParaLaudo(&filaExames, &filaLaudo); // Função para alocar os exames para laudo

        // Verifica se há radiologistas disponíveis e realiza laudos
        verificarFilaParaLaudo(&filaLaudo, &filaLaudados); // Função para verificar a fila de exames para laudo

        // Atualiza o tempo
        tempoAtual++;
        usleep(100000); // Aguarda 100.000 microssegundos (0,1 segundos)
    }
}

int main() {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios com o tempo atual

    // Simulação da chegada de pacientes ao hospital
    for (int i = 1; i <= 10; ++i) { // Simulação de 10 instantes de tempo (pode ajustar conforme necessário)
        if (chegadaPaciente()) {
            printf("No instante %d: Um paciente chegou ao hospital.\n", i);
            // Cria um novo paciente
            Paciente novo = novopacientefunc(i, "NomePaciente", "12345678901", 30); // Os dados do paciente são fictícios
            // Aqui você pode fazer o que for necessário com o paciente, como adicionar à fila de exames, etc.
        } else {
            printf("No instante %d: Nenhum paciente chegou ao hospital.\n", i);
        }
        usleep(1000000); // Aguarda 1 segundo entre cada instante de tempo
    }

    // Chamada para simular o processo de realização de exames
    printf("\nSimulando o processo de realizacao de exames...\n");
    simularProcesso(); // Chamada da função para simular o processo de realização de exames

return 0;
}