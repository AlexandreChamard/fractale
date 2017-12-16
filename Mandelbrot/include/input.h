/*
** input.h for ok in /home/alexandre/Documents/balek/platform/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat Aug 19 11:55:22 2017 Alexandre Chamard-bois
** Last update Sat Aug 19 19:35:48 2017 Alexandre Chamard-bois
*/

#ifndef INPUT_H_
# define INPUT_H_

#include "graph.h"

typedef struct  s_input
{
  int           key;
  int           (*func)(void *);
}   t_input;

int move_horizontal(t_box *box);
int move_vertical(t_box *box);
int zoom(t_box *box);

#endif
