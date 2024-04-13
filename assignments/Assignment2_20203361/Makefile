CC			:= c++
FLAG		:= -Wall -Wextra -Werror -O3 -std=c++17

DIR			:= ./
BASE		:= source_code
SRC			:= $(addprefix $(DIR), $(addsuffix .cpp, $(BASE)))
OBJ			:= $(addprefix $(DIR), $(addsuffix .o, $(BASE)))
NAME		:= sorting

all : $(NAME) run

$(NAME): $(OBJ)
	$(CC) $(FLAG) $^ -o $@

%.o : %.cpp
	$(CC) $(FLAG) -I$(dir $<) -c $< -o $@

run :
	./$(NAME) input.txt output.txt

clean :
	rm -f $(OBJ) $(NAME)

.PHONY : all clean fclean re
