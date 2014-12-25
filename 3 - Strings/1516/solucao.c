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
	int N, M, A, B, i, j, k, l, o, p;
	char desenho[50][51], novo[100][101];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d", &N, &M) && !(N == 0 && M == 0))
	{
		for(i = 0; i < N; i++)
			scanf(" %s", desenho[i]);
		
		scanf("%d %d", &A, &B);
		
		A /= N;
		B /= M;
		
		for(i = 0, o = 0; i < N; i++)
			for(j = 0; j < A; j++, o++)
			{
				for(k = 0, p = 0; k < M; k++)
					for(l = 0; l < B; l++, p++)
						novo[o][p] = desenho[i][k];
				
				novo[o][p] = '\0';
			}
		
		A *= N;
		
		for(i = 0; i < A; i++)
			printf("%s\n", novo[i]);
		
		printf("\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}