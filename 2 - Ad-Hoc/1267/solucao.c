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
	int N, D, i, j, todos, jantares[500][100], alunos[100];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d", &N, &D) && !(N == 0 && D == 0))
	{
		for(i = 0; i < D; i++)
			for(j = 0; j < N; j++)
				scanf("%d", &jantares[i][j]);
		
		memset(alunos, 0, N * sizeof(int));
		
		for(i = 0; i < D; i++)
			for(j = 0; j < N; j++)
				alunos[j] += jantares[i][j];
		
		todos = 0;
		
		for(i = 0; i < N; i++)
			if(alunos[i] == D)
			{
				todos = 1;
				break;
			}
		
		if(todos)
			printf("yes\n");
		else
			printf("no\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}