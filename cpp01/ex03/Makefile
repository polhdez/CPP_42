CXX := c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME  = violence
SRC_DIR := src
INCLUDES_DIR := includes
INCLUDES := $(INCLUDES_DIR)/HumanA.hpp \
						$(INCLUDES_DIR)/HumanB.hpp \
						$(INCLUDES_DIR)/Weapon.hpp
SRCS := $(SRC_DIR)/main.cpp \
						$(SRC_DIR)/HumanA.cpp \
						$(SRC_DIR)/HumanB.cpp \
						$(SRC_DIR)/Weapon.cpp
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
