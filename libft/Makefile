# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ujyzene <ujyzene@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 13:55:20 by ujyzene           #+#    #+#              #
#    Updated: 2019/09/29 03:15:52 by ujyzene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## COLORS ##
IGreen = "\033[0;92m"
IRed = "\033[0;91m"
IYellow = "\033[0;93m"
IBlue = "\033[0;94m"
IOff = "\033[0m"

## GENERAL ##
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = .
INCL = includes
FILES = ft_abs.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_atoi_base.c \
		ft_lstlen.c \
		ft_lstappend.c \
		ft_stnew.c \
		ft_stpop.c \
		ft_stpush.c \
		ft_stremove.c \
		ft_itoa_base.c \
		ft_uitoa_base.c \
		ft_isupper.c \
		ft_islower.c \
		ft_chcase.c \
		ft_ftoa.c \
		ft_ftoe.c \
		ft_pow.c \
		ft_lftoa.c \
		ft_strarrlen.c \
		ft_strarrdel.c \
		get_next_line.c

OBJ = $(FILES:%.c=%.o)

## COMMANDS ##
define done
@if ($(1)); \
	then \
		echo $(IGreen) "done!"$(IOff); \
	else \
		echo $(IRed) "fail!"$(IOff); \
	fi
endef

.PHONY: clean all re fclean

all : $(OBJ) $(NAME)

$(OBJ) : $(FILES)
	@echo "Files compilation ...\c"
	$(call done, $(CC) -I $(INCL) $(FLAGS) -c $(FILES))

$(NAME) : $(OBJ)
	@echo "Create $(NAME) ...\c"
	$(call done, ar rcs $(NAME) $(OBJ))
	@ranlib $(NAME)

clean :
	@echo "Obj files removing ...\c"
	$(call done, rm -rf $(OBJ))

fclean : clean
	@echo "$(NAME) removing ...\c"
	$(call done, rm -rf $(NAME))

re : fclean all
