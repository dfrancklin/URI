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
	char A[100], B[100], C[100];
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	while(scanf("%s*s", &A) != EOF)
	{
		scanf("%s*s", &B);
		scanf("%s*s", &C);
		
		if(strcmp(A, "vertebrado") == 0)
			if(strcmp(B, "ave") == 0)
				if(strcmp(C, "carnivoro") == 0)
					printf("aguia\n");
				else if(strcmp(C, "onivoro") == 0)
					printf("pomba\n");
			else if(strcmp(B, "mamifero") == 0)
				if(strcmp(C, "onivoro") == 0)
					printf("homem\n");
				else if(strcmp(C, "herbivoro") == 0)
					printf("vaca\n");
		else if(strcmp(A, "invertebrado") == 0)
			if(strcmp(B, "inseto") == 0)
				if(strcmp(C, "hematofago") == 0)
					printf("pulga\n");
				else if(strcmp(C, "herbivoro") == 0)
					printf("lagarta\n");
			else if(strcmp(B, "anelideo") == 0)
				if(strcmp(C, "hematofago") == 0)
					printf("sanguessuga\n");
				else if(strcmp(C, "onivoro") == 0)
					printf("minhoca\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}