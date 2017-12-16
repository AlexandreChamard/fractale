/*
** my.h for ok in /home/alexandre/colle1/CPE_2016_stumper1/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Fri Apr 21 10:09:46 2017 Alexandre Chamard-bois
** Last update Fri Apr 21 10:47:15 2017 Antoine Caullet
*/

#ifndef MY_H_
# define MY_H_

typedef struct	s_patern
{
  char		**patern;
  int		width;
  int		height;
  int		dimension;
}		t_patern;

void		my_putstr(char *str);
void		my_puterr(char *str);
int		my_strlen(char *str);
int		my_pow(int nb, int power);
int		my_getnbr(char *str, int *err);
char		**my_str_to_wordtab(char *str, int width, int height);
void		free_tab(char **tab);
void		my_putchar(char c);
int		parsing(char **av, t_patern *patern);
int		recup_patern(char **av, t_patern *patern);
int		verif_fractal(t_patern patern);

#endif	/* MY_H_ */
