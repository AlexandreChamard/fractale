/*
** input.c for ok in /home/alexandre/Documents/balek/module_inventaire/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat Jul 15 12:19:35 2017 Alexandre Chamard-bois
** Last update Sat Dec 16 12:12:32 2017 alexandre Chamard-bois
*/

#include "input.h"

static int close_evt(t_box *box);

static const t_input	g_tab_input[] =
{
	{sfKeyEscape, (int (*)(void*))close_evt},
	{sfKeyUp, (int (*)(void*))move_vertical},
	{sfKeyDown, (int (*)(void*))move_vertical},
	{sfKeyRight, (int (*)(void*))move_horizontal},
	{sfKeyLeft, (int (*)(void*))move_horizontal},
	{sfKeyP, (int (*)(void*))zoom},
	{sfKeyM, (int (*)(void*))zoom},
	{sfKeyUnknown, NULL}
};

static int	close_evt(t_box *box)
{
	box->close = 1;
	return (0);
}

static void	sf_event(t_box *box)
{
	sfEvent ev;

	while (sfRenderWindow_pollEvent(box->window, &ev)) {
		if (ev.type == sfEvtClosed) {
			box->close = 1;
		}
	}
}

int		get_input(t_box *box)
{
	int last_exit = 0;
	t_input	*cur;

	cur = (t_input*) g_tab_input;
	while (cur->key != sfKeyUnknown) {
		if (sfKeyboard_isKeyPressed(cur->key) && cur->func) {
			last_exit = cur->func(box);
		}
		if (last_exit) {
			return (last_exit);
		}
		cur++;
	}
	sf_event(box);
	return (0);
}
