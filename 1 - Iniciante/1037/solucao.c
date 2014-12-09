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
	double A;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%lf", &A) != EOF)
	{
		if(A < 0 && A > 100)
			printf("Fora de intervalo\n");
		else if(A >= 0 && A <= 25)
			printf("Intervalo [0,25]\n");
		else if(A > 25 && A <= 50)
			printf("Intervalo (25,50]\n");
		else if(A > 50 && A <= 75)
			printf("Intervalo (50,75]\n");
		else if(A > 75 && A <= 100)
			printf("Intervalo (75,100]\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}