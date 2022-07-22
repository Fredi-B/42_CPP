# _*_ Makefile _*_

NAME = clap
CPP = c++
CPP_FLAGS= -Wall -Wextra -Werror

CPP_FILES = main.cpp ClapTrap.cpp

O_DIR = o_files
OBJECTS := $(patsubst %.cpp,%.o,$(CPP_FILES))
OBJECTS := $(addprefix $(O_DIR)/,$(OBJECTS))

UNAME_S := $(shell uname -s)

$(NAME): $(O_DIR) $(OBJECTS)

ifeq ($(UNAME_S),Linux)
	$(CPP) $(CPP_FLAGS) $(OBJECTS) -o $(NAME)
else
	$(CPP) $(CPP_FLAGS) $(OBJECTS) -o $(NAME)
endif

$(O_DIR):
	@mkdir $(O_DIR)

$(O_DIR)/%.o: %.cpp
ifeq ($(UNAME_S),Linux)
	$(CPP) $(CPP_FLAGS) -c $< -o $@
else
	$(CPP) $(CPP_FLAGS) -c $< -o $@
endif

.phony: all
all: $(NAME)

.phony: clean
clean:
	rm -f $(OBJECTS)
	rm -rf $(O_DIR)

.phony: fclean
fclean: clean
	rm -f $(NAME) *~

.phony: re
re: fclean all
