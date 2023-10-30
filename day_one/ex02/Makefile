CPP = c++
ODIR = obj
CPP_FLAGS = -Wall -Wextra -Werror
NAME = account_test
OBJS = $(patsubst %,$(ODIR)/%,$(CPP_FILES:=.o))
CPP_FILES = tests Account

all : $(NAME)

$(ODIR):
	mkdir -p $(ODIR)

$(NAME): $(OBJS) 
	$(CPP) $(CPP_FLAGS)  -o  $@ $(OBJS)

obj/tests.o: tests.cpp | $(ODIR)
	$(CPP) -c -o $@ $<

obj/Account.o: Account.cpp | $(ODIR)
	$(CPP) $(CPP_FLAGS) -c -o $@ $<
clean:
	rm -Rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)