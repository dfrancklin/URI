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
	int N, L, i, j, calc;
	unsigned char string[51];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf("%d", &L);
		
		calc = 0;
		
		for(i = 0; i < L; i++)
		{
			scanf(" %s", string);
			
			for(j = 0; string[j] != '\0'; j++)
			{
				calc += (string[j] - 'A') + i + j;
				
				#ifdef DEBUG
					printf("%d = %d + %d + %d\n", (string[j] - 'A') + i + j, (string[j] - 'A'), i, j);
				#endif
			}
		}
		
		printf("%d\n", calc);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}