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
	int A, B, C;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d %d", &A, &B, &C) != EOF)
	{
		
		if(A < B && B < C)
			printf("%d\n%d\n%d\n", A, B, C);
		else if(A < C && C < B)
			printf("%d\n%d\n%d\n", A, C, B);
		else if(B < C && C < A)
			printf("%d\n%d\n%d\n", B, C, A);
		else if(B < A && A < C)
			printf("%d\n%d\n%d\n", B, A, C);
		else if(C < A && A < B)
			printf("%d\n%d\n%d\n", C, A, B);
		else if(C < B && B < A)
			printf("%d\n%d\n%d\n", C, B, A);
		
		printf("\n");
		
		printf("%d\n%d\n%d\n", A, B, C);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}