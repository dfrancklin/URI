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
	int x1, x2, y1, y2;
	float DISTANCIA;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d", &x1, &y1) != EOF)
	{
		scanf("%d %d", &x2, &y2);
		
		DISTANCIA  = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	
		printf("%.4f\n", DISTANCIA);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}