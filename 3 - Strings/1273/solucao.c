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
	int N, i, tamanho, c = 0;
	char palavras[50][51];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) && N != 0)
	{
		if(c > 0)
			printf("\n");
		
		tamanho = 0;
		
		for(i = 0; i < N; i++)
		{
			scanf(" %s", palavras[i]);
			
			if(strlen(palavras[i]) > tamanho)
				tamanho = strlen(palavras[i]);
		}
		
		for(i = 0; i < N; i++)
			printf("%*s\n", tamanho, palavras[i]);
		
		c++;
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}