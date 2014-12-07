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

unsigned long long graos(int, unsigned long long);

int main()
{
	int N, X;
	unsigned long long t;
	double p;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf("%d", &X);
		
		if(X < 64)
		{
			t = graos(X, 1);
			p = (t / 12) / 1000;
		}
		else
			p = (pow(2, X) / 12) / 1000;
		
		printf("%.0f kg\n", p);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

unsigned long long graos(int q, unsigned long long t)
{
	if(q == 0)
		return t;
	else
		return graos(--q, t * 2);
}