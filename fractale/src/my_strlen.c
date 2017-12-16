/*
** my_strlen.c for fractale in /home/alexandre/Documents/git/fractale/fractale/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Dec 16 14:39:13 2017 alexandre Chamard-bois
** Last update Sat Dec 16 14:39:17 2017 alexandre Chamard-bois
*/

int	my_strlen(char *str)
{
	int i = 0;

	while (str[i]) {
		i++;
	}
	return (i);
}
