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
#define CONECT	5

int compat(int *conect1, int *conect2)
{
	int i;
	
	for(i = 0; i < CONECT; i++)
		if(conect1[i] == conect2[i])
			return 0;
	
	return 1;
}

int main()
{
	int conectores[2][CONECT], i, j;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	for(i = 0; i < 2; i++)
		for(j = 0; j < CONECT; j++)
			scanf("%d", &conectores[i][j]);
	
	if(compat(conectores[0], conectores[1]))
		printf("Y\n");
	else
		printf("N\n");
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}