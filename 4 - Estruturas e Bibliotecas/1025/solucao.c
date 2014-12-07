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

int buscar(int *v, int valor, int inicio, int fim)
{
	int meio = inicio + (fim - inicio) / 2;
	
	if(inicio <= fim)
	{
		if(v[meio] == valor)
		{
			while(v[meio - 1] == valor)
				meio--;
			
			return meio;
		}
		else if(v[meio] < valor)
			return buscar(v, valor, meio + 1, fim);
		else if(v[meio] > valor)
			return buscar(v, valor, inicio, meio - 1);
	}
	
	return -1;
}

int comparar(const void *p1, const void *p2)
{
	int *a = (int *) p1, *b = (int *) p2;
	
	if(*a > *b)
		return 1;
	else if(*a < *b)
		return -1;
	else
		return 0;
}

int main()
{
	int N, Q, c = 1, i, j, k;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d", &N, &Q) != EOF)
	{
		if(N == 0 && Q == 0)
			break;
		
		int v[N];
		
		for(i = 0; i < N; i++)
			scanf("%d", &v[i]);
		
		qsort(v, N, sizeof(int), comparar);
		
		printf("CASE# %d:\n", c);
		
		for(i = 0; i < Q; i++)
		{
			scanf("%d", &j);
			k = buscar(v, j, 0, N);
			
			if(k == -1)
				printf("%d not found\n", j);
			else
				printf("%d found at %d\n", j, k + 1);
		}
		
		c++;
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}