#include "../inc/cub3d.h"

void	hooks(t_cubed *s)
{
	mlx_hook(s->mw, 2, 1L << 0, inputs, s);
	mlx_hook(s->mw, 17, 1L << 5, close_map, s);
}

void	init_mlx(t_cubed *s)
{
	s->width = 10;
	s->height = 10;
	s->mx = mlx_init();
	s->mw = mlx_new_window(s->mx, 640, 480, NAME);
	s->mi = mlx_new_image(s->mx, s->width, s->height);
	hooks(s);
    mlx_loop(s->mx);
}

// Cierra el mapa (Por implantar)
int	close_map(t_cubed *s)
{
	mlx_clear_window(s->mx, s->mw);
	mlx_destroy_window(s->mx, s->mw);
	ft_putendl_fd(EXIT2, 2);
	exit(0);
}

// Cuando tengamos todo pintado, seguir con las funciones de moverse.
int	inputs(int k, t_cubed *s)
{
	printf("%d\n", k);
	if (k == 119 || k == 97 || k == 115 || k == 100)
		close_map(s);// Llamar a la funcion que hace que se mueva
	if (k == 24 || k == 26)
		close_map(s); // Mover camara
	else if (k == 65307)
		close_map(s); // ESC, CERRAR
	return (0);
}