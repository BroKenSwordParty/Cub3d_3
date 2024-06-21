#include "../inc/cub3d.h"

// si la dirección de la letra JUGADOR con ft_strchr y la de JUGADOR de ft_strrchr son distintas es que hay mas de un jugador
// pero hay que hacerlas para **
char	*ft_strchr_array(char **array)
{

	int	i;
	int	j;

	i = -1;
	printf("FT_STRCHR_ARRAY\n");
	while (array[++i])
	{
		j = -1;
		while (array[i][++j])
		{
			if (array[i][j] == 'N' || array[i][j] == 'S' || array[i][j] == 'E' || array[i][j] == 'W')
				return (&array[i][j]);
		}
	}
	return (0);
}

// funcion que va hasta el final del array y hace un ft_strrchr buscando al jugador
char	*ft_strrchr_array(char **array)
{
	int	i;
	int	j;

	i = -1;
	printf("FT_STRRCHR_ARRAY DEL REVES\n");
	while (array[i])
		i++;
	while(i >= 0)
	{
		j = ft_strlen(array[i]);
		while (j-- >= 0)
		{
			if (array[i][j] == 'N' || array[i][j] == 'S' || array[i][j] == 'E' || array[i][j] == 'W')
				return (&array[i][j]);
		}
	}
	return(0);
}


/*void	hooks(t_cubed *s)
{
	mlx_hook(s->mlx.win, 2, 1L << 0, key_pressed, s);
	mlx_hook(s->mlx.win, 3, 1L << 1, key_release, s);
	mlx_hook(s->mlx.win, 6, 1L << 6, mouse_move, s);
	mlx_hook(s->mlx.win, 17, 1L << 17, destroy_window, s);
}*/

void	free_double_char(char **s)
{
	int	i;

	if (s)
	{
		i = -1;
		while (s[++i])
			free(s[i]);
		free (s);
	}
}

void	color_rgb_ceiling(t_cubed *s)
{
	int	rgb_c;

	//Inicializar a 0 rgb_c??
	rgb_c = ft_atoi(s->imgs.c[0]) << 16 | ft_atoi(s->imgs.c[1]) << 8 | ft_atoi(s->imgs.c[2]);
	s->imgs.ceiling = rgb_c;
}

void	color_rgb_floor(t_cubed *s)
{
	int	rgb_f;

	rgb_f = ft_atoi(s->imgs.f[0]) << 16 | ft_atoi(s->imgs.f[1]) << 8 | ft_atoi(s->imgs.f[2]);
	s->imgs.floor = rgb_f;
}