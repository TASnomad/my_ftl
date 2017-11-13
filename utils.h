/*
** utils.h for ftl in /home/nomad/C/ftl/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Wed Nov  8 10:06:02 2017 BARREAU Martin
** Last update Wed Nov  8 13:34:54 2017 BARREAU Martin
*/

#ifndef	_UTILS_H_
# define _UTILS_H_

#define	INFO 	0
#define	WARN	1
#define	ERROR	2

void	info_print(char *);
void	warning_print(char *);
void	error_print(char *);
void	print_str_num(char *, int, int);
int	help();

#endif /*  ! _UTILS_H_ */
