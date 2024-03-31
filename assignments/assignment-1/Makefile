CC			:= cc
FLAG		:= -Wall -Wextra -Werror

DIR			:= ./
BASE		:= sorting merge insertion merge_insertion
SRC			:= $(addprefix $(DIR), $(addsuffix .c, $(BASE)))
OBJ			:= $(addprefix $(DIR), $(addsuffix .o, $(BASE)))
NAME		:= sorting

all : $(NAME) run

$(NAME): $(OBJ)
	$(CC) $(FLAG) $^ -o $@

%.o : %.cpp
	$(CC) $(FLAG) -I$(dir $<) -c $< -o $@

run : $(NAME)
	./$(NAME)

clean :
	rm -f $(OBJ) $(NAME)

re : fclean all

.PHONY : all clean fclean re
