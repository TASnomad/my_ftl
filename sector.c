/*
** sector.c for ftl in /home/nomad/C/ftl/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Tue Nov  7 10:22:48 2017 BARREAU Martin
** Last update Fri Nov 10 17:58:04 2017 BARREAU Martin
*/

#include	"ftl.h"
#include	"sector.h"
#include	"utils.h"
#include	"libmy.h"
#include	<time.h>
#include	<stdlib.h>

void		print_container(t_freight **arr)
{
  int	i;

  i = 0;
  my_putstr("\n---- Collectes des containers -----\n");
  while (i < 10)
    {
      info_print("\nVous avez recupere du ");
      my_putstr((*(arr + i))->item);
      my_putchar('\n');
      i += 1;
    }
  my_putstr("\n----- Fin du rapport -----\n");
}

void		my_get_bonus(t_freight **bonus)
{
  int		rng;
  int           i;

  i = 0;
  if (!bonus)
      return ;
  while (i < 10)
    {
      *(bonus + i) = (t_freight *) malloc(sizeof(t_freight));
      rng = random() % 101;
      if (rng > 29)
	(*(bonus + i))->item = my_strdup("scrap");
      else if (rng <= 29)
	{
	  rng = random() % 3;
	  if (rng == 0)
	    (*(bonus + i))->item = my_strdup("energy");
	  if (rng == 1)
	    (*(bonus + i))->item = my_strdup("attackbonus");
	  if (rng == 2)
	    (*(bonus + i))->item = my_strdup("evadebonus");
	}
      i += 1;
    }
}

int		scan_sector(t_ship *ship)
{
  int		i;
  t_freight	**bonus;

  if (!ship->nav->detect_remaining)
    {
      warning_print("\nVous avez déjà scanné ce secteur !\n");
      return (-1);
    }
  i = 0;
  bonus =  (t_freight **) malloc(10 * sizeof(t_freight *));
  my_get_bonus(bonus);
  if (!bonus)
    return (0);
  while (i < 10)
    {
      add_freight_to_container(ship, *(bonus + i));
      i += 1;
    }
  print_container(bonus);
  ship->nav->detect_remaining -= 1;
  free(bonus);
  return (0);
}
