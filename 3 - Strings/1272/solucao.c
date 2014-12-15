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
	int N, i, j, s;
	char texto[51], mensagem[51];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	getchar();
	
	while(N--)
	{
		gets(texto);
		
		s = 1;
		
		for(i = 0, j = 0; texto[i] != '\0'; i++)
		{
			if(s && texto[i] != ' ')
			{
				mensagem[j] = texto[i];
				s = 0;
				j++;
			}
			else if(texto[i] == ' ')
				s = 1;
		}
		
		mensagem[j] = '\0';
		
		printf("%s\n", mensagem);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}