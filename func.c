#include "func.h"

void MallocaSequencia(int** vetor, int tamanho)
{
    (*vetor) = (int*)malloc(tamanho * sizeof(int));
}

void PreencheSequencia(TipoSequencia* seq, int tamanho, int tipo)
{
    int i, controle, aux;

    srand(time(NULL));

    //tipo == 0 (crescente)
    //tipo == 1 (decrescente)
    //tipo >= 2 (aleatorio)
    if(tipo == 0)
    {
        for(i = 0; i < tamanho; i++)
        {
            seq->vetor[i] = i;
        }
    }
    else
    {
        if(tipo == 1)
        {
            for(i = tamanho - 1; i >= 0; i--)
            {
                seq->vetor[i] = i;
            }
        }
        else
        {
            if(tipo >= 2)
            {
                for(i = 0; i < tamanho; i++)
                {
                    seq->vetor[i] = i;
                }

                for(i = 0; i < tamanho; i++)
                {
                    do
                    {
                        controle = rand() % tamanho;
                    }while((controle > tamanho) || (controle < 0));

                    aux = seq->vetor[i];
                    seq->vetor[i] = seq->vetor[controle];
                    seq->vetor[controle] = aux;
                }
            }
        }
    }

}

void MinMax1(int *vet, int *min, int *max, int tamanho, int* comparacoes)
{
    int i, cont = 0;
    *min = *max = vet[0];
    for (i = 1; i < tamanho; i++)
    {
        if (vet[i] > *max)
        {
            cont++;
            *max = vet[i];
        }
        if (vet[i] < *min)
        {
            cont++;
            *min = vet[i];
        }

    }
    *comparacoes = cont;
}

void MinMax2(int *vet, int *min, int *max, int tamanho, int* comparacoes)
{
    int i, cont = 0;
    *min = *max = vet[0];
    for (i = 1; i < tamanho; i++)
    {
        if (vet[i] > *max)
        {
            cont++;
            *max = vet[i];
        }
        else
        {
            cont++;
            if (vet[i] < *min)
            {
                cont++;
                *min = vet[i];
            }
        }
    }
    *comparacoes = cont;
}

void MinMax3(int *vet, int *min, int *max, int tamanho, int* comparacoes)
{
    int i, cont, cont2 = 0;
    if (tamanho % 2 > 0)
    {
        cont2++;
        vet[tamanho] = vet[tamanho - 1]; cont = tamanho;
    }
    else
    {
        cont2++;
        cont = tamanho - 1;
    }

    if (vet[0] > vet[1])
    {
        cont2++;
        *max = vet[0];
        *min = vet[1];
    }
    else
    {
        cont2++;
        *max = vet[1];
        *min = vet[0];
    }

    i = 3;

    while (i <= cont)
    {
        if (vet[i - 1] > vet[i])
        {
            cont2++;
            if (vet[i - 1] > *max)
            {
                cont2++;
                *max = vet[i - 1];
            }

            if (vet[i] < *min)
            {
                cont2++;
                *min = vet[i];
            }
        }
        else
        {
            cont2++;
            if (vet[i - 1] < *min)
            {
                cont2++;
                *min = vet[i - 1];
            }
            if (vet[i] > *max)
            {
                cont2++;
                *max = vet[i];
            }
        }
            i += 2;
    }
    *comparacoes = cont;
}
