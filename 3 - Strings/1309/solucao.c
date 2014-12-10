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
	char dollares[110], centavos, i, c;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%s", dollares) != EOF)
	{
		scanf("%hhd", &centavos);
		
		printf("$");
		
		for(i = 0; i < strlen(dollares) % 3; i++)
			printf("%c", dollares[i]);
		
		if(i > 0 && i < strlen(dollares))
			printf(",");
		
		c = 0;
		
		for(; dollares[i] != '\0'; i++, c++)
		{	
			printf("%c", dollares[i]);
			
			if(c == 2 && dollares[i + 1] != '\0')
			{
				printf(",");
				c = -1;
			}
		}
		
		printf(".%02hhd\n", centavos);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}