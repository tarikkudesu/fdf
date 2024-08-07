#include "../headers/fdf.h"

t_fdf   *getFdf( t_fdf *fdf ) {
    static t_fdf    *__fdf;

    if (fdf)
        __fdf = fdf;
    return __fdf;
}

void	*talloc( size_t __size ) {
	void	*__ptr;
	t_heap	*__node;
	t_fdf	*__fdf;

	__fdf = getFdf(NULL);
	__ptr = malloc(__size);
	if (__ptr == NULL)
		terror(ERR_MAL);
	__node = heap_new(__ptr);
	if (!__node)
		(free(__ptr), terror(ERR_MAL));
	heap_addback(&__fdf->heap, __node);
    // printf("pointer \033[32m%p\033[0m was allocated, size : \033[32m%ld\033[0m\n", __ptr, __size);
	return (__ptr);
}
