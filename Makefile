# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 12:51:55 by mcolas-d          #+#    #+#              #
#    Updated: 2017/10/24 05:07:47 by mcolas-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CPPFLAG = -Iinclude

RM = rm -rf

NAME = libftprintf.a

PATHSRC = ./src/
PATHLIB = ./lib/
PATHINC = ./inc/
PATHOBJ = ./obj/
PATHOBJLIB = ./obj/

INCLIST = printf.h

SRCLIST = 	ft_apply_d.c \
			ft_handle_c.c \
	  		ft_handle_d.c \
	 		ft_handle_flag.c \
	 		ft_handle_mc.c \
	  		ft_handle_md.c \
	  		ft_handle_mo.c \
	  		ft_handle_ms.c \
	  		ft_handle_mu.c \
	  		ft_handle_o.c \
	  		ft_handle_p.c \
			ft_handle_percent.c \
	  		ft_handle_s.c \
	  		ft_handle_u.c\
	  		ft_handle_x.c \
	  		ft_int_to_char.c \
	  		ft_mini_field.c \
	  		ft_pre.c \
	  		ft_printf.c \
	  		ft_set_flag.c \
	  		ft_set_flag2.c \
	  		ft_wchar.c \
			ft_check.c \

LIBLIST = 	ft_strlen.c \
	  		ft_atoi.c \
	  		ft_itoa.c \
	  		ft_intlen.c \
	  		ft_isdigit.c \
	  		ft_itoa_base_next_level.c \
	  		ft_power.c \
	  		ft_putchar.c \
	  		ft_putstr.c \
	  		ft_strcat.c \
	  		ft_strcpy.c \
	  		ft_strjoin.c \
	  		ft_strlen.c \
	  		ft_strrev.c

OBJECTLIST = $(SRCLIST:.c=.o)

OBJECTLIBLIST = $(LIBLIST:.c=.o)

SRC = $(addprefix $(PATHSRC), $(SRCLIST))
LIB = $(addprefix $(PATHLIB), $(LIBLIST))
INC = $(addprefix $(PATHINC), $(INCLIST))
OBJ = $(addprefix $(PATHOBJ), $(OBJECTLIST))
OBJLIB = $(addprefix $(PATHOBJLIB), $(OBJECTLIBLIST))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	ar rc $(NAME) $(OBJ) $(OBJLIB)
	ranlib $(NAME)

$(PATHOBJ)%.o: $(PATHSRC)%.c
	@mkdir $(PATHOBJ) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(PATHOBJLIB)%.o: $(PATHLIB)%.c
	@mkdir $(PATHOBJLIB) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	$(RM) $(OBJ) $(OBJLIB)

fclean: clean
	$(RM) ./$(NAME)

re: fclean all
