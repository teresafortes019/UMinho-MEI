/* GUIAO 1 - 27/09/2022

Objetivo da aula:
Criar 3 funções
    - uma para alocar espaço
    - uma para inicializar 
    - uma para fazer a multiplicação
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 512

double** allocMatrix(int n){
    double **m = malloc(sizeof (double*) * n);
    int i;
    for(i = 0; i<n; i++){
        m[i] = malloc(sizeof(double) * n);
    }
    return m;
}

void initMatrix(double **m, int n){
    double fMin = 1, fMax = 10;
    int i,j;
    for( i = 0; i<n; i++){
        for (j = 0; j<n; j++){
            double f = (double)rand() / RAND_MAX;
            m[i][j] = fMin + f * (fMax - fMin); 
        }
    }
}

void multMatrix(double** a, double** b, double** l){
    int i,j,k;
    for(i=0;i<N;i++){    
        for(j=0;j<N;j++){    
            l[i][j]=0;    
            for(k=0;k<N;k++){    
                l[i][j]+=a[i][k]*b[k][j];    
            }    
        }    
    }       
}

void printMatrix(double** m, int n){
    int i,j;
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++)
            printf("%f ", m[i][j]);
        printf("\n");
    }
}

int main(){

    //clock_t start, end;
    //double cpu_time_used;

    //start = clock();

    double **A = allocMatrix(N); 
    double **B = allocMatrix(N); 
    double **L = allocMatrix(N); 

    //end = clock();
    //cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    //printf("Time used to alloc: %fs\n", cpu_time_used);

    //start = clock();

    initMatrix(A, N);
    initMatrix(B, N);

    //end = clock();
    //cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    //printf("Time used to init: %fs\n", cpu_time_used);
    
    //start = clock();

    multMatrix(A, B, L);

    //end = clock();
    //cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    //printf("Time used to mult: %fs\n", cpu_time_used);

    return 1;
}