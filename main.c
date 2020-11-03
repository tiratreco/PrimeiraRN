#include <stdio.h>
#include "bibliotecas/matriz.h"
#define linhas(m) (sizeof(m) / sizeof(m[0]))
#define colunas(m) (sizeof(m[0]) / sizeof(m[0][0]))

#define ENTRADA 2
#define OCULTO 3
#define SAIDA 1

int main (){
    //cada entrada é uma linha de uma matriz coluna
    float entradas[ENTRADA][1];
    //pesos de uma entrada ficam organizados numa mesma coluna
    float pesos[ENTRADA][OCULTO];

    inserirAleatorio(ENTRADA, 1, entradas);
    imprimirMatriz(ENTRADA, 1, entradas);

    inserirAleatorio(OCULTO, ENTRADA, pesos);
    imprimirMatriz(ENTRADA, OCULTO, pesos);

    float r[OCULTO][ENTRADA];
    multiplicarMatriz(ENTRADA, 1, ENTRADA, OCULTO, entradas, pesos, r);
    imprimirMatriz(ENTRADA, OCULTO, r);
}
