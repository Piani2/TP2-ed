Definições de Constantes:
MAX_PACIENTES: Número máximo de pacientes.
MAX_EXAMES: Número máximo de exames.
TEMPO_TOTAL_SIMULACAO: Tempo total da simulação.
MAX_EXAMES_FILA: Tamanho máximo da fila de exames.
MAX_EXAMES_PARA_LAUDO: Tamanho máximo da fila de exames para laudo.
MAX_EXAMES_LAUDADOS: Tamanho máximo da fila de exames laudados.

Estruturas:
Paciente: Representa um paciente com nome, CPF, idade e identificador.
Exame: Representa um exame com o ID do paciente, instante de tempo e condição.
FilaExames: Representa a fila de exames.
ExameRealizado: Representa um exame realizado com o ID do paciente.
FilaExamesParaLaudo: Representa a fila de exames para laudo.
LaudoMedico: Representa um laudo médico com o ID do exame.
FilaExamesLaudados: Representa a fila de exames laudados.

Funções:
chegadaPaciente(): Simula a chegada de pacientes com uma probabilidade de 20%.
novopacientefunc(): Cria um novo paciente com informações fornecidas.
adicionarPacienteNaFilaExame(): Adiciona um paciente à fila de exames.
realizarExames(): Simula a realização de exames para os pacientes na fila.
alocarExamesParaLaudo(): Simula a alocação de exames para laudo.
verificarFilaParaLaudo(): Simula a verificação da fila de exames para laudo.
simularProcesso(): Função principal que simula o processo hospitalar.

Função Principal (main()):
Inicializa a semente do gerador de números aleatórios.
Simula a chegada de pacientes em 10 instantes de tempo.
Chama a função simularProcesso() para iniciar a simulação do processo hospitalar.
