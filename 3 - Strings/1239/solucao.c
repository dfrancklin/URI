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
	int b, i, j, k;
	char texto[51], novo[201];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(gets(texto))
	{
		
		b = i = 0;
		
		for(j = 0, k = 0; texto[j] != '\0'; j++, k++)
		{
			if(texto[j] == '_')
				if(!i)
				{
					novo[k] = '<';
					novo[++k] = 'i';
					novo[++k] = '>';
					i = 1;
				}
				else
				{
					novo[k] = '<';
					novo[++k] = '/';
					novo[++k] = 'i';
					novo[++k] = '>';
					i = 0;
				}
			else if(texto[j] == '*')
				if(!b)
				{
					novo[k] = '<';
					novo[++k] = 'b';
					novo[++k] = '>';
					b = 1;
				}
				else
				{
					novo[k] = '<';
					novo[++k] = '/';
					novo[++k] = 'b';
					novo[++k] = '>';
					b = 0;
				}
			else
				novo[k] = texto[j];
		}
		
		novo[k] = '\0';
		
		printf("%s\n", novo);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}