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
	int tamanho, i, f, m, c = 0;
	char N[3], Pares[10000];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf(" %s", &N) != EOF)
	{
		if(c > 0)
			printf("\n");
		
		scanf(" %[^\n]s", &Pares);
		tamanho = strlen(Pares);
		
		f = m = 0;
		
		for(i = 0; i < tamanho; i += 5)
		{
			if(Pares[i] == N[0] && Pares[i + 1] == N[1])
				if(Pares[i + 3] == 'F')
					f++;
				else
					m++;
		}
		
		printf("Caso %d:\nPares Iguais: %d\nF: %d\nM: %d\n", ++c, (f + m), f, m);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}