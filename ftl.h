/*
0;95;0c0;95;0c** ftl.h for ftl in /home/nomad/C/ftl/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Mon Nov  6 08:59:30 2017 BARREAU Martin
** Last update Fri Nov 10 16:07:15 2017 BARREAU Martin
*/

#ifndef _FTL_H_
# define _FTL_H_

#include	"ui.h"

typedef struct          s_actions
{
  char                  *name;
  int                   (*action)();
} t_actions;

typedef struct		s_freight
{
  char			*item;
  struct s_freight	*next;
  struct s_freight	*prev;
} t_freight;

typedef struct		s_container
{
  t_freight		*first;
  t_freight		*last;
  int			nb_elem;
} t_container;

typedef struct		s_navigation_tools
{
  char			*system_state;
  int			sector;
  int			evade;
  int			detect_remaining;
} t_navigation_tools;

typedef struct		s_ftl_drive
{
  char			*system_state;
  int			energy;
} t_ftl_drive;

typedef struct  	s_weapon
{
  char          	*system_state;
  int           	damage;
} t_weapon;

typedef struct		s_ship
{
  int			hull;
  float			kill;
  t_weapon		*weapon;
  t_ftl_drive		*driver;
  t_navigation_tools	*nav;
  t_container		*container;
} t_ship;

typedef struct          s_repair_command
{
  char                  *name;
  void                  (*repair_fct)(t_ship *);
} t_repair_command;

t_ship  *create_ship();
void	craft_ship(t_ship *);
t_ship	*spawn_ennemy(float);

int     add_weapon_to_ship(t_ship *);
int     add_ftl_drive_to_ship(t_ship *);
int	add_navigation_tools_to_ship(t_ship *);
int	add_container_to_ship(t_ship *);

void	add_freight_to_container(t_ship *, t_freight *);
void	del_freight_from_container(t_ship *, t_freight *);
void	get_bonus(t_ship *);

void	system_control(t_ship *);

void	ftl_drive_system_repair(t_ship *);
void	navigation_tools_system_repair(t_ship *);
void	weapon_system_repair(t_ship *);
void	hull_repair(t_ship *);

void	system_repair(t_ship *);

int	stat_ship(t_ship *);
int	control_system(t_ship *);
int	jump_ship(t_ship *, t_ship **, t_gui *);
int	upgrade_ship(t_ship *);
int	help();

void	play(t_ship *, t_gui *);

#endif /* ! _FTL_H_ */
