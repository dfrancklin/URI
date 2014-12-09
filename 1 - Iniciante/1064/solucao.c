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
	double N[6], M;
	int i, c;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%lf", &N[0]) != EOF)
	{
		c = 0;
		M = 0;
		
		for(i = 1; i < 6; i++)
			scanf("%lf", &N[i]);
		
		for(i = 0; i < 6; i++)
			if(N[i] > 0){
				c++;
				M += N[i];
			}
		
		M = M / c;
		
		printf("%d valores positivos\n%.1f\n", c, M);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}