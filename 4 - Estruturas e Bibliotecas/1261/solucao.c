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

typedef struct { char palavra[17]; int valor; } hpoint;

int comparar(const void *p1, const void *p2)
{
	char *valor = (char *) p1;
	hpoint *elemento = (hpoint *) p2;
	
	return strcmp(valor, elemento->palavra);
}

int main()
{
	int M, N, i;
	long long valor;
	char s[17];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d", &M, &N) != EOF)
	{
		hpoint dicionario[M], *r;
		
		for(i = 0; i < M; i++)
			scanf("%s %d", dicionario[i].palavra, &dicionario[i].valor);
		
		qsort(dicionario, M, sizeof(hpoint), comparar);
		
		for(i = 0; i < N; i++)
		{
			valor = 0;
			
			while(1){
				scanf(" %s", s);
				
				if(strcmp(s, ".") == 0)
					break;
				
				r = (hpoint*) bsearch(s, dicionario, M, sizeof(hpoint), comparar);
				
				if(r != NULL)
					valor += r->valor;
			}
			
			printf("%lld\n", valor);
		}
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}