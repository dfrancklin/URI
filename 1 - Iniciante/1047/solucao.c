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
	int HI, HF, MI, MF, H, M;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d %d %d %d", &HI, &MI, &HF, &MF) != EOF)
	{
		
		if(HF <= HI)
			HF += 24;
		
		H = HF - HI;
		
		if(MF <= MI){
			MF += 60;
			H--;
		}
		
		M = MF - MI;
		
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", H, M);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}