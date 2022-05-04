#include <stdio.h>
#include <stdlib.h>
#include "Trab4.h"

int main()
{
    FILE* fp;
    Fila *fe, *f0, *f1, *f2;
    fe = cria_fila();
    f0 = cria_fila();
    f1 = cria_fila();
    f2 = cria_fila();
    read_file("C:/Users/iandev/Dropbox/PC/Documents/Faculdade/1.txt");
    if(print_values(fe, "C:/Users/iandev/Dropbox/PC/Documents/Faculdade/Imprime.txt"))
    {
        printf("\t ENTRADA:\n\n");
        imprime(fe);
    }
    clear();
    do
    {
        if(!fila_vazia(fe))
        {
            delay(500);
            system("cls");
        }
        else clear();
        for(int cont = 0; cont < 5; cont ++)
        {
            int i = 0, p = 0;
            consulta(fe, &p, &i);
            if(p == 1)
            {
                insere(f0, p, i);
                remove_fila(fe);
            }
            else if(p == 2)
            {
                insere(f1, p, i);
                remove_fila(fe);
            }
            else if(p == 3)
            {
                insere(f2, p, i);
                remove_fila(fe);
            }
            else remove_fila(fe);
        }
        if(!fila_vazia(fe))
        {
            printf("\t ENTRADA:\n\n");
            imprime(fe);
            printf("\n\n");
        }
        if(!fila_vazia(f0))
        {
            printf("\t FILA 0:\n\n");
            imprime(f0);
            printf("\n\n");
        }
        if(!fila_vazia(f1))
        {
            printf("\t FILA 1:\n\n");
            imprime(f1);
            printf("\n\n");
        }
        if(!fila_vazia(f2))
        {
            printf("\t FILA 2:\n\n");
            imprime(f2);
            printf("\n\n");
        }
    }
    while(!fila_vazia(fe));
    libera(fe);
    libera(f0);
    libera(f1);
    libera(f2);
    return 0;
}
