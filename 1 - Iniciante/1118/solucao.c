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
	int C, N;
	double M, A;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	do 
	{
		N = M = 0;
		
		while(N < 2)
		{
			scanf("%lf", &A);
			
			if(A >= 0 && A <= 10)
			{
				M += A;
				N++;
			}
			else
				printf("nota invalida\n");
		}
		
		M = M / 2;
		
		printf("media = %.2f\n", M);
		
		do
		{
			printf("novo calculo (1-sim 2-nao)\n");
			scanf("%d", &C);
		}
		while(C != 1 && C != 2);
	}
	while(C == 1);
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}