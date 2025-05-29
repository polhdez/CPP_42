CXX := c++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++98

NAME  = zombiehorde
SRC_DIR := src
INCLUDES_DIR := includes
INCLUDES := $(INCLUDES_DIR)/Zombie.hpp
SRCS := $(SRC_DIR)/main.cpp \
						$(SRC_DIR)/Zombie.cpp \
						$(SRC_DIR)/zombieHorde.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)
LDFLAGS :=

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

%.o: %.cpp $(INCLUDES) Makefile
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all
