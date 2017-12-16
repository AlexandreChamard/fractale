/*
** main.c for ok in /home/alexandre/Documents/start_project
**
** Made by alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu>
**
** Started on  Fri Jun  2 12:43:05 2017 alexandre Chamard-bois
** Last update Sat Dec 16 19:00:12 2017 alexandre Chamard-bois
*/

#include "libmy.h"
#include "graph.h"
#include <unistd.h>
#include <time.h>
#include <stdint.h>

int new_frame(struct timespec *frame_time) {
	struct timespec new_frame;
	uint64_t delta;

	clock_gettime(CLOCK_MONOTONIC_RAW, &new_frame);
	delta = (new_frame.tv_sec - frame_time->tv_sec) * 1000000 +
	(new_frame.tv_nsec - frame_time->tv_nsec) / 1000;
	if (delta >= 1000000 / FPS) {
		clock_gettime(CLOCK_MONOTONIC_RAW, frame_time);
		return (1);
	}
	usleep(1);
	return (0);
}

void loop(t_box *box) {
	struct timespec frame_time;
	// int fps = 0;
	// time_t t = time(NULL);

	clock_gettime(CLOCK_MONOTONIC_RAW, &frame_time);
	while (!box->close) {
		// if (new_frame(&frame_time)) {
			if (get_input(box)) {
				break;
			}
			sfRenderWindow_clear(box->window, sfBlack);
			clear_buff(box->background.buff);
			draw(box);
			sfTexture_updateFromPixels(box->background.texture, box->background.buff->pxs, WIDTH, HEIGHT, 0, 0);
			sfRenderWindow_drawSprite(box->window, box->background.sprite, NULL);
			sfRenderWindow_display(box->window);
			// fps++;
			// if (t != time(NULL)) {
			//     my_printf("fps: %d\n", fps);
			//     fps = 0;
			//     t = time(NULL);
			// }
		// }
	}
}

int main()
{
	t_box box;

	if (init_box(&box)) {
		return (1);
	}
	my_printf("les fleches pour bouger.\n");
	my_printf("P et M pour zommer.\n");
	loop(&box);
	sfRenderWindow_close(box.window);
	return (0);
}
