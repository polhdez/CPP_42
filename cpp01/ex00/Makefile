CXX := c++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++98

NAME  = zombie
SRC_DIR := src
INCLUDES_DIR := includes
INCLUDES := $(INCLUDES_DIR)/Zombie.hpp
SRCS := $(SRC_DIR)/main.cpp \
						$(SRC_DIR)/newZombie.cpp \
						$(SRC_DIR)/randomChump.cpp \
						$(SRC_DIR)/Zombie.cpp
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
