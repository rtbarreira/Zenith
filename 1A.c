#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 8

int main(){

	int i, aux=0;	
	float soma=0, media, desvio=0;
	int *v;
	
	v = (int *) malloc (sizeof(int) * N);

	for (i=0; i<N; i++)
	{
		scanf ("%d", &v[i]);
		soma += v[i];
	}
	media = soma/N;
	for (i=0; i<N; i++)
	{
		aux += pow(v[i]-media, 2);
	}
	desvio = sqrt(aux/(N-1));
	
	printf("soma = %lf media = %lf desvio = %lf", soma, media, desvio);

	return 0;
}
