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
	int L, i, k;
	double M[12][12], P;
	char O;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d ", &L) != EOF)
	{
		scanf("%c", &O);
		
		P = 0;
		
		for(i = 0; i < 12; i++)
			for(k = 0; k < 12; k++)
				scanf("%lf", &M[i][k]);
		
		for(i = 0; i < 12; i++)
			P += M[L][i];
		
		if(O == 'M')
			P = P / 12;
		
		printf("%.1f\n", P);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}