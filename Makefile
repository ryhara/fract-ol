# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 10:16:07 by ryhara            #+#    #+#              #
#    Updated: 2023/08/03 17:56:10 by ryhara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS =  main.c hooks.c mandelbrot.c ft_strcmp.c julia.c
OBJS = $(SRCS:%.c=$(OBJDIR)%.o)
OBJDIR = ./obj/
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

all : $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	make -C ./mlx/
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit  -o $@ $^

$(OBJDIR):
	mkdir obj

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) -Imlx -o $@ -c $<

clean :
	make clean -C ./mlx/
	$(RM) $(OBJDIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re