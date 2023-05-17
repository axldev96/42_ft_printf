# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaceres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 12:43:34 by acaceres          #+#    #+#              #
#    Updated: 2023/05/15 13:34:16 by acaceres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c			\
	   ft_printf_utils.c

### COLORS ###
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m


### OBJS FOLDER ###
OBJS_DIR = objs/

## MAIN ###
OBJS			=	$(SRCS:.c=.o)
OBJS_TO_FOLDER	= 	$(addprefix $(OBJS_DIR), $(OBJS))

### COMPILED OUTPUT ###
NAME = libftprintf.a

### COMPILE COMMANDS AND FLAGS ###
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror

### REMOVE COMMAND
RM		=	rm -rf

### CREATE FOLDER & COMPILE .o ###
$(OBJS_DIR)%.o: %.c	ft_printf.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(COLOUR_BLUE)Compiling: $(COLOUR_END)$(COLOUR_GREEN)$<$(COLOUR_END)"

### COMPILE LIBRARY ###
$(NAME): $(OBJS_TO_FOLDER)
	@ar rcs $(NAME) $(OBJS_TO_FOLDER)
	@echo "$(COLOUR_GREEN)ft_printf done!$(COLOUR_END)"

### DEFINE MAKE ALL ###
all: $(NAME)
	
### MAKE CLEAN ###
clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(COLOUR_BLUE)$(OBJS_DIR)$(COLOUR_END) $(COLOUR_GREEN)cleaned!$(COLOUR_END)"

### MAKE FCLEAN ###
fclean:	clean
	@$(RM) $(NAME)

### RELINK ###
re: fclean all

### PHONY'S ###
.PHONY: all clean fclean re
