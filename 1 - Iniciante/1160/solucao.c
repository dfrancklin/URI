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
	int T, PA, PB, i, j;
	double G1, G2;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &T) != EOF)
	{
		for(i = 0; i < T; i++)
		{
			scanf("%d %d %lf %lf", &PA, &PB, &G1, &G2);
			
			G1 = (G1 / 100) + 1;
			G2 = (G2 / 100) + 1;
			
			for(j = 0; j <= 100; j++)
			{
				if(PA > PB)
					break;
				
				PA = PA * G1;
				PB = PB * G2;
			}
			
			if(j > 100)
				printf("Mais de 1 seculo.\n");
			else
				printf("%d anos.\n", j);
		}
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}