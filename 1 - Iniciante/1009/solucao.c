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
	double Salario, Vendas, total;
	char Nome[20];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf(" %s", Nome) != EOF)
	{
		scanf("%lf", &Salario);
		scanf("%lf", &Vendas);
		
		total = Salario + (Vendas * 0.15);
		
		printf("TOTAL = R$ %.2lf\n", total);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}