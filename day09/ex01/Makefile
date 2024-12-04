CPP = c++
ODIR = obj
IDIR = include
CPP_FLAGS = -Wall -Wextra -Werror --std=c++98 -g3 -I$(IDIR)
NAME = RPN
OBJS = $(patsubst %,$(ODIR)/%,$(CPP_FILES:=.o))
CPP_FILES = main Rpn
all : $(NAME)

$(ODIR):
	mkdir -p $(ODIR)

$(NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS)  -o  $@ $(OBJS)

$(ODIR)/%.o : %.cpp | $(ODIR)
	$(CPP) $(CPP_FLAGS) -c -o $@ $< 

clean:
	rm -Rf $(ODIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMED)

re: fclean $(NAME)
