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

typedef struct { int num, den; } Racional;

Racional Somar(Racional, Racional);
Racional Subtrair(Racional, Racional);
Racional Multiplicar(Racional, Racional);
Racional Dividir(Racional, Racional);
Racional Simplificar(Racional);
int mdc(int m, int n);

int main()
{
	int N;
	char op;
	Racional X, Y, res, simp;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf("%d / %d %c %d / %d", &X.num, &X.den, &op, &Y.num, &Y.den);
		
		switch(op)
		{
			case '+': res = Somar(X, Y); break;
			case '-': res = Subtrair(X, Y); break;
			case '*': res = Multiplicar(X, Y); break;
			case '/': res = Dividir(X, Y); break;
		}
		
		simp = Simplificar(res);
		
		printf("%d/%d = %d/%d\n", res.num, res.den, simp.num, simp.den);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

Racional Somar(Racional p1, Racional p2)
{
	Racional res;

	res.num = p1.num * p2.den + p2.num * p1.den;
	res.den = p1.den * p2.den;
	
	return res;
}

Racional Subtrair( Racional p1, Racional p2 )
{
	Racional res;

	res.num = p1.num * p2.den - p2.num * p1.den;
	res.den = p1.den * p2.den;
	
	return res;
}

Racional Multiplicar( Racional p1, Racional p2 )
{
	Racional res;

	res.num = p1.num * p2.num;
	res.den = p1.den * p2.den;
	
	return res;
}

Racional Dividir( Racional p1, Racional p2 )
{
	Racional res;

	res.num = p1.num * p2.den;
	res.den = p2.num * p1.den;
	
	return res;
}

Racional Simplificar(Racional num)
{
	int n;

	n = mdc(num.num, num.den);
	
	num.num = num.num / n;
	num.den = num.den / n;
	
	return num;
}

int mdc(int m, int n)
{
	m = ABS(m);
	n = ABS(n);
	
	if(m % n == 0)
		return n;
	else
		return mdc(n, m % n);
}