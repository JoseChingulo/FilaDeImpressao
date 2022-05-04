#ifndef TRAB4_H_INCLUDED
#define TRAB4_H_INCLUDED


typedef struct fila Fila;
Fila* cria_fila();
void libera(Fila* f);
int tamanho(Fila* f);
int fila_vazia(Fila* f);
int insere(Fila* f, int p, int i[4]);
int remove_fila(Fila* f);
int consulta(Fila* f, int *i, int *p);
int imprime(Fila* f);
int read_file(char fnome[50]);
int print_values(Fila* f, char *fnome);

#endif // TRAB4_H_INCLUDED
