/*
** recup_map.c for ok in /home/alexandre/Documents/balek/platform/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Fri Aug 18 21:45:10 2017 Alexandre Chamard-bois
** Last update Sat Dec 16 12:09:01 2017 alexandre Chamard-bois
*/

#include <unistd.h>
#include <fcntl.h>
#include "libmy.h"
#include "map.h"

int	__recup_color(t_myfd *fd, t_color *color, const int nb_color)
{
	my_memset(color, 0, nb_color * sizeof(t_color));
	for (int i = 0; i < nb_color; i++) {
		if (my_dscanf(fd, " %d : ", &color[i].num) != 1) {
			return (1);
		}
		if (my_dscanf(fd, " color: %d %d %d ",
		color[i].code.rgb, color[i].code.rgb + 1, color[i].code.rgb + 2) == 3) {
			color[i].type = 1;
		} else if (my_dscanf(fd, " path: %s ", color[i].code.path) == 1) {
			color[i].type = 2;
		} else {
			return (1);
		}
	}
	return (0);
}

int	__recup(t_myfd *fd, t_map *map)
{
	for (int i = 0; i < map->height; i++) {
		for (int j = 0; j < map->width; j++) {
			if (my_dscanf(fd, " %d , ", &map->map[i * map->width + j]) != 1) {
				return (1);
			}
		}
	}
	return (0);
}

int	recup_map(const char *filename, t_map *map)
{
	t_myfd *fd;
	int ret = 0;

	map->width = 0;
	map->height = 0;
	map->nb_color = 0;
	map->map = NULL;
	if (!(fd = my_open(filename, O_RDONLY))) {
		return (1);
	}
	my_dscanf(fd, " %d, %d, %d ", &map->width, &map->height, &map->nb_color);
	if (map->width <= 0 || map->height <= 0 || map->nb_color <= 0) {
		return (1);
	}
	if (!(map->map = my_malloc(map->width * map->height * sizeof(int))) ||
	!(map->color = my_malloc(map->nb_color * sizeof(t_color)))) {
		ret = 1;
	} else if (__recup_color(fd, map->color, map->nb_color) || __recup(fd, map)) {
		ret = 1;
	}
	my_close(fd);
	return (ret);
}
