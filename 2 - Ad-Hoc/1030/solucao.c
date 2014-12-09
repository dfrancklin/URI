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

struct rLista {
	int pessoa;
	struct rLista *ant;
	struct rLista *prox;
};

typedef struct rLista TLista;

typedef struct {
	TLista *inicio, *final;
	int qtde;
} TDesc;

void Iniciar(TDesc *);
void Inserir(TDesc *, int);
void Matar(TDesc *, int);

int main()
{
	int N, Q, S, i, j;
	TDesc lista;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	for(i = 1; i <= N; i++)
	{
		scanf("%d %d", &Q, &S);
		
		Iniciar(&lista);
		
		for(j = 1; j <= Q; j++)
			Inserir(&lista, j);
		
		Matar(&lista, S);
		
		printf("Case %d: %d\n", i, lista.inicio->pessoa);
		
		free(lista.inicio);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

void Iniciar(TDesc *lista)
{
	lista->inicio = NULL;
	lista->final = NULL;
	lista->qtde = 0;
}

void Inserir(TDesc *lista, int pessoa)
{
	TLista *aux;
	
	aux = (TLista *) malloc(sizeof(TLista));
	aux->pessoa = pessoa;
	aux->prox = NULL;
	
	if(lista->inicio == NULL)
	{
		aux->ant = NULL;
		lista->inicio = aux;
	}
	else
	{
		aux->ant = lista->final;
		lista->final->prox = aux;
	}
	
	lista->final = aux;
	lista->qtde++;
}

void Matar(TDesc *lista, int salto)
{
	int n;
	
	TLista *aux, *ant;
	
	lista->final->prox = lista->inicio;
	aux = lista->inicio;
	n = 1;
	
	while(lista->qtde > 1)
	{
		ant = aux;
		aux = aux->prox;
		n++;
		
		if(n == salto)
		{
			if(lista->inicio == aux)
				lista->inicio = aux->prox;
			
			ant->prox = aux->prox;
			free(aux);
			aux = ant->prox;
			lista->qtde--;
			n = 1;
		}
	}
}