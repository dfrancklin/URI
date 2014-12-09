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
	int nA, qA, nB, qB;
	float vA, vB, VALOR;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d %f", &nA, &qA, &vA) != EOF)
	{
		scanf("%d %d %f", &nB, &qB, &vB);
		
		VALOR = (qA * vA) + (qB * vB);
		
		printf("VALOR A PAGAR: R$ %.2f\n", VALOR);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}