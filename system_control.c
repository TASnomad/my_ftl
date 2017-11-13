/*
** system_control.c for ftl in /home/nomad/C/ftl/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Mon Nov  6 11:42:27 2017 BARREAU Martin
** Last update Mon Nov  6 11:54:12 2017 BARREAU Martin
*/

#include	"ftl.h"
#include	"libmy.h"

void		ftl_drive_system_check(t_ship *ship)
{
  my_putstr("verification du reacteur en cours...\n");
  if (my_strcmp(ship->driver->system_state, "online") == 0)
    my_putstr("reacteur OK!\n");
  else
    my_putstr("reacteur hors service!\n");
}

void		navigation_tools_system_check(t_ship *ship)
{
  my_putstr("verification du systeme de navigation en cours...\n");
  if (my_strcmp(ship->nav->system_state, "online") == 0)
    my_putstr("systeme de navigation OK!\n");
  else
    my_putstr("systeme de navigation hors service!\n");
}

void		weapon_system_check(t_ship *ship)
{
  my_putstr("verification du systeme d'armement en cours...\n");
  if (my_strcmp(ship->weapon->system_state, "online") == 0)
    my_putstr("systeme d'armement OK!\n");
  else
    my_putstr("systeme d'armement hors service!\n");
}

void		system_control(t_ship *ship)
{
  ftl_drive_system_check(ship);
  navigation_tools_system_check(ship);
  weapon_system_check(ship);
}
