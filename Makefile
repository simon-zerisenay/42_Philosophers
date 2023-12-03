# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 01:04:54 by szerisen          #+#    #+#              #
#    Updated: 2023/05/07 01:04:54 by szerisen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo  

CFLAGS = -g -Wall -Wextra -Werror -pthread

RM = rm -rf
   
SRCS = 	philosophers.c build_struct.c utilities.c simulation.c timing.c operations.c

$(NAME) :
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
