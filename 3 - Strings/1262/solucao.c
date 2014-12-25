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
	int P, i, r, ciclos;
	char rastro[51];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf(" %s", rastro) != EOF)
	{
		scanf("%d", &P);
		
		for(i = 0, r = 0, ciclos = 0; rastro[i] != '\0'; i++)
		{
			if(rastro[i] == 'W')
			{
				ciclos++;
				r = 0;
			}
			else
			{
				r++;
				
				if(r == 1)
					ciclos++;
				
				if(r == P)
					r = 0;
			}
		}
		
		printf("%d\n", ciclos);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}