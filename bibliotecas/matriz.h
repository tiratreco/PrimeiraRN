
#define linhas(m) (sizeof(m) / sizeof(m[0]))
#define colunas(m) (sizeof(m[0]) / sizeof(m[0][0]))

int somarMatriz(int x1,int y1,int x2,int y2,float m1[x1][y1],float m2[x2][y2], float r[x1][x2]){
    if (x1!=x2 || y1!=y2) return 1;
    for (int i=0; i<x1; i++){
        for (int j=0; j<y1; j++){
            r[i][j]=m1[i][j]+m2[i][j];
        }
    }
    return 0;
}

int multiplicarMatriz(int x1,int y1,int x2,int y2,float m1[x1][y1],float m2[x2][y2], float r[x1][y2]){
    for (int i=0; i<x1; i++){
        for (int j=0; j<y2; j++){
            int sum = 0;
            for (int k=0; k<x1; k++) sum+=m1[i][k]*m2[i][k];
            r[i][j]=sum;
        }
    }
    return 0;
}

void inserirAleatorio(int x,int y,float mat[x][y]){
    for (int i=0; i<x; i++) for (int j=0; j<y; j++) mat[i][j]=5.0;
}

void imprimirMatriz(int x,int y,float mat[x][y]){
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) printf("%.2f ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}
