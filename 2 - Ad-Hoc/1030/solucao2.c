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

int main ()
{
	int N, Q, S, pessoas[10000], i, k, m, p, u;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	for(i = 1; i <= N; i++)
	{
		scanf("%d %d", &Q, &S);
		
		for(k = 0; k < 10000; k++)
			pessoas[k] = 1;
		
		m = p = 0;
		
		while(m < (Q - 1))
			for(k = 0; k < Q; k++)
			{
				if(pessoas[k] == 1)
					p++;
				
				if(p == S)
				{
					pessoas[k] = 0;
					m++;
					p = 0;
				}
			}
		
		for(k = 0; k < Q; k++)
			if(pessoas[k] == 1)
			{
				u = k + 1;
				break;
			}
		
		printf("Case %d: %d\n", i, u);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}