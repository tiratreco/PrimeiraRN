#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>

//#define m_construct(l, c) (m_construct(l, c, false))

void m_random();

typedef struct Matriz {
    int linhas;
    int colunas;
    double** data;
}Matriz;

Matriz* m_construct(int l, int c, ...) {
    va_list ap; va_start(ap, c);
    int random = va_arg(ap, int);

    Matriz* mat = malloc(sizeof(Matriz));
    mat->linhas = l;
    mat->colunas = c;
    double** data = malloc(sizeof(double*) * l);
    for(int i = 0; i < l; i++){
        data[i] = calloc(c, sizeof(double));
    }
    mat->data = data;
    if(random==1) m_random(mat);
    va_end(ap);
    return mat;
}

Matriz* m_somar(Matriz* m1, Matriz* m2){
    Matriz* resp = m_construct(m1->linhas, m1->colunas);
    if (m1->linhas != m2->linhas || m1->colunas!=m2->colunas) {
    printf("Soma de matrizes diferentes");
    return resp;
    }
    for (int i=0; i<m1->linhas; i++){
        for (int j=0; j<m1->colunas; j++){
            resp->data[i][j]=m1->data[i][j]+m2->data[i][j];
        }
    }
    return resp;
}

Matriz* m_multiplicar(Matriz* m1,Matriz* m2){
    Matriz* resp = m_construct(m1->linhas, m2->colunas);
    if (m1->colunas!=m2->linhas){
        printf("Multiplicação de matrizes indisponnível.");
        return resp;
    }
    for (int i=0; i<m1->linhas; i++){
        for (int j=0; j<m2->colunas; j++){
            double sum = 0;
            for (int k=0; k<m1->colunas; k++) sum+=m1->data[i][k]*m2->data[k][j];
            resp->data[i][j]=sum;
        }
    }
    return resp;
}

void m_random(Matriz* m){
    srand(time(NULL));
    for (int i=0; i<m->linhas; i++) for (int j=0; j<m->colunas; j++) m->data[i][j] = (double)(rand() % 100)/100;
}

void m_imprimir(Matriz* m){
    for (int i=0; i<m->linhas; i++) {
        for (int j=0; j<m->colunas; j++) printf("%.2f ", m->data[i][j]);
        printf("\n");
    }
    printf("\n");
}
