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
	int i;
	char texto[51];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(gets(texto))
	{
		for(i = 0; texto[i] != '\0'; i++)
			if(texto[i] >= 'a' && texto[i] <= 'z')
				if(texto[i] + 13 > 'z')
					texto[i] += 13 - 26;
				else
					texto[i] += 13;
			else if(texto[i] >= 'A' && texto[i] <= 'Z')
				if(texto[i] + 13 > 'Z')
					texto[i] += 13 - 26;
				else
					texto[i] += 13;
		
		printf("%s\n", texto);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}