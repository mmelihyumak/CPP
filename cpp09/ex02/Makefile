SRCS	=	main.cpp PmergeMe.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	PmergeMe

CXX 	=	c++ -g

CXXFLAGS=	-std=c++98

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(OBJS) -o $(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
					$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re