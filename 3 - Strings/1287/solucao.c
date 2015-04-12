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
	int i, j, e;
	unsigned long long result;
	char entrada[51], num[51];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(gets(entrada))
	{
		e = result = 0;
		
		if(strlen(entrada) == 0)
			e = 1;
		else
		{
			for(i = 0, j = 0; entrada[i] != '\0'; i++)
				if(entrada[i] >= '0' && entrada[i] <= '9')
					num[j++] = entrada[i];
				else if(entrada[i] == 'l')
					num[j++] = '1';
				else if(entrada[i] == 'O' || entrada[i] == 'o')
					num[j++] = '0';
				else if(entrada[i] != ' ' && entrada[i] != ',' && !(entrada[i] >= '0' && entrada[i] <= '9'))
				{
					e = 1;
					break;
				}
			
			num[j] = '\0';
			
			if(strlen(num) == 0)
				e = 1;
			else
				result = atoll(num);
		}
		
		if(e || result > 2147483647)
			printf("error\n");
		else
			printf("%llu\n", result);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}