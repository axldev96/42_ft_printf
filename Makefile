# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaceres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 12:43:34 by acaceres          #+#    #+#              #
#    Updated: 2023/10/29 07:33:26 by acaceres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_printf.c			\
	   srcs/ft_printf_utils.c

NAME = libftprintf.a

OBJS =	$(SRCS:.c=.o)

MAIN_TARGET = all

CC = cc
C_FLAGS =	-Wall -Wextra -Werror
INC = -I includes
AR = ar
AR_FLAGS = -rcs
RM = rm -rf

%.o: %.c
	$(CC) $(C_FLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJS)

all: $(OBJS) $(NAME)
	
clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) $(MAIN_TARGET)

.PHONY: all clean fclean re
