int    parse_colors(char *line, int color[3])
{
	char *tmp;
	char **colors;
	int idx;

	// TOOD: IMPROVE THE PARSING WITH MORE EDGE CASES FOR INPUT ERRORS
	tmp = ft_strtrim(line, " ");
	colors = ft_split(tmp, ',');
	free(tmp);
	if (double_pointer_len(colors) != 3)
	{
		free_double_pointer(colors);
		return (1);
	}
	color[0] = ft_atoi(colors[0]);
	color[1] = ft_atoi(colors[1]);
	color[2] = ft_atoi(colors[2]);
	idx = -1;
	while (color[++idx])
	{
		if (color[idx] < 0 || color[idx] > 255)
			return (free_double_pointer(colors), 1);
	}
	free_double_pointer(colors);
	return (0);
}

void    parse_map(char *line, t_cube_data *cube_data)
{
	int     map_size;
	char    **tmp;
	int     idx;

	if (cube_data->map != NULL)
		map_size = double_pointer_len(cube_data->map);
	else
		map_size = 0;

	cube_data->max_y = map_size;
	tmp = ft_calloc(sizeof(char *), (map_size + 2));
	idx = -1;
	while (++idx < map_size)
		tmp[idx] = cube_data->map[idx];
	tmp[idx] = ft_strtrim(line, "\n");
	free(cube_data->map);
	cube_data->map = tmp;
}

int parse_line(char *line, t_cube_data *cube_data)
{
	int error;

	error = 0;
	if (!line)
		return (1);
	if (!error && ft_strncmp("NO ", line, 3) == 0)
		cube_data->north_texture = line_content(line);
	else if (!error && ft_strncmp("SO ", line, 3) == 0)
		cube_data->south_texture = line_content(line);
	else if (!error && ft_strncmp("WE ", line, 3) == 0)
		cube_data->west_texture = line_content(line);
	else if (!error && ft_strncmp("EA ", line, 3) == 0)
		cube_data->east_texture = line_content(line);
	else if (!error && ft_strncmp("F ", line, 2) == 0)
		error = parse_colors(line + 1, cube_data->floor_color);
	else if (!error && ft_strncmp("C ", line, 2) == 0)
		error = parse_colors(line + 1, cube_data->ceiling_color);
	else
		parse_map(line, cube_data);
	if (error)
	{
		printf("Error parsing; wrong content\n");
		free(line);
		free_content(cube_data);
		exit(1);
	}
	// TODO: CHECK IF THE PATHS ARE VALID
	return (0);
}

char    *line_content(char *line)
{
	int idx;

	idx = 2;

	while (line[++idx])
	{
		if (!ft_isspace(line[idx]))
			break;
	}
	return (ft_substr(line, idx, ft_strlen(line) - idx));
}

int read_file(char *file, t_cube_data *cube_data)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Can't read the file\n"), 1);
	line = get_next_line(fd);
	if (!line)
		return (ft_printf("File is empty\n"), 1);
	parse_line(line, cube_data);
	free(line);
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			continue;
		}
		parse_line(line, cube_data);
		free(line);
	}
	close(fd);
	return (0);
}

void replace_tabs_with_spaces(char ***map)
{
	int 	idx;
	int 	idx2;
	char 	*new_line;
	char 	*tmp;
	char 	*to_append;

	idx = -1;
	while ((*map)[++idx])
	{
		new_line = ft_strdup("");
		idx2 = -1;
		while ((*map)[idx][++idx2])
		{
			if ((*map)[idx][idx2] == '\t')
				to_append = ft_strdup("    ");
			else
				to_append = ft_sprintf("%c", (*map)[idx][idx2]);
			tmp = ft_strdup(new_line);
			free(new_line);
			new_line = ft_sprintf("%s%s", tmp, to_append);
			free(tmp);
			free(to_append);
		}
		free((*map)[idx]);
		(*map)[idx] = new_line;
	}
}


int validate_file(t_cube_data *cube_data)
{
	if (!cube_data->north_texture || !cube_data->south_texture || !cube_data->west_texture || !cube_data->east_texture)
		return (ft_printf("Missing texture\n"), 1);
	if (cube_data->floor_color[0] < 0 || cube_data->floor_color[1] < 0 || cube_data->floor_color[2] < 0)
		return (ft_printf("Invalid floor color\n"), 1);
	if (cube_data->ceiling_color[0] < 0 || cube_data->ceiling_color[1] < 0 || cube_data->ceiling_color[2] < 0)
		return (ft_printf("Invalid ceiling color\n"), 1);
	if (!cube_data->map)
		return (ft_printf("Missing map\n"), 1);
	return (0);
}

int validate_top_bottom(char *line)
{
	int idx;

	idx = -1;
	while (line[++idx] && line[idx] != '\n')
	{
		if (!(line[idx] == ' ' || line[idx] == '1'))
			return (ft_printf("Invalid map top || bottom:\n\t%s\n", line), 1);
	}
	return (0);
}

void    set_initial_position(t_player_position *player_position, int x, int y, char orientation)
{
	player_position->x = x;
	player_position->y = y;
	player_position->orientation = orientation;
	printf("Start position: %d, %d, %c\n", player_position->x, player_position->y, player_position->orientation);
}

int validate_neighbors(char **map, int x, int y)
{
	int map_len = double_pointer_len(map);
	int line_len = (int)ft_strlen(map[y]);

	if (map[y][x] && ft_strchr("0NSWE", map[y][x]))
	{
		if (y > 0 && (int)ft_strlen(map[y-1]) - 1 < x)
			return (printf("Invalid map line. Not closed:\n\t%s\n\t%s <-\n", map[y - 1], map[y]), 1);
		if (x > 0 && map[y][x-1] == '\0')
			return (printf("Invalid map line. Not closed:\n\t%s\n", map[y]), 1);
		if (y < map_len - 1 && (int)ft_strlen(map[y+1]) - 1 < x)
			return (printf("Invalid map line. Not closed:\n\t%s <-\n\t%s\n", map[y], map[y+1]), 1);
		if (x < line_len - 1 && map[y][x+1] == '\0')
			return (printf("Invalid map line: %s\n", map[y]), 1);
		if (y > 0 && map[y-1][x] && map[y-1][x] == ' ')
			return (printf("Invalid map line. Not closed:\n\t%s\n\t%s <-\n", map[y - 1], map[y]), 1);
		if (x > 0 && map[y][x-1] && map[y][x-1] == ' ')
			return (printf("Invalid map line. Not closed:\n\t%s\n", map[y]), 1);
		if (y < map_len - 1 && map[y+1][x] && map[y+1][x] == ' ')
			return (printf("Invalid map line. Not closed:\n\t%s <-\n\t%s\n", map[y], map[y+1]), 1);
		if (x < line_len - 1 && map[y][x+1] && map[y][x+1] == ' ')
			return (printf("Invalid map line: %s\n", map[y]), 1);
	}
	return (0);
}
int validate_line(char **map, int y, t_player_position *player_position)
{
	int x;
	char *line;

	x = -1;
	line = map[y];
	while (line[++x] && ft_isspace(line[x]))
		;
	if (line[x] != '1' || line[ft_strlen(line) - 1] != '1')
		return (ft_printf("Invalid map line:\n\t%s\n", line), 1);
	while (line[++x])
	{
		if (!ft_strchr(" 01", line[x]))
		{
			if (ft_strchr("NSWE", line[x]))
			{
				if (player_position->orientation)
					return (ft_printf("Multiple start positions\n"), 1);
				set_initial_position(player_position, x, y, line[x]);
			}
			else
				return (ft_printf("Invalid map line:\n\t%s\n", line), 1);
		}
		if (validate_neighbors(map, x, y))
			return (1);
	}
	return (0);
}

int validate_map(t_cube_data *cube_data, t_player_position *player_position)
{
	int idx;
	int max_y;

	max_y = double_pointer_len(cube_data->map);
	idx = 0;
	if (max_y <= 0)
		return (ft_printf("Invalid map y\n"), 1);
	while (cube_data->map[++idx])
	{
		if (ft_strlen(cube_data->map[idx]) <= 0)
			return (ft_printf("Invalid map x\n Cube data map[%s] with idex %d",cube_data->map[idx],idx),1);
		if ((idx == 0 || idx == max_y - 1) && validate_top_bottom(cube_data->map[idx]))
			return (1);
		if (validate_line(cube_data->map, idx, player_position))
			return (1);
	}
	return (0);
}