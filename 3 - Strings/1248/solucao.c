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
#define TAM		27

int ordena(const void *arg1, const void *arg2)
{
	char *i = (char *) arg1, *j = (char *) arg2;
	
	if(*i == *j)
		return 0;
	else if(*i > *j)
		return 1;
	else
		return -1;
}

int Remove(char c, char *dieta)
{
	int i;
	char *r;
	
	r = (char *) bsearch(&c, dieta, strlen(dieta), sizeof(char), ordena);
	
	if(r == NULL)
		return 1;
	else
		for(i = r - dieta; dieta[i] != '\0'; i++)
			dieta[i] = dieta[i + 1];
	
	return 0;
}

int main()
{
	int N, i, j, c;
	char dieta[TAM], cafe[TAM], almoco[TAM], *r;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	getchar();
	
	while(N--)
	{
		gets(dieta);
		gets(cafe);
		gets(almoco);
		
		if(strcmp(dieta, "") == 0)
			if(strcmp(cafe, "") != 0 || strcmp(almoco, "") != 0)
				printf("CHEATER\n");
			else
				printf("\n");
		else
		{
			qsort(dieta, strlen(dieta), sizeof(char), ordena);
			
			c = 0;
			
			for(i = 0; cafe[i] != '\0' && !c; i++)
				c = Remove(cafe[i], dieta);
			
			for(i = 0; almoco[i] != '\0' && !c; i++)
				c = Remove(almoco[i], dieta);
			
			if(c)
				printf("CHEATER\n");
			else
				printf("%s\n", dieta);
		}
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}