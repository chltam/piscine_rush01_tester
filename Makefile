NAME = rush01_tester

CXX := c++

CXXFLAGS :=  -g #-Wall -Wextra -Werror

SRCS := main.cpp Grid.cpp utils.cpp

SRCDIR = ./srcs

OBJDIR = objs

INCDIR = ./includes

OBJS := $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

vpath %.cpp $(SRCDIR)

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) -c $(CXXFLAGS) -I $(INCDIR) $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJS) demo.c
	@printf "\e[33;1m> $(SRCS) [$(CXXFLAGS)] \n> $(NAME) compiled\e[0m\n"
	@$(CXX) $(CXXFLAGS) -I $(INCDIR) $(OBJS) -o $(NAME)
	@cc demo.c

clean:
	@printf "\e[31;1m--- $(OBJS)\e[0m\n"
	@rm -rf $(OBJS)

fclean: clean
	@printf "\e[31;1m--- $(NAME)\e[0m\n"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
