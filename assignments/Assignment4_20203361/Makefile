CC			:= c++
FLAG		:= -Wall -Wextra -Werror -O3 -std=c++17

DIR			:= ./
BASE		:= source_code
SRC			:= $(addprefix $(DIR), $(addsuffix .cpp, $(BASE)))
OBJ			:= $(addprefix $(DIR), $(addsuffix .o, $(BASE)))
NAME		:= graph

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $^ -o $@

%.o : %.cpp
	$(CC) $(FLAG) -I$(dir $<) -c $< -o $@

run :
	./$(NAME) input_sp.txt input_mst.txt output_sp.txt output_mst.txt

clean :
	rm -f $(OBJ) $(NAME) output_sp.txt output_mst.txt

.PHONY : all clean run
