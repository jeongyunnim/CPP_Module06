NAME 		=	ex01

CXX 		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

INCS		=	./Base.hpp\
				./A.hpp\
				./B.hpp\
				./C.hpp\

SRCS		=	./main.cpp\
				./Base.cpp\
				./A.cpp\
				./B.cpp\
				./C.cpp\

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