#pragma once
#define N 100

struct fila {
	int n;
	int ini;
	float vet[N];
};

struct lista_fila {
	int info;
	struct lista_fila* prox;
};
typedef struct lista_fila Lista_fila;

struct filal {
	Lista_fila* ini;
	Lista_fila* fim;
};



typedef struct fila Fila;
typedef struct filal FilaL;


Fila* fila_cria_vet();
void fila_insere_vet(Fila* f, float v);
float fila_retira_vet(Fila* f);
int fila_vazia_vet(Fila* f);
void fila_libera_vet(Fila* f);

FilaL* fila_cria_l();
void fila_insere_l(FilaL* f, int v);
int fila_retira_l(FilaL* f);
int fila_vazia_l(FilaL* f);
void fila_libera_l(FilaL* f);
void fila_imprime_l(FilaL* f);
Lista_fila* fila_busca_l(FilaL* fila, char informacao[]);
