# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alellouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 08:35:31 by alellouc          #+#    #+#              #
#    Updated: 2021/03/26 22:51:45 by alellouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=-gcc
AR=-ar crs
RM=-rm -rf
CFLAGS=-Wall -Wextra -Werror
CHEADERS=-I . 
SRC=$(addprefix ft_, $(addsuffix .c,\
		memset\
		bzero\
		strlen\
		isalpha\
		isdigit\
		isalnum\
		isascii\
		isprint\
		toupper\
		tolower\
		strncmp\
		atoi\
		strdup\
		putchar_fd\
		putstr_fd\
		putendl_fd\
		putnbr_fd\
	))
OBJ=$(SRC:.c=.o)
NAME=libft.a

.PHONY: clean fclean re all so cleanso

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
	
#	memcpy\
#	memmove\
#	memchr\
#	memcmp\
#	strchr\
#	strrchr\
#	strlcpy\
#	strlcat\
#	strnstr\
#	calloc\
#	substr\
#	strjoin\
#	strtrim\
#	split\
#	itoa\
#	strmapi\

