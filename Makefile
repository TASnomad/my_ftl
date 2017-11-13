##
## makefile for ftl in /home/nomad/C/ftl/barrea_m
## 
## Made by BARREAU Martin
## Login   <barrea_m@etna-alternance.net>
## 
## Started on  Mon Nov  6 09:07:33 2017 BARREAU Martin
## Last update Fri Nov 10 18:26:28 2017 BARREAU Martin
##

CC = 		gcc
CFLAGS = 	-Wall -Werror -Wextra
LDFLAGS =	-L./libmy -lmy
SDL_FLAGS =	-lSDL
NAME = 		my_ftl
LIB_NAME =	libmy.a
SRC =		air_sched.c		\
		container.c		\
		system_control.c	\
		system_repair.c		\
		sector.c		\
		game.c			\
		combat.c		\
		damage.c		\
		utils.c			\
		readline.c		\
		ui.c			\
		main.c
OBJS =		$(SRC:%.c=%.o)
RM =		rm -f

all:			$(LIB_NAME) $(OBJS) $(NAME)

$(LIB_NAME):
		make -C ./libmy

$(NAME):		$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(SDL_FLAGS)

clean:
		$(RM) $(OBJS)

fclean:			clean
		make fclean -C ./libmy
		$(RM) $(NAME)

.PHONY:			all clean fclean

re:			fclean all

%.o:%.c
		$(CC) $(CFLAGS) -c $<
