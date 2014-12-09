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
	int N[10], A, i;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &A);
	
	N[0] = A;
	
	for(i = 1; i < 10; i++)
		N[i] = N[i - 1] * 2;
	
	for(i = 0; i < 10; i++)
		printf("N[%d] = %d\n", i, N[i]);
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}