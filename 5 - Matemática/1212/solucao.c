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
	int nCarry, carry, num[2], r[2];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d", &num[0], &num[1]) && !(num[0] == 0 && num[1] == 0))
	{
		nCarry = carry = 0;
		
		while(num[0] > 0 || num[1] > 0)
		{
			r[0] = num[0] % 10;
			num[0] /= 10;
			
			r[1] = num[1] % 10;
			num[1] /= 10;
			
			#ifdef DEBUG
				printf("%d %d\n", r[0], r[1]);
			#endif
			
			if(r[0] + r[1] + carry > 9)
			{
				carry = 1;
				nCarry++;
			}
			else
				carry = 0;
		}
		
		if(nCarry == 0)
			printf("No carry operation.\n");
		else if(nCarry == 1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n", nCarry);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}