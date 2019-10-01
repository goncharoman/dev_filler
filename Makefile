# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 00:11:07 by ujyzene           #+#    #+#              #
#    Updated: 2019/10/01 11:11:58 by ujyzene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARS
NAME = ujyzene.filler

CC = gcc
FLAGS = -g -Wall -Wextra -Werror

SRCS_PATH = sources
TEMPS_PATH = temp
INCL_PATH = includes
LIB_DIR = libft
LIB = $(LIB_DIR)/libft.a

FILES = main.c \
		init.c \
		init_data1.c \
		init_data2.c \
		helpers.c \
		solve.c \
		result.c \
		free.c \
		test.c

LIBFT_INCL = -I $(LIB_DIR)/includes
LIBFT_LINK = -L$(LIB_DIR) -lft

SRCS = $(addprefix $(SRCS_PATH)/, $(FILES))
TEMPS = $(addprefix $(TEMPS_PATH)/, $(FILES:.c=.o))

# ADD
.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(LIB) $(TEMPS_PATH) $(TEMPS)
	$(CC) $(FLAGS) $(LIBFT_INCL) -I $(INCL_PATH) -o $(NAME) $(TEMPS) $(LIBFT_LINK)

$(LIB):
	make -C $(LIB_DIR)

$(TEMPS_PATH):
	mkdir -p $@

$(TEMPS_PATH)/%.o : $(SRCS_PATH)/%.c
	$(CC) $(FLAGS) -I $(INCL_PATH) $(LIBFT_INCL) -o $@ -c $<

# RULES
clean:
	rm -rf $(TEMPS_PATH)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all
