# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 10:16:07 by ryhara            #+#    #+#              #
#    Updated: 2023/08/05 18:31:47 by ryhara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCDIR = ./srcs/
SRC =  main.c hooks.c mandelbrot.c ft_strcmp.c julia.c ft_atof.c check_args.c \
		ft_print_utils.c ft_atoi.c color.c zoom.c
SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJDIR = ./obj/
OBJS = $(addprefix $(OBJDIR), $(SRC:%.c=%.o))
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
INC = -I ./includes/

all : $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	make -C ./mlx/
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit  -o $@ $^

$(OBJDIR):
	mkdir obj

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -Imlx -o $@ -c $< $(INC)

clean :
	make clean -C ./mlx/
	$(RM) $(OBJDIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

norm :
	norminette srcs
	norminette includes

.PHONY : all clean fclean re norm