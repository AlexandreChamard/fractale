/*
** graph.h for ok in /home/alexandre/Documents/balek/platform/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat Aug 19 11:51:56 2017 Alexandre Chamard-bois
** Last update Mon Dec 18 13:43:58 2017 alexandre Chamard-bois
*/

#ifndef GRAPH_H_
# define GRAPH_H_

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>

# include "map.h"
# include "camera.h"

# define WIDTH          300
# define HEIGHT         300

# define FPS            60

typedef struct s_buff
{
  sfUint8       *pxs;
  int           width;
  int           height;
}               t_buff;

typedef struct s_sprite
{
  sfTexture         *texture;
  sfSprite          *sprite;
  t_buff            *buff;
}     t_sprite;

typedef struct      s_box
{
  sfRenderWindow    *window;
  int               close;
  t_sprite          background;
  t_map             map;
  t_camera          camera;
}                   t_box;

// INIT //
void  clear_buff(t_buff *buff);
int   init_sprite(t_sprite *sprite, const int width, const int height);
int   init_box(t_box *box);

// CLOSE //
void free_sprite(t_sprite *);

int  get_input(t_box *box);

// PRINT //
void	draw(t_box *box);
void print_map(t_box *box);
void print_chunk(t_box *box, int x, int y);

#endif
