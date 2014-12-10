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
#define FOLGA	33

typedef struct { int caracter, qtde; } Freq;

int ordena(const void *arg1, const void *arg2)
{
	Freq *i = (Freq *) arg1, *j = (Freq *) arg2;
	
	if(i->qtde > 0 && j->qtde > 0)
		if(i->qtde == j->qtde)
			if(i->caracter == j->caracter)
				return 0;
			else if(i->caracter > j->caracter)
				return -1;
			else
				return 1;
		else if(i->qtde > j->qtde)
			return 1;
		else
			return -1;
	else if(i->qtde > 0 && j->qtde == 0)
		return -1;
	else
		return 1;
}

int main()
{
	int i, c = 0;
	char linha[1001];
	Freq freq[100];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf(" %s", linha) != EOF)
	{
		if(c > 0)
			printf("\n");
		
		for(i = 0; i < 100; i++)
		{
			freq[i].caracter = i + FOLGA;
			freq[i].qtde = 0;
		}
		
		for(i = 0; linha[i] != '\0'; i++)
			freq[linha[i] - FOLGA].qtde++;
		
		qsort(freq, 100, sizeof(Freq), ordena);
		
		for(i = 0; freq[i].qtde > 0 && i < 100; i++)
			printf("%d %d\n", freq[i].caracter, freq[i].qtde);
		
		c++;
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}