//Júlia Almeida Luna
#include <stdio.h>
#include "listas.h"
#include "pilhas.h"
#include "filas.h"

#define SUCESSO 0


int eh_possivel(lista* inseridos, int valor) {
	lista* p;
	int tamanho=0, controle_eh_possivel=0, controle=0;
	p = lst_cria();
	for (p = inseridos; p != NULL; p = p->prox) {
		tamanho++;
	}
	for (p = inseridos; p != NULL; p = p->prox) {
		controle_eh_possivel++;
		if (p->info == valor) {
			return 0;
		}
		else if ((p->info != valor) && (controle_eh_possivel == tamanho)) {
			return 1;
		}
	}
}

int calcula_tam_fila(filal* fila) {
	Lista_fila* q;
	int tamanho = 0;

	for (q = fila->ini; q != NULL; q = q->prox) {
		tamanho++;
	}
	return tamanho;
}

int calcula_tam_pilha(pilha_lst* pilha) {
	Lista_pilha* l;
	int tamanho = 0;

	for (l = pilha->prim; l != NULL; l = l->prox) {
		tamanho++;
	}
	return tamanho;
}

int calcula_tam_lista(lista* lista_ordenado) {
	Lista* p;
	int tamanho = 0;

	for (p = lista_ordenado; p != NULL; p = p->prox) {
		tamanho++;
	}

	return tamanho;
}

int resultado(int tam_fila, int tam_pilha, int tam_lista, int valor_restante) {

	if (tam_fila == valor_restante && tam_lista == valor_restante) {
		printf("not sure");
		return SUCESSO;
	}

	if (tam_pilha == valor_restante && tam_lista == valor_restante) {
		printf("not sure");
		return SUCESSO;
	}

	if (tam_fila == valor_restante) {
		printf("queue");
		return SUCESSO;
	}
	else if (tam_pilha == valor_restante) {
		printf("stack");
		return SUCESSO;
	}
	else if (tam_lista == valor_restante) {
		printf("priority queue");
		return SUCESSO;
	}
	else {
		printf("impossible");
		return SUCESSO;
	}

}

int main(int argc, char** argv) {
	FILE* fp;
	lista* lista_ordenado;
	lista* inseridos;
	lista* retirados;
	pilha_lst* pilha;
	filal* fila;
	int i, num_linhas = 0, comando = 0, valor = 0, controle = 0, controle_eh_possivel = 0;
	int tam_pilha = 0, tam_fila=0, tam_lista = 0, valor_inseridos=0, valor_retirados=0, diferen�a=0;

	lista_ordenado = lst_cria();
	retirados = lst_cria();
	inseridos = lst_cria();
	pilha = pilha_lst_cria();
	fila = fila_cria_l();

	fp = fopen("entrada.txt", "r");

	fscanf(fp, "%d", &num_linhas);

	for (i = 0; i < num_linhas; i++) {

		fscanf(fp, "%d %d", &comando, &valor);

		if (comando == 1) {
			
			valor_inseridos++;
			inseridos = lst_insere(inseridos, valor);
			pilha_lst_push(pilha, valor);
			fila_insere_l(fila, valor);
			lista_ordenado=lst_insere_ordenado(lista_ordenado, valor);

		}
		else if (comando == 2) {

			valor_retirados++;

			controle_eh_possivel = eh_possivel(inseridos, valor);

			if (controle_eh_possivel == 1) {
				printf("impossible");
				return SUCESSO;
			}
			else if (controle_eh_possivel == 0) {
				continue;
			}
			retirados = lst_insere(retirados, valor);

			if (pilha->prim->info == valor) {
				pilha_lst_pop(pilha);
			}
			
			if (fila->ini->info == valor) {
				fila_retira_l(fila);
			}

			if (lista_ordenado->info == valor) {
				lista_ordenado = lst_retira(lista_ordenado, valor);
			}
		}
	}

	tam_fila = calcula_tam_fila(fila);
	tam_pilha = calcula_tam_pilha(pilha);
	tam_lista = calcula_tam_lista(lista_ordenado);
	
	diferen�a = valor_inseridos - valor_retirados;
	resultado(tam_fila, tam_pilha, tam_lista, diferen�a);

	return SUCESSO;
}