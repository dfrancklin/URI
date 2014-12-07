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

int somar(int, int, int);

int main()
{
	int N/*, i, j*/;
	char ok;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &N) != EOF)
	{
		ok = FALSE;
		
		/*
		for(i = 1; i < ceil(sqrt(N)) && !ok; i++)
			for(j = i; j < ceil(sqrt(N)) && !ok; j++)
				ok = N == (int) (pow(i, 2) + pow(j, 2));
		*/
		
		ok = somar(N, sqrt(N), sqrt(N));
		
		if(ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int somar(int N, int a, int b)
{
	if(a <= 0 && b <= 0)
		return FALSE;
	else if(N == (int) (pow(a, 2) + pow(b, 2)))
		return TRUE;
	else
		return somar(N, b - 1, a);
}