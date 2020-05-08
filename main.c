#include <stdio.h>
#include <function.h>

int main(int argc, char const *argv[])
{
	pgm_t *image;

	int wight, height;
	char name[10];

	scanf("%s", name);
	scanf(" %d %d", &wight, &height);

	pgm_create(&image, wight, height);

	command(image);

	pgm_free(image);
	printf("Funcionou!!!!\n");


	return 0;
}
