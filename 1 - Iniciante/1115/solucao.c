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
	double X, Y;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%lf %lf", &X, &Y) != EOF)
	{
		if(X == 0 || Y == 0)
			break;
		
		if(X > 0 && Y > 0)
			printf("primeiro\n");
		else if(X < 0 && Y > 0)
			printf("segundo\n");
		else if(X < 0 && Y < 0)
			printf("terceiro\n");
		else if(X > 0 && Y < 0)
			printf("quarto\n");
			
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}