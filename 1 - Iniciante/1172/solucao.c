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
	int X[10], i;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	for(i = 0; i < 10; i++)
		scanf("%d", &X[i]);
	
	for(i = 0; i < 10; i++)
		if(X[i] <= 0)
			X[i] = 1;
	
	for(i = 0; i < 10; i++)
		printf("X[%d] = %d\n", i, X[i]);
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}