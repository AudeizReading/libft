# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alellouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 08:35:31 by alellouc          #+#    #+#              #
#    Updated: 2021/03/23 08:35:42 by alellouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=-gcc
AR=-ar crs
RM=-rm -rf
CFLAGS=-Wall -Wextra -Werror
CHEADERS=-I . 
SRC=$(addprefix ft_, $(addsuffix .c,\
		isalpha\
		toupper\
		tolower\
		putchar_fd\
		putstr_fd\
		putendl_fd\
		putnbr_fd\
	))
OBJ=$(SRC:.c=.o)
NAME=libft.a

.PHONY: clean fclean re all 

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(HEADERS) $(CFLAGS) -c $^
	$(AR) $@ $(OBJ)
	$(RM) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
#	memset\
#	bzero\
#	memcpy\
#	memmove\
#	memchr\
#	memcmp\
#	strlen\
#	isdigit\
#	isalnum\
#	isascii\
#	isprint\
#	strchr\
#	strrchr\
#	strncmp\
#	strlcpy\
#	strlcat\
#	strnstr\
#	atoi\
#	calloc\
#	strdup\
#	substr\
#	strjoin\
#	strtrim\
#	split\
#	itoa\
#	strmapi\

