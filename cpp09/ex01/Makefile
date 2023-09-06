SRCS	=	main.cpp RPN.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	RPN

CXX 	=	c++

CXXFLAGS=	-std=c++98 

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(OBJS) -o $(NAME) -fsanitize=address -g

clean:		
			$(RM) $(OBJS)

fclean:		clean
					$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re