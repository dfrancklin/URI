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

typedef struct {
	char nome[21];
	int ordem, pontos, vitorias, gols;
} Time;

int busca(const void *arg1, const void *arg2)
{
	Time *i = (Time *) arg1, *j = (Time *) arg2;
	
	return strcmp(i->nome, j->nome);
}

int ordena(const void *arg1, const void *arg2)
{
	Time *i = (Time *) arg1, *j = (Time *) arg2;
	
	if(i->pontos == j->pontos)
		if(i->vitorias == j->vitorias)
			if(i->gols == j->gols)
				if(i->ordem == j->ordem)
					return 0;
				else if(i->ordem > j->ordem)
					return 1;
				else
					return -1;
			else if(i->gols > j->gols)
				return -1;
			else
				return 1;
		else if(i->vitorias > j->vitorias)
			return -1;
		else
			return 1;
	else if(i->pontos > j->pontos)
		return -1;
	else
		return 1;
}

int main()
{
	int T, N, M, X, Y, i;
	Time times[100], bus1, bus2, *time1, *time2;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%d %d", &N, &M);
		
		for(i = 0; i < N; i++)
		{
			scanf(" %s", times[i].nome);
			times[i].ordem = i;
			times[i].pontos = times[i].vitorias = times[i].gols = 0;
		}
		
		qsort(times, N, sizeof(Time), busca);
		
		for(i = 0; i < M; i++)
		{
			scanf("%d %s %d %s", &X, bus1.nome, &Y, bus2.nome);
			
			time1 = (Time *) bsearch(&bus1, times, N, sizeof(Time), busca);
			time2 = (Time *) bsearch(&bus2, times, N, sizeof(Time), busca);
			
			time1->gols += X;
			time2->gols += Y;
			
			if(X == Y)
			{
				time1->pontos++;
				time2->pontos++;
			}
			else if(X > Y)
			{
				time1->pontos += 3;
				time1->vitorias++;
			}
			else
			{
				time2->pontos += 3;
				time2->vitorias++;
			}
		}
		
		qsort(times, N, sizeof(Time), ordena);
		
		for(i = 0; i < N; i++)
			printf("%s\n", times[i].nome);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}