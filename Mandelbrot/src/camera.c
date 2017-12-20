/*
** camera.c for ok in /home/alexandre/Documents/balek/platform/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat Aug 19 18:23:47 2017 Alexandre Chamard-bois
** Last update Sat Dec 16 23:46:27 2017 alexandre Chamard-bois
*/

#include "camera.h"
#include "graph.h"

int	move_vertical(t_box *box)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		box->camera.y -= SPEED * box->camera.zoom;
	} else if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		box->camera.y += SPEED * box->camera.zoom;
	}
	return (0);
}

int	move_horizontal(t_box *box)
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		box->camera.x -= SPEED * box->camera.zoom;
	} else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		box->camera.x += SPEED * box->camera.zoom;
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

int	init_camera(t_camera *camera)
{
	camera->x = 0.360240443437614363236125244;
	camera->y = -0.641313061064803174860375015179302066579494952282305259;
	camera->zoom = .000001;
	return (0);
}
