#include "../headers/fdf.h"

int main( int ac, char **av ) {
    t_fdf   fdf;

	if (ac != 2)
		terror(ERR_ARG);
    memset(&fdf, 0, sizeof(t_fdf));
    getFdf(&fdf);
    initFdf(&fdf, *(av + 1));
    initWindow(&fdf);
}
