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

typedef struct { int R, X, Y; } Circulo;

int main()
{
	double distancia;
	
	Circulo A, B;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d %d %d %d %d", &A.R, &A.X, &A.Y, &B.R, &B.X, &B.Y) != EOF)
	{
		distancia = sqrt(pow((A.X - B.X), 2) + pow((A.Y - B.Y), 2));
		
		if(distancia + B.R <= A.R)
			printf("RICO\n");
		else
			printf("MORTO\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}