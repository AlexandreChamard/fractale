/*
** main.c for fractale in /home/alexandre/Documents/git/fractale/fractale/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Dec 16 14:38:23 2017 alexandre Chamard-bois
** Last update Sat Dec 16 14:38:25 2017 alexandre Chamard-bois
*/

#include "my.h"

int	main(int ac, char **av)
{
	t_patern patern;

	if (ac > 3) {
		my_puterr("Too many arguments.\n");
		return (1);
	}
	if (ac < 3) {
		my_puterr("Too few arguments.\n");
		return (1);
	}
	if (parsing(av, &patern) || recup_patern(av, &patern)) {
		return (1);
	}
	if (patern.dimension) {
		verif_fractal(patern);
	} else {
		my_putstr("#\n");
	}
	free_tab(patern.patern);
	return (0);
}
