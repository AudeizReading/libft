CC=-/bin/gcc
AR=-/bin/ar crs
RM=-/bin/rm -rf
CFLAGS=-Wall -Wextra -Werror
CHEADERS=-I . 
SRC=$(addprefix ft_, $(addsuffix .c,\
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
#	isalpha\
#	isdigit\
#	isalnum\
#	isascii\
#	isprint\
#	toupper\
#	tolower\
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
#	putchar_fd\
#	putstr_fd\
#	putendl_fd\
#	putnbr_fd\
