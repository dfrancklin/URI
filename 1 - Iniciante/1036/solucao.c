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
	double A, B, C, D, R1, R2;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%lf %lf %lf", &A, &B, &C) != EOF)
	{
		D = pow(B, 2) - (4 * A * C);
		
		if(A == 0 || D < 0)
			printf("Impossivel calcular\n");
		else {
			R1 = (-B + sqrt(D)) / (2 * A);
			R2 = (-B - sqrt(D)) / (2 * A);
			
			printf("R1 = %.5f\n", R1);
			printf("R2 = %.5f\n", R2);
		}
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}