/*
** damage.c for ftl in /home/nomad/C/ftl/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Wed Nov  8 12:52:36 2017 BARREAU Martin
** Last update Fri Nov 10 13:15:40 2017 BARREAU Martin
*/

#include	"ftl.h"
#include	"libmy.h"
#include	"damage.h"
#include	"utils.h"
#include	<stdlib.h>

int		my_hit(t_ship *ship)
{
  int		rng;

  rng = random() % 100;
  if (rng < 20)
    {
      rng = random() % 3;
      if (rng == 0)
	{
	  error_print("\nArme HS, impossible de tirer !\n");
	  free(ship->weapon->system_state);
	  ship->weapon->system_state = my_strdup("offline");
	}
      if (rng == 1)
	{
	  error_print("\nMoteur HS, impossible de faire un jump !\n");
	  free(ship->driver->system_state);
	  ship->driver->system_state = my_strdup("offline");
	}
      if (rng == 2)
	{
	  error_print("\n\n");
	  free(ship->nav->system_state);
	  ship->weapon->system_state = my_strdup("offline");
	}
    }
  return 0;
}

void		print_rebel(t_ship *ship)
{
  info_print("\nVie restante de l'ennemi: \n");
  my_put_nbr(ship->hull);
  my_putchar('\n');
  info_print("\nPuissance de l'arme ennemie: \n");
  my_put_nbr(ship->weapon->damage);
  my_putchar('\n');
  my_putchar('\n');
}
