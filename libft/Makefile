NAME 	= libft.a
SRCS 	= ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
ft_strcmp.c 
SRCS_B 	= ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c 

GNL 	= gnl/get_next_line_utils.c \
gnl/get_next_line.c

OBJS 	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}
GNL_O	= ${GNL:.c=.o}


CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	@echo Compiling.. $<
	@${CC} ${CFLAGS} -I. -Ignl -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@echo Creating library.. ${NAME}
	ar rcs $@ $^

all: ${NAME}
	@echo Done.

bonus: ${OBJS} ${OBJS_B} 
	@echo Bonus..
	@ar rcs ${NAME} $^

gnl: ${GNL_O} bonus
	@echo Libft with gnl..
	@ar rcs ${NAME} $<

clean:
	@echo Deleting.. ${OBJS}
	@${RM} ${OBJS}
	@echo Deleting.. ${OBJS_B}
	@${RM} ${OBJS_B}
	@echo Deleting.. ${GNL_O}
	@${RM} ${GNL_O}

fclean: clean
	@echo Deleting.. ${NAME}
	@${RM} ${NAME}
	
re: fclean all

.PHONY: all clean fclean re bonus
