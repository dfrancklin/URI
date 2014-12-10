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

typedef struct { int x, y; } Ponto;

int main()
{
	int N;
	Ponto A, B, C, D, R;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf("%d %d %d %d %d %d %d %d %d %d", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y, &R.x, &R.y);
		
		if(
			R.x >= A.x && R.x <= B.x && 
			R.x >= D.x && R.x <= C.x && 
			R.y >= A.y && R.y <= D.y && 
			R.y >= B.y && R.y <= C.y)
			printf("1\n");
		else
			printf("0\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}