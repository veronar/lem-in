# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vesingh <vesingh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 13:33:16 by vesingh           #+#    #+#              #
#    Updated: 2019/08/16 11:14:34 by vesingh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

L_DIR = ./srcs/

LIBRARY_NAME = libft.a
LIBRARY_DIR = ./libft/
LIBRARY = $(addprefix $(LIBRARY_DIR), $(LIBRARY_NAME))

FLAGS = -Wall -Werror -Wextra

LEM_FUNC =	lem-in.c\
			ft_reader.c\
			ft_do_line.c\
			ft_error.c\

LEM_FILES = $(addprefix $(L_DIR), $(LEM_FUNC))

all: $(NAME)

$(NAME): $(LIBRARY_NAME) 
	@gcc $(FLAGS) -o $(NAME) $(LEM_FILES) $(LIBRARY) 
	@echo "Lem-in Built!"

$(LIBRARY_NAME):
	@make -C $(LIBRARY_DIR)
	@echo "Libft Built!"

clean:
	@echo "Removing Objects..."
	@make clean -C $(LIBRARY_DIR)
	@echo "Clean complete!"

fclean:
	@echo "Removing Objects..."
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIBRARY_DIR)
	@echo "Fclean complete!"

re: fclean all