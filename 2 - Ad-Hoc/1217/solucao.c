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
#define TAM		10000

int QtdeFrutas(char *frutas)
{
	int qtde = 0, i, j;
	char fruta[TAM];
	
	fruta[0] = '\0';
	
	for(i = 0, j = 0; frutas[i] != '\0'; i++, j++)
	{
		if(frutas[i] == ' ')
		{
			j = -1;
			fruta[0] = '\0';
			qtde++;
		}
		else
			fruta[j] = frutas[i];
	}
	
	if(strcmp(fruta, "") != 0)
		qtde++;
	
	return qtde;
}

int main()
{
	int N, i, kg, kilos = 0;
	double V, valor = 0;
	char frutas[TAM];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++)
	{
		scanf("%lf", &V);
		scanf(" %[^\n]s", frutas);
		
		kg = QtdeFrutas(frutas);
		
		kilos += kg;
		valor += V;
		
		printf("day %d: %d kg\n", (i + 1), kg);
	}
	printf("%.2lf kg by day\n", kilos / (double) N);
	printf("R$ %.2lf by day\n", valor / (double) N);
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}