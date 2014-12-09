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
	int N = 0, I = 0, G = 0, E = 0, A, B, C;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	do
	{
		N++;
		
		scanf("%d %d", &A, &B);
		
		if(A == B)
			E++;
		else if(A > B)
			I++;
		else
			G++;
		
		do
		{
			printf("Novo grenal (1-sim 2-nao)\n");
			scanf("%d", &C);
		}
		while(C != 1 && C != 2);
	}
	while(C == 1);
	
	printf("%d grenais\nInter:%d\nGremio:%d\nEmpates:%d\n", N, I, G, E);
	
	if(I == G)
		printf("Nao houve vencedor\n");
	else if(I > G)
		printf("Inter venceu mais\n");
	else
		printf("Gremio venceu mais\n");
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}