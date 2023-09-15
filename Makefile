##
## EPITECH PROJECT, 2022
## raytracer
## File description:
## No configuration there , just an epitech header example
##

SRC = $(shell find src/ -type f -name '*.cpp')
OBJ = $(SRC:.cpp=.o)

CC = g++
NAME = raytracer
CPPFLAGS = -iquote include -Wall -Wextra -Werror
CXXFLAGS = -std=c++20 -lconfig++ -lsfml-graphics -lsfml-window -lsfml-system

TEST_SRC = $(shell find test/ -type f -name '*Test.cpp')

INCLUDE_GTEST = /usr/local/include/gtest
LIBS_GTEST = /usr/local/lib/libgtest_main.a /usr/local/lib/libgtest.a

ARGS = 'configuration.scene'

$(NAME): $(OBJ)
	@$(CC) $(OBJ) Main.cpp -o $(NAME) $(CXXFLAGS) $(CPPFLAGS)
	@echo -e '\e[1m\e[32m✅ Raytracer compiled\e[0m'

all: $(NAME)

%.o : %.cpp
	@echo -e '\e[2mCompiling $@\e[0m'
	@$(CC) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

graphical: $(OBJ)
	@$(CC) -o $(NAME) $(CXXFLAGS) $(CPPFLAGS) $(OBJ) Main.cpp
	@echo -e '\e[1m\e[32m✅ Raytracer compiled\e[0m'

fclean: clean
	@echo -e '\e[1m\e[91m🗑️  Deleting binaries\e[0m\n'
	@rm -Rf $(NAME)
	@rm -Rf $(NAME)_debug
	@rm -Rf $(NAME)_test
	@rm -f lib/*.so

clean:
	@echo -e '\e[1m\e[91m🗑️  Deleting compilation files\e[0m'
	@rm -f profile.txt gmon.out
	@find . -type f -name '*.o' -delete
	@find . -type f -name '*.gcda' -delete
	@find . -type f -name '*.gcno' -delete
	@find . -type f -name '*.gcov' -delete
	@find . -type f -name 'vgcore.*' -delete

re:
	@echo -e '\e[1m\e[94m🚀 Rebuild project\e[0m\n'
	@make fclean --no-print-directory
	@make all --no-print-directory

debug:
	@echo -e '\e[1m\e[94m🚀 Compile debug binary\e[0m'
	@$(CC) -o $(NAME)_debug -g -g3 $(CXXFLAGS) $(CPPFLAGS) $(SRC) Main.cpp

gdb: debug
	@echo -e '\e[1m\e[94m🚀 Run GDB\e[0m\n'
	@gdb --quiet $(NAME)_debug $(ARGS)

profile:
	@echo -e '\e[1m\e[94m🚀 Profile binary\e[0m\n'
	@$(CC) -o $(NAME)_profile -pg $(CXXFLAGS) $(CPPFLAGS) $(SRC) Main.cpp
	@./$(NAME)_profile $(ARGS)
	@gprof $(NAME) gmon.out > profile.txt
	@echo -e '\e[1m\e[90m⚠️  Profiling saved in profile.txt\e[0m'

valgrind: debug
	@echo -e '\e[1m\e[94m🚀 Run valgrind\e[0m\n'
	@valgrind ./$(NAME)_debug $(ARGS)

leak: debug
	@echo -e '\e[1m\e[94m🚀 Run valgrind (\e[34mleak\e[94m)\e[0m\n'
	@valgrind --leak-check=full ./$(NAME)_debug $(ARGS)

origins: debug
	@echo -e '\e[1m\e[94m🚀 Run valgrind (\e[34mtrack-origins\e[94m)\e[0m\n'
	@valgrind --track-origins=yes ./$(NAME)_debug $(ARGS)

tests_run: $(GTEST_LIBS)
	@echo -e '\e[1m\e[94m🚀 Run tests (\e[34mvalidation\e[94m)\e[0m\n'
	@$(CC) -o $(NAME)_test $(CXXFLAGS) $(CPPFLAGS) -I $(INCLUDE_GTEST) --coverage $(LIBS_GTEST) $(SRC) $(TEST_SRC)
	@./$(NAME)_test

coverage: $(GTEST_LIBS)
	@echo -e '\e[1m\e[94m🚀 Run tests (\e[34mcoverage\e[94m)\e[0m\n'
	@$(CC) -o $(NAME)_test $(CXXFLAGS) $(CPPFLAGS) -I $(INCLUDE_GTEST) --coverage $(LIBS_GTEST) $(SRC) $(TEST_SRC)
	@./$(NAME)_test
	@gcovr --exclude test/

.PHONY: all clean fclean re debug gdb profile valgrind leak origins
