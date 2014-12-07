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
    int N, i, diamantes, achou, a;
    char linha[1001];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
    scanf("%d", &N);
	
	while(N--)
	{
		scanf(" %s", linha);
		
		achou = 1;
		diamantes = 0;
		
		while(achou)
		{
			a = 0;
			achou = 0;
			
			for(i = 0; linha[i] != '\0'; i++)
			{
				if(linha[i] == '<' && a == 0)
				{
					a = 1;
					linha[i] = '.';
				}
				
				if(linha[i] == '>' && a)
				{
					a = 0;
					achou = 1;
					diamantes++;
					linha[i] = '.';
				}
			}
		}
		
		printf("%d\n", diamantes);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}