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
	int L, C, R1, R2;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d %d %d", &L, &C, &R1, &R2) && !(L == 0 && C == 0 && R1 == 0 && R2 == 0))
	{
		if(R1 * 2 <= L && R1 * 2 <= C && R2 * 2 <= L && R2 * 2 <= C)
		{
			if(sqrt(pow((R1 - (C - R2)), 2) + pow(((L - R1) - R2), 2)) >= (R1 + R2))
				printf("S\n");
			else
				printf("N\n");
		}
		else
			printf("N\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}