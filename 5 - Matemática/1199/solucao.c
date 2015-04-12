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

void Hexa(char *hexa, unsigned int valor)
{
    int i = 0, j;
	char num[101];
    
	if(valor == 0)
		num[i++] = '0';
	else
		for(i = 0; valor > 0; i++)
		{
			num[i] = valor % 16;
			
			if(num[i] > 9)
				num[i] = num[i] - 10 + 'A';
			else
				num[i] = ITOC(num[i]);
			
			valor /= 16;
		}
	
	hexa[0] = '0';
	hexa[1] = 'x';
	
	for(i--, j = 2; i >= 0; i--, j++)
		hexa[j] = num[i];
	
	hexa[j] = '\0';
}
 
unsigned int Decimal(char *hexa)
{
    unsigned int valor = 0;
	int i, j;
    
    for(i = strlen(hexa) - 1, j = 0; i > 1; i--, j++)
	{
		if(hexa[i] >= 'A' && hexa[i] <= 'F')
			valor += (hexa[i] + 10 - 'A') * pow(16, j);
		else if(hexa[i] >= 'a' && hexa[i] <= 'f')
			valor += (hexa[i] + 10 - 'a') * pow(16, j);
		else
			valor += CTOI(hexa[i]) * pow(16, j);
    }
	
    return valor;
}

int main()
{
	char num[101], hexa[101];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf(" %s", num) && num[0] != '-')
	{
		if(num[1] == 'x')
			printf("%u\n", Decimal(num));
		else
		{
			Hexa(hexa, atoi(num));
			printf("%s\n", hexa);
		}
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}