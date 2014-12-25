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
	int N, K, i, d;
	char idiomas[100][21];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf("%d", &K);
		
		for(i = 0; i < K; i++)
			scanf(" %s", idiomas[i]);
		
		d = 0;
		
		for(i = 1; i < K && !d; i++)
			if(strcmp(idiomas[0], idiomas[i]) != 0)
				d = 1;
		
		if(d)
			printf("ingles\n");
		else
			printf("%s\n", idiomas[0]);
		
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}