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

void toBinary(char *Bin, long long int Valor)
{
	int i = 0;
	
	for(i = 31; i >= 0; i--)
	{
		Bin[i] = Valor % 2;
		Valor = Valor / 2;
	}
}

long long int toDecimal(char *Bin)
{
	long long int Valor = 0;
	int i, p = 0;
	
	for(i = 31; i >= 0; i--, p++)
		Valor += Bin[i] * pow(2, p);
	
	return Valor;
}

int main()
{
	long long int A, B, C, i;
	char BinA[32], BinB[32], BinC[32];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%lld %lld", &A, &B) != EOF)
	{
		toBinary(BinA, A);
		toBinary(BinB, B);
		
		for(i = 31; i >= 0; i--)
			BinC[i] = (BinA[i] == BinB[i] ? 0 : 1);
		
		C = toDecimal(BinC);
		
		printf("%lld\n", C);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}