CC			:= c++
FLAG		:= -Wall -Wextra -Werror -std=c++17

DIR			:= ./
BASE		:= sorting insertion merge merge_insertion
SRC			:= $(addprefix $(DIR), $(addsuffix .c, $(BASE)))
OBJ			:= $(addprefix $(DIR), $(addsuffix .o, $(BASE)))
NAME		:= sorting

all : $(NAME) run

$(NAME): $(OBJ)
	$(CC) $(FLAG) $^ -o $@

%.o : %.cpp
	$(CC) $(FLAG) -I$(dir $<) -c $< -o $@

run : $(NAME)
	python3 -u input_generator.py
	./$(NAME) input.txt output.txt

clean :
	rm -f $(OBJ) $(NAME)

.PHONY : all clean fclean re
