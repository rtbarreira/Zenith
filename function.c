#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <function.h>

void command(pgm_t *image){
	char command[10];

	while (strcmp(command, "EXPORT") !=0){

		scanf("%s", command);
	
		int x=0, y=0, x_1=0, x_2=0, y_1=0, y_2=0, width=0, height=0, radius=0, color=0;
		char name[10];

		 if (strcmp(command,"EXPORT")==0){
			scanf("%s", name);
			pgm_save(image, name);
		}
		 else if (strcmp(command,"LINE")==0){
			scanf(" %d %d %d %d %d", &x_1, &y_1, &x_2, &y_2, &color);
			draw_line(image, x_1, y_1, x_2, y_2, color);
		}
		else if(strcmp(command, "CIRCLE")==0){
			scanf(" %d %d %d %d", &x, &y, &radius, &color);
			draw_circle(image, x, y, radius, color);
		}
		else if (strcmp(command, "DISK")==0){
			scanf(" %d %d %d %d", &x, &y, &radius, &color);
			draw_disk(image, x, y, radius, color);
		}
		else if (strcmp(command, "RECT")==0){
			scanf(" %d %d %d %d %d", &x, &y, &width, &height, &color);
			draw_rect(image, x, y, width, height, color);
		}
	}
}

int pgm_create(pgm_t **image, int width, int height)
{
	if(!image) return ERROR_PGM;
	if(width < 0 || width > MAX_IMAGE_SIZE) return ERROR_PGM;
	if(height < 0 || height > MAX_IMAGE_SIZE) return ERROR_PGM;

	int j;

	*image = (pgm_t *)calloc(1, sizeof(pgm_t));
	(*image)->magic_number[0] = 'P';
	(*image)->magic_number[1] = '2';
	(*image)->magic_number[2] = '\0';
	(*image)->height = height;
	(*image)->width = width;
	(*image)->tones = 255;
	(*image)->pixels = (int **)calloc(height, sizeof(int *));
	for(j = 0; j < height; j++)
		(*image)->pixels[j] = (int *)calloc(width, sizeof(int));

	return SUCCESS_PGM;
}

int pgm_free(pgm_t *image)
{
	if(!image) return ERROR_PGM;

	int i;

	for(i = 0; i < image->height; i++)
		free(image->pixels[i]);
	free(image->pixels);
	free(image);

	return SUCCESS_PGM;
}

int pgm_save(pgm_t *image, char *name)
{
	if(!image) return ERROR_PGM;
	if(!name) return ERROR_PGM;

	int i, j;
	FILE *file;

	file = fopen(name, "w");
	fprintf(file, "%s\n", image->magic_number);
	fprintf(file, "%d %d\n", image->width, image->height);
	fprintf(file, "%d\n", image->tones);
	for(i = 0; i < image->height; i++){
		for(j = 0; j < (image->width - 1); j++){
			fprintf(file, "%d ", image->pixels[i][j]);
		}
		if(i == (image->height - 1))
			fprintf(file, "%d", image->pixels[i][j]);
		else
			fprintf(file, "%d\n", image->pixels[i][j]);
	}
	fclose(file);

	return SUCCESS_PGM;
}

int pgm_set_pixel(pgm_t *image, int x, int y, int color)
{
	if(!image) return ERROR_PGM;
	if(x < 0 || x > image->width) return ERROR_PGM;
	if(y < 0 || y > image->height) return ERROR_PGM;
	if(color < 0 || color > MAX_COLOR_VALUE) return ERROR_PGM;

	image->pixels[y][x] = color;

	return SUCCESS_PGM;
}

int draw_line(pgm_t *image, int x_1, int y_1, int x_2, int y_2, int color)
{
	if(!image) return ERROR_PGM;

	int tan, x1, x2, y1, y2, j;
	int delta_x, delta_y;

	if(x_1 > x_2){ x1 = x_2; x2 = x_1;}
	else{ x1 = x_1; x2 = x_2;}

	if(y_1 > y_2){ y1 = y_2; y2 = y_1;}
	else{ y1 = y_1; y2 = y_2;}

	delta_x = x2 - x1;
	delta_y = y2 - y1;

	if(delta_x > delta_y){
		tan = (int) (delta_y/delta_x);
		for (j = x1; j < x2; j++)
			pgm_set_pixel(image, j, y1 + tan*j, color);
	}
	else{
		tan = (int) (delta_x/delta_y);
		for (j = y1; j < y2; j++)
			pgm_set_pixel(image, x1 + tan*j, j, color);
	}


	return SUCCESS_PGM;
}


int draw_circle(pgm_t *image, int x, int y, int radius, int color)
{
	if(!image) return ERROR_PGM;
	if(radius < 0) return ERROR_PGM;

	int j;

	for(j = x - radius; j < x + radius; j++){
		pgm_set_pixel(image, j, y + sqrt(pow(radius, 2) - pow((j - x), 2)), color);
		pgm_set_pixel(image, j, y - sqrt(pow(radius, 2) - pow((j - x), 2)), color);
	}
	for(j = y - radius; j < y + radius; j++){
		pgm_set_pixel(image, x + sqrt(pow(radius, 2) - pow((j - y), 2)), j, color);
		pgm_set_pixel(image, x - sqrt(pow(radius, 2) - pow((j - y), 2)), j, color);
	}


	return SUCCESS_PGM;
}

int draw_disk(pgm_t *image, int x, int y, int radius, int color)
{
	if(!image) return ERROR_PGM;
	if(radius < 0) return ERROR_PGM;

	int i, j;

	for(i = x - radius; i < x + radius; i++){
		for(j = y - radius; j < y + radius; j++){
			if((pow(x - i, 2) + pow(y - j, 2)) <= pow(radius, 2))
				pgm_set_pixel(image, i, j, color);
		}
	}

	return SUCCESS_PGM;
}

int draw_rect(pgm_t *image, int x, int y, int width, int height, int color)
{
        if(!image) return ERROR_PGM;
      
        int i;	
	
	int x_1 = x - width/2;
	int y_1 = y - height/2;
	int y_2 = y + height/2;

	for(i = 0; i <= width; i++)
        	draw_line(image, x_1 + i, y_1, x_1 + i, y_2, color);	

        return SUCCESS_PGM;
 }

