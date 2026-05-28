#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "caminho.h"

//FUÇÃO PARA CRIAR UM COMANDO

Comando * CriarComando(char direcao) {
    Comando * novo = (Comando *) malloc(sizeof(Comando)); // USANDO MALLOC

    if (novo == NULL)
        return NULL;

    novo->Direcao = direcao;
    novo->Proximo = NULL;

    return novo;
}

//FUNCAO PARA CRIAR POSICAO

Posicao * CriarPosicao(int x, int y) {

    Posicao * nova = (Posicao *) malloc(sizeof(Posicao));//USANDO MALLOC



    if (nova == NULL)
        return NULL;

    nova->X = x;
    nova->Y = y;
    nova->Proximo = NULL;


    return nova;
}

int DirecaoValida(char c) {

    return (c == 'N' || c == 'S' || c == 'L' || c == 'O');


}



//FUNÇAO PARA COMECAR UM NOVO CAMINHO




Caminho * InicializarCaminho(const char *Sequencia,
                             int xInicial,
                             int yInicial) {

    if (Sequencia == NULL)
        return NULL;

    Caminho * C = (Caminho *) malloc(sizeof(Caminho));

    if (C == NULL)
        return NULL;

    C->Inicio = CriarPosicao(xInicial, yInicial);

    if (C->Inicio == NULL) {
        free(C);
        return NULL;
    }

    C->Fim = NULL;
    C->Historico = NULL;
    C->Instrucoes = NULL;
    C->N = 0;

    Comando * ultimo = NULL;

    for (int i = 0; Sequencia[i] != '\0'; i++) {

        char dir = Sequencia[i];

        if (!DirecaoValida(dir)) {

            DestruirCaminho(C);
            return NULL;
        }

        Comando * novo = CriarComando(dir);

        if (novo == NULL) {

            DestruirCaminho(C);
            return NULL;
        }

        if (C->Instrucoes == NULL) {

            C->Instrucoes = novo;

        } else {

            ultimo->Proximo = novo;
        }

        ultimo = novo;
        C->N++;
    }

    return C;
}

//FUNÇ~~AO PARA DESTRUIR O CAMINHO

void DestruirCaminho(Caminho * C) {

    if (C == NULL)
        return;

    // LIBERA OS COMANDOS



    Comando * cmd = C->Instrucoes;

    while (cmd != NULL) {

        Comando * temp = cmd;
        cmd = cmd->Proximo;

        free(temp);
    }

    /* Liberar histórico */

    Posicao * hist = C->Historico;

    while (hist != NULL) {

        Posicao * temp = hist;
        hist = hist->Proximo;

        free(temp);
    }

    /* Liberar início */

    if (C->Inicio != NULL)
        free(C->Inicio);

    /* Liberar fim */

    if (C->Fim != NULL)
        free(C->Fim);

    free(C);
}





//DETERMINAR O FIM





Posicao * DeterminarFim(Caminho * C) {

    if (C == NULL || C->Inicio == NULL)
        return NULL;

    int x = C->Inicio->X;
    int y = C->Inicio->Y;

    Comando * atual = C->Instrucoes;

    while (atual != NULL) {

        switch (atual->Direcao) {

            case 'N':
                y++;
                break;

            case 'S':
                y--;
                break;

            case 'L':
                x++;
                break;

            case 'O':
                x--;
                break;

            default:
                return NULL;
        }

        atual = atual->Proximo;
    }

    if (C->Fim != NULL)
        free(C->Fim);

    C->Fim = CriarPosicao(x, y);

    return C->Fim;
}





//HISTORICO DE POSICAO DO ROBO





Posicao * HistoricoPosicoes(Caminho * C) {

    if (C == NULL || C->Inicio == NULL)
        return NULL;

    /* Limpa histórico antigo */

    Posicao * apagar = C->Historico;

    while (apagar != NULL) {

        Posicao * temp = apagar;
        apagar = apagar->Proximo;

        free(temp);
    }

    C->Historico = NULL;

    int x = C->Inicio->X;
    int y = C->Inicio->Y;

    Posicao * primeiro = CriarPosicao(x, y);

    if (primeiro == NULL)
        return NULL;

    C->Historico = primeiro;

    Posicao * ultimo = primeiro;

    Comando * cmd = C->Instrucoes;

    while (cmd != NULL) {

        switch (cmd->Direcao) {

            case 'N':
                y++;
                break;

            case 'S':
                y--;
                break;

            case 'L':
                x++;
                break;

            case 'O':
                x--;
                break;

            default:
                return NULL;
        }

        Posicao * nova = CriarPosicao(x, y);

        if (nova == NULL)
            return NULL;

        ultimo->Proximo = nova;
        ultimo = nova;

        cmd = cmd->Proximo;
    }

    return C->Historico;
}





//FUNÇAO PARA CALCULAR A  DISTANCIA TOTAL




int CalcularDistanciaTotal(Caminho * C) {

    if (C == NULL)
        return -1;

    return C->N;
}

//DISTANCIA GEOMETRICA

double CalcularDistanciaGeometrica(Caminho * C) {

    if (C == NULL || C->Inicio == NULL)
        return -1.0;

    Posicao * fim = DeterminarFim(C);

    if (fim == NULL)
        return -1.0;

    int x1 = C->Inicio->X;
    int y1 = C->Inicio->Y;

    int x2 = fim->X;
    int y2 = fim->Y;

    return sqrt(
        pow(x2 - x1, 2) +
        pow(y2 - y1, 2)
    );
}


/* FUNÇ~~AO PARA CALCULAR A DISTÂNCIA MANHATTAN       */
 

int CalcularDistanciaManhattan(Caminho * C) {

    if (C == NULL || C->Inicio == NULL)
        return -1;

    Posicao * fim = DeterminarFim(C);

    if (fim == NULL)
        return -1;

    int dx = abs(fim->X - C->Inicio->X);
    int dy = abs(fim->Y - C->Inicio->Y);

    return dx + dy;
}

// FUNCAO PARA CONTAR TODOS OS CAMINHOS QUE O ROBO IRA PERCORRER

int ContarInstrucoes(Caminho * C) {

    if (C == NULL)
        return -1;

    return C->N;
}
