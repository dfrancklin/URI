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
	int N, i, j, tam;
	char msg[1001], aux;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++)
	{
		scanf(" %[^\n]s", msg);
		tam = strlen(msg);
		
		for(j = 0; j < tam; j++)
			if((msg[j] >= 'a' && msg[j] <= 'z') || (msg[j] >= 'A' && msg[j] <= 'Z'))
				msg[j] += 3;
		
		for(j = 0; j < tam / 2; j++)
		{
			aux = msg[tam - 1 - j];
			msg[tam - 1 - j] = msg[j];
			msg[j] = aux;
		}
		
		for(j = tam / 2; j < tam; j++)
			msg[j]--;
		
		printf("%s\n", msg);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}