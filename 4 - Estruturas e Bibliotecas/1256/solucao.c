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

struct RChave {
	int num;
	struct RChave *prox;
};

typedef struct RChave TChave;

int Hashing(int, int);

int main()
{
	int N, M, C, i, p;
	TChave **hash, *aux, *tmp;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf("%d %d", &M, &C);
		
		hash = (TChave **) malloc(M * sizeof(TChave *));
		
		for(i = 0; i < M; i++)
			hash[i] = NULL;
		
		for(i = 0; i < C; i++)
		{
			aux = (TChave *) malloc(sizeof(TChave));
			
			scanf("%d", &(aux->num));
			aux->prox = NULL;
			
			p = Hashing(aux->num, M);
			
			if(hash[p] == NULL)
				hash[p] = aux;
			else
			{
				for(tmp = hash[p]; tmp->prox != NULL; tmp = tmp->prox);
				tmp->prox = aux;
			}
		}
		
		for(i = 0; i < M; i++)
		{
			printf("%d ->", i);
			
			for(tmp = hash[i]; tmp != NULL; tmp = tmp->prox)
				printf(" %d ->", tmp->num);
			
			printf(" \\\n");
		}
		
		if(N > 0)
			printf("\n");
		
		free(hash);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int Hashing(int num, int max)
{
	return num % max;
}