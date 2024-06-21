#include "../inc/cub3d.h"

// la funcion found player recibe una string (linea del mapa) y comprueba si hay "jugador".
// deberia llamarla cada linea en check map y si hay jugador poner la letra y un contador para saber si hay más de uno

void	fill_map(t_cubed *s)
{
	int		i;
	int		j;
	char	*temp;

	i = 5;
	j = -1;
	printf("6. FILL MAP -------- HAGO FREE\n");
	s->imgs.map = (char **)malloc(sizeof(char *) * (s->height + 1));
	while (s->file[++i])
	{
		printf("%s\n", s->file[i]);
		s->imgs.map[++j] = ft_strdup(s->file[i]);
		free(s->file[i]);
	}
	free(s->file);
	temp = ft_strchr_array(s->imgs.map);
	if (temp == NULL)
		exit(1); // NO PLAYER
	s->player.dir = *temp; // CHECK THIS QUE NO SE SI FUNCION
}

int	check_sides(t_cubed *s, int i, int j)
{
	if (s->imgs.map[i][0] == s->player.dir || s->imgs.map[i][0] == '0')
		return(printf("RETORNO 1\n"), 1);
	if ((s->imgs.map[i][j] == s->player.dir || s->imgs.map[i][j] == '0') && s->imgs.map[i][j + 1] == '\0')
		return(printf("RETORNO 2\n"), 1);
	if (s->imgs.map[i - 1][j] && (s->imgs.map[i - 1][j] != '0' && s->imgs.map[i - 1][j] != '1' && s->imgs.map[i - 1][j] != s->player.dir))
		return(printf("RETORNO 3\n"), 1);
	if (s->imgs.map[i + 1][j] && (s->imgs.map[i + 1][j] != '0' && s->imgs.map[i + 1][j] != '1' && s->imgs.map[i + 1][j] != s->player.dir))
		return(printf("RETORNO 4\n"), 1);
	return (0);
}
// esta funcion mira la primera y ultima linea y comprueba los caracteres
int	outer_lines(char *map, char player, int i)
{
	printf("OUTER LINES\n");
	while(map[++i])
	{
		if (map[i] == player || map[i] == '0')
			return 1;
	}
	return 0;
}
// CHEQUEO EL MAPA
void check_map(t_cubed *s)
{
	int	i;
	int	j;

	i = 0;
	printf("CHECK MAP\n");
	if (outer_lines(s->imgs.map[0], s->player.dir, -1) == 1 || \
		outer_lines(s->imgs.map[s->height - 1], s->player.dir, -1) == 1 )// es la primera/ultima linea
		exit(1); // AQUI LIBERAR Y SALIR
	while (++i < (s->height - 1))// leo el mapa, tengo que hacer un doble bucle
	{
		// AQUI COMPRUEBO CADA LINEA DIRECTAMENTE (LAS DEL MEDIO)
		// printf("LINEA A COMPROBAR------> %s\n", s->imgs.map[i]);
		if (ft_strstr(s->imgs.map[i], " 0") || ft_strstr(s->imgs.map[i], "0 ") || \
		ft_strstr(s->imgs.map[i], " N") || ft_strstr(s->imgs.map[i], "N "))
			exit(printf("HE SALIDO POR STRSTR\n"));
		j = 0;
		while(s->imgs.map[i][++j])
		{
			if (i > 0 && i < (s->height - 1) && (s->imgs.map[i][j] == '0' || s->imgs.map[i][j] == s->player.dir))
			{
				if (check_sides(s, i, j) == 1)
					exit(1); // HAY QUE HACER FREE MAP Y FILE
			}
		}
	}
}

//TENGO QUE LIBERAR FILE EN CUANTO PASE LAS VARIABLES A LA STRUCT