/*
0;95;0c** air_sched.c for ftl in /home/nomad/C/ftl/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Mon Nov  6 09:03:18 2017 BARREAU Martin
** Last update Wed Nov  8 10:30:32 2017 BARREAU Martin
*/

#include	"ftl.h"
#include	"libmy.h"
#include	<stdlib.h>

int		add_navigation_tools_to_ship(t_ship *ship)
{
  t_navigation_tools	*nav;

  nav = (t_navigation_tools *) malloc (sizeof(t_navigation_tools));
  my_putstr("ajout des outils de navigations...\n");
  if (!nav)
    {
      my_putstr("votre vaisseau a explose lorsque vous avez pose les outils de navigations\n");
      return (0);
    }
  nav->sector = 0;
  nav->detect_remaining = 1;
  nav->evade = 25;
  nav->system_state = my_strdup("online");
  ship->nav = nav;
  my_putstr("les outils de navigations ont ete ajoutes avec succes!\n");
  return (1);
}

int		add_ftl_drive_to_ship(t_ship *ship)
{
  t_ftl_drive *driver;

  my_putstr("ajout du reacteur en cours...\n");
  driver = (t_ftl_drive *) malloc(sizeof(t_ftl_drive));
  if (!driver)
    {
      my_putstr("votre vaisseau a explose lorsque vous avez pose le reacteur\n");
      return (0);
    }
  driver->system_state = my_strdup("online");
  driver->energy = 10;
  ship->driver = driver;
  my_putstr("le reacteur a ete ajoute avec succes!\n");
  return (1);
}

int     	add_weapon_to_ship(t_ship *ship)
{
  t_weapon	*new;
  
  my_putstr("ajout des armes en cours...\n");
  new = (t_weapon *) malloc(sizeof(t_weapon));
  if (!new)
    {
      my_putstr("votre vaisseau a explose quand vous avez tente d'ajouter les armes\n");
      return (0);
    }
  new->damage = 10;
  new->system_state = my_strdup("online");
  ship->weapon = new;
  my_putstr("les armes on ete ajoutes avec succes!\n");
  return (1);
}

t_ship		*create_ship()
{
  t_ship	*spaceship;

  my_putstr("construction du vaisseau en cours...\n");
  spaceship = (t_ship *) malloc(sizeof(t_ship));
  if (!spaceship)
    {
      my_putstr("le vaisseau n'a pas pu etre construit par manque de materiaux\n");
      return (NULL);
    }
  my_putstr("amelioration du vaisseau termine!\n");
  spaceship->hull = 50;
  spaceship->kill = 0.0f;
  spaceship->weapon = NULL;
  spaceship->driver = NULL;
  spaceship->nav = NULL;
  return (spaceship);
}

void		craft_ship(t_ship *ship)
{
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);
}
