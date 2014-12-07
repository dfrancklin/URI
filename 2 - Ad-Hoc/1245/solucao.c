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

typedef struct { int D, E; } Par;

int main()
{
	int N, M, i, qtd;
	char L;
	Par pares[61];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) != EOF)
	{
		for(i = 0; i < 61; i++)
			pares[i].D = pares[i].E = 0;
		
		for(i = 0; i < N; i++)
		{
			scanf("%d %c", &M, &L);
			
			if(L == 'D')
				pares[M].D++;
			else
				pares[M].E++;
		}
		
		qtd = 0;
		for(i = 0; i < 61; i++)
			if(pares[i].D > pares[i].E)
				qtd += pares[i].E;
			else
				qtd += pares[i].D;
		
		printf("%d\n", qtd);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}