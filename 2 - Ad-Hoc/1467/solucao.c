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
	int A, B, C;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d %d", &A, &B, &C) != EOF)
	{
		if((A == 0 && B == 1 && C == 1) || (A == 1 && B == 0 && C == 0))
			printf("A\n");
		else if((A == 1 && B == 0 && C == 1) || (A == 0 && B == 1 && C == 0))
			printf("B\n");
		else if((A == 1 && B == 1 && C == 0) || (A == 0 && B == 0 && C == 1))
			printf("C\n");
		else
			printf("*\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}