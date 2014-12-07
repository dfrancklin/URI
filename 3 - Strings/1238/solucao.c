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
	int N, i, j, min, t1, t2;
	char str1[51], str2[51], comb[101];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf(" %s %s", str1, str2);
		t1 = strlen(str1);
		t2 = strlen(str2);
		min = MIN(t1, t2);
		
		for(i = 0, j = 0; i < min; i++, j += 2)
		{
			comb[j] = str1[i];
			comb[j + 1] = str2[i];
		}
		
		if(t1 == min)
			for(i = j; str2[i - min] != '\0'; i++)
				comb[i] = str2[i - min];
		else if(t2 == min)
			for(i = j; str1[i - min] != '\0'; i++)
				comb[i] = str1[i - min];
		
		comb[i] = '\0';
		
		printf("%s\n", comb);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}