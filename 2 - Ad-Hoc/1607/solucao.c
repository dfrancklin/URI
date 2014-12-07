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
	int T, i, avanco;
	char tenho[10001], quero[10001];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &T);
	
	while(T--)
	{
		scanf(" %s %s", tenho, quero);
		
		avanco = 0;
		
		for(i = 0; tenho[i] != '\0'; i++)
		{
			if(tenho[i] > quero[i])
			{
				avanco += 26 - (tenho[i] - quero[i]);
			}
			else if(tenho[i] < quero[i])
			{
				avanco += quero[i] - tenho[i];
			}
		}
		
		printf("%d\n", avanco);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}