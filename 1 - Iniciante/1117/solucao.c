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
	int N = 0;
	double M = 0, A;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
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
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}