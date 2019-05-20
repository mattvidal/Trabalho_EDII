#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 10

typedef struct _sequencia
{
    int* vetor;
    int tamanho;

}TipoSequencia;

typedef long time_t;
typedef long clock_t;

void MallocaSequencia(int** vetor, int tamanho);

void PreencheSequencia(TipoSequencia* seq, int tamanho, int tipo);

void MinMax1(int *vet, int *min, int *max, int tamanho, int* comparacoes);

void MinMax2(int *vet, int *min, int *max, int tamanho, int* comparacoes);

void MinMax3(int *vet, int *min, int *max, int tamanho, int* comparacoes);



#endif // FUNC_H_INCLUDED
