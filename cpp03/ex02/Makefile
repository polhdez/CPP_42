CXX := c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME  = claptrap
SRC_DIR := src
INCLUDES_DIR := includes
INCLUDES := $(INCLUDES_DIR)/ClapTrap.hpp \
			$(INCLUDES_DIR)/FravTrap.hpp \
			$(INCLUDES_DIR)/ScavTrap.hpp
SRCS := $(SRC_DIR)/main.cpp \
		$(SRC_DIR)/ClapTrap.cpp \
		$(SRC_DIR)/FragTrap.cpp \
		$(SRC_DIR)/ScavTrap.cpp
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
