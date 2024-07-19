CPP = c++
ODIR = obj
CPP_FLAGS = -Wall -Wextra -Werror  -std=c++98
NAME = a.out
OBJS = $(patsubst %,$(ODIR)/%,$(CPP_FILES:=.o))
CPP_FILES = main Intern Bureaucrat AForm RobotomyRequestForm PresidentialPardonForm ShrubberyCreationForm 

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

re: fclean $(NAME)