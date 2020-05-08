#ifndef FUNCTION_H_
#define FUNCTION_H_

//Constantes de utilização
#define MAX_IMAGE_SIZE 2000
#define MAX_COLOR_VALUE 255


//Constantes de retorno
#define SUCCESS_PGM		 0
#define ERROR_PGM 		-1

struct PGM_STRUCT
{
	char magic_number[3];
	int height;
	int width;
	int tones;
	int **pixels;
};
typedef struct PGM_STRUCT pgm_t;

void command(pgm_t *);

int pgm_create(pgm_t **, int, int);
int pgm_free(pgm_t *);


int pgm_save(pgm_t *, char *);
int pgm_set_pixel(pgm_t *, int , int , int);

int draw_line(pgm_t *, int, int, int, int, int);
int draw_circle(pgm_t *, int, int, int, int);
int draw_disk(pgm_t *, int, int, int, int);
int draw_rect(pgm_t *, int, int, int, int, int);


#endif
