EXEC		= fdf

CC			= clang
LIB			= -L$(LIBFT) -L${MINILIBX}-linux/ -lft -lm -lmlx -lXext -lX11
CFLAGS		= -Werror -Wall -Wextra -I$(INCLUDE) ${LIB} -g

LINKER		= clang
LFLAGS		= -Werror -Wall -Wextra -I$(INCLUDE) -g

RM			= rm -rf

MINILIBX	= minilibx
MINILIBX_M	= ${MAKE} -C ${MINILIBX}-linux/
LIBFT		= libft
LIBFT_M		= ${MAKE} -C ${LIBFT}/
INCLUDE		= includes/
SRC_DIR		= src
OBJ_DIR		= obj
SRC			= $(wildcard $(SRC_DIR)/*.c)
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	COLOR = \033
endif
ifeq ($(UNAME_S),Darwin)
	COLOR = \x1b
endif

$(EXEC): $(OBJ)
	@${MINILIBX_M}
	@${LIBFT_M} gnl
	$(CC) $(OBJ) $(LFLAGS) -o $@
	@printf "$(COLOR)[32mCompiled "$@" successfully! $(COLOR)[0m\n"
#	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p ${OBJ_DIR}
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@
	@printf "$(COLOR)[34mCompiled "$<" successfully! $(COLOR)[0m\n"


all: $(EXEC)

clean:
	${LIBFT_M} clean
	${RM} $(OBJ_DIR)
	
fclean: clean
	${LIBFT_M} fclean
	${RM} $(EXEC)
re: fclean all

.PHONY: clean fclean all 