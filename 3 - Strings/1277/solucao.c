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

typedef struct { char nome[51], reg[100]; float pres, aus;} Aluno;

int main()
{
	Aluno aluno[100];
	int i, j, k, T, N;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &T);
	
	while(T--)
	{
		scanf("%d", &N);
		
		for(i = 0; i < N; i++)
			scanf(" %s", aluno[i].nome);
		
		for(i = 0; i < N; i++) {
			scanf(" %s", aluno[i].reg);
			aluno[i].pres = aluno[i].aus = 0;
		}
		
		for(i = 0, k = 0; i < N; i++)
		{
			for(j = 0; aluno[i].reg[j] != '\0'; j++)
				if(aluno[i].reg[j] == 'P')
					aluno[i].pres++;
				else if(aluno[i].reg[j] == 'A')
					aluno[i].aus++;
			
			if(aluno[i].pres / (aluno[i].pres + aluno[i].aus) < 0.75)
			{
				if(k)
					printf(" ");
				
				printf("%s", aluno[i].nome);
				k++;
			}
		}
		
		printf("\n");
	
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}