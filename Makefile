# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julmarti <julmarti@42.student.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 18:16:33 by julmarti          #+#    #+#              #
#    Updated: 2022/01/28 18:18:20 by julmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

SRCSB =       

SRCS =  pipex.c \
               
CC = gcc

AR = ar -rc

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRCS:.c=.o)

OBJB = $(SRCSB:.c=.o)

%.o : %.c
        $(CC) $(FLAGS) -I. -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
        $(AR) $(NAME) $(OBJ)

bonus : $(OBJ) $(OBJB)
        @$(AR) $(NAME) $(OBJ) $(OBJB)

clean:
        rm -f $(OBJ) $(OBJB)

fclean: clean
        rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean