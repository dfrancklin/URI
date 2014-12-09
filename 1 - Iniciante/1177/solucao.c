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
#define TAM		1000

int main()
{
	int N[TAM], T, i, k;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &T);
	
	for(i = 0; i < TAM; )
		for(k = 0; k < T && i < TAM; k++, i++)
			N[i] = k;
	
	for(i = 0; i < TAM; i++)
		printf("N[%d] = %d\n", i, N[i]);
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}