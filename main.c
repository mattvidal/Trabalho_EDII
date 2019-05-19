#include "func.h"

void main(void)
{
    int min, max, i, j, k, contador = 0, comparacoes = 0;
    double inicio, fim, tempo_decorrido;
    TipoSequencia seq[TAM];
    FILE *pont_arq;
    char linha[100];
    char ch;
    for(j = 0; j < TAM; j++)
    {
        seq[j].tamanho = 10000 * (j + 1);
        MallocaSequencia(&seq[j].vetor, seq[j].tamanho);
        PreencheSequencia(&seq[j], seq[j].tamanho, 0);
    }

    for(k = 0; k < 3; k++)//Crescente, Decrescente e Aleatório
    {
        contador = 0;

        while(contador < TAM)//Ordenar Decrescente
        {
            PreencheSequencia(&seq[contador], seq[contador].tamanho, k);
            contador++;
        }
        for(i = 0; i < 12; i++)//Algoritmos MinMaX1, 2, e 3
        {
            for(j = 0; j < TAM; j++)//Todas as sequencias
            {
                pont_arq = fopen("arquivo.txt", "a");
                if(k == 0)
                {
                    fprintf(pont_arq, "Crescente\n");
                }
                else
                {
                    if(k == 1)
                    {
                        fprintf(pont_arq, "Descrescente\n");
                    }
                    else
                    {
                        if(k >= 2)
                        {
                           fprintf(pont_arq, "Aleatorio\n");
                        }
                    }
                }
                time_t time (time_t *x);

                if(i == 0)//MinMax1
                {
                    inicio = (double) clock()/CLOCKS_PER_SEC;
                    MinMax1(seq[j].vetor, &min, &max, seq[j].tamanho, &comparacoes);
                    fim = (double) clock()/CLOCKS_PER_SEC;
                    clock_t clock(void);
                    tempo_decorrido = fim - inicio;
                    fprintf(pont_arq, "MinMax1\n");
                }
                else
                {
                    if(i == 1)//MinMax2
                    {
                        inicio = (double) clock()/CLOCKS_PER_SEC;
                        MinMax2(seq[j].vetor, &min, &max, seq[j].tamanho, &comparacoes);
                        fim = (double) clock()/CLOCKS_PER_SEC;
                        clock_t clock(void);
                        tempo_decorrido = fim - inicio;
                        fprintf(pont_arq, "MinMax2\n");
                    }
                    else
                    {
                        if(i == 2)//MaxMin3
                        {
                            inicio = (double) clock()/CLOCKS_PER_SEC;
                            MinMax3(seq[j].vetor, &min, &max, seq[j].tamanho, &comparacoes);
                            fim = (double) clock()/CLOCKS_PER_SEC;
                            clock_t clock(void);
                            tempo_decorrido = fim - inicio;
                            fprintf(pont_arq, "MaxMin3\n");
                        }
                    }
                }

                if(pont_arq == NULL)
                {
                  printf("Erro na abertura do arquivo!");
                  return 1;
                }

                fprintf(pont_arq, "Sequencia com %i elementos:\n", seq[j].tamanho);
                fprintf(pont_arq, "%i\n", seq[j].tamanho);

                if(k >= 2)
                {
                    fprintf(pont_arq, "Sequencia aleatoria de numero: %i\n", k - 1);
                }
                fprintf(pont_arq, "Numero de comparacoes: %i\n", comparacoes);
                fprintf(pont_arq, "Tempo Levado: %lf\n", tempo_decorrido);
                fprintf(pont_arq, "Min: %i\n", min);
                fprintf(pont_arq, "Max: %i\n\n", max);
            }
        }
        fprintf(pont_arq, "\n-----------------------------------------\n");

        fclose(pont_arq);

    }

    printf("Dados salvos no arquivo com sucesso!\n");
}
