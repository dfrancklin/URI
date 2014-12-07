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
	int N, i, picos, direcao, anterior, *vetor;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) && N != 0)
	{
		vetor = (int *) malloc((N + 1) * sizeof(int));
		
		for(i = 0; i < N; i++)
			scanf("%d", &vetor[i]);
		
		vetor[i] = vetor[0];
		
		picos = 0;
		
		if(vetor[i - 1] > vetor[0])
			anterior = -1;
		else if(vetor[i - 1] < vetor[0])
			anterior = 1;
		
		for(i = 0; i < N; i++)
		{
			if(vetor[i] < vetor[i + 1])
				direcao = 1;
			
			if(vetor[i] > vetor[i + 1])
				direcao = -1;
			
			if(direcao != anterior)
				picos++;
			
			anterior = direcao;
		}
		
		printf("%d\n", picos);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}