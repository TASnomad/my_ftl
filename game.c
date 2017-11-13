/*
** game.c for ftl in /home/nomad/C/ftl/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Tue Nov  7 12:14:42 2017 BARREAU Martin
** Last update Fri Nov 10 17:38:14 2017 BARREAU Martin
*/

#include	"ftl.h"
#include	"ui.h"
#include	"utils.h"
#include	"sector.h"
#include	"libmy.h"
#include	"combat.h"
#include	"damage.h"
#include	<stdlib.h>

t_actions game_fcts[] = {
  { "jump", jump_ship },
  { "attack", my_attack },
  { "control_system", control_system },
  { "stat", stat_ship },
  { "detect", scan_sector },
  { "getbonus", upgrade_ship },
  { "repair_system", wrapper_system },
  { "help", help },
  { NULL, NULL }
}; 

int             exec_cmd(t_ship *ship, t_ship **rebel, char *buf, t_gui *ui)
{
  int           found;
  int           i;
  int           res;

  res = i = found = 0;
  if (!buf)
    {
      error_print("\nCommande introuvable !\n");
      return (0);
    }
  while ((*(game_fcts + i)).name && !found)
    {
      if (my_strcmp(buf, (*(game_fcts + i)).name) == 0)
	{
	  res = (*(game_fcts + i)).action(ship, rebel, ui);
	  found = 1;
	}
      i += 1;
    }
  if (!found)
    error_print("\nCommande introuvable !\n");
  if (found && res > 0 && *rebel)
    rebel_attack(ship, *rebel);
  return (res);
}

void		play(t_ship *ship, t_gui *ui)
{
  t_ship	*rebel;
  char		*buff;
  
  my_putstr("\e[1;1H\e[2J");
  my_putstr("Bienvenue sur my_FTL !\nTapez une commande pour jouer !\n");
  my_putstr("Tapez help pour connaitre les actions disponibles !\n");
  print_str_num("\nVous etes au secteur : ", ship->nav->sector, WARN);
  rebel = spawn_ennemy(ship->kill);
  if (rebel)
    {
      warning_print("\nVaisseau ennemi a 12 heures !\n");
      print_rebel(rebel);
    }
  while (ship->hull > 0 && ship->nav->sector < 10 && ship->driver->energy > 0)
    {
      my_putstr("my_FTL> ");
      buff = readline();
      refresh_ui(ui);
      exec_cmd(ship, &rebel, buff, ui);
      if (buff && my_strcmp(buff, "quit") == 0)
	ship->hull = -42;
      free(buff);
    }
  free(rebel);
}

int		jump_ship(t_ship *ship, t_ship **rebel, t_gui *ui)
{
  if (ship->driver->energy <= 0)
    return (-1);
  if (*rebel)
    {
      error_print("\nJump impossible, il y a un ennemi !\n");
      return (0);
    }
  if (my_strcmp(ship->driver->system_state, "online") != 0)
    {
      error_print("\nJump impossible, moteur HS !\n");
      return (0);
    }
  ship->driver->energy -= 1;
  ship->nav->sector += 1;
  ship->nav->detect_remaining = 1;
  if (!*rebel)
    *rebel = spawn_ennemy(ship->kill);
  print_str_num("Jump réussi !\nVous etes au secteur : ", ship->nav->sector, WARN);
  if (*rebel)
    {
      TOGGLE_ENNEMY(ui, VISIBLE);
      TOGGLE_SHIP(ui, VISIBLE);
      warning_print("Vaisseau ennemi a 12 heures !\n");
      print_rebel(*rebel);
    }
  refresh_ui(ui);
  return (0);
}

int		upgrade_ship(t_ship *ship)
{
  if (!ship->container->first)
    {
      warning_print("Aucun conteneurs en stock !\n");
      return (0);
    }
  info_print("\nRécolte des bonus en cours ...\n");
  get_bonus(ship);
  info_print("\nRécolte terminée !\n");
  return (0);
}

t_ship		*spawn_ennemy(float kill_count)
{
  int		rng;
  t_ship	*rebel;

  rng = random() % 100;
  if (rng > 30)
    return (0x0);
  rebel = (t_ship *) malloc(sizeof(t_ship));
  if (!rebel)
    return (0x0);
  rebel->hull = (int) (20 + (kill_count * 10));
  rebel->weapon = (t_weapon *) malloc(sizeof(t_weapon));
  if (!rebel->weapon)
    {
      free(rebel);
      return (0x0);
    }
  rebel->weapon->damage = (int) (10 + (kill_count * 5));
  rebel->weapon->system_state = my_strdup("online");
  return (rebel);
}
