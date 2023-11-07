NAME		=	Weapon

OBJ_DIR		=	./.obj/

SRCS		=   main.cpp Weapon.cpp	HumanA.cpp	HumanB.cpp

OBJS        =	$(addprefix $(OBJ_DIR),$(notdir $(SRCS:.cpp=.o)))

CC			=	g++

RM			=	rm -rf

FLAGS		=	-Wall -Wextra -Werror -g -std=c++98

MAKEFLAGS	+=	--silent

CLR_RMV		=	\033[0m
RED		    =	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
CYAN 		=	\033[1;36m


${OBJ_DIR}%.o:	%.cpp
				@mkdir -p ${OBJ_DIR}
				${CC} ${FLAGS} -c $< -o $@

${NAME}:		${OBJS}
				@echo "${GREEN}Compilation ${CLR_RMV}of ${YELLOW}${NAME} ${CLR_RMV}..."
				${CC} ${FLAGS} ${OBJS} -o ${NAME}
				@echo "${GREEN}${NAME} created[0m ✔️"

all:			${NAME}

clean:
				@ echo "${RED}Deleting ${CYAN}${NAME} ${CLR_RMV}objs ✔️"
				@${RM} ${OBJ_DIR}


fclean:			clean
				@ echo "${RED}Deleting ${CYAN}${NAME} ${CLR_RMV}binary ✔️"
				@${RM} ${NAME}

re:				fclean all

run:			all
				./${NAME}

.PHONY:			all clean fclean re bonus