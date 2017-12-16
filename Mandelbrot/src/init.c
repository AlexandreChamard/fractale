/*
** init.c for ok in /home/alexandre/Documents/balek/wolf3d/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sun Jul  2 23:16:51 2017 Alexandre Chamard-bois
** Last update Sat Dec 16 19:00:57 2017 alexandre Chamard-bois
*/

#include <stdlib.h>
#include <string.h>
#include "libmy.h"
#include "graph.h"

void	clear_buff(t_buff *buff)
{
	my_memset(buff->pxs, 0, buff->width * buff->height * 4);
}

t_buff	*my_framebuffer_create(const int width, const int height)
{
	t_buff  *buffer;

	if (!(buffer = my_malloc(sizeof(t_buff)))) {
		return (NULL);
	}
	buffer->width = width;
	buffer->height = height;
	if (!(buffer->pxs = my_malloc(width * height * 4))) {
		my_free(buffer);
		return (NULL);
	}
	clear_buff(buffer);
	return (buffer);
}

sfRenderWindow	*create_window(const char *name, const int width, const int height)
{
	const sfVideoMode mode = {width, height, 32};
	sfRenderWindow  *window;

	window = sfRenderWindow_create(mode, name, sfClose, NULL);
	return (window);
}

int	init_sprite(t_sprite *sprite, const int width, const int height)
{
	if (!(sprite->buff = my_framebuffer_create(width, height)) ||
	!(sprite->sprite = sfSprite_create()) ||
	!(sprite->texture = sfTexture_create(width, height))) {
		return (1);
	}
	sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
	return (0);
}

int	init_box(t_box *box)
{
	box->close = 0;
	init_camera(&box->camera);
	if (!(box->window = create_window("SFML Window", WIDTH, HEIGHT))) {
		return (1);
	}
	if (init_sprite(&box->background, WIDTH, HEIGHT)) {
		return (1);
	}
	return (0);
}
