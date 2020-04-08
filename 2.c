#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float fsoma (int *v, int N)
{
	int i;
	float soma=0;
	for (i=0; i<N; i++)
	{
		scanf ("%d", &v[i]);
		soma += v[i];
	}
	
	return soma;
}

float fmedia (float soma, int N)
{
	float media;
	media = soma/N;

	return media;
}

float fdesvio (float media, int *v, int N)
{
	int aux=0, i;
	float desvio;
	for (i=0; i<N; i++)
	{
		aux += pow(v[i]-media, 2);
	}
	desvio = sqrt(aux/(N-1));

	return desvio;
}

int main()
{
	int N;
	float soma, media, desvio;
	int *v;
	
	scanf("%d", &N);
	
	v = (int *) malloc (sizeof(int) * N);

	soma = fsoma(v, N);
	media = fmedia(soma, N);
	desvio = fdesvio(media, v, N);

	printf("soma = %lf media = %lf desvio = %lf", soma, media, desvio);

	return 0;
}
