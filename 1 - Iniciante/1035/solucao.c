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
	int A, B, C, D;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d %d %d", &A, &B, &C, &D) != EOF)
	{
		
		if(B > C && D > A && (C + D) > (A + B) && C > 0 && D > 0 && (A % 2) == 0)
			printf("Valores aceitos\n");
		else
			printf("Valores nao aceitos\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}