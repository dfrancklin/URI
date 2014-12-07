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
	int N, i;
	char *comandos, direcao;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) && N != 0)
	{
		comandos = (char *) malloc(N * sizeof(char));
		direcao = 'N';
		
		scanf("%s", comandos);
		
		for(i = 0; comandos[i] != '\0'; i++)
		{
			switch(direcao)
			{
				case 'N': direcao = comandos[i] == 'D' ? 'L' : 'O'; break;
				case 'L': direcao = comandos[i] == 'D' ? 'S' : 'N'; break;
				case 'S': direcao = comandos[i] == 'D' ? 'O' : 'L'; break;
				case 'O': direcao = comandos[i] == 'D' ? 'N' : 'S'; break;
			}
		}
		
		printf("%c\n", direcao);
		
		free(comandos);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}