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
	int N, M, T[20000], i, j, k;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d", &N, &M) && !(N == 0 && M == 0))
	{
		for(i = 0; i < M; i++)
			scanf("%d", &T[i]);
		
		j = 0;
		k = -1;
		
		qsort(T, M, sizeof(int), ordenar);
		
		for(i = 1; i < M; i++)
			if(T[i] == T[i - 1] && T[i] != k)
			{
				j++;
				k = T[i];
			}
		
		printf("%d\n", j);
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
	else if(*i > *j)
		return 1;
	else
		return -1;
}