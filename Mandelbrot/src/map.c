/*
** map.c for ok in /home/alexandre/Documents/balek/platform/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat Aug 19 18:49:22 2017 Alexandre Chamard-bois
** Last update Sat Dec 16 18:05:34 2017 alexandre Chamard-bois
*/

#include "graph.h"
#include "macro.h"
#include "mymath.h"
#include <stdio.h>
#include <math.h>


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

void	draw(t_box *box)
{
	double rangeX[2] = {box->camera.x - box->camera.zoom, box->camera.x + box->camera.zoom};
	double rangeY[2] = {box->camera.y - box->camera.zoom, box->camera.y + box->camera.zoom};
	// double range[2] = {-2.5, 2.5};
	int maxiterations = 400;
	float a, b;
	float ca, cb;
	float aa, bb;
	int n;

	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			a = map(x, (double[2]){0, WIDTH}, rangeX);
			b = map(y, (double[2]){0, HEIGHT}, rangeY);

			ca = a;
			cb = b;

			n = 0;
			while (n < maxiterations) {
				aa = a * a - b * b;
				bb = 2 * a * b;
				a = aa + ca;
				b = bb + cb;
				if (a * a + b * b > 8) {
					break;
				}
				n++;
			}

			float bright = map(n, (double[2]){0, maxiterations}, (double[2]){0, 1});
			bright = map(sqrt(bright), (double[2]){0, 1.0}, (double[2]){0, 255.0});

			if (n == maxiterations) {
				bright = 0;
			}

			int pix = (x + y * WIDTH) * 4;
			box->background.buff->pxs[pix + 0] = bright;
			box->background.buff->pxs[pix + 1] = bright;
			box->background.buff->pxs[pix + 2] = bright;
			box->background.buff->pxs[pix + 3] = 255;
		}
	}
}
