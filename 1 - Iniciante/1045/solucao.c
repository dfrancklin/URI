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
#define LADOS	3

void ordena(double *vetor)
{
	int i, j;
	double aux;
	
	for(i = LADOS - 1; i >= 0; i--)
		for(j = 0; j < i; j++)
			if(vetor[j] < vetor[j + 1])
			{
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
			}
}

int main()
{
	double lados[LADOS];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%lf %lf %lf", &lados[0], &lados[1], &lados[2]) != EOF)
	{
		ordena(lados);
		
		if(lados[0] >= (lados[1] + lados[2]))
			printf("NAO FORMA TRIANGULO\n");
		else
		{
			if(pow(lados[0], 2) == (pow(lados[1], 2) + pow(lados[2], 2)))
				printf("TRIANGULO RETANGULO\n");
			
			if(pow(lados[0], 2) > (pow(lados[1], 2) + pow(lados[2], 2)))
				printf("TRIANGULO OBTUSANGULO\n");
			
			if(pow(lados[0], 2) < (pow(lados[1], 2) + pow(lados[2], 2)))
				printf("TRIANGULO ACUTANGULO\n");
			
			if(lados[0] == lados[1] && lados[1] == lados[2] && lados[2] == lados[0])
				printf("TRIANGULO EQUILATERO\n");
			else if(lados[0] == lados[1] || lados[1] == lados[2] || lados[2] == lados[0])
				printf("TRIANGULO ISOSCELES\n");
		}
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}