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
	int DI, DF, D, HI, HF, H, MI, MF, M, SI, SF, S;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%*s %d", &DI) != EOF)
	{
		scanf("%d : %d : %d", &HI, &MI, &SI);
		scanf("%*s %d", &DF);
		scanf("%d : %d : %d", &HF, &MF, &SF);
		
		D = DF - DI;
		
		if(HF < HI){
			HF += 24;
			D--;
		}
		
		H = HF - HI;
		
		if(MF < MI){
			MF += 60;
			H--;
		}
		
		M = MF - MI;
		
		if(SF < SI)
			SF += 60;
		
		S = SF - SI;
		
		printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", D, H, M, S);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}