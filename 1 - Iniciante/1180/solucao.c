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
	int A, M, P, i, X[1000];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &A);
	
	for(i = 0; i < A; i++)
		scanf("%d", &*(X + i));
	
	M = X[0];
	
	for(i = 1; i < A; i++)
	{
		if(M > X[i])
		{
			M = X[i];
			P = i;
		}
	}
	
	printf("Menor valor: %d\nPosicao: %d\n", M, P);
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}