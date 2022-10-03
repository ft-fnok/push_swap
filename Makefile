# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 18:31:50 by nlalleik          #+#    #+#              #
#    Updated: 2022/10/03 09:59:57 by nlalleik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := 		gcc

CFLAGS :=	-Wall -Werror -Wextra

PRINTF 	:=	./printf/libftprintf.a

LIBFT 	:=	./libft/libft.a

SRCS 	:=	push_swap.c \
			checks.c \
			helper.c \
			logic.c \
			logic-helpers.c \
			logic-helpers-2.c \
			statistic-helpers.c \
			lst_functions.c \

OBJS = $(@subst .c,.o,$(SRCS))

NAME = push_swap

all: $(NAME) $(PRINTF) $(LIBFT)

# %.o:%.c
	$(CC) $(CFLAGS) $(SRCS) $(PRINTF) $(LIBFT) -o $(NAME)

$(NAME): $(OBJS)
#	@ar rcs $(NAME) $(OBJS)
	@rm -f $(OBJS)
	@rm -f $(NAME)

$(PRINTF):
	@make -C ./printf
	@rm -f $(OBJS)
#	@rm -f $(NAME)

$(LIBFT):
	@make -C ./libft
	@rm -f $(OBJS)
#	@rm -f $(NAME)
		 
clean: 
	@rm -f $(OBJS)
	@make clean -C ./printf
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
	@make fclean -C ./printf
	@make fclean -C ./libft

re: fclean all

.PHONY:    all    clean    fclean    re bonus