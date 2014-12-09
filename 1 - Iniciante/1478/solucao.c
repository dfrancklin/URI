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
		
		int MATRIZ[N][N], LINHA, COLUNA, VALOR, INICIO = 0, FIM = N - 1;
		
		for(LINHA = 0; LINHA < N; LINHA++)
		{
			VALOR = 1;

			for(COLUNA = INICIO; COLUNA < N; COLUNA++)
			{
				MATRIZ[LINHA][COLUNA] = VALOR;
				VALOR++;
			}
			
			INICIO++;
		}
		
		for(LINHA = N - 1; LINHA > 0; LINHA--)
		{
			VALOR = 2;
			
			for(COLUNA = FIM - 1; COLUNA >= 0; COLUNA--)
			{
				MATRIZ[LINHA][COLUNA] = VALOR;
				VALOR++;
			}
			
			FIM--;
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