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
	int N, i, j, t;
	char texto[101], novo[101];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	getchar();
	
	while(N--)
	{
		gets(texto);
		
		t = strlen(texto);
		
		for(i = (t / 2) - 1, j = 0; i >= 0; i--, j++)
			novo[j] = texto[i];
			
		for(i = t - 1; i >= (t / 2); i--, j++)
			novo[j] = texto[i];
		
		novo[j] = '\0';
		
		printf("%s\n", novo);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}