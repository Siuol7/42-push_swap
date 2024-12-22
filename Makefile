NAME	:= push_swap
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror

# Additional library paths
LIBFT_DIR			:= library/libft
FT_PRINTF_FD_DIR	:= library/ft_printf_fd

# Libraries
LIBFT				:= ${LIBFT_DIR}/libft.a
FT_PRINTF_FD		:= ${FT_PRINTF_FD_DIR}/libftprintf.a

#INCLUDE
INCLUDE				:= -I ${LIBFT_DIR} -I ${FT_PRINTF_FD_DIR} -I ./includes

MANDATORY			:= ./execution/mandatory
BONUS				:= ./execution/bonus

PARSING				:= parsing
PRE_PS				:= pre_push_swap
ERROR				:= error

PARSING_C			:=	number_parsing.c	\
						parsing.c			\
						utils.c

PRE_PS_C			:= sorting.c			\

ERROR_C				:= error_parsing.c

SRCS				:= 			./execution/main.c										\
								$(addprefix	${MANDATORY}/${PARSING}/,	${PARSING_C})	\
								$(addprefix ${MANDATORY}/${PRE_PS}/,		${PRE_PS_C})	\
								$(addprefix ${MANDATORY}/${ERROR}/,		${ERROR_C})

#BONUS				:=

OBJS				:= ${SRCS:.c=.o}

#OBJS_BN			:= ${BONUS:.c=.o}

#Default Target
all:	${LIBFT_DIR} ${FT_PRINTF_FD_DIR} ${NAME}

#Compiling Rule
%.o:	%.c
	@echo "----------------------------Compiling----------------------------"
	${CC} ${CFLAGS} -o $@ -c $< ${INCLUDE}

#Create source library
${NAME}: ${OBJS} ${LIBFT} ${FT_PRINTF_FD}
		cc ${OBJS} ${LIBFT} ${FT_PRINTF_FD} -o ${NAME}

# Create bonus lib
bonus : .bonus
.bonus : ${OBJS_BN} ${LIBFT} ${FT_PRINTF_FD}
		cc ${OBJS_BN} ${LIBFT} ${FT_PRINTF_FD} -o ${NAME}
		@touch .bonus

# Clean target
clean:
		rm -f ${OBJS} ${OBJS_BN} .bonus
		$(MAKE) -C ${LIBFT_DIR} clean
		$(MAKE) -C ${FT_PRINTF_FD_DIR} clean

# Fclean target
fclean:
		@echo "----------------------------Cleaning----------------------------"
		rm -rf ${NAME} ${OBJS} ${OBJS_BN} .bonus
		$(MAKE) -C ${LIBFT_DIR} fclean
		$(MAKE) -C ${FT_PRINTF_FD_DIR} fclean
		@echo "----------------------------Finished----------------------------"

# Rebuild target
re: fclean all


.PHONY: all clean fclean re
