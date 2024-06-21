#include "../inc/cub3d.h"

// Libera lo que le envíes como segundo parámetro e imprime el primero.
void	f_exit(char *problem, char *to_free)
{
	ft_putendl_fd(problem, 2);
	free(to_free);
	exit (0);
}

