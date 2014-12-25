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

void Converter(char *vetor, int tamanho, int valor)
{
	int i = 0;
	
	for(i = tamanho - 1; i >= 0; i--)
	{
		vetor[i] = valor % 2;
		valor /= 2;
	}
}

void Imprimir(char *hora, char *minuto)
{
	printf(" ____________________________________________\n");
	printf("|                                            |\n");
	printf("|    ____________________________________    |_\n");
	printf("|   |                                    |   |_)\n");
	printf("|   |   8         4         2         1  |   |\n");
	printf("|   |                                    |   |\n");
	printf("|   |   ");
	
	if(hora[0]) printf("o         "); else printf("          ");
	if(hora[1]) printf("o         "); else printf("          ");
	if(hora[2]) printf("o         "); else printf("          ");
	if(hora[3]) printf("o  "); else printf("   ");
	
	printf("|   |\n");
	printf("|   |                                    |   |\n");
	printf("|   |                                    |   |\n");
	printf("|   |   ");
	
	if(minuto[0]) printf("o     "); else printf("      ");
	if(minuto[1]) printf("o     "); else printf("      ");
	if(minuto[2]) printf("o     "); else printf("      ");
	if(minuto[3]) printf("o     "); else printf("      ");
	if(minuto[4]) printf("o     "); else printf("      ");
	if(minuto[5]) printf("o  "); else printf("   ");
	
	printf("|   |\n");
	printf("|   |                                    |   |\n");
	printf("|   |   32    16    8     4     2     1  |   |_\n");
	printf("|   |____________________________________|   |_)\n");
	printf("|                                            |\n");
	printf("|____________________________________________|\n\n");
}

int main()
{
	int H, M;
	char hora[4], minuto[6];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%d:%d", &H, &M) != EOF)
	{
		Converter(hora, 4, H);
		Converter(minuto, 6, M);
		
		Imprimir(hora, minuto);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}