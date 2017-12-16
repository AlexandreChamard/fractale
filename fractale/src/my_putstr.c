/*
** my_putstr.c for fractale in /home/alexandre/Documents/git/fractale/fractale/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Dec 16 14:38:49 2017 alexandre Chamard-bois
** Last update Sat Dec 16 14:38:50 2017 alexandre Chamard-bois
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *str)
{
	write(1, str , my_strlen(str));
}

void	my_puterr(char *str)
{
	write(2, str, my_strlen(str));
}
