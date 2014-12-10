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
	int id, pontos, marcados, recebidos, inscricoes;
	double average;
} Time;

int ordena(const void *arg1, const void *arg2)
{
	Time *i = (Time *) arg1, *j = (Time *) arg2;
	
	if(i->pontos == j->pontos)
		if(i->average == j->average)
			if(i->marcados == j->marcados)
				if(i->inscricoes == j->inscricoes)
					return 0;
				else if(i->inscricoes > j->inscricoes)
					return 1;
				else
					return -1;
			else if(i->marcados > j->marcados)
				return -1;
			else
				return 1;
		else if(i->average > j->average)
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
	int N, X, Y, Z, W, t, i, c = 0;
	Time times[100];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) && N != 0)
	{
		if(c > 0)
			printf("\n");
		
		for(i = 0; i < N; i++)
		{
			times[i].id			= i + 1;
			times[i].pontos		= 0;
			times[i].marcados	= 0;
			times[i].recebidos	= 0;
			times[i].average		= 0;
			times[i].inscricoes	= 0;
		}
		
		t = N * (N - 1) / 2;
		
		while(t--)
		{
			scanf("%d %d %d %d", &X, &Y, &Z, &W);
			
			times[X - 1].inscricoes++;
			times[Z - 1].inscricoes++;
			
			if(Y > W)
			{
				times[X - 1].pontos += 2;
				times[Z - 1].pontos++;
			}
			else
			{
				times[X - 1].pontos++;
				times[Z - 1].pontos += 2;
			}
			
			times[X - 1].marcados += Y;
			times[Z - 1].marcados += W;
			times[X - 1].recebidos += W;
			times[Z - 1].recebidos += Y;
		}
		
		for(i = 0; i < N; i++)
			if(times[i].recebidos == 0)
				times[i].average = times[i].marcados;
			else
				times[i].average = times[i].marcados / (double) times[i].recebidos;
		
		qsort(times, N, sizeof(Time), ordena);
		
		printf("Instancia %d\n", ++c);
		
		printf("%d", times[0].id);
		
		for(i = 1; i < N; i++)
			printf(" %d", times[i].id);
		
		printf("\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}