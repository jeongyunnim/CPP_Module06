NAME 		=	converter

CXX 		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

# INCS		=	./ScalarConverter.hpp\
				
SRCS		=	./main.cpp\
				# ./ScalarConverter.hpp\

OBJS		=	$(SRCS:%.cpp=%.o)

RM			=	rm -f

all:	$(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%o:	%.cpp
	$(CXX) $(CXXFLAGS) $(INCS) -c $^ -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re