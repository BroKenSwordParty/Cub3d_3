#include "../inc/cub3d.h"

int validate_file(t_imgs *imgs)
{
	printf("VALIDATE FILE\n");
	if (check_textures(imgs) == 1)
		return (printf(F_ERR));
	if (check_colours(imgs) == 1)
		return (printf(C_ERR));
	return (0);
}
//COmprueba si existen y si tienen .xml || HECHO?
int	check_ext(t_imgs *imgs)
{
	printf("CHECK EXTENSION\n");
	if (!imgs->no || ft_strcmp(ft_strrchr(imgs->no, '.'), ".xml") == 0)
		return (1);
	if (!imgs->so || ft_strcmp(ft_strrchr(imgs->so, '.'), ".xml") == 0)
		return (1);
	if (!imgs->ea || ft_strcmp(ft_strrchr(imgs->ea, '.'), ".xml") == 0)
		return (1);
	if (!imgs->we || ft_strcmp(ft_strrchr(imgs->we, '.'), ".xml") == 0)
		return (1);
	return (0);
}

// Aqui voy a mirar a ver si las rutas empiezan por las letras NSEW //CREO QUE HECHO
int	check_textures(t_imgs *imgs)
{
	printf("CHECK TEXTURES\n");
	if(check_ext(imgs))
		return (1);
	if(ft_strchr(imgs->no, ' ') != NULL || ft_strchr(imgs->so, ' ') != NULL \
	 || ft_strchr(imgs->ea, ' ') != NULL || ft_strchr(imgs->we, ' ') != NULL)// si las rutas de los archivos tienen espacios
		return(1); // Hay que liberar
	//comprobar si los archivos existen,  y se pueden abrir
	if(try_open(imgs))
		return (1);
	return (0);
}
// CREO QUE HECHO
int check_colours(t_imgs *imgs)
{
	printf("CHECK COLOURS\n");
	if (ft_atoi(imgs->f[0]) < 0 || ft_atoi(imgs->f[1]) < 0 || ft_atoi(imgs->f[2]) < 0)
		return(1);
	if (ft_atoi(imgs->f[0]) > 255 || ft_atoi(imgs->f[1]) > 255 || ft_atoi(imgs->f[2]) > 255)
		return(1);
	if (ft_atoi(imgs->c[0]) < 0 || ft_atoi(imgs->c[1]) < 0 || ft_atoi(imgs->c[2]) < 0)
		return(1);
	if (ft_atoi(imgs->c[0]) > 255 || ft_atoi(imgs->c[1]) > 255 || ft_atoi(imgs->c[2]) > 255)
		return(1);
	return (0);
}