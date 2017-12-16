/*
** map.c for ok in /home/alexandre/Documents/balek/platform/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat Aug 19 18:49:22 2017 Alexandre Chamard-bois
** Last update Sat Dec 16 12:19:50 2017 alexandre Chamard-bois
*/

#include "graph.h"
#include "macro.h"
#include <stdio.h>

static void	__parcourt_map(t_box *box, int points[2][2])
{
	for (int y = points[0][1]; y <= points[1][1]; y++) {
		for (int x = points[1][0]; x <= points[0][0]; x++) {
			print_chunk(box, x, y);
		}
	}
}

void	print_map(t_box *box)
{
	static const float sx = WIDTH / 2.0 / SIZE_BLOCK;
	static const float sy = HEIGHT / 2.0 / SIZE_BLOCK;
	float mx = sx / box->camera.zoom;
	float my = sy / box->camera.zoom;
	int points[2][2];

	points[0][0] = MIN(box->camera.x + mx, box->map.width);
	points[0][1] = MAX(0, box->camera.y - my);
	points[1][0] = MAX(0, box->camera.x - mx);
	points[1][1] = MIN(box->camera.y + my, box->map.height);
	__parcourt_map(box, points);
	// printf("p1:[%d, %d]\tp2:[%d, %d]\n",
	//         points[0][0], points[0][1], points[1][0], points[1][1]);
	// sleep(1);
}
