# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alellouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 08:35:31 by alellouc          #+#    #+#              #
#    Updated: 2021/03/29 12:29:14 by alellouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=-gcc
AR=-ar crs
RM=-rm -rf
MAKE=-make
CFLAGS=-Wall -Wextra -Werror
CHEADERS=-I . 
SRC=$(addprefix ft_, $(addsuffix .c,\
		memset\
		bzero\
		memcpy\
		memccpy\
		memchr\
		memmove\
		memcmp\
		strlen\
		isalpha\
		isdigit\
		isalnum\
		isascii\
		isprint\
		isspace\
		toupper\
		tolower\
		strncmp\
		strchr\
		strrchr\
		strlcpy\
		strnstr\
		atoi\
		strdup\
		calloc\
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
	$(MAKE) clean

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
#	strlcat\
#	substr\
#	strjoin\
#	strtrim\
#	split\
#	itoa\
#	strmapi\

