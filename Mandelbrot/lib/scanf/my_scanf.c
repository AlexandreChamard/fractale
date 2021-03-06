/*
** my_scanf.c for ok in /home/alexandre/Documents/balek/platform/lib/scanf/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Fri Aug 18 22:00:08 2017 Alexandre Chamard-bois
** Last update Sun Aug 20 20:43:53 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "scanf.h"

int my_scanf(char *str, ...)
{
  static t_myfd fd = {0, 0, (t_buffer){"", 0}};
  t_format format;
  int nb_read;

  format.str = str;
  va_start(format.ap, str);
  nb_read = scan(&fd, format);
  va_end(format.ap);
  return (nb_read);
}

int my_dscanf(t_myfd *fd, char *str, ...)
{
  t_format format;
  int nb_read;

  format.str = str;
  va_start(format.ap, str);
  nb_read = scan(fd, format);
  va_end(format.ap);
  return (nb_read);
}
