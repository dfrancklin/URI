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
	double S, NS, R, P;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%lf", &S) != EOF)
	{
		if(S <= 400)
			P = 0.15;
		else if(S > 400 && S <= 800)
			P = 0.12;
		else if(S > 800 && S <= 1200)
			P = 0.10;
		else if(S > 1200 && S <= 2000)
			P = 0.07;
		else if(S > 2000)
			P = 0.04;
		
		R = S * P;
		NS = S + R;
		
		printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %.0f %%\n", NS, R, (P * 100));
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}