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
	int H1, H2, M1, M2;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d %d %d", &H1, &M1, &H2, &M2) && !(H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0))
	{
		if(H2 == H1)
			if(M2 < M1)
			{
				H2 += 23;
				M2 += 60;
			}
		
		if(H2 < H1)
		{
			H2 += 23;
			
			if(M2 < M1)
				M2 += 60;
			else if(M2 > M1)
				H2++;
		}
		
		printf("%d\n", M2 - M1 + ((H2 - H1) * 60));
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}