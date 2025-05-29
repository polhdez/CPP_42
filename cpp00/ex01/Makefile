CXX := c++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++98

NAME  = phonebook
SRC_DIR := src
INCLUDES_DIR := includes
INCLUDES := $(INCLUDES_DIR)/Contact.hpp \
						$(INCLUDES_DIR)/Phonebook.hpp
SRCS := $(SRC_DIR)/main.cpp \
						$(SRC_DIR)/Contact.cpp \
						$(SRC_DIR)/Phonebook.cpp
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
