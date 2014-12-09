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
#define M		70

int main()
{
	int i, j, matriz[M][M], N;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) != EOF)
	{
		for(i = 0; i < N; i++)
			for(j = 0; j < N; j++)
				matriz[i][j] = 3;
		
		for(i = 0; i < N; i++)
			matriz[i][i] = 1;
		
		for(i = 0, j = (N - 1); i < N && j >= 0; i++, j--)
			matriz[i][j] = 2;
		
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < N; j++)
				printf("%d", matriz[i][j]);
			
			printf("\n");
		}
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}