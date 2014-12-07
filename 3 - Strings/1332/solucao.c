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
	char string[6];
	int i, k, N;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d ", &N);
	
	for(i = 0; i < N; i++)
	{
		gets(string);
		
		k = 0;
		
		if((strlen(string) - 1) > 3)
			printf("3\n");
		else
		{
			if(string[0] == 'o')
				k++;
			if(string[1] == 'n')
				k++;
			if(string[2] == 'e')
				k++;
			
			if(k >= 2)
				printf("1\n");
			else
				printf("2\n");
		}
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}