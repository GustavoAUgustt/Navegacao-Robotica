#ifndef CAMINHO_H
#define CAMINHO_H

typedef struct Comando {
    char Direcao;
    struct Comando * Proximo;
} Comando;

typedef struct Posicao {
    int X;
    int Y;
    struct Posicao * Proximo;
} Posicao;

typedef struct Caminho {
    Posicao * Inicio;
    Posicao * Fim;
    Posicao * Historico;
    Comando * Instrucoes;
    int N;
} Caminho;

Caminho * InicializarCaminho(const char *Sequencia, int xInicial, int yInicial);

void DestruirCaminho(Caminho * C);

Posicao * DeterminarFim(Caminho * C);

Posicao * HistoricoPosicoes(Caminho * C);

int CalcularDistanciaTotal(Caminho * C);

double CalcularDistanciaGeometrica(Caminho * C);

int CalcularDistanciaManhattan(Caminho * C);

int ContarInstrucoes(Caminho * C);

#endif
