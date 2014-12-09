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
	int N[20], A, i, k = 19;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	for(i = 0; i < 20; i++)
		scanf("%d", &N[i]);
	
	for(i = 0; i < 10; i++)
	{
		A = N[i];
		N[i] = N[k];
		N[k] = A;
		k--;
	}
	
	for(i = 0; i < 20; i++)
		printf("N[%d] = %d\n", i, N[i]);
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}