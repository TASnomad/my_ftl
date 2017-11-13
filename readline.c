/*
** readline.c for ftl in /home/nomad/C/ftl/barrea_m
** 
** Made by BARREAU Martin
** Login   <barrea_m@etna-alternance.net>
** 
** Started on  Mon Nov  6 15:02:35 2017 BARREAU Martin
** Last update Mon Nov  6 15:06:28 2017 BARREAU Martin
*/

/*
** Cette fonction permet de récuper une ligne
** de moins de 50 caractères sur l'entrée standard.
** La fonction ne prend pas de paramètre et renvoit une chaîne
** allouée (pensez a free()).
*/
#include	<stdlib.h>
#include	<unistd.h>

char*		readline(void)
{
  int		ret;
  char		*buff;

  if ((buff = malloc((50 + 1) * sizeof(char))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  free(buff);
  return (NULL);
}
