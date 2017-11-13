/*
0;95;0c** combat.c for ftl in /home/nomad/C/ftl/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Tue Nov  7 14:14:01 2017 BARREAU Martin
** Last update Fri Nov 10 18:01:13 2017 BARREAU Martin
*/

#include	"ftl.h"
#include	"libmy.h"
#include	"utils.h"
#include	"combat.h"
#include	"damage.h"
#include	<stdlib.h>

int             wrapper_system(t_ship *ship)
{
  system_repair(ship);
  return (1);
}

int		stat_ship(t_ship *ship)
{
  my_putstr("\n----- Statistiques du vaisseau : -----\n\n");
  print_str_num("Vie restante: ", ship->hull, INFO);
  if (ship->driver)
    {
      info_print("\nPropulsion restante : ");
      my_put_nbr(ship->driver->energy);
    }
  if (ship->weapon)
    {
      info_print("\nPuissance de l'arme: ");
      my_put_nbr(ship->weapon->damage);
    }
  if (ship->nav)
    {
      info_print("\nTaux de reussite des esquives : ");
      my_put_nbr(ship->nav->evade);
    }
  my_putstr("\n\n----- Fin du rapport -----\n\n");
  return (0);
}

int		control_system(t_ship *ship)
{
  my_putstr("\n----- Rapport sur l'etat du vaisseau : -----\n\n");
  if (ship->driver)
    {
      my_putstr("Systeme de propulsion : ");
      my_putstr(ship->driver->system_state);
    }
  if (ship->weapon)
    {
      my_putstr("\n\nEtat de l'arme : ");
      my_putstr(ship->weapon->system_state);
    }
  if (ship->nav)
    {
      my_putstr("\n\nEtat de la navigation : ");
      my_putstr(ship->nav->system_state);
    }
  my_putstr("\n----- Fin du rapport -----\n\n");
  return (0);
}

int		my_attack(t_ship *ship, t_ship **rebel, t_gui *ui)
{
  if (!*rebel)
    {
      info_print("\nAucun vaisseau rebelle en vue !\n");
      return (0);
    }
  if (my_strcmp(ship->weapon->system_state, "online") != 0)
    {
      error_print("Arme HS, impossible de tirer !\n");
      return (0);
    }
  (*rebel)->hull -= ship->weapon->damage;
  info_print("\nVous avez touché l'ennemi !\n");
  if ((*rebel)->hull <= 0)
    {
      ship->kill += 0.5f;
      info_print("Vaisseau ennemi abbatu !\n");
      TOGGLE_ENNEMY(ui, HIDDEN);
      free(*rebel);
      *rebel = NULL;
      if ((random() % 2) == 1)
	{
	  info_print("Fin du combat, vous perdez une propulsion !\n");
	  ship->driver->energy -= 1;
	}
    }
  else
    print_rebel(*rebel);
  return (1);
}

int		rebel_attack(t_ship *ship, t_ship *rebel)
{
  int           rng;

  rng = random() % 101;
  warning_print("\nLe vaisseu rebelle attaque !\n");
  if (rng >= ship->nav->evade)
    {
      ship->hull -= rebel->weapon->damage;
      my_hit(ship);
      error_print("Votre vaisseau a subit des dommages !\n");
    }
  else
    info_print("Le missile ennemi a rate notre vaisseau!\n");
  return (1);
}
