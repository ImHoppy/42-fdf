# EXEC		= fdf

# CC			= clang
# LIB			= -L$(LIBFT) -L${MINILIBX}/ -lft -lm -lmlx -lXext -lX11
# CFLAGS		= -Werror -Wall -Wextra -I$(LIBFT) -I$(INCLUDE) -Iminilibx  -g

# LINKER		= clang
# LFLAGS		= -Werror -Wall -Wextra -g

# RM			= rm -rf

# MINILIBX	= minilibx
# MINILIBX_M	= ${MAKE} -C ${MINILIBX}/
# LIBFT		= libft
# LIBFT_M		= ${MAKE} -C ${LIBFT}/
# INCLUDE		= includes/
# SRC_DIR		= src
# OBJ_DIR		= obj
# SRC			= $(wildcard $(SRC_DIR)/*.c)
# OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# UNAME_S := $(shell uname -s)
# ifeq ($(UNAME_S),Linux)
# 	COLOR = \033
# endif
# ifeq ($(UNAME_S),Darwin)
# 	COLOR = \x1b
# endif

# $(EXEC): $(OBJ)
# 	@${MINILIBX_M}
# 	@${LIBFT_M} gnl
# 	$(CC) $(OBJ) $(LFLAGS) -o $@ 
# 	@printf "$(COLOR)[32mCompiled "$@" successfully! $(COLOR)[0m\n"
# #	$(CC) -o $@ $^ $(LDFLAGS)

# $(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
# 	@mkdir -p ${OBJ_DIR}
# 	$(CC) $(CFLAGS)  -c $< -o $@
# 	@printf "$(COLOR)[34mCompiled "$<" successfully! $(COLOR)[0m\n"


# all: $(EXEC)

# clean:
# 	${LIBFT_M} clean
# 	${RM} $(OBJ_DIR)
	
# fclean: clean
# 	${LIBFT_M} fclean
# 	${RM} $(EXEC)
# re: fclean all

# .PHONY: clean fclean all 

#
#	Config
#
EXEC	= fdf
SRCS	= main.c fdf.c
SRC_D	= srcs/
OBJ_D	= obj/

INCLUDE = -Iincludes -Iminilibx -Ilibft

#	
#	Don't touch
#	
SRC			= $(addprefix $(SRC_D), $(SRCS))
OBJ			= $(patsubst $(SRC_D)%.c, $(OBJ_D)%.o, $(SRC))
CC			= clang
CFLAGS		= -Wall -Werror -Wextra -pedantic -g -fsanitize=address $(INCLUDE)
LDFLAGS		= -fsanitize=address
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	COLOR = \033
endif
ifeq ($(UNAME_S),Darwin)
	COLOR = \x1b
endif
ccred		= $(COLOR)[0;31m
ccgreen		= $(COLOR)[0;32m
ccyellow	= $(COLOR)[0;33m
ccblue		= $(COLOR)[0;34m
ccend		= $(COLOR)[0m



$(OBJ_D)%.o: $(SRC_D)%.c
	@mkdir -p $(OBJ_D)
	$(CC) $(CFLAGS) -o $@ -c $<
	@printf "$(ccblue)Compiled "$<" successfully!$(ccend)\n"
$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)
	@printf "$(ccgreen)Compiled "$@" successfully!$(ccend)\n"
all: $(EXEC)
clean:
	rm -rf $(OBJ) 
fclean: clean
	rm -rf $(EXEC)
re: fclean all
.PHONY: clean fclean all