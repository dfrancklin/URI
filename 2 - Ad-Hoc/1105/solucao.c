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

int main()
{
	int B, N, D, C, V, i, quites, *reservas;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d", &B, &N) && !(B == 0 && N == 0))
	{
		reservas = (int *) malloc(B * sizeof(int));
		
		for(i = 0; i < B; i++)
			scanf("%d", &reservas[i]);
		
		for(i = 0; i < N; i++)
		{
			scanf("%d %d %d", &D, &C, &V);
			
			reservas[D - 1] -= V;
			reservas[C - 1] += V;
		}
		
		quites = 1;
		
		for(i = 0; i < B; i++)
			if(reservas[i] < 0)
				quites = 0;
		
		if(quites)
			printf("S\n");
		else
			printf("N\n");
		
		free(reservas);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}