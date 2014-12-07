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

int comparar(const void *p1, const void *p2)
{
	int *a = (int *) p1, *b = (int *) p2;
	
	if((*a % 2) == 0 && (*b % 2) == 0)
		if(*a > *b)
			return 1;
		else if(*a < *b)
			return -1;
		else
			return 0;
	else if((*a % 2) == 1 && (*b % 2) == 1)
		if(*a < *b)
			return 1;
		else if(*a > *b)
			return -1;
		else
			return 0;
	else if((*a % 2) == 0 && (*b % 2) == 1)
		return -1;
	else
		return 1;
	
}

int main()
{
	int N, i;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	int v[N];
	
	for(i = 0; i < N; i++)
		scanf("%d", &v[i]);
	
	qsort(v, N, sizeof(int), comparar);
	
	for(i = 0; i < N; i++)
		printf("%d\n", v[i]);
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}