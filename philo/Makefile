# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 20:43:27 by ayael-ou          #+#    #+#              #
#    Updated: 2023/09/13 20:49:55 by ayael-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./srcs

SRCS	= main.c action.c death.c get.c init.c routine.c time.c utils.c


OBJS			=	$(addprefix $(SRC_DIR)/, $(SRCS:%.c=%.o))

NAME			=	philo

CC				=	gcc -pthread

CC2				=	gcc -pthread -g3

CC1				=	gcc -pthread -fsanitize=thread

CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all:		${NAME}

ff :	$(OBJS)
	$(CC1) -o $(NAME) $(OBJS)

g3 :	$(OBJS)
	$(CC2) -o $(NAME) $(OBJS)

bonus :		$(BONUS)
				rm -f $(NAME)

clean:
	${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
