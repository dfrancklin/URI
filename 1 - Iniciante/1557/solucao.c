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

#define MAX 15

int qtdDigitos(int);

int main()
{
	int N, T, matriz[MAX][MAX], i, j;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) && N != 0)
	{
		for(i = 0; i < N; i++)
			for(j = 0; j < N; j++)
				matriz[i][j] = (int) pow(2, i + j);
		
		T = qtdDigitos((int) pow(2, i + j - 2));
		
		for(i = 0; i < N; i++)
		{
			printf("%*d", T, matriz[i][0]);
			
			for(j = 1; j < N; j++)
				printf(" %*d", T, matriz[i][j]);
			
			printf("\n");
		}
		
		printf("\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int qtdDigitos(int N)
{
	if(N < 10)
		return 1;
	else
		return 1 + qtdDigitos(N / 10);
}