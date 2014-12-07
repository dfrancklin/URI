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

typedef struct {
	char nome[7];
	float valor;
} Aluno;

int ordem(const void *, const void *);

int main()
{
	
	Aluno alunos[3];
	int N, X, Y;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d", &N);
	
	while(N--)
	{
		scanf("%d %d", &X, &Y);
		
		strcpy(alunos[0].nome, "Rafael");
		alunos[0].valor = pow((3 * X), 2) + pow(Y, 2);
		
		strcpy(alunos[1].nome, "Beto");
		alunos[1].valor = (2 * pow(X, 2)) + pow((5 * Y), 2);
		
		strcpy(alunos[2].nome, "Carlos");
		alunos[2].valor = (-100 * X) + pow(Y, 3);
		
		qsort(alunos, 3, sizeof(Aluno), ordem);
		
		printf("%s ganhou\n", alunos[0].nome);
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}

int ordem(const void *p1, const void *p2)
{
	Aluno *i = (Aluno *) p1, *j = (Aluno *) p2;
	
	if(i->valor == j->valor)
		return 0;
	else if(i->valor < j->valor)
		return 1;
	else
		return -1;
}