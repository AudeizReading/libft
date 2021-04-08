# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alellouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 08:35:31 by alellouc          #+#    #+#              #
#    Updated: 2021/04/08 17:17:16 by alellouc         ###   ########.fr        #
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
		cntwds\
		memcpy\
		memccpy\
		memchr\
		memmove\
		memcmp\
		strlen\
		intlen\
		isalpha\
		isdigit\
		isalnum\
		isascii\
		isprint\
		isspace\
		isneg\
		ischarset\
		toupper\
		tolower\
		strncmp\
		strchr\
		strrchr\
		strlcpy\
		strlcat\
		strnstr\
		atoi\
		strdup\
		calloc\
		substr\
		strjoin\
		strshift\
		strtrim\
		itoa\
		strmapi\
		split\
		putchar_fd\
		putstr_fd\
		putendl_fd\
		putnbr_fd\
	))
BONUS_SRC=$(addprefix ft_, $(addsuffix .c,\
		  lstnew\
		  lstadd_front\
		  lstsize\
		  lstlast\
		  lstadd_back\
		  lstdelone\
		  lstclear\
		  lstiter\
		  lstmap\
		  ))
OBJ=$(SRC:.c=.o)
BONUS_OBJ=$(BONUS_SRC:.c=.o)
NAME=libft.a

.PHONY: clean fclean re all bonus

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(HEADERS) $(CFLAGS) -c $^
	$(AR) $@ $(OBJ)
	$(MAKE) clean

bonus: $(NAME)
	$(CC) $(HEADERS) $(CFLAGS) -c $(BONUS_SRC)
	$(AR) $^ $(BONUS_OBJ)
	$(MAKE) clean

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
