SRCS	=	main.cpp BitcoinExchange.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	btc

CC		=	c++

CPPFLAGS=	-std=c++98 #-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
					$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re