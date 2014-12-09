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
	double A, B, C, D, E, M;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%lf %lf %lf %lf", &A, &B, &C, &D) != EOF)
	{
		E = 0;
		
		M = ((A * 2) + (B * 3) + (C * 4) + D) / 10;
		
		printf("Media: %.1f\n", M);
		
		if(M >= 7)
			printf("Aluno aprovado.\n");
		else if(M >= 5 && M < 7){
			scanf("%lf", &E);
			
			printf("Aluno em exame.\n");
			printf("Nota do exame: %.1f\n", E);
			
			M = (M + E) / 2;
			
			if(M >= 5)
				printf("Aluno aprovado.\n");
			else
				printf("Aluno reprovado.\n");
			
			printf("Media final: %.1f\n", M);
		} else
			printf("Aluno reprovado.\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}