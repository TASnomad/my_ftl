/*
** utils.c for ftl in /home/nomad/C/ftl/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Wed Nov  8 10:07:41 2017 BARREAU Martin
** Last update Fri Nov 10 17:44:57 2017 BARREAU Martin
*/

#include	"utils.h"
#include	"libmy.h"

void		info_print(char *str)
{
  my_putstr("\x1b[36m");
  my_putstr(str);
  my_putstr("\x1b[0m");
}

void		warning_print(char *str)
{
  my_putstr("\x1b[33m");
  my_putstr(str);
  my_putstr("\x1b[0m");
}

void		error_print(char *str)
{
  my_putstr("\x1b[31m");
  my_putstr(str);
  my_putstr("\x1b[0m");
}

void	print_str_num(char *str, int num, int level)
{
  if (level == 0)
    info_print(str);
  if (level == 1)
    warning_print(str);
  if (level == 2)
    error_print(str);
  my_put_nbr(num);
  my_putchar('\n');
}

int             help()
{
  my_putstr("Voici les commandes disponibles:\n");
  my_putstr("\tattack: Attaquer un vaisseau ennemi\n");
  my_putstr("\tdetect: Recuperer des conteneurs spaciaux\n");
  my_putstr("\tjump: Sauter vers le secteur suivant\n");
  my_putstr("\tgetbonus: Récuperer tout les bonus collectes\n");
  my_putstr("\trepair_system: Réparer son vaisseau\n");
  my_putstr("\tsystem_control: Afficher l'etat du vaisseau\n");
  my_putstr("\tstat: Afficher les caracteristique du vaisseau\n");
  my_putstr("\tquit: Abandonner la partie en cours\n");
  my_putstr("\thelp: Afficher l'aide\n\n");
  return (0);
}
