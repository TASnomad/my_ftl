/*
** main.c for ftl in /home/nomad/C/ftl/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Mon Nov  6 09:14:45 2017 BARREAU Martin
** Last update Fri Nov 10 17:06:02 2017 BARREAU Martin
*/

#include	"ftl.h"
#include	"utils.h"
#include	"ui.h"
#include	"libmy.h"
#include 	<stdlib.h>
#include	<time.h>
#include	<SDL/SDL.h>

void		clean_up(t_gui *ui, t_ship *ship)
{
  if (ui)
    {
      SDL_FreeSurface(ui->back);
      SDL_FreeSurface(ui->ship);
      SDL_FreeSurface(ui->ennemy);
      free(ui);
    }
  free(ship->nav);
  free(ship->driver);
  free(ship->weapon);
  free(ship);
}

void		init(t_gui *ui, t_ship *ship)
{
  set_background(ui, "assets/back.bmp");
  create_sprite_ship(ui, "assets/ship.bmp", SHIP_X, SHIP_Y);
  create_ennemy_sprite(ui, "assets/ennemy.bmp", ENNEMY_X, ENNEMY_Y);
  craft_ship(ship);
}

int		main()
{
  t_gui		*ui;
  t_ship	*ship;

  ui = create_window();
  ship = create_ship();
  init(ui, ship);
  srandom(time(NULL));
  play(ship, ui);
  if (ship->hull <= 0)
    {
      warning_print("Mayday ! Mayday ! Mayday !\n");
      error_print("Vaisseau detruit !\nGAME OVER !\n");
    }
  if (ship->driver->energy == 0 && ship->nav->sector < 10)
    {
      warning_print("Mayday ! Mayday ! Mayday !\n");
      error_print("Plus d'energie pour avancer plus loin !\nGAME OVER !\n");
    }
  if (ship->nav->sector == 10)
    info_print("Vous avez attein le dernier secteur!\nVous avez gagne !\n");
  clean_up(ui, ship);
  SDL_Quit();
  return (0);
}
