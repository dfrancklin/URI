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
	unsigned char string[201], chars[26], M;
	int N, i, j, k;
	
	#ifdef DEBUG
		double tI_ = clock();
	#endif
	
	scanf("%d ", &N);
	
	for(i = 0; i < N; i++)
	{
		scanf("%[^\n]s", string);
		getchar();
		
		for(k = 0; k < 26; k++)
			chars[k] = 0;
		
		M = 0;
		
		for(k = 0; string[k] != '\0'; k++)
			for(j = 97; j <= 122; j++)
				if(tolower(string[k]) == j)
					chars[j - 97]++;
		
		for(k = 0; k < 26; k++)
			if(M < chars[k])
				M = chars[k];
		
		for(k = 0; k < 26; k++)
			if(chars[k] == M)
				printf("%c", (k + 97));
		
		printf("\n");
	}
	
	#ifdef DEBUG
		printf("Tempo: %.1lf %.1lf\n", clock() - tI_, (clock() - tI_) / CLK_TCK);
	#endif
	
	return 0;
}