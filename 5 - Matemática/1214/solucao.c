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
	
	if(*i == *j)
		return 0;
	else if(*i > *j)
		return -1;
	else
		return 1;
}

int main()
{
	int C, N, *final, i;
	double media, alunos;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &C);
	
	while(C--)
	{
		scanf("%d", &N);
		
		final = (int *) malloc(N * sizeof(int));
		
		for(i = 0, media = 0; i < N; i++)
		{
			scanf("%d", &final[i]);
			
			media += final[i];
		}
		
		media /= N;
		
		qsort(final, N, sizeof(int), ordena);
		
		for(i = 0, alunos = 0; final[i] > media; i++, alunos++);
		
		alunos = (alunos / N) * 100;
		
		printf("%.3lf%%\n", alunos);
		
		free(final);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}