#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Trab4.h"

typedef struct fila
{
    struct nodo *inicio;
    struct nodo *fim;
};
typedef struct nodo
{
    int id[4];
    int priority;
    struct nodo *prox;
};
typedef struct nodo nodo;
void clear()
{
    printf("\n\t");
    printf("Pressione [ENTER] para continuar...");
    getchar();
    system("cls");
}
void delay(int s)
{
    clock_t start_time = clock();
    while(clock() < start_time + s);
}
Fila* cria_fila()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if(f != NULL)
    {
        f->fim = NULL;
        f->inicio = NULL;
    }
    return f;
}
void libera(Fila* f)
{
    if(f != NULL)
    {
        nodo* no;
        while(f->inicio != NULL)
        {
            no = f->inicio;
            f->inicio = f->inicio->prox;
            free(no);
        }
        free(f);
    }
}
int tamanho(Fila* f)
{
    if(f == NULL) return 0;
    int cont = 0;
    nodo* no = f->inicio;
    while(no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}
int fila_vazia(Fila* f)
{
    if(f == NULL) return 1;
    if(f->inicio == NULL) return 1;
    return 0;
}
int insere(Fila* f, int p, int i[4])
{
    if(f == NULL) return 0;
    if(p == 0) return 0;
    nodo* no = (nodo*) malloc(sizeof(nodo));
    if(no == NULL) return 0;
    for(int j = 0; j < 4; j++)
        no->id[j] = i[j];
    no->priority = p;
    no->prox = NULL;
    if(f->fim == NULL) f->inicio = no;
    else f->fim->prox = no;
    f->fim = no;
    return 1;
}
int remove_fila(Fila* f)
{
    if(fila_vazia(f)) return 0;
    nodo *no = f->inicio;
    f->inicio = f->inicio->prox;
    if(f->inicio == NULL) f->fim = NULL;
    free(no);
    return 1;
}
int consulta(Fila* f, int *p, int *i)
{
    if(fila_vazia(f)) return 0;
    *i = f->inicio->id;
    *p = f->inicio->priority;
    return 1;
}
int imprime(Fila* f)
{
    if(fila_vazia(f)) return 0;
    nodo *no = f->inicio;
    while(no != NULL)
    {
        int x = 0, y = 0;
        printf("\t Prioridade %d | IP: ", no->priority);
        for(int i = 0; i < 4; i++)
        {
            if(no->id[i] != NULL)
            {
                if(i != 3) printf("%d.", no->id[i]);
                else printf("%d\n", no->id[i]);
            }
        }
        no = no->prox;
    }
    return 1;
}
int read_file(char fnome[50])
{
    FILE *fp, *f1;
    fp = fopen(fnome, "r");
    fnome = "C:/Users/iandev/Dropbox/PC/Documents/Faculdade/Imprime.txt";
    f1 = fopen(fnome, "w+");
    if(fp == NULL || f1 == NULL)
    {
        printf("\n\t Arquivo não encontrado: %s\n", fnome);
        return 0;
    }
    else
    {
        char ch;
        int id, p = 0;
        do
        {
            ch = fgetc(fp);
            if(feof(fp))
            {
                break ;
            }
            if((ch < 60))
            {
                if(ch == ';' || ch == ',' && ch)
                {
                    fprintf(f1, "\n");
                    continue;
                }
                else if(ch != '\n' && ch != ' ')
                {
                    if(ch == '.')
                    {
                        fprintf(f1, " ");
                        continue;
                    }
                    else if((ch > 47 && ch < 58))
                        fprintf(f1, "%c", ch);
                }
            }
        }
        while(1);
    }
    fclose(f1);
    fclose(fp);
    return 1;
}
int print_values(Fila* f, char *fnome)
{
    if(f == NULL) return 0;
    FILE *fp;
    fp = fopen(fnome, "r");
    if(fp == NULL) return 0;
    while(1)
    {
        int id[4] = {NULL, NULL, NULL, NULL}, i0, i1, i2, i3, p = 0;
        if(feof(fp)) break;
        fscanf(fp, "%d", &p);
        fscanf(fp, /*"%d%d%d%d"*/"%d", /*&id[0], &id[1], &id[2],*/ &id[3]);
        insere(f, p, id);
    };
    fclose(fp);
    return 1;
};
