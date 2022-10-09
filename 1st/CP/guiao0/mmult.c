/* GUIAO 0 - 20/09/2022 */

#include <stdio.h>
#include <stdlib.h>

/* Multiplicação de Matrizes
double C=A*B

3 funções:
    1) alocar espaço para as matrizes                   - tempo linear N
    2) inicialização das matrizes A e B, usando rand()  - tempo quadrático N^2
    3) multiplicação das matrizes A e B                 - tempo cúbico N^3
*/

//Ferramenta Instruments do XCode para medir a performance

int sizeM=2;

/* 1) alocar espaço para as matrizes */
//start time
void alloc(double** m){
    for(int i=0;i<sizeM;i++){
        m[i] = malloc(sizeof(double)*sizeM);
    }
}
//stop time 

/* 2) inicialização das matrizes */
void init(double** m){
    if(!m) return;
    for(int i=0;i<sizeM;i++){
        for(int j=0;j<sizeM;j++){
            m[i][j] = rand()%100;
        }
    }
}

/* 3) multiplicação das matrizes */
double** mult(double** a,double** b){
    double** c;
    alloc(c);
    double res=0;
    for(int i=0;i<sizeM;i++){
        for(int j=0;j<sizeM;j++){
            res=0;
            for(int k=0;k<sizeM;k++){ //cálculo do produto interno
                res += a[i][k]*b[k][j];
            }
            c[i][j]=res;
        }
    }
    return c;
}

void printM(double** m){
    for(int i=0;i<sizeM;i++){
        for(int j=0;j<sizeM;j++){
            printf("%f,",m[i][j]);
        }
        printf("\n");
    }
}

int main(){
    double** a=malloc(sizeM*sizeof(double*));
    alloc(a);
    double** b=malloc(sizeM*sizeof(double*));
    alloc(b);

    srand(2);
    init(a);
    init(b);

    printM(a);
    printM(b);

    double** c = malloc(sizeM*sizeof(double*));
    c = mult(a,b);
    printM(c);

    free(a);
    free(b);
    free(c);
    return 0;
}