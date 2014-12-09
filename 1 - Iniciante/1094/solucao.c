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
	int N, Q, C = 0, R = 0, S = 0, total = 0;
	char T;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	C = R = S = total = 0;
	
	while(N--)
	{
		scanf("%d %c", &Q, &T);
		
		switch(T)
		{
			case 'C': C += Q; break;
			case 'R': R += Q; break;
			case 'S': S += Q; break;
		}
		
		total += Q;
	}
	
	printf("Total: %d cobaias\n", total);
	printf("Total de coelhos: %d\n", C);
	printf("Total de ratos: %d\n", R);
	printf("Total de sapos: %d\n", S);
	printf("Percentual de coelhos: %.2lf %%\n", (C * 100.0) / (double) total);
	printf("Percentual de ratos: %.2lf %%\n", (R * 100.0) / (double) total);
	printf("Percentual de sapos: %.2lf %%\n", (S * 100.0) / (double) total);
	
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}