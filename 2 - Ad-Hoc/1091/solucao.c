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

typedef struct { int x, y; } Ponto;

int main()
{
	int K;
	Ponto divisa, residencia;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &K) && K != 0)
	{
		scanf("%d %d", &divisa.x, &divisa.y);
		
		while(K--)
		{
			scanf("%d %d", &residencia.x, &residencia.y);
			
			if(residencia.x == divisa.x || residencia.y == divisa.y)
				printf("divisa\n");
			else
			{
				if(residencia.y > divisa.y)
					printf("N");
				else
					printf("S");
				
				if(residencia.x > divisa.x)
					printf("E\n");
				else
					printf("O\n");
			}
		}
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}