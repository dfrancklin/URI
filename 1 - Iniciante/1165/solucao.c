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
	int N, A, B, i, j;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) != EOF)
	{
		for(i = 0; i < N; i++)
		{
			scanf("%d", &A);
			
			B = 0;
			
			for(j = 1; j <= A; j++)
			{
				if((A % j) == 0)
					B++;
			}
			
			if(B == 2)
				printf("%d eh primo\n", A);
			else
				printf("%d nao eh primo\n", A);
		}
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}