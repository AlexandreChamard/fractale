/*
** my_getnbr.c for fractale in /home/alexandre/Documents/git/fractale/fractale/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Dec 16 14:38:29 2017 alexandre Chamard-bois
** Last update Sat Dec 16 14:38:30 2017 alexandre Chamard-bois
*/

int	my_getnbr(char *str, int *err)
{
	int nb = 0;

	while (*str >= '0' && *str <= '9') {
		nb = nb * 10 + *str - '0';
		str++;
	}
	if (*str) {
		*err = 84;
	} else {
		*err = 0;
	}
	return (nb);
}
