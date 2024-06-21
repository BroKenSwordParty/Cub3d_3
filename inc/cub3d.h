#ifndef CUB3D_H
# define	CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>

# define NAME "It's made in less than 30 DAYS"

// ESTOS MACROS, que son las direcciones de los assets. De momento no se toca
# define WALL "./assets/_oseano.xpm"
# define FLOOR "./assets/_sand.xpm"
# define P "./assets/_BorderlinePirate.xpm"
# define ITEM "./assets/_item.xpm"
# define EXIT "./assets/_exit.xpm"

// Gestion de errores escrito aquí para que quede más limpio.
# define ARG_NUM "Error\nMust introduce 2 valid arguments\n"
# define ARG_INV "Error\nInvalid argument\n"
# define ARG_CUB "Error\nFile must be .cub\n"

# define F_ERR "Error\nFile error\n"
# define C_ERR "Error\nColor error\n"
# define MAP_READ "Error\nUnable to read the file\n"
# define MAP_LINE "Error\nFirst line empty\n"
# define MAP_WALL "Error\nMap must be sorrounded by walls\n"

# define MAP_PEC "Error\nMap contains invalid characters\n"
# define MAP_P2 "Error\nMap contains more than 1 Player\n"
# define MAP_P "Error\nNo PLAYER in this map\n"

# define EXIT2 "Closing the game\n"
# define WIN "YOU FOUND THE TREASURE!!!!\n"

# define SIZE 64
# define WIDTH 900
# define HEIGTH 600
# define MOVE_SPEED 0.2
# define ROT_SPEED 0.3

// Estructura para alojar las direcciones de las texturas. Usaremos una función para cargar las imagenes con las direcciones de los macros de arriba.
typedef struct s_imgs
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	**c;
	char	**f;
	char	**map;
	int 	ceiling; //ceiling color rgb
	int 	floor;   //floor color rgb
}	 		t_imgs;

// Struct para posicion del jugador y dirección del personaje
typedef struct s_player
{
	int		x; //
	int		y; //
	char	dir; //
	void	*player_dir; // ESTO NO SE SI LO USO NI SI LO VOY A USAR
	double	pos_x; //
	double	pos_y; //
	double	dir_x; //
	double	old_dir_x; //
	double	dir_y; //
	double	plane_x; //
	double	old_plane_x; //
	double	plane_y; //
}	 		t_player;

typedef struct s_mlx
{
	void 	*dir; // PUNTERO A LA PUTA MIERDA ESTA
	void	*img;
	void	*addr;//puntero a la dirección de los datos de una imagen
	int		bits_per_pixel;
	int		line_length;
	int		endian; //formato de los datos de color en la imagen
	int		w;
	int		h;
}				t_mlx;

typedef struct s_ray
{
	double	camera_x; //
	double	raydir_x; //
	double	raydir_y; //
	int		x;//
	int		y; //
	int		map_x;//
	int		map_y;//
	double	side_dist_x;//
	double	side_dist_y;//
	double	delta_dist_x;//
	double	delta_dist_y;//
	double	perp_wall_dist; // 
	int		step_x; //
	int		step_y; // 
	int		hit; //
	int		side; //
	int		line_height; // 
	int		draw_start; // 
	int		draw_end; //
	int		h;// == height
	int		tex_x; //
	int		tex_y; //
	int		tex; //
}			t_ray;

// Estructura general.
// La relacionamos con las estructuras que creemos para poder pasar toda la info de una FT a otra sin tener que pasar datos específicos.
typedef struct s_cubed
{
	ssize_t		fd;
	int		width;
	int		height;
	char		**file;
	char		*line;
	void		*mx; // Esto debería ir en otro sitio?¿?¿
	void		*mw;
	void		*mi;
	int			max_x;
	int			max_y;
	t_imgs		imgs;
	t_player	player;
	t_mlx		tex[4];
	t_mlx		mlx_s;
	//void		*mlx; //Creo que es lo mismo que mx
	//void		*window; // Creo que es lo mismo que mw
}				t_cubed;

void	args_checker(int argc, char **argv);
void	init_struc(t_cubed *s, char *map_arg);
void	create_file(t_cubed *s);
void	fill_and_check(t_cubed *s);
void	fill_map(t_cubed *s);
void	file_checker(t_cubed *s, char *map_arg);
void 	check_map(t_cubed *s);
void	init_mlx(t_cubed *s);
void	hooks(t_cubed *s);
void	f_exit(char *problem, char *to_free);
int		try_open(t_imgs *imgs);
int		check_ext(t_imgs *imgs);
int		check_colours(t_imgs *imgs);
int		check_textures(t_imgs *imgs);
int		check_sides(t_cubed *s, int i, int j);
int		validate_file(t_cubed *s);
int		inputs(int k, t_cubed *s);
int		close_map(t_cubed *s);
int		outer_lines(char *map, char player, int i);
char	*ft_strchr_array(char **array);
char	*ft_strrchr_array(char **array);

/************** RAYCASTING *************/
void	raycast_init(t_cubed *s, t_ray *ray);
void	raycast_dir(t_cubed *s, t_ray *ray);
void	raycast_hit(t_cubed *s, t_ray *ray);
void	raycast_draw_pos(t_cubed *s, t_ray *ray);
void	texturing_calculations(t_cubed *s, t_ray *ray);

/************** DRAW MAP ***************/
void	my_mlx_pixel_put(t_cubed *s, int x, int y, int color);
void	my_mlx_column_color(t_cubed *s, t_ray ray, int color);
void	print_map_ew(t_cubed *s, t_ray ray);
void	print_map_ns(t_cubed *s, t_ray ray);
void	print_map(t_cubed *s, t_ray ray);

/************* GAME MANAGER ************/
int		raycast(t_cubed *s);
void	init_window(t_cubed *s);
int		ft_input(int keycode, t_cubed *s);
int		ft_esc(t_cubed *s);

/************ DRAW TEXTURES ************/
void	print_texture(t_cubed *s, t_ray ray, double tex_pos, double step);
void	get_texture_id(t_ray *ray);
void	my_mlx_draw_column(t_cubed *s, t_ray ray, t_mlx *texture);
unsigned int	get_mlx_pixel_color(t_mlx *mlx_s, int x, int y);

/************ DRAW TERMINAL ************/
void	position_values(t_cubed *s, int i, int j);
void	change_value(t_cubed *s);
void	print_data(t_cubed *s);

/************ CAM MOVEMENTS ************/
void	cam_left(t_cubed *s);
void	cam_right(t_cubed *s);

/************* GET MOVEMENTS ***********/
void	player_a(t_cubed *s);
void	player_d(t_cubed *s);
void	player_w(t_cubed *s);
void	player_s(t_cubed *s);

/************* GET PLAYER **************/
void	get_player_init(t_cubed *s);
int		get_player_init_n(t_cubed *s, int i, int j);
int		get_player_init_s(t_cubed *s, int i, int j);
int		get_player_init_e(t_cubed *s, int i, int j);
int		get_player_init_w(t_cubed *s, int i, int j);

/************* UTILS *******************/
//void	hooks(t_cubed *s);
void	free_double_char(char **str);
void	color_rgb_ceiling(t_cubed *s);
void	color_rgb_floor(t_cubed *s);

#endif