#include "../inc/cub3d.h"

// ACABADA
int	try_open(t_imgs *imgs)
{
	int	fd;

	printf("TRY OPEN\n");
	fd = open(imgs->no, O_RDONLY);
	if (fd == -1)
		return (printf(F_ERR), 1);
	close(fd);
	fd = open(imgs->so, O_RDONLY);
	if (fd == -1)
		return (printf(F_ERR), 1);
	close(fd);
	fd = open(imgs->ea, O_RDONLY);
	if (fd == -1)
		return (printf(F_ERR), 1);
	close(fd);
	fd = open(imgs->we, O_RDONLY);
	if (fd == -1)
		return (printf(F_ERR), 1);
	close(fd);
	return(0);
}