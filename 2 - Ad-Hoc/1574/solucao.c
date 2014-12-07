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
	char instrucoes[100], instrucao[15];
	int T, N, O, i, inst;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%d", &N);
		
		O = 0;
		
		for(i = 0; i < N; i++)
		{
			scanf(" %s", instrucao);
			
			if(strcmp(instrucao, "LEFT") == 0)
				instrucoes[i] = -1;
			else if(strcmp(instrucao, "RIGHT") == 0)
				instrucoes[i] = 1;
			else
			{
				scanf(" %s %d", instrucao, &inst);
				instrucoes[i] = instrucoes[inst - 1];
			}
			
			O += instrucoes[i];
		}
		
		printf("%d\n", O);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}