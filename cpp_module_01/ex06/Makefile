NAME = harlFilter
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = Harl.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re