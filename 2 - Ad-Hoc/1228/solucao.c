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

typedef struct { int ini, fim; } Competicao;

int buscar(Competicao v[], int valor, int N)
{
	int i = 0;
	
	while(i < N && v[i].ini != valor)
		i++;
	
	if(i == N)
		return -1;
	else
		return i;
}

int main()
{
	int N, i, cont, b, aux;
	Competicao final[25];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) != EOF)
	{
		cont = 0;
		
		for(i = 0; i < N; i++)
			scanf("%d", &final[i].ini);
		
		for(i = 0; i < N; i++)
			scanf("%d", &final[i].fim);
		
		i = 0;
		
		do {
			while(final[i].fim != final[i].ini)
			{
				b = buscar(final, final[i].fim, N);
				aux = final[b - 1].ini;
				final[b - 1].ini = final[b].ini;
				final[b].ini = aux;
				cont++;
			}
			
			i++;
		} while(final[i - 1].fim == final[i - 1].ini && i < N);
		
		printf("%d\n", cont);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}