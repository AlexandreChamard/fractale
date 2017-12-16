/*
** camera.c for ok in /home/alexandre/Documents/balek/platform/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat Aug 19 18:23:47 2017 Alexandre Chamard-bois
** Last update Sat Dec 16 18:08:11 2017 alexandre Chamard-bois
*/

#include "camera.h"
#include "graph.h"

int	move_vertical(t_box *box)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		box->camera.y -= SPEED;
	} else if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		box->camera.y += SPEED;
	}
	return (0);
}

int	move_horizontal(t_box *box)
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		box->camera.x -= SPEED;
	} else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		box->camera.x += SPEED;
	}
	return (0);
}

int	zoom(t_box *box)
{
	if (sfKeyboard_isKeyPressed(sfKeyM)) {
		box->camera.zoom /= SPEED_ZOOM;
	} else if (sfKeyboard_isKeyPressed(sfKeyP)) {
		box->camera.zoom *= SPEED_ZOOM;
	}
	return (0);
}

int	init_camera(t_camera *camera, t_map *map)
{
	camera->x = 0;
	camera->y = 0;
	camera->zoom = 1.0;
	return (0);
}
