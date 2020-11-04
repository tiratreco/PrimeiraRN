#include <stdio.h>
#include "bibliotecas/matriz.h"
#define linhas(m) (sizeof(m) / sizeof(m[0]))
#define colunas(m) (sizeof(m[0]) / sizeof(m[0][0]))

#define ENTRADA 3
#define OCULTO 2
#define SAIDA 1

int redeNeural();

int main (){
    redeNeural();
}

int redeNeural(){
    //cada entrada é uma linha de uma matriz coluna
    Matriz* entradas = m_construct(ENTRADA, 1, 1);

    //pesos de uma entrada ficam organizados numa mesma linha
    Matriz* pesos = m_construct(OCULTO, ENTRADA, 1);

    m_imprimir(entradas);
    m_imprimir(pesos);

    Matriz* respostas = m_multiplicar(pesos, entradas);
    m_imprimir(respostas);

}
