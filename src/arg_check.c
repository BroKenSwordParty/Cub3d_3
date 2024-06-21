#include "../inc/cub3d.h"


// TERMINADA
void	args_checker(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd(ARG_NUM, 2);
		exit (0);
	}
	if ((ft_strlen(argv[1]) < 4) || (!ft_strrchr(argv[1], '.')))
	{
		ft_putendl_fd(ARG_INV, 2);
		exit(0);
	}
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".cub") != 0)
	{
		ft_putendl_fd(ARG_CUB, 2);
		exit(0);
	}
}
// TERMINADA
void	create_file(t_cubed *s, char *map_arg)
{
	char	*line;
	int		i;

	i = -1;
	while(1)
	{
		line = get_next_line(s->fd);
		if(line && line[0] != '\n')
		{
			s->height++;
			s->file[++i] = ft_strdup(line);
			if (!s->file[i])
				break ;
			if (ft_strchr(s->file[i], '\n'))
				*ft_strchr(s->file[i], '\n') = '\0';
		}
		if (!line)
			break;
		free(line);
	}
	s->file[++i] = '\0';
	close(s->fd);
}
// ESTA FUNCION ME SOBRA --------------------------------------
void	print_file(t_cubed *s)
{
	int i = -1;

	while (s->file[++i])
		printf("%s\n", s->file[i]);
}
// CHECKEO EL FILE QUE HE CREADO Y LOS COLORES
void	file_checker(t_cubed *s, char *map_arg)
{
	int i = 0;

	s->fd = open(map_arg, O_RDONLY);
	create_file(s, map_arg);
	fill_and_check(s);
	if (validate_file(&s->imgs) == 1)
		exit(1); // AQUI HAY QUE LIBERAR COSITAS Y NO SALIR CON EXIT ------
	fill_map(s);
	check_map(s);
	printf("CORRECT MAP\n");
}
// Llena la estructura con las direcciones de los assets y los colores
void	fill_and_check(t_cubed *s)
{	
	int i;

	i = -1;
	printf("5. FILL AND CHECK\n");
	while (++i < 6)
	{
		if (s->file[i][0] == 'N' && s->file[i][1] == 'O' && s->file[i][2] == ' ')
			s->imgs.no = ft_substr(s->file[i], 3, (ft_strlen(s->file[i]) - 3));
		if (s->file[i][0] == 'S' && s->file[i][1] == 'O' && s->file[i][2] == ' ')
			s->imgs.so = ft_substr(s->file[i], 3, (ft_strlen(s->file[i]) - 3));
		if (s->file[i][0] == 'E' && s->file[i][1] == 'A' && s->file[i][2] == ' ')
			s->imgs.ea = ft_substr(s->file[i], 3, (ft_strlen(s->file[i]) - 3));
		if (s->file[i][0] == 'W' && s->file[i][1] == 'E' && s->file[i][2] == ' ')
			s->imgs.we = ft_substr(s->file[i], 3, (ft_strlen(s->file[i]) - 3));
		if (s->file[i][0] == 'F' && s->file[i][1] == ' ')
		{
			s->imgs.f = ft_split(s->file[4], ',');
			s->imgs.f[0] = ft_substr(s->imgs.f[0], 2, (ft_strlen(s->imgs.f[0]) - 2));
		}
		if (s->file[i][0] == 'C' && s->file[i][1] == ' ')
		{
			s->imgs.c = ft_split(s->file[5], ',');
			s->imgs.c[0] = ft_substr(s->imgs.c[0], 2, (ft_strlen(s->imgs.c[0]) - 2));
		}
	}
}

void	ft_doublefree(char **s)
{
	int	i;

	i = -1;
	while(s[++i])
		free(s[i]);
	free(s);
}
