/*
** my_strstr.c for mystrstr in /home/Alex.Chamardbois/CPool/CPool_Day06
**
** Made by Alexandre Chamard-bois
** Login	 <Alex.Chamardbois@epitech.net>
**
** Started on  Mon Oct 10 14:05:37 2016 Alexandre Chamard-bois
** Last update Wed Oct 12 17:39:07 2016 Alexandre Chamard-bois
*/

static int comp(const char *str, const char *to_find)
{
  while (*to_find && *str == *to_find)
  {
    str++;
    to_find++;
  }
  if (*to_find)
    return (1);
  return (0);
}

char	my_strstr(const char *str, const char *to_find)
{
  while (*str)
  {
    while (*str && *str != *to_find)
      str++;
    if (!comp(str, to_find))
      return (*str);
    str++;
  }
	return (*str);
}
