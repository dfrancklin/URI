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
	int par[5], impar[5], k, p = 0, i = 0, A;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	for(k = 0; k < 15; k++)
	{
		scanf("%d", &A);
		
		if((A % 2) == 0)
		{
			par[p] = A;
			p++;
		}
		else
		{
			impar[i] = A;
			i++;
		}
		
		if(p == 5)
		{
			for(p = 0; p < 5; p++)
				printf("par[%d] = %d\n", p, par[p]);
			
			p = 0;
		}
		
		if(i == 5)
		{
			for(i = 0; i < 5; i++)
				printf("impar[%d] = %d\n", i, impar[i]);
			
			i = 0;
		}
	}
	
	for(k = 0; k < i; k++)
		printf("impar[%d] = %d\n", k, impar[k]);
	
	for(k = 0; k < p; k++)
		printf("par[%d] = %d\n", k, par[k]);
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}