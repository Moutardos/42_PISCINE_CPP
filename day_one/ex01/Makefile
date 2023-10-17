CPP = c++
CONTACT_MAX = 8
CPP_FLAGS = -Wall -Wextra -Werror
NAME = phonebook
CPP_FILES = Phonebook.hpp Phonebook.cpp Contact.cpp Contact.hpp Main.cpp

all : $(NAME)

$(NAME):
	$(CPP)  $(CPP_FILES) $(CPP_FLAGS) -DCONTACT_MAX=$(CONTACT_MAX)