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
	char Nomes[100][100], Registros[100][100], Barrados[100][100];
	int i, j, k, T, N, B;
	float F, P, A;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &T);
	
	for(i = 0; i < T; i++)
	{
		scanf("%d ", &N);
		
		for(j = 0; j < N; j++)
			scanf("%s", Nomes[j]);
		
		for(j = 0; j < N; j++)
			scanf("%s", Registros[j]);
		
		
		B = 0;
		
		for(j = 0; j < N; j++)
		{
			P = A = 0;
			
			for(k = 0; Registros[j][k] != '\0'; k++)
				if(Registros[j][k] == 'P')
					P++;
				else if(Registros[j][k] == 'A')
					A++;
			
			F = P / (P + A);
			
			if(F < 0.75)
			{
				memcpy(Barrados[B], Nomes[j], strlen(Nomes[j]) + 1);
				B++;
			}
		}
		
		for(j = 0; j < B; j++)
		{
			printf("%s", Barrados[j]);
			
			if(j < (B - 1))
				printf(" ");
		}
		
		printf("\n");
	
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}