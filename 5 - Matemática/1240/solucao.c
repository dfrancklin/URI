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
	int N, t1, t2, i, j;
	char num1[15], num2[15];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf("%s %s", num1, num2);
		t1 = strlen(num1);
		t2 = strlen(num2);
		
		if(t1 < t2)
			printf("nao encaixa\n");
		else
		{
			for(i = t1 - t2, j = 0; i < t1; i++, j++)
				num1[j] = num1[i];
			
			num1[j] = '\0';
			
			if(strcmp(num1, num2) == 0)
				printf("encaixa\n");
			else
				printf("nao encaixa\n");
		}
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}