#include "../inc/cub3d.h"

// ACABADA
void	init_struc(t_cubed *s, char *map_arg)
{
	int		i;

	i = 0;
	s->fd = open(map_arg, O_RDONLY);
	if (s->fd == -1)
	{
		ft_putendl_fd(MAP_READ, 2);
		exit(1);
	}
	printf("2. INIT STRUCT\n");
	s->height = -6;
	s->file = (char **)malloc(sizeof (char **) * (ft_fdhei(s->fd) + 1));
	if (!s->file)
		exit(1);
	close(s->fd);
	file_checker(s, map_arg);
}

int	main(int argc, char **argv)
{
	t_cubed	cub3d;

	args_checker(argc, argv);
	init_struc(&cub3d, argv[1]);
	get_player_init(&cub3d);
	print_data(&cub3d); //Mirarlo bien tiene que estar??
	init_window(&cub3d);
	//mlx_loop(cub3d.mx);
	//mlx_clear_window(cub3d.mx, cub3d.mw);
	//mlx_destroy_window(cub3d.mx, cub3d.mw);
	/*xml_to_img(&map);
	paint_map(&map);*/
	return (0);
}

// SI NO HAY JUGADOR EL PROGRAMA PETA