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
	int D, i, j;
	char N[110], resultado[110];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf(" %d %s", &D, N) && !(D == 0 && strcmp(N, "0") == 0))
	{
		D = ITOC(D);
		
		for(i = 0, j = 0; N[i] != '\0'; i++)
			if(N[i] != D)
				if(j == 1 && resultado[j - 1] == '0')
					resultado[j - 1] = N[i];
				else
				{
					resultado[j] = N[i];
					j++;
				}
		
		if(j == 0)
		{
			resultado[j] = '0';
			j++;
		}
		
		resultado[j] = '\0';
		
		printf("%s\n", resultado);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}