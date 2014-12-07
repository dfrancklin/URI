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
	char string[101];
	int N, i, j, leds, Num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d ", &N);
	
	for(i = 0; i < N; i++)
	{
		gets(string);
		
		leds = 0;
		
		for(j = 0; string[j] != '\0'; j++)
			leds += Num[string[j] - 48];
		
		printf("%d leds\n", leds);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}