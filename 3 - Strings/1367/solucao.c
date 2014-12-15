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

typedef struct { int tempo, tentativas, resolvido; } Problema;

int main()
{
	int N, T, i, pontos, total;
	char P, status[10];
	Problema problemas[26];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) && N != 0)
	{
		for(i = 0; i < 26; i++)
			problemas[i].tempo = problemas[i].tentativas = problemas[i].resolvido = 0;
		
		for(i = 0; i < N; i++)
		{
			scanf(" %c %d %s", &P, &T, status);
			
			if(strcmp(status, "correct") == 0)
			{
				problemas[P - 'A'].tempo = T;
				problemas[P - 'A'].resolvido = 1;
			}
			else
				problemas[P - 'A'].tentativas++;
		}
		
		total = pontos = 0;
		
		for(i = 0; i < 26; i++)
		{
			if(problemas[i].resolvido)
			{
				total++;
				pontos += problemas[i].tempo + (problemas[i].tentativas * 20);
			}
		}
		
		printf("%d %d\n", total, pontos);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}