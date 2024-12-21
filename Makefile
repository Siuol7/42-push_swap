# Compiler and flags
CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror
INCLUDES 		= -I./includes -I./library/*

# Directories
MANDATORY		= ./execution/mandatory
BONUS		= ./execution/bonus

# Additional library paths
LIBFT_DIR = library/libft
FT_PRINTF_FD_DIR = library/ft_printf_fd

# Libraries
LIBFT = ${LIBFT_DIR}/libft.a
FT_PRINTF_FD = ${FT_PRINTF_FD_DIR}/libftprintf.a


# Source's directories
PARSING		= parsing

# Source files by directory
MAIN_FILES 		= 	main.c
PARSING 		= 	number_parsing.c		\
					parsing.c				\
					utils.c

ERROR			=	error_parsing.c
PUSH_SWAP	= 	main.c													\
					$(addprefix $(MANDATORY)/$(PARSING)/, $(PARSING_FILES))

# Executables
NAME 			= push_swap

# Targets
all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF_FD) $(PUSH_SWAP)
	$(CC) $(CFLAGS) $(INCLUDES) $(PUSH_SWAP) $(LIBFT) $(FT_PRINTF_FD) -o $(NAME)

# Build libft.a
${LIBFT}:
		$(MAKE) -C ${LIBFT_DIR}

# Build ft_printf.a
${FT_PRINTF_FD}:
		$(MAKE) -C ${FT_PRINTF_FD_DIR}

# Clean target
clean:
		rm -f ${PUSH_SWAP}
		$(MAKE) -C ${LIBFT_DIR} clean
		$(MAKE) -C ${FT_PRINTF_FD_DIR} clean

# Fclean target
fclean:
		rm -rf ${NAME} ${PUSH_SWAP}
		$(MAKE) -C ${LIBFT_DIR} fclean
		$(MAKE) -C ${FT_PRINTF_FD_DIR} fclean

# Rebuild target
re: fclean all


.PHONY: all clean fclean re
