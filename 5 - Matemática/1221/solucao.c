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
	int N, num, i, p;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf("%d", &num);
		
		p = 1;
		
		if((num > 2 && num % 2 == 0) || num % 3 == 0 || num % 5 == 0 || num % 7 == 0)
			p = 0;
		else
			for(i = 2; i <= sqrt(num); i++)
				if(num % i == 0)
				{
					p = 0;
					break;
				}
		
		if(p)
			printf("Prime\n");
		else
			printf("Not Prime\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}