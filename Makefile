NAME	:= push_swap
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror

# Additional library paths
LIBFT_DIR			:= ./library/libft
FT_PRINTF_FD_DIR	:= ./library/ft_printf_fd

# Libraries
LIBFT				:= ${LIBFT_DIR}/libft.a
FT_PRINTF_FD		:= ${FT_PRINTF_FD_DIR}/libftprintf.a

#INCLUDE
INCLUDE				:= -I ${LIBFT_DIR} -I ${FT_PRINTF_FD_DIR} -I ./includes

MAIN				:= ./srcs/main
MANDATORY			:= ./srcs/mandatory
BONUS				:= ./srcs/bonus


PARSING				:= parsing
PRE_PS				:= pre_push_swap
STACK				:= stack
PS_OPS				:= ps_ops
EXECUTION			:= execution
ERROR				:= error

MAIN_C				:=	main.c				\
						utilities.c

PRE_PS_C			:= sorting.c			\

PARSING_C			:=	number_parsing.c	\
						parsing.c			\
						utils.c

STACK_C				:=	push_stack.c		\
						stack_ops.c			\
						utils.c

PS_OPS_C			:=	push.c				\
						swap.c				\
						rotate.c			\
						reverse.c

EXECUTION_C			:=	sort3.c				\
						sort5.c				\
						bigsort.c

ERROR_C				:= error_parsing.c

SRCS				:= 			$(addprefix ${MAIN}/,					${MAIN_C})			\
								$(addprefix	${MANDATORY}/${PARSING}/,	${PARSING_C})		\
								$(addprefix ${MANDATORY}/${PRE_PS}/,	${PRE_PS_C})		\
								$(addprefix ${MANDATORY}/${STACK}/,		${STACK_C})			\
								$(addprefix ${MANDATORY}/${PS_OPS}/,	${PS_OPS_C})		\
								$(addprefix ${MANDATORY}/${EXECUTION}/, ${EXECUTION_C})		\
								$(addprefix ${MANDATORY}/${ERROR}/,		${ERROR_C})

#BONUS				:=

OBJS				:= ${SRCS:.c=.o}

#OBJS_BN			:= ${BONUS:.c=.o}

#Default Target
all:	${LIBFT} ${FT_PRINTF_FD} ${NAME}
		@echo "Sources: ${SRCS}"

#Compiling Rule
%.o:	%.c
	@echo "----------------------------Compiling----------------------------"
	${CC} ${CFLAGS} -o $@ -c $< ${INCLUDE}

#Create source library
${NAME}: ${OBJS} ${LIBFT} ${FT_PRINTF_FD}
		cc ${OBJS} ${LIBFT} ${FT_PRINTF_FD} -o ${NAME}

# Build libft.a
${LIBFT}:
		$(MAKE) -C ${LIBFT_DIR}

# Build ft_printf.a
${FT_PRINTF_FD}:
		$(MAKE) -C ${FT_PRINTF_FD_DIR}


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
