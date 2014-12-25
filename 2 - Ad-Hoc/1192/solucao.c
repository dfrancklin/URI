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
	int N, i;
	char sequ[4];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf(" %[^\n]s", sequ);
		
		if(sequ[0] == sequ[2])
			printf("%d\n", (CTOI(sequ[0])) * (CTOI(sequ[2])));
		else if(sequ[1] >= 'A' && sequ[1] <= 'Z')
			printf("%d\n", (CTOI(sequ[2])) - (CTOI(sequ[0])));
		else
			printf("%d\n", (CTOI(sequ[0])) + (CTOI(sequ[2])));
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}