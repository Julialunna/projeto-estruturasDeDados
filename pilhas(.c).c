#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

//Pilhas com vetor
Pilha_vet* pilha_vet_cria() {
	Pilha_vet* p = (Pilha_vet*)malloc(sizeof(Pilha_vet));
	p->n = 0;

	return p;
}

void pilha_vet_push(Pilha_vet* p, char v) {
	if (p->n == N) {
		printf("A capacidade da pilha estorou.");
		exit(1);
	}

	p->vet[p->n++] = v;
}

char pilha_vet_pop(Pilha_vet* p) {
	if (pilha_vet_vazia(p)) {
		printf("Pilha vazia.");
		exit(1);
	}

	return p->vet[--p->n];
}

int pilha_vet_vazia(Pilha_vet* p) {
	return (p->n == 0);
}

void pilha_vet_libera(Pilha_vet* p) {
	free(p);
}

void pilha_vet_imprime(Pilha_vet* p) {
	int i;

	for (i = p->n - 1; i >= 0; i--) {
		printf("%c\n", p->vet[i]);
	}
}

void pilha_vet_testa_sequencia(pilha_vet* pilha) {
	int x = 0, y = 0, i;
	for (i = pilha->n - 1; i >= 0; i--) {
		if (pilha->vet[i] == '(') {
			x++;
		}
		else if (pilha->vet[i] == ')') {
			y++;
		}
	}

	if (x == y) {
		printf("Sequencia bem formada");
	}
	else {
		printf("Sequencia mal formada");
	}
}

//Pilhas com listas
Pilha_lst* pilha_lst_cria() {
	Pilha_lst* p = (Pilha_lst*)malloc(sizeof(Pilha_lst));
	p->prim = NULL;
	return p;
}

void pilha_lst_push(Pilha_lst* p, int v) {
	Lista_pilha* l = (Lista_pilha*)malloc(sizeof(Lista_pilha));
	l->info = v;
	l->prox = p->prim;
	p->prim = l;
}

char pilha_lst_pop(Pilha_lst* p) {
	Lista_pilha* l;
	int c;
	if (pilha_lst_vazia(p)) {
		printf("Pilha vazia\n");
		exit(1);
	}
	l = p->prim;
	c = l->info;
	p->prim = l->prox;
	free(l);
	return c;
}

int pilha_lst_vazia(Pilha_lst* p) {
	return (p->prim == NULL);
}

void pilha_lst_libera(Pilha_lst* p) {
	Lista_pilha* l = p->prim;
	while (l != NULL) {
		Lista_pilha* t = l->prox;
		free(l);
		l = t;
	}
	free(p);
}

void pilha_lst_imprime(Pilha_lst* p) {
	Lista_pilha* l;

	for (l = p->prim; l != NULL; l = l->prox) {
		printf("%d\n", l->info);
	}
}