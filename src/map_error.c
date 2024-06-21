#include "../inc/cub3d.h"


// Pone todo el mapa en una línea y comprueba todos los caracteres para que no haya de más. NO LO ESTAMOS USANDO NI CREO QUE HAGA FALTA
void	line_error(t_cubed *s)
{
	int	i;
	int	p;

	p = 0;
	i = 0;
	while (s->line[i])
	{
		if ((s->line[i] != '1') && (s->line[i] != '0') && (s->line[i] != 'N'
			) && (s->line[i] != 'S') && (s->line[i] != 'E') && (s->line[i] != 'W'))
			f_exit(MAP_PEC, s->line);
		else if (s->line[i] == 'N' || s->line[i] == 'S' || s->line[i] == 'E' || s->line[i] == 'W')
			p++;
		i++;
	}
	if (p > 1)
		f_exit(MAP_P2, s->line);
}


// Libera lo que le envíes como segundo parámetro e imprime el primero.
void	f_exit(char *problem, char *to_free)
{
	ft_putendl_fd(problem, 2);
	free(to_free);
	exit (0);
}

