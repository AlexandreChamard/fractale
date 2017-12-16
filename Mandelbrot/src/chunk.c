/*
** chunk.c for ok in /home/alexandre/Documents/balek/platform/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sun Aug 20 10:48:27 2017 Alexandre Chamard-bois
** Last update Sat Dec 16 12:03:30 2017 alexandre Chamard-bois
*/

#include "graph.h"

static void	__print(t_box *box, t_code_c *color, const int x, const int y)
{
	const int size_block = SIZE_BLOCK * box->camera.zoom;
	const t_buff *buff = box->background.buff;
	int pos;

	for (int i = 0; i < size_block; i++) {
		for (int j = 0; j < size_block; j++) {
			if ((i + y) < 0 || (i + y) >= buff->height ||
			(j + x) < 0 || (j + x) >= buff->width) {
				continue;
			}
			pos = ((i + y) * buff->width + (j + x)) * 4;
			buff->pxs[pos] = color->rgb[0];
			buff->pxs[pos + 1] = color->rgb[1];
			buff->pxs[pos + 2] = color->rgb[2];
			buff->pxs[pos + 3] = 255;
		}
	}
}

static void	__print_full(t_box *box, t_code_c *color, const int x, const int y)
{
	const int size_block = SIZE_BLOCK * box->camera.zoom;
	const t_buff *buff = box->background.buff;
	int pos;

	for (int i = 0; i < size_block; i++) {
		for (int j = 0; j < size_block; j++) {
			pos = ((i + y) * buff->width + (j + x)) * 4;
			buff->pxs[pos] = color->rgb[0];
			buff->pxs[pos + 1] = color->rgb[1];
			buff->pxs[pos + 2] = color->rgb[2];
			buff->pxs[pos + 3] = 255;
		}
	}
}

static t_code_c	*__find_code_color(t_box *box, const int x, const int y)
{
	int num;

	if (x < 0 || x >= box->map.width || y < 0 || y >= box->map.height) {
		return (NULL);
	}
	num = box->map.map[y * box->map.width + x];
	for (int i = 0; i < box->map.nb_color; i++) {
		if (box->map.color[i].num == num) {
			return (&box->map.color[i].code);
		}
	}
	return (NULL);
}

void	print_chunk(t_box *box, int x, int y)
{
	const int size_block = SIZE_BLOCK * box->camera.zoom;
	t_code_c *color;

	if (!(color = __find_code_color(box, x, y))) {
		return ;
	}
	y = box->background.buff->height / 2 - (box->camera.y - y)  * size_block;
	x = box->background.buff->width / 2 - (box->camera.x - x) * size_block;
	if (x < 0 || x + size_block >= box->map.width ||
		y < 0 || y + size_block >= box->map.height) {
			__print(box, color, x, y);
		} else {
			__print_full(box, color, x, y);
		}
	}
