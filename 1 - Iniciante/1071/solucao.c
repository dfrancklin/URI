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
	int A, B, I, F, k, c;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &A) != EOF)
	{
		scanf("%d", &B);
		
		c = 0;
		
		if(A <= B){
			I = A + 1;
			F = B;
		} else {
			I = B + 1;
			F = A;
		}
		
		for(k = I; k < F; k++)
			if(abs(k % 2) == 1)
				c += k;
		
		printf("%d\n", c);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}