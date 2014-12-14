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

struct rFolha {
	struct rFolha *esq, *dir;
	int valor;
};
 
typedef struct rFolha TFolha;
 
void Iniciar(TFolha *);
void Inserir(TFolha *, int);
void Imprimir(TFolha *, int);
void Destruir(TFolha *);
TFolha *AcharPai(TFolha *, int);

int main()
{
	int C, N, i, j, valor;
	TFolha *raiz, *aux, *pai;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &C);
	
	for(i = 1; i <= C; i++)
	{
		scanf("%d", &N);
		
		raiz = NULL;
		
		for(j = 0; j < N; j++)
		{
			scanf("%d", &valor);
			
			aux = (TFolha *) malloc(sizeof(TFolha));
			aux->esq = NULL;
			aux->dir = NULL;
			aux->valor = valor;
			
			pai = AcharPai(raiz, valor);
			
			if(raiz == NULL)
				raiz = aux;
			else
				if(valor <= pai->valor)
					pai->esq = aux;
				else
					pai->dir = aux;
		}
		
		printf("Case %d:\n", i);
		
		printf("Pre.:");
		Imprimir(raiz, 0);
		
		printf("\nIn..:");
		Imprimir(raiz, 1);
		
		printf("\nPost:");
		Imprimir(raiz, 2);
		
		printf("\n\n");
		
		Destruir(raiz);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

void Imprimir(TFolha *raiz, int tipo)
{
	if(raiz == NULL)
		return;
	
	switch(tipo)
	{
		case 0:
			printf(" %d", raiz->valor);
			Imprimir(raiz->esq, tipo);
			Imprimir(raiz->dir, tipo);
			break;
		case 1:
			Imprimir(raiz->esq, tipo);
			printf(" %d", raiz->valor);
			Imprimir(raiz->dir, tipo);
			break;
		case 2:
			Imprimir(raiz->esq, tipo);
			Imprimir(raiz->dir, tipo);
			printf(" %d", raiz->valor);
			break;
	}
}

void Destruir(TFolha *raiz)
{
	if(raiz != NULL)
	{
		Destruir(raiz->esq);
		Destruir(raiz->dir);
		free(raiz);
	}
}

TFolha *AcharPai(TFolha *raiz, int valor)
{
	if(raiz == NULL)
		return NULL;
	else
		if(valor <= raiz->valor)
			if(raiz->esq == NULL)
				return raiz;
			else
				return AcharPai(raiz->esq, valor);
		else
			if(raiz->dir == NULL)
				return raiz;
			else
				return AcharPai(raiz->dir, valor);
}