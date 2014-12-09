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
	int A;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &A) != EOF)
	{
		if(A == 11)
			printf("Sao Paulo\n");
		else if(A == 19)
			printf("Campinas\n");
		else if(A == 21)
			printf("Rio de Janeiro\n");
		else if(A == 27)
			printf("Vitoria\n");
		else if(A == 31)
			printf("Belo Horizonte\n");
		else if(A == 32)
			printf("Juiz de Fora\n");
		else if(A == 61)
			printf("Brasilia\n");
		else if(A == 71)
			printf("Salvador\n");
		else 
			printf("DDD nao cadastrado\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}