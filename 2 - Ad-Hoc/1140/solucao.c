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
	int i, k;
	char sentenca[1051], aux[21], c, t;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf(" %[^\n]s", sentenca) && strcmp(sentenca, "*") != 0)
	{
		i = k = 0;
		c = sentenca[0];
		t = TRUE;
		
		while(t)
		{
			if(sentenca[i] == ' ' || sentenca[i] == '\0')
			{
				aux[k] = '\0';
				
				if(tolower(aux[0]) != tolower(c))
					t = FALSE;
				
				k = -1;
			}
			else
				aux[k] = sentenca[i];
			
			if(sentenca[i] == '\0')
				break;
			
			i++;
			k++;
		}
		
		if(t)
			printf("Y\n");
		else
			printf("N\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}