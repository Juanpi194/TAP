PROGRAM_NAME = tap

ENTRY = main.cpp

SRC_FOLDER = src
INC_FOLDER = inc

CHARACTERS_FOLDER = characters
CHARACTERS_SRC =

SERVER_FOLDER = server
SERVER_SRC = $(addprefix $(SRC_FOLDER)/$(SERVER_FOLDER)/, \
				PlayerConnection.cpp Server.cpp ServerOwner.cpp)

UTILS_FOLDER = utils
UTILS_SRC = $(addprefix $(SRC_FOLDER)/$(UTILS_FOLDER)/, \
				colors.cpp globals.cpp log.cpp string_utils.cpp)

WORLD_FOLDER = world
WORLD_SRC = $(addprefix $(SRC_FOLDER)/$(WORLD_FOLDER)/, \
				Room.cpp World.cpp)

SRC = $(CHARACTERS_SRC) $(SERVER_SRC) $(UTILS_SRC) $(WORLD_SRC)

FLAGS = -std=c++17 -I $(INC_FOLDER)
COMPILATION_FLAGS = -Wall -Wextra -Werror -Wunused-parameter
DEBUG_FLAG = -D WOW
CC = c++

COLOR_RESET			:= \033[0m
COLOR_GRAY			:= \033[0;30m
COLOR_LIGHT_GRAY	:= \033[1;30m
COLOR_RED			:= \033[0;31m
COLOR_GREEN			:= \033[0;32m
COLOR_LIGHT_GREEN	:= \033[1;32m
COLOR_YELLOW		:= \033[0;33m
COLOR_LIGHT_YELLOW	:= \033[1;33m
COLOR_BLUE			:= \033[0;34m
COLOR_LIGHT_BLUE	:= \033[1;34m
COLOR_MAGENTA		:= \033[0;35m
COLOR_CYAN			:= \033[0;36m
COLOR_WHITE			:= \033[0;37m
BOLD				:= \033[1m
BOLD_OFF			:= \033[22m
UNDERLINE			:= \033[4m
UNDERLINE_OFF		:= \033[24m


# DE AQUÍ PARA ABAJO ESTÁ COMO LA MIERDA

help:
	# TODO

run:
	./$(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJECTS)
	# TODO

all: compile

compile:
	$(CC) $(FLAGS) $(ENTRY) $(SRC) -o $(PROGRAM_NAME)

compile-debug:
	$(CC) $(FLAGS) $(ENTRY) $(DEBUG_FLAG) -o $(PROGRAM_NAME)

clean:
	rm $(PROGRAM_NAME)

fclean:
	# TODO

re: clean all


.DEFAULT_GOAL= all
