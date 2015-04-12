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
	int N, T, i, hit, tiros[50];
	char acoes[51];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf("%d", &T);
		
		for(i = 0; i < T; i++)
			scanf("%d", &tiros[i]);
		
		scanf(" %s", acoes);
		
		for(i = 0, hit = 0; i < T; i++)
			if((acoes[i] == 'S' && tiros[i] < 3) || (acoes[i] == 'J' && tiros[i] > 2))
				hit++;
		
		printf("%d\n", hit);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}