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
	double I = 0, J = 1, k = 3, l = 1;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(I <= 2)
	{
		J = l;
		
		while(J <= k)
		{
			printf("I=%g J=%g\n", I, J);
			J++;
		}
		
		l += 0.2;
		k += 0.2;
		I += 0.2;
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}