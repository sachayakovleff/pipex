# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 02:23:38 by syakovle          #+#    #+#              #
#    Updated: 2023/05/24 01:00:19 by syakovle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIBFT = libft/libft.a
PRINTF = printf/printf.a

FILES	=	childs	\
			error	\
			free	\
			getcmd	\

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


.c.o: $(SRCS)
	$(CC) -g $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)
	@make all -C libft
	@make all -C printf
	$(CC) -g $(CFLAGS) ./pipex.c $(NAME) ./printf/ft_printf.a ./libft/libft.a -o pipex

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make clean -C libft
	@make clean -C printf

fclean: clean
	$(RM) $(NAME) pipex
	@make fclean -C libft
	@make fclean -C printf
	
re: clean all

.PHONY: all clean fclean re
