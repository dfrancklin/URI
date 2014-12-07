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

long int fibonacci(int n);

int main ()
{
	int N, M, i, k;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) != EOF)
	{
		for(i = 0; i < N; i++)
		{
			scanf("%d", &M);
			
			printf("Fib(%d) = %ld\n", M, fibonacci(M + 1));
		}
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

long fibonacci(int n)
{
	int cont;
	long int x = 0, z = 1;
	
	if(n % 2 == 0)
	{
		for(cont = 2; cont != n; cont = cont + 2)
		{
			x = x + z;
			z = x + z;
		}
		
		return z;
	}
	else
	{
		for(cont = 1; cont != n; cont = cont + 2)
		{
			x = x + z;
			z = x + z;
		}
		
		return x;
	}
}