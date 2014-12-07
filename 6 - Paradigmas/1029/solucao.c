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

int chamadas;

long long fib(int num)
{
	chamadas++;
	
	if(num <= 0)
		return 0;
	else if(num == 1)
		return 1;
	else
		return fib(num - 1) + fib(num - 2);
}

int main()
{
	int N, X;
	long long resultado;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf("%d", &X);
		
		chamadas = -1;
		resultado = fib(X);
		
		printf("fib(%d) = %d calls = %lld\n", X, chamadas, resultado);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}