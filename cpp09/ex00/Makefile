SRCS	=	main.cpp BitcoinExchange.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	btc

CXX 	=	c++

CXXFLAGS=	-std=c++98 -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(OBJS) -o $(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
					$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re