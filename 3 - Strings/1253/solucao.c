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
	char string[51];
	int i, k, N, P;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d ", &N);
	
	for(i = 0; i < N; i++)
	{
		gets(string);
		
		scanf("%d ", &P);
		
		for(k = 0; string[k] != '\0'; k++)
			if(string[k] >= 65 && string[k] <= 90)
				if((string[k] - P) < 65)
					string[k] = (string[k] - P) + 26;
				else
					string[k] -= P;
		
		printf("%s\n", string);
		
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}