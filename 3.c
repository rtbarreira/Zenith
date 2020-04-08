#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float fsoma (int *v, int i, int j)
{
	float soma=0;
	soma += v[i][j];
		
	return soma;
}

float fmedia (float soma, int *v, int i, int j)
{
	float media=0;

	media = soma/i;

	return media;
}

float fdesvio (float media, int *v, int i, int j)
{
	int aux=0;
	float desvio=0;
	
	aux += pow(v[i][j]-media, 2);
	desvio = sqrt(aux);

	return desvio;
}

int main()
{
	int i, j;
	float soma, media, desvio;
	int *v = (int *) malloc(sizeof(int) * 20);  //ver no arq o max de números em cada linha, mudar o segundo 10 e o da linha
	FILE *dados1, *resultados;
	
	dados1 = fopen("dados1.cvs", "rt");
	resultados = fopen("resultados.cvs", "wt");
	
	for (j=0; j<3; j++)  
	{
		for (i=0; i<10; i++)   
		{
			fscanf(dados1, "%d", &v[i][j]);

			soma = fsoma(v, i, j);

			if(i==9)
			{
				media = fmedia(soma, v, 9, j);
				desvio = fdesvio(media, v, 9, j);
				resultados[j] = "soma = %lf media = %lf desvio = %lf", soma, media, desvio;  
			}
		}

	}

	fclose(dados1);
	fclose(resultados);

	return 0;
}
