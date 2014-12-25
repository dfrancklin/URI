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

typedef struct {
	char nome[51];
	double valor;
} Fruta;

int ordena(const void *arg1, const void *arg2)
{
	Fruta *i = (Fruta *) arg1, *j = (Fruta *) arg2;
	
	return strcmp(i->nome, j->nome);
}

int main()
{
	int N, M, P, i, qtde;
	double total;
	Fruta *frutas, busca, *result;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf("%d", &M);
		
		frutas = (Fruta *) malloc(M * sizeof(Fruta));
		
		for(i = 0; i < M; i++)
			scanf(" %s %lf", frutas[i].nome, &frutas[i].valor);
		
		qsort(frutas, M, sizeof(Fruta), ordena);
		
		scanf("%d", &P);
		
		total = 0;
		
		for(i = 0; i < P; i++)
		{
			scanf(" %s %d", busca.nome, &qtde);
			result = (Fruta *) bsearch(&busca, frutas, M, sizeof(Fruta), ordena);
			
			total += result->valor * qtde;
		}
		
		printf("R$ %.2lf\n", total);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}