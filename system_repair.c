/*
** system_repair.c for ftl in /home/nomad/C/ftl/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Mon Nov  6 12:42:44 2017 BARREAU Martin
** Last update Fri Nov 10 16:39:51 2017 BARREAU Martin
*/

#include	"ftl.h"
#include	"libmy.h"
#include	<stdlib.h>

static const t_repair_command repairs[] = {
  { "ftl_drive", ftl_drive_system_repair },
  { "navigation_tools", navigation_tools_system_repair },
  { "weapon", weapon_system_repair },
  { "hull", hull_repair },
  { NULL, NULL }
};

void		ftl_drive_system_repair(t_ship *ship)
{
  my_putstr("reparation du reacteur en cours...\n");
  free(ship->driver->system_state);
  ship->driver->system_state = my_strdup("online");
  if (!ship->driver->system_state)
    my_putstr("les reparations du reacteur ont echoue\n");
  else
    my_putstr("reparation termine! systeme reacteur OK!\n");
}

void		navigation_tools_system_repair(t_ship *ship)
{
  my_putstr("reparation du systeme de navigation en cours...\n");
  free(ship->nav->system_state);
  ship->nav->system_state = my_strdup("online");
  if (!ship->nav->system_state)
    my_putstr("les reparations des outils de navigations ont echoue\n");
  else
    my_putstr("reparation termine! systeme de navigation OK!\n");
}

void		weapon_system_repair(t_ship *ship)
{
  my_putstr("reparation du systeme d'armement en cours...\n");
  free(ship->weapon->system_state);
  ship->weapon->system_state = my_strdup("online");
  if (!ship->weapon->system_state)
    my_putstr("les reparations du systeme d'armement ont echoue\n");
  else
    my_putstr("reparation termine! systeme d'armement OK!\n");
}

void		hull_repair(t_ship *ship)
{
  if (ship->hull <= 50)
    ship->hull += 10;
}

void		system_repair(t_ship *ship)
{
  int		i;
  int		found;
  char		*buff;
  
  i = found = 0;
  my_putstr("repair_system~>");
  buff = readline();
  if (!buff)
    {
      my_putstr("[SYSTEM FAILURE] : le lecteur de commande est bloque\n");
      return ;
    }
  while (repairs[i].name && !found)
    {
      if (my_strcmp(repairs[i].name, buff) == 0)
	found = 1;
      else
	i += 1;
    }
  if (!found)
    my_putstr("[SYSTEM FAILURE] : commande inconnue\n");
  if (found)
    {
      repairs[i].repair_fct(ship);
      ship->hull += 10;
      my_putstr("Reparation terminee !\n");
    }
  free(buff);
}
