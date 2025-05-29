CXX := c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME  = animals
SRC_DIR := src
INCLUDES_DIR := includes
INCLUDES := $(INCLUDES_DIR)/Animal.hpp \
$(INCLUDES_DIR)/Dog.hpp \
$(INCLUDES_DIR)/Cat.hpp \
$(INCLUDES_DIR)/Brain.hpp
SRCS := $(SRC_DIR)/main.cpp \
$(SRC_DIR)/Dog.cpp \
$(SRC_DIR)/Cat.cpp \
$(SRC_DIR)/Animal.cpp \
$(SRC_DIR)/Brain.cpp
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
