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
	int R, ptExtra, total[2], i, ultimo[2], count[2], *mark, *leti;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &R) && R != 0)
	{
		mark = (int *) malloc(R * sizeof(int));
		leti = (int *) malloc(R * sizeof(int));
		
		for(i = 0; i < R; i++)
			scanf("%d", &mark[i]);
		
		for(i = 0; i < R; i++)
			scanf("%d", &leti[i]);
		
		total[0] = total[1] = ultimo[0] = ultimo[1] = count[0] = count[1] = 0;
		ptExtra = 1;
		
		for(i = 0; i < R; i++)
		{
			total[0] += mark[i];
			total[1] += leti[i];
			
			if(ultimo[0] == mark[i])
				count[0]++;
			else
				count[0] = 1;
			
			if(ultimo[1] == leti[i])
				count[1]++;
			else
				count[1] = 1;
			
			ultimo[0] = mark[i];
			ultimo[1] = leti[i];
			
			if(ptExtra && (count[0] == 3 || count[1] == 3))
			{
				if(count[0] == 3 && count[1] != 3)
					total[0] += 30;
				else if(count[1] == 3 && count[0] != 3)
					total[1] += 30;
				
				ptExtra = 0;
			}
		}
		
		if(total[0] == total[1])
			printf("T\n");
		else if(total[0] > total[1])
			printf("M\n");
		else
			printf("L\n");
		
		free(mark);
		free(leti);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}