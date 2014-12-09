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
	float A, B, C, TRIANGULO, CIRCULO, TRAPEZIO, QUADRADO, RETANGULO;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%f %f %f", &A, &B, &C) != EOF)
	{
		TRIANGULO = (A * C) / 2;
		CIRCULO = 3.14159 * pow(C, 2);
		TRAPEZIO = (C * (A + B)) / 2;
		QUADRADO = pow(B, 2);
		RETANGULO = A * B;
	
		printf("TRIANGULO: %.3f\nCIRCULO: %.3f\nTRAPEZIO: %.3f\nQUADRADO: %.3f\nRETANGULO: %.3f\n", TRIANGULO, CIRCULO, TRAPEZIO, QUADRADO, RETANGULO);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}