/*
** parsing.c for fractale in /home/alexandre/Documents/git/fractale/fractale/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Dec 16 14:38:11 2017 alexandre Chamard-bois
** Last update Sat Dec 16 14:38:14 2017 alexandre Chamard-bois
*/

#include "my.h"

int	recup_patern(char **av, t_patern *patern)
{
	int err;

	patern->dimension = my_getnbr(av[1], &err);
	if (err) {
		my_puterr("The dimension must be a positive number.\n");
		return (1);
	}
	patern->patern = my_str_to_wordtab(av[2], patern->width, patern->height);
	if (!patern->patern) {
		my_puterr("Error malloc.\n");
		return (1);
	}
	return (0);
}

int	verif_char(char **av, int i)
{
	if (av[2][i] != '#' && av[2][i] != ' ' && av[2][i] != '@') {
		my_puterr("Invalid caracter.\n");
		return (1);
	}
	return (0);
}

int	verif_size_line(char **av, int size_line)
{
	int i = size_line;

	while (av[2][i]) {
		if (av[2][i] != '@') {
			return (1);
		}
		i += size_line + 1;
	}
	return (0);
}

int	parsing(char **av, t_patern *patern)
{
	int nb_return = 0;
	int i = 0;

	for (; av[2][i]; i++) {
		if (verif_char(av, i)) {
			return (1);
		}
		if (av[2][i] == '@') {
			nb_return++;
		}
	}
	patern->height = nb_return + 1;
	patern->width = (i - nb_return) / patern->height;
	if (verif_size_line(av, patern->width)) {
		my_puterr("Size line differ.\n");
		return (1);
	}
	return (0);
}
