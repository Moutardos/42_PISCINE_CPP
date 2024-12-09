CPP = c++
ODIR = obj
IDIR = include
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -I$(IDIR)
NAME = FordJohnson
NAMED = FordJohnson_debug
OBJS = $(patsubst %,$(ODIR)/%,$(CPP_FILES:=.o))
CPP_FILES = main

DEBUG ?= 0

ifeq ($(DEBUG),1)
	CPP_FLAGS += -DDEBUG=1
	NAME = $(NAMED)
endif

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

debug: clean
	make DEBUG=1
