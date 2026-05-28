Robô Autônomo em Plano Cartesiano

Projeto desenvolvido em linguagem C para a disciplina de Estrutura de Dados da Universidade Católica de Brasília (UCB).

O sistema simula o deslocamento de um robô em um plano cartesiano utilizando listas encadeadas para armazenar:

comandos de movimentação
histórico de posições
posição inicial e final
quantidade de instruções executadas
Estruturas Utilizadas

O projeto utiliza listas encadeadas implementadas com ponteiros através das seguintes estruturas:

Comando

Responsável por armazenar cada instrução do robô.

typedef struct Comando {
    char Direcao;
    struct Comando * Proximo;
} Comando;

Direções válidas:

N → Norte
S → Sul
L → Leste
O → Oeste
Posicao

Responsável por armazenar as coordenadas visitadas pelo robô.

typedef struct Posicao {
    int X;
    int Y;
    struct Posicao * Proximo;
} Posicao;
Caminho

Responsável por armazenar todas as informações do trajeto.

typedef struct Caminho {
    Posicao * Inicio;
    Posicao * Fim;
    Posicao * Historico;
    Comando * Instrucoes;
    int N;
} Caminho;
Funcionalidades Implementadas

O projeto implementa as seguintes funções:

Função	Descrição
InicializarCaminho	Cria o caminho do robô
DestruirCaminho	Libera toda memória alocada
DeterminarFim	Retorna a posição final
HistoricoPosicoes	Retorna o histórico completo
CalcularDistanciaTotal	Soma total dos deslocamentos
CalcularDistanciaGeometrica	Distância euclidiana
CalcularDistanciaManhattan	Distância Manhattan
ContarInstrucoes	Quantidade de comandos
Organização dos Arquivos
Projeto/
│
├── caminho.h
├── main.c
└── 25104110.c
Como Compilar

Utilizando GCC:

gcc 25104110.c main.c -o navegacao
Como Executar

No Windows:

navegacao.exe

No Linux:

./navegacao
Exemplo de Execução
Entrada
InicializarCaminho("LLLLLLLNNNNN", 2, 2);
Saída Esperada
Posicao final: (9, 7)

Historico de posicoes:
(2, 2) -> (3, 2) -> (4, 2) -> (5, 2) -> (6, 2)
-> (7, 2) -> (8, 2) -> (9, 2)
-> (9, 3) -> (9, 4) -> (9, 5)
-> (9, 6) -> (9, 7)

Distancia total percorrida: 12
Distancia geometrica: 8.60
Distancia de Manhattan: 12
Quantidade de instrucoes: 12
Tratamento de Erros

O sistema possui tratamento para:

comandos inválidos
falha de alocação dinâmica
ponteiros nulos
inconsistências no caminho

Comandos inválidos resultam em retorno NULL.

Exemplo inválido:

InicializarCaminho("LLAXN", 0, 0);
Conceitos Utilizados
listas encadeadas
ponteiros
alocação dinâmica
manipulação de memória
tipo abstrato de dados (TAD)
estruturas em C
encadeamento de nós
percurso de listas
Compilador Utilizado

Projeto compatível com:

GCC (GNU Compiler Collection)
Autor

Projeto acadêmico desenvolvido para a disciplina de Estrutura de Dados — UCB.
