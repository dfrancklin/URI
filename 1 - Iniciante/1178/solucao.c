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
	int i, k;
	double N[100], T;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%lf", &T) != EOF)
	{
		N[0] = T;
		
		for(i = 1; i < 100; i++)
		{
			N[i] = N[i - 1] / 2;
		}
		
		for(i = 0; i < 100; i++)
			printf("N[%d] = %.4f\n", i, N[i]);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}