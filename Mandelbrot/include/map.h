/*
** map.h for ok in /home/alexandre/Documents/balek/platform/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat Aug 19 18:35:28 2017 Alexandre Chamard-bois
** Last update Sun Aug 20 00:19:06 2017 Alexandre Chamard-bois
*/

#ifndef MAP_H_
# define MAP_H_

typedef struct   s_code_c
{
  char          path[128];
  int           rgb[3];
}               t_code_c;

typedef struct  s_color
{
  int           num;
  int           type;
  t_code_c  code;
}               t_color;

typedef struct  s_map
{
  int           width;
  int           height;
  int           nb_color;
  int           *map; // size with * height
  t_color       *color;
}               t_map;

int recup_map(const char *filename, t_map *map);

#endif
