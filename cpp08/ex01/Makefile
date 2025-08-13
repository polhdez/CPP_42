CXX := c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME  = span
SRC_DIR := src
INCLUDES_DIR := include
INCLUDES := $(INCLUDES_DIR)/Span.hpp
SRCS := $(SRC_DIR)/main.cpp \
$(SRC_DIR)/Span.cpp
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
