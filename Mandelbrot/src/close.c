/*
** close.c for ok in /home/alexandre/Documents/balek/module_inventaire/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat Jul 15 12:39:55 2017 Alexandre Chamard-bois
** Last update Sat Dec 16 12:04:16 2017 alexandre Chamard-bois
*/

#include "libmy.h"
#include "graph.h"

void	free_sprite(t_sprite *sprite)
{
	sfTexture_destroy(sprite->texture);
	sfSprite_destroy(sprite->sprite);
	if (sprite->buff) {
		my_free(sprite->buff->pxs);
		my_free(sprite->buff);
	}
}
