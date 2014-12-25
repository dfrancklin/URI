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
	int N, t1, t2, i, j, k;
	char num1[1001], num2[1001];
	
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
			k = 1;
			
			for(i = t1 - 1, j = t2 - 1; i >= 0 && j >= 0; i--, j--)
				if(num1[i] != num2[j])
					k = 0;
			
			if(k)
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