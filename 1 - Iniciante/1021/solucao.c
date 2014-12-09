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
	int notas[6], moedas[6];
	double valor;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%lf", &valor) != EOF)
	{
		notas[0] = valor / 100;
		notas[1] = (valor - (notas[0] * 100)) / 50;
		notas[2] = (valor - (notas[0] * 100) - (notas[1] * 50)) / 20;
		notas[3] = (valor - (notas[0] * 100) - (notas[1] * 50) - (notas[2] * 20)) / 10;
		notas[4] = (valor - (notas[0] * 100) - (notas[1] * 50) - (notas[2] * 20) - (notas[3] * 10)) / 5;
		notas[5] = (valor - (notas[0] * 100) - (notas[1] * 50) - (notas[2] * 20) - (notas[3] * 10) - (notas[4] * 5)) / 2;
		
		valor -= (notas[0] * 100) + (notas[1] * 50) + (notas[2] * 20) + (notas[3] * 10) + (notas[4] * 5) + (notas[5] * 2);
		
		moedas[0] = valor / 1;
		moedas[1] = (valor - (moedas[0] * 1)) / 0.5;
		moedas[2] = (valor - (moedas[0] * 1) - (moedas[1] * 0.5)) / 0.25;
		moedas[3] = (valor - (moedas[0] * 1) - (moedas[1] * 0.5) - (moedas[2] * 0.25)) / 0.10;
		moedas[4] = (valor - (moedas[0] * 1) - (moedas[1] * 0.5) - (moedas[2] * 0.25) - (moedas[3] * 0.10)) / 0.05;
		moedas[5] = ((valor - (moedas[0] * 1) - (moedas[1] * 0.5) - (moedas[2] * 0.25) - (moedas[3] * 0.10) - (moedas[4] * 0.05)) / 0.01);
		
		printf("NOTAS:\n");
		printf("%d nota(s) de R$ 100.00\n", notas[0]);
		printf("%d nota(s) de R$ 50.00\n", notas[1]);
		printf("%d nota(s) de R$ 20.00\n", notas[2]);
		printf("%d nota(s) de R$ 10.00\n", notas[3]);
		printf("%d nota(s) de R$ 5.00\n", notas[4]);
		printf("%d nota(s) de R$ 2.00\n", notas[5]);
		printf("MOEDAS:\n");
		printf("%d moeda(s) de R$ 1.00\n", moedas[0]);
		printf("%d moeda(s) de R$ 0.50\n", moedas[1]);
		printf("%d moeda(s) de R$ 0.25\n", moedas[2]);
		printf("%d moeda(s) de R$ 0.10\n", moedas[3]);
		printf("%d moeda(s) de R$ 0.05\n", moedas[4]);
		printf("%d moeda(s) de R$ 0.01\n", moedas[5]);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}