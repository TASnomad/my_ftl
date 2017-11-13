/*
** ui.h for ftl in /home/nomad/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Thu Nov  9 10:16:44 2017 BARREAU Martin
** Last update Fri Nov 10 15:42:21 2017 BARREAU Martin
*/

#ifndef	_UI_H_
# define _UI_H_

#include	<SDL/SDL.h>

#define	SHIP_X	42
#define	SHIP_Y	42

#define	ENNEMY_X	480
#define	ENNEMY_Y	21

#define	VISIBLE	1
#define	HIDDEN	0

#define	TOGGLE_SHIP(ui, action) { if (ui) { ui->show_ship = action; refresh_ui(ui); } }
#define	TOGGLE_ENNEMY(ui, action) { if (ui) { ui->show_ennemy = action; refresh_ui(ui); } }

typedef struct	s_gui
{
  SDL_Surface	*frame;
  SDL_Surface	*ship;
  SDL_Surface	*ennemy;
  SDL_Surface	*back;
  int		show_ship;
  int		show_ennemy;
}		t_gui;

t_gui		*create_window();
int		set_background(t_gui *, char *);
int		refresh_ui(t_gui *);
int		create_sprite_ship(t_gui *, char *, int , int);
int		create_ennemy_sprite(t_gui *, char *, int, int);

#endif /* ! _UI_H_ */
