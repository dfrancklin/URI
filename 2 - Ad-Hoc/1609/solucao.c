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

int ordena(const void *arg1, const void *arg2)
{
	int *i = (int *) arg1, *j = (int *) arg2;
	
	if(*i > *j)
		return 1;
	else
		if(*i < *j)
			return -1;
		else
			return 0;
}

int main()
{
	int T, N, i, num, p, total, *vetor;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%d", &N);
		
		vetor = (int *) malloc(N * sizeof(int));
		
		for(i = 0; i < N; i++)
			scanf("%d", &vetor[i]);
		
		total = 0;
		
		qsort(vetor, N, sizeof(int), ordena);
		
		for(i = 1; i < N; i++)
			if(vetor[i] != vetor[i - 1])
				total++;
		
		printf("%d\n", ++total);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}