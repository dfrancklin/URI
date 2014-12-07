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
	int i, j;
	double duracao;
	char composicao[201];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%s", composicao) && strcmp(composicao, "*") != 0)
	{
		duracao = j = 0;
		
		for(i = 1; composicao[i] != '\0'; i++)
		{
			if(composicao[i] != '/')
				switch(composicao[i])
				{
					case 'W': duracao += 1.0; break;
					case 'H': duracao += 1 / 2.0; break;
					case 'Q': duracao += 1 / 4.0; break;
					case 'E': duracao += 1 / 8.0; break;
					case 'S': duracao += 1 / 16.0; break;
					case 'T': duracao += 1 / 32.0; break;
					case 'X': duracao += 1 / 64.0; break;
				}
			else
			{
				if(duracao == 1)
					j++;
				
				duracao = 0;
			}
		}
		
		printf("%d\n", j);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}