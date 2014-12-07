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
	int X1, X2, Y1, Y2, dx, dy;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2) && !(X1 == 0 && Y1 == 0 && X2 == 0 && Y2 == 0))
	{
		if(X1 == X2 && Y1 == Y2)
			printf("0\n");
		else
		{
			dx = ABS(X1 - X2);
			dy = ABS(Y1 - Y2);
			
			if(dx == dy || (X1 == X2 && Y1 != Y2) || (Y1 == Y2 && X1 != X2))
				printf("1\n");
			else if(dx > dy || dx < dy)
				printf("2\n");
		}
		
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}