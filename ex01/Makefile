CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = RPN

SRC = 	RPN.cpp main.cpp
	
OBJ = $(SRC: .c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CPPFLAGS)  $(OBJ) -o $(NAME)

clean:
		rm -f *.o
		rm -f ./src/*.o

fclean: clean
		rm -f $(NAME)

re: fclean all