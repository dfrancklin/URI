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
	int N, QT, S, i, aluno, dif, alunos[10];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf("%d %d", &QT, &S);
		
		for(i = 0; i < QT; i++)
			scanf("%d", &alunos[i]);
		
		dif = 100;
		
		for(i = 0; i < QT; i++)
		{
			if(alunos[i] == S)
			{
				aluno = i;
				break;
			}
			else if((ABS(alunos[i] - S)) < dif)
			{
				aluno = i;
				dif = ABS(alunos[i] - S);
			}
		}
		
		printf("%d\n", aluno + 1);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}