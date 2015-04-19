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

int ordenar(const void *, const void *);

int main()
{
	int f, t, i;
	char faixas[25][4], str[51], inicio, fim;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(gets(str))
	{
		t = strlen(str);
		f = 0;
		
		if(t)
		{
			qsort(str, t, sizeof(char), ordenar);
			sscanf(str, " %s", str);
			
			inicio = str[0];
			
			for(i = 1; str[i] != '\0'; i++)
				if(str[i] > str[i - 1] + 1)
				{
					fim = str[i - 1];
					sprintf(faixas[f++], "%c:%c", inicio, fim);
					inicio = str[i];
				}
					
			sprintf(faixas[f++], "%c:%c", inicio, str[i - 1]);
			
			printf("%s", faixas[0]);
			
			for(i = 1; i < f; i++)
				printf(", %s", faixas[i]);
			
		}
		
		printf("\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int ordenar(const void *p1, const void *p2)
{
	char *i = (char *) p1, *j = (char *) p2;
	
	if(*i == *j)
		return 0;
	else if(*i > *j)
		return 1;
	else 
		return -1;
}