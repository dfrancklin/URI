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
	int valor, h, m, s;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d", &valor) != EOF)
	{
		m = valor / 60;
		h = m / 60;
		s = valor - (m * 60);
		
		if(h > 0)
			m = m - (h * 60);
		
		printf("%d:%d:%d\n", h, m, s);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}