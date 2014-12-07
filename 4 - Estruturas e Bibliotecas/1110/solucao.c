#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MIN(a, b)	((a) < (b) ?  (a) : (b))
#define MAX(a, b)	((a) > (b) ?  (a) : (b))
#define ABS(a)		((a) <  0  ? -(a) : (a))
#define IMPAR(a)	((a)&1)
#define CTOI(a)		((a) - '0')
#define ITOC(a)		((a) + '0')

#define TRUE	1
#define FALSE	0

struct regCarta {
	int carta;
	struct regCarta *prox;
};

typedef struct regCarta TCarta;

typedef struct {
	TCarta *inicio, *fim;
	int quantidade;
} TDesc;

void Iniciar(TDesc *);
void Inserir(TDesc *, int);
void Excluir(TDesc *);
void Trocar(TDesc *);
void Imprimir(TDesc *);

int main()
{
	int N, i, j, discartadas[50];
	TDesc cartas;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) && N != 0)
	{
		Iniciar(&cartas);
		
		for(i = 1; i <= N; i++)
			Inserir(&cartas, i);
		
		j = 0;
		
		while(cartas.quantidade > 2)
		{
			discartadas[j] = cartas.inicio->carta;
			Excluir(&cartas);
			Trocar(&cartas);
			j++;
		}
		
		discartadas[j] = cartas.inicio->carta;
		Excluir(&cartas);
		
		printf("Discarded cards: %d", discartadas[0]);
		
		for(i = 1; i < N - 1; i++)
			printf(", %d", discartadas[i]);
		
		printf("\nRemaining card: %d\n", cartas.inicio->carta);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

void Iniciar(TDesc *lista)
{
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->quantidade = 0;
}

void Inserir(TDesc *lista, int carta)
{
	TCarta *aux;
	
	aux = (TCarta *) malloc(sizeof(TCarta));
	
	aux->carta = carta;
	aux->prox = NULL;
	
	if(lista->inicio == NULL)
		lista->inicio = aux;
	else
		lista->fim->prox = aux;
	
	lista->fim = aux;
	lista->quantidade++;
}

void Excluir(TDesc *lista)
{
	TCarta *aux, *exc;
	
	aux = lista->inicio->prox;
	exc = lista->inicio;
	
	free(exc);
	
	lista->inicio = aux;
	lista->quantidade--;
}

void Trocar(TDesc *lista)
{
	TCarta *aux;
	
	aux = lista->inicio->prox;
	lista->inicio->prox = NULL;
	lista->fim->prox = lista->inicio;
	lista->fim = lista->inicio;
	lista->inicio = aux;
}

void Imprimir(TDesc *lista)
{
	TCarta *aux;
	
	printf("\n\nLista:\n");
	
	aux = lista->inicio;
	
	while(aux != NULL)
	{
		printf("%2d\n", aux->carta);
		aux = aux->prox;
	}
}