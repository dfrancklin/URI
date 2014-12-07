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
	int i, p;
	char expressao[1001];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf(" %s", expressao) != EOF)
	{
		if(expressao[0] == ')' || expressao[strlen(expressao) - 1] == '(')
			p = 1;
		else
		{
			p = 0;
			
			for(i = 0; expressao[i] != '\0'; i++)
				if(expressao[i] == '(')
					p++;
				else if(expressao[i] == ')')
					p--;
		}
		
		if(!p)
			printf("correct\n");
		else
			printf("incorrect\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}