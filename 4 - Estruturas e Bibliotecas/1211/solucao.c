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

int ordena(const void *arg1, const void *arg2)
{
	return strcmp((char *) arg1, (char *) arg2);
}

int main()
{
	int N, i, j, total;
	char telefones[10000][201];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) != EOF)
	{
		for(i = 0; i < N; i++)
			scanf(" %s", telefones[i]);
			
		qsort(telefones, N, 201 * sizeof(char), ordena);
		
		for(i = 1, total = 0; i < N; i++)
			for(j = 0; telefones[i][j] != '\0'; j++)
				if(telefones[i][j] == telefones[i - 1][j])
					total++;
				else
					break;
		
		printf("%d\n", total);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}