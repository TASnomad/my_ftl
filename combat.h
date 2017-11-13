/*
** combat.h for ftl in /home/nomad/C/ftl/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Tue Nov  7 13:30:50 2017 BARREAU Martin
** Last update Fri Nov 10 10:36:36 2017 BARREAU Martin
*/

#ifndef	_COMBAT_H_
# define _COMBAT_H_

#include	"ftl.h"
#include	"ui.h"

int             wrapper_system(t_ship *);
int		my_attack(t_ship *, t_ship **, t_gui *);
int		rebel_attack(t_ship *, t_ship *);

#endif /* ! _COMBAT_H_ */
