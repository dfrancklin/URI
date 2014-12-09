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
	double V, I;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%lf", &V) != EOF)
	{
		I = 0;
		
		if(V <= 2000){
			printf("Isento\n");
		} else {
			if(V > 2000 && V <= 3000)
				I = (V - 2000) * 0.08;
			else if(V > 3000 && V <= 4500)
				I = (1000 * 0.08) + ((V - 3000) * 0.18);
			else if(V > 4500)
				I = (1000 * 0.08) + (1500 * 0.18) + ((V - 4500) * 0.28);
			
		
			printf("R$ %.2f\n", I);
		}
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}