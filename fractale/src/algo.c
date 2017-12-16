/*
** algo.c for fractale in /home/alexandre/Documents/git/fractale/fractale/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Dec 16 14:38:18 2017 alexandre Chamard-bois
** Last update Sat Dec 16 14:38:19 2017 alexandre Chamard-bois
*/

#include "my.h"

void		print_patern(t_patern patern, int vpatern, int height_act)
{
  int		i;

  if (vpatern != patern.dimension - 1)
  {
    i = 0;
    while (i < patern.width)
    {
      my_putchar(' ');
      i++;
    }
  }
  else
    my_putstr(patern.patern[height_act % patern.height]);
}

int		check_this_dimension(t_patern patern, int this_dim, int i, int j)
{
  int		width_dim;
  int		height_dim;

  width_dim = my_pow(patern.width, this_dim);
  height_dim = my_pow(patern.height, this_dim);
  height_dim = i / height_dim % patern.height;
  width_dim = (j * patern.width) / width_dim % patern.width;
  if (patern.patern[height_dim][width_dim] == '#')
    return (1);
  return (0);
}

int		verif_fractal(t_patern patern)
{
  int		i;
  int		j;
  int		dim_actual;
  int		verif_patern;

  i = 0;
  while (i < patern.height * my_pow(patern.width, patern.dimension - 1))
  {
    j = 0;
    while (j < my_pow(patern.width, patern.dimension - 1))
    {
      verif_patern = 0;
      dim_actual = 1;
      while (dim_actual < patern.dimension)
      {
        verif_patern += check_this_dimension(patern, dim_actual, i, j);
        dim_actual++;
      }
      print_patern(patern, verif_patern, i);
      j++;
    }
    my_putstr("\n");
    i++;
  }
  return (0);
}
