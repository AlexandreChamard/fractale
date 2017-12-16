/*
** my_pow.c for fractale in /home/alexandre/Documents/git/fractale/fractale/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Dec 16 14:38:34 2017 alexandre Chamard-bois
** Last update Sat Dec 16 14:38:35 2017 alexandre Chamard-bois
*/

int	my_pow(int nb, int power)
{
	int i = 1;
	int res = nb;

	if (!power) {
		return (1);
	}
	while (i != power) {
		res *= nb;
		i++;
	}
	return (res);
}
