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
	int N;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) != EOF)
	{
		if(N == 0)
			break;
		
		int MATRIZ[N][N], MEIO, LINHA, COLUNA, VALOR = 1, ACIMA = 0, DIREITA = 0, ABAIXO = N - 1, ESQUERDA = N - 1;
		
		if(N % 2 == 0)
			MEIO = N / 2;
		else
			MEIO = (N / 2) + 1;
		
		while(VALOR <= MEIO)
		{
			for(LINHA = DIREITA; LINHA <= ESQUERDA; LINHA++)
			{
				MATRIZ[ACIMA][LINHA] = VALOR;
				MATRIZ[ABAIXO][LINHA] = VALOR;
			}
			
			for(COLUNA = ACIMA + 1; COLUNA < ABAIXO; COLUNA++)
			{
				MATRIZ[COLUNA][DIREITA] = VALOR;
				MATRIZ[COLUNA][ESQUERDA] = VALOR;
			}
			
			ACIMA++;
			ABAIXO--;
			DIREITA++;
			ESQUERDA--;
			VALOR++;
		}
		
		for(LINHA = 0; LINHA < N; LINHA++)
		{
			for(COLUNA = 0; COLUNA < N - 1; COLUNA++)
				printf ("%3d ",MATRIZ[LINHA][COLUNA]);
			
			printf ("%3d\n",MATRIZ[LINHA][N-1]);
		}
		
		printf("\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}