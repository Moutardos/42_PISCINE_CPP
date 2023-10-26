CPP = c++
ODIR = obj
CONTACT_MAX = 8
CPP_FLAGS = -Wall -Wextra -Werror
NAME = phonebook
FILES =  Phonebook Contact
OBJS = $(patsubst %,%,$(CPP_FILES:=.o))
CPP_FILES = Phonebook Contact Main

all : $(NAME)

$(ODIR):
	mkdir -p $(ODIR)

$(NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS)  -o  $@ $(OBJS)

%.o : %.cpp | $(ODIR)
	$(CPP) $(CPP_FLAGS) -c $<
