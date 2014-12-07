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

int ordenar(const void *, const void *);

int main()
{
	int N, M, *P, *L, i, j;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf("%d", &M);
		P = (int *) malloc(M * sizeof(int));
		L = (int *) malloc(M * sizeof(int));
		
		for(i = 0; i < M; i++)
			scanf("%d", &P[i]);
		
		memcpy(L, P, M * sizeof(int));
		
		qsort(L, M, sizeof(int), ordenar);
		
		for(i = 0, j = 0; i < M; i++)
			if(P[i] != L[i])
				j++;
		
		printf("%d\n", M - j);
		
		free(P);
		free(L);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int ordenar(const void *p1, const void *p2)
{
	int *i = (int *) p1, *j = (int *) p2;
	
	if(*i == *j)
		return 0;
	else if(*i < *j)
		return 1;
	else
		return -1;
}