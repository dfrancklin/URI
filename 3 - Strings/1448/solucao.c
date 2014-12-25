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
	int T, i, t1, t2, e1, e2, e, c = 0;
	char original[101], frase1[101], frase2[101];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &T);
	
	getchar();
	
	while(T--)
	{
		gets(original);
		gets(frase1);
		gets(frase2);
		
		for(i = 0, t1 = 0, t2 = 0, e1 = 0, e2 = 0, e = 0; original[i] != '\0'; i++)
		{
			if(frase1[i] == original[i])
				t1++;
			else
				e1++;
			
			if(frase2[i] == original[i])
				t2++;
			else
				e2++;
			
			if(e == 0)
			{
				if(e1 == e2)
					e1 = e2 = 0;
				else if(e1 > e2)
					e = 2;
				else
					e = 1;
			}
		}
		
		printf("Instancia %d\n", ++c);
		
		if(t1 == t2)
			if(e == 1)
				printf("time 1\n\n");
			else if(e == 2)
				printf("time 2\n\n");
			else
				printf("empate\n\n");
		else if(t1 > t2)
			printf("time 1\n\n");
		else
			printf("time 2\n\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}