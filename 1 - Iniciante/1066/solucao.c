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
	int M[5], i, pa, im, po, ne;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &M[0]) != EOF)
	{
		pa = im = po = ne = 0;
		
		for(i = 1; i < 5; i++)
			scanf("%d", &M[i]);
		
		for(i = 0; i < 5; i++){
			if((M[i] % 2) == 0)
				pa++;
			else
				im++;
			
			if(M[i] > 0)
				po++;
			else if(M[i] < 0)
				ne++;
			
		}
		
		printf("%d valor(es) par(es)\n%d valor(es) impar(es)\n%d valor(es) positivo(s)\n%d valor(es) negativo(s)\n", pa, im, po, ne);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}