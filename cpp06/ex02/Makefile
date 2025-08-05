CXX := c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME  = realtype
SRC_DIR := src
INCLUDES_DIR := include
INCLUDES := $(INCLUDES_DIR)/A.hpp \
$(INCLUDES_DIR)/B.hpp \
$(INCLUDES_DIR)/C.hpp \
$(INCLUDES_DIR)/Base.hpp
SRCS := $(SRC_DIR)/main.cpp \
$(SRC_DIR)/Base.cpp
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
