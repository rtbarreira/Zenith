#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	float soma, media, desvio;

	soma = a+b+c;
	media = soma/3;
	desvio = sqrt((pow(a-media, 2) + pow(b-media, 2) + pow(c-media, 2))/2);

	printf("soma = %lf media = %lf desvio = %lf", soma, media, desvio);

	return 0;
}

