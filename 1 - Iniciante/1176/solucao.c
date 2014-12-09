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
	int N, M, i;
	
	unsigned long int F[62];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	F[0] = 0;
	F[1] = 1;
	
	for(i = 2; i < 62; i++)
		F[i] = F[i - 1] + F[i - 2];
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++)
	{
		scanf("%d", &M);
		
		printf("Fib(%d) = %lu\n", M, F[M]);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}