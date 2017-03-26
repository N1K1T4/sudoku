DEBUG=yes
CXX=g++
ifeq ($(DEBUG),yes)
CXXFLAGS=-Og -g -ggdb -std=c++1y -Wpedantic -Wall -Wextra -Werror
LDFLAGS=
else
CXXFLAGS=-march=native -Ofast -pipe
LDFLAGS=-s
endif
EXEC=sudoku_solver
SRC=$(wildcard *.cxx)
OBJ=$(SRC:.cxx=.o)

.PHONY: clean bleach

all: $(EXEC)
ifeq ($(DEBUG),yes)
	@echo "Debugging executable ready."
else
	@echo "Release executable ready."
endif

$(EXEC): $(OBJ)
	@echo "Linking objects..."
	@$(CXX) $(LDFLAGS) $^ -o $@
	@echo "Done."

main.o: cell.h

grid.o: grid.h cell.h

cell.o: cell.h

%.o: %.cxx
	@echo "Compiling $*..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Done."

run: $(EXEC)
	@./$(EXEC)

clean:
	@echo "Deleting objects..."
	@rm -rf *.o
	@echo "Done."

bleach: clean
	@echo "Deleting $(EXEC) and temporary files..."
	@rm -rf *~ $(EXEC)
	@echo "Done."
