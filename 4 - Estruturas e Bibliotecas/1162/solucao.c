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

int bubble(int *v, int L)
{
	int aux, i, j, k = L - 1, t = 0;
	
	for(i = 0; i < L; i++)
		for(j = 0; j < (L - 1); j++)
			if(v[j] > v[j+1])
			{
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
				t++;
			}
	
	return t;
}

int main()
{
	int N, L, S, i, j;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++)
	{
		scanf("%d", &L);
		int vagoes[L];
		
		for(j = 0; j < L; j++)
			scanf("%d", &vagoes[j]);
		
		printf("Optimal train swapping takes %d swaps.\n", bubble(vagoes, L));
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}