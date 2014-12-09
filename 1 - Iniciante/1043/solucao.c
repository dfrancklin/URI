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
	double A, B, C, P;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%lf %lf %lf", &A, &B, &C) != EOF)
	{
		if(abs(B - C) < A && A < (B + C) && abs(A - C) < B && B < (A + C) && abs(A - B) < C && C < (A + B)){
			P = A + B + C;
			printf("Perimetro = %.1f\n", P);
		} else {
			A = ((A + B) * C) / 2;
			printf("Area = %.1f\n", A);
		}
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}