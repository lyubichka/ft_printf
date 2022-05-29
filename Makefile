NAME = libftprintf.a

SRCS	= 	printf.c \
		print_sdi.c \
		print_xXp.c \

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIB			= ar -rc
RM			= /bin/rm -f

INCS		= ft_printf.h

OBJS		= $(SRCS:.c=.o)

all: 		${NAME}

$(NAME):	$(OBJS) $(INCS)
			$(LIB)	$(NAME) $(OBJS)

.c.o: 		
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all