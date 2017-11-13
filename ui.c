/*
** ui.c for ftl in /home/nomad/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Thu Nov  9 10:19:15 2017 BARREAU Martin
** Last update Fri Nov 10 16:59:27 2017 BARREAU Martin
*/

#include	"ui.h"
#include	"utils.h"
#include	<SDL/SDL.h>
#include	<stdlib.h>

t_gui		*create_window()
{
  t_gui		*res;
  
  if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) < 0)
    {
      error_print("SDL ne peut pas charger les modules graphiques !\n");
      return (0x0);
    }
  res = (t_gui *) malloc(sizeof(t_gui));
  if (!res)
    return (0x0);
  res->show_ship = 0;
  res->show_ennemy = 0;
  res->frame = SDL_SetVideoMode(1020, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (!res->frame)
    {
      free(res);
      return (0x0);
    }
  SDL_WM_SetCaption("my_FTL", 0x0);
  return (res);
}

int		set_background(t_gui *ui, char *path)
{
  if (!ui)
    return (-1);
  ui->back = SDL_LoadBMP(path);
  SDL_BlitSurface(ui->back, NULL, ui->frame, NULL);
  SDL_Flip(ui->frame);
  SDL_Delay(1000);
  if (!ui->back)
    return (-1);
  return (0);
}

int		create_sprite_ship(t_gui *ui, char *path, int x, int y)
{
  SDL_Surface	*image;
  SDL_Rect	dst;

  if (!ui)
    return (-1);
  dst.x = x;
  dst.y = y;
  image = SDL_LoadBMP(path);
  ui->ship = image;
  ui->show_ship = 1;
  SDL_BlitSurface(ui->ship, 0x0, ui->frame, &dst);
  SDL_Flip(ui->frame);
  return (refresh_ui(ui));
}

int		create_ennemy_sprite(t_gui *ui, char *path, int x, int y)
{
  SDL_Surface   *image;
  SDL_Rect	dst;

  if (!ui)
    return (-1);
  dst.x = x;
  dst.y = y;
  image = SDL_LoadBMP(path);
  ui->ennemy = image;
  ui->show_ennemy = 0;
  SDL_BlitSurface(ui->ennemy, 0x0, ui->frame, &dst);
  SDL_Flip(ui->frame);
  return (refresh_ui(ui));
}

int		refresh_ui(t_gui *ui)
{
  SDL_Rect	dst;
  
  if (!ui)
    return (-1);
  SDL_FillRect(ui->frame, 0x0, SDL_MapRGB(ui->frame->format, 255, 255, 255));
  SDL_BlitSurface(ui->back, 0x0, ui->frame, 0x0);
  if (ui->show_ship)
    {
      dst.x = 50;
      dst.y = ui->frame->h / 3;
      SDL_SetColorKey(ui->ship, SDL_SRCCOLORKEY, SDL_MapRGB(ui->ship->format, 0, 0, 0));
      SDL_BlitSurface(ui->ship, NULL, ui->frame, &dst);
    }
  if (ui->show_ennemy)
    {
      dst.x = ui->frame->h;
      dst.y = ui->frame->h / 3;
      SDL_SetColorKey(ui->ennemy, SDL_SRCCOLORKEY, SDL_MapRGB(ui->ennemy->format, 0, 0, 0));
      SDL_BlitSurface(ui->ennemy, NULL, ui->frame, &dst);
    }
  SDL_Flip(ui->frame);
  return (0);
}
