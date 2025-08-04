CXX := c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME  = serialize
SRC_DIR := src
INCLUDES_DIR := include
INCLUDES := $(INCLUDES_DIR)/Serializer.hpp \
$(INCLUDES_DIR)/Data.hpp
SRCS := $(SRC_DIR)/main.cpp \
$(SRC_DIR)/Serializer.cpp \
$(SRC_DIR)/Data.cpp
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
