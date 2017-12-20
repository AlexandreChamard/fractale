/*
** map.c for ok in /home/alexandre/Documents/balek/platform/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat Aug 19 18:49:22 2017 Alexandre Chamard-bois
** Last update Mon Dec 18 13:44:42 2017 alexandre Chamard-bois
*/

#include "graph.h"
#include "mymath.h"
#include <math.h>

void	draw(t_box *box)
{
	double rangeX[2] = {box->camera.x - box->camera.zoom, box->camera.x + box->camera.zoom};
	double rangeY[2] = {box->camera.y - box->camera.zoom, box->camera.y + box->camera.zoom};
	int maxiterations = 500;

	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			double a = map(x, (double[2]){0, WIDTH}, rangeX);
			double b = map(y, (double[2]){0, HEIGHT}, rangeY);

			double ca = a;
			double cb = b;

			int n = 0;
			for (; n < maxiterations; n++) {
				double aa = a * a - b * b;
				double bb = 2 * a * b;
				a = aa + ca;
				b = bb + cb;
				if (a * a + b * b > 8) {
					break;
				}
			}

			double bright = map(n, (double[2]){0, maxiterations}, (double[2]){0, 1});
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
