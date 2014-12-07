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
	char string[50];
	int i, up;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(gets(string))
	{
		up = 1;
		
		for(i = 0; string[i] != '\0'; i++)
			if(string[i] >= 'A' && string[i] <= 'Z' || string[i] >= 'a' && string[i] <= 'z')
				if(up)
				{
					string[i] = toupper(string[i]);
					up = 0;
				}
				else
				{
					string[i] = tolower(string[i]);
					up = 1;
				}
		
		printf("%s\n", string);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}