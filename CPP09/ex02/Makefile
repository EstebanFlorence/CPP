NAME		=	PmergeMe

OBJ_DIR		=	./.obj/

SRCS		=   main.cpp PmergeMe.cpp

OBJS        =	$(addprefix $(OBJ_DIR),$(notdir $(SRCS:.cpp=.o)))

CXX			=	c++

RM			=	rm -rf

CXXFLAGS	=	-Wall -Wextra -Werror -Wconversion -g -std=c++98

ARGS		=	`shuf -i 1-1000 -n 3000 | tr "\n" " " `


MAKEFLAGS	+=	--silent


${OBJ_DIR}%.o:	%.cpp
				@mkdir -p ${OBJ_DIR}
				${CXX} ${CXXFLAGS} -c $< -o $@

${NAME}:		${OBJS}
				@echo "Compilation of ${NAME} ..."
				${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}
				@echo "${NAME} created[0m ✔️"

all:			${NAME}

clean:
				@ echo "Deleting ${NAME} objs ✔️"
				@${RM} ${OBJ_DIR}


fclean:			clean
				@ echo "Deleting ${NAME} binary ✔️"
				@${RM} ${NAME}

re:				fclean all

run:			re
				./${NAME} ${ARGS}

.PHONY:			all clean fclean re bonus