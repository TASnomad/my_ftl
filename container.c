/*
0;95;0c** container.c for ftl in /home/nomad/C/ftl/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Mon Nov  6 10:22:58 2017 BARREAU Martin
** Last update Wed Nov  8 11:06:52 2017 BARREAU Martin
*/

#include	"ftl.h"
#include	"libmy.h"
#include	<stdlib.h>

int		add_container_to_ship(t_ship *ship)
{
  t_container	*cont;

  my_putstr("ajout du container en cours...\n");
  cont = NULL;
  cont = (t_container *) malloc(sizeof(t_container));
  if (!cont || !ship)
    {
      my_putstr("votre vaisseau a explose lorsque vous avez pose le container\n");
      return (0);
    }
  cont->first = NULL;
  cont->last = NULL;
  cont->nb_elem = 0;
  ship->container = cont;
  my_putstr("le container a ete ajoute avec succes!\n");
  return (1);
}

void	add_freight_to_container(t_ship *ship, t_freight *freight)
{
  if (!ship->container->first)
    {
      ship->container->first = freight;
      ship->container->last = NULL;
      ship->container->nb_elem += 1;
    }
  else
    {
      ship->container->first->prev = freight;
      freight->next = ship->container->first;
      ship->container->first = freight;
      ship->container->nb_elem += 1;
    }
}

void	del_freight_from_container(t_ship *ship, t_freight *freight)
{
  t_freight *base;

  base = ship->container->first;
  if (ship->container->nb_elem == 1 && ship->container->first == freight)
    {
      ship->container->first = NULL;
      ship->container->last = NULL;
      base = NULL;
    }
  else if (ship->container->first == freight)
    {
      base = base->next;
      base->prev = NULL;
    }
  else
    {
      while (ship->container->first != freight && ship->container->first)
	ship->container->first = ship->container->first->next;
      if (ship->container->first)
	{
	  if (!ship->container->first->next)
	    ship->container->last = NULL;
	  else
	    {
	      ship->container->first->next->prev = ship->container->first->next;
	      ship->container->first->prev->next = ship->container->first->prev;
	    }
	}
    }
  free(freight);
  ship->container->first = base;
  ship->container->nb_elem -= 1;
}

void	get_bonus(t_ship *ship)
{
  while (ship->container->first)
    {
      if (my_strcmp(ship->container->first->item, "attackbonus") == 0)
	ship->weapon->damage += 5;
      if (my_strcmp(ship->container->first->item, "evadebonus") == 0)
	ship->nav->evade += 3;
      if (my_strcmp(ship->container->first->item, "energy") == 0)
	ship->driver->energy += 1;
      del_freight_from_container(ship, ship->container->first);
    }
}
