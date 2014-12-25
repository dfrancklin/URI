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

char troca(char c)
{
	int i;
	char cs[] = {"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};
	
	for(i = 0; cs[i] != '\0' && cs[i] != c; i++);
	
	return (cs[i] == '\0' ? c : cs[i - 1]);
}

int main()
{
	int i;
	char linha[10000];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(gets(linha))
	{
		for(i = 0; linha[i] != '\0'; i++)
			linha[i] = troca(linha[i]);
		
		printf("%s\n", linha);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}