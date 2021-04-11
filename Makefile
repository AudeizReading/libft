# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alellouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 08:35:31 by alellouc          #+#    #+#              #
#    Updated: 2021/04/11 20:36:07 by alellouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ECHO=-echo
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
		nextstr\
		nextcharset\
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
	@${ECHO} "\033[1;32m"
	$(CC) $(HEADERS) $(CFLAGS) -c $^
	@${ECHO} "\033[1;36m"
	$(AR) $@ $(OBJ)
	@${ECHO} "\033[0m"
	$(MAKE) clean

bonus: $(NAME)
	@${ECHO} "\033[1;32m"
	$(CC) $(HEADERS) $(CFLAGS) -c $(BONUS_SRC)
	@${ECHO} "\033[1;36m"
	$(AR) $^ $(BONUS_OBJ)
	@${ECHO} "\033[0m"
	$(MAKE) cleanbonus

clean:
	@${ECHO} "\033[1;31m"
	$(RM) $(OBJ)
	@${ECHO} "\033[0m"

cleanbonus: 
	@${ECHO} "\033[1;31m"
	$(RM) $(BONUS_OBJ)
	@${ECHO} "\033[0m"

fclean: clean cleanbonus
	@${ECHO} "\033[1;31m"
	$(RM) $(NAME)
	@${ECHO} "\033[0m"

re: fclean all
