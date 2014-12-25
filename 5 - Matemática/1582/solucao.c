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
#define LADOS   3

int mdc(int m, int n);
void ordena(int *);

int main()
{
	int lados[LADOS];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d %d", &lados[0], &lados[1], &lados[2]) != EOF)
	{
		ordena(lados);
		
		if(pow(lados[0], 2) == pow(lados[1], 2) + pow(lados[2], 2))
			if(mdc(mdc(lados[0], lados[1]), lados[2]) == 1)
				printf("tripla pitagorica primitiva\n");
			else
				printf("tripla pitagorica\n");
		else
			printf("tripla\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int mdc(int m, int n)
{
	m = ABS(m);
	n = ABS(n);
	
	if(m % n == 0)
		return n;
	else
		return mdc(n, m % n);
}

void ordena(int *vetor)
{
    int i, j, aux;
     
    for(i = LADOS - 1; i >= 0; i--)
        for(j = 0; j < i; j++)
            if(vetor[j] < vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
}