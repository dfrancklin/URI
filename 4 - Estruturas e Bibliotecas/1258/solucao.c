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

typedef struct { char cor[9], tamanho[2], nome[31]; } Camiseta;

int ordenar(const void *, const void *);

int main()
{
	int N, i, c = 0;
	Camiseta camisetas[60];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) && N != 0)
	{
		if(c != 0)
			printf("\n");
		
		for(i = 0; i < N; i++)
		{
			scanf(" %[^\n]s", camisetas[i].nome);
			scanf(" %s %s", camisetas[i].cor, camisetas[i].tamanho);
		}
		
		qsort(camisetas, N, sizeof(Camiseta), ordenar);
		
		for(i = 0; i < N; i++)
			printf("%s %s %s\n", camisetas[i].cor, camisetas[i].tamanho, camisetas[i].nome);
		
		c++;
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int ordenar(const void *p1, const void *p2)
{
	Camiseta *i = (Camiseta *) p1, *j = (Camiseta *) p2;
	
	if(strcmp(i->cor, j->cor) == 0)
		if(strcmp(i->tamanho, j->tamanho) == 0)
			return strcmp(i->nome, j->nome);
		else
			return strcmp(i->tamanho, j->tamanho) * -1;
	else
		return strcmp(i->cor, j->cor);
}