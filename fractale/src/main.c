/*
** main.c for fractale in /home/alexandre/Documents/git/fractale/fractale/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Dec 16 14:38:23 2017 alexandre Chamard-bois
** Last update Sat Dec 16 14:46:03 2017 alexandre Chamard-bois
*/

#include <stdio.h>
#include "my.h"

int	main(int ac, char **av)
{
	t_patern patern;

	if (ac != 3) {
		printf("%s: size format\n", *av);
		printf("\texemple: %s 3 \"###@# #@###\"\n", *av);
		return (0);
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
