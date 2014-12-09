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
	int notas[7], valor;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &valor) != EOF)
	{
		notas[0] = valor / 100;
		notas[1] = (valor - (notas[0] * 100)) / 50;
		notas[2] = (valor - (notas[0] * 100) - (notas[1] * 50)) / 20;
		notas[3] = (valor - (notas[0] * 100) - (notas[1] * 50) - (notas[2] * 20)) / 10;
		notas[4] = (valor - (notas[0] * 100) - (notas[1] * 50) - (notas[2] * 20) - (notas[3] * 10)) / 5;
		notas[5] = (valor - (notas[0] * 100) - (notas[1] * 50) - (notas[2] * 20) - (notas[3] * 10) - (notas[4] * 5)) / 2;
		notas[6] = (valor - (notas[0] * 100) - (notas[1] * 50) - (notas[2] * 20) - (notas[3] * 10) - (notas[4] * 5) - (notas[5] * 2)) / 1;
		
		printf("%d\n%d nota(s) de R$ 100,00\n%d nota(s) de R$ 50,00\n%d nota(s) de R$ 20,00\n%d nota(s) de R$ 10,00\n%d nota(s) de R$ 5,00\n%d nota(s) de R$ 2,00\n%d nota(s) de R$ 1,00\n", valor, notas[0], notas[1], notas[2], notas[3], notas[4], notas[5], notas[6]);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}