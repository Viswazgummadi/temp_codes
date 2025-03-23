# Define compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# List all .cpp files in the current directory
CPP_FILES := $(wildcard *.cpp)
EXECUTABLES := $(CPP_FILES:.cpp=)

# Default target: show usage
.PHONY: all
all:
	@echo "Usage:"
	@echo "  make list                       - List all C++ files in current directory"
	@echo "  make compile-all                - Compile all C++ files in current directory"
	@echo "  make compile FILE=file.cpp      - Compile a specific C++ file"
	@echo "  make run CODE=executable TEST=testcase - Run executable with test case input"
	@echo "  make run-interactive CODE=executable - Run in interactive terminal session"
	@echo "  make clean                      - Remove all compiled executables"

# List all C++ files in current directory
.PHONY: list
list:
	@echo "C++ files in current directory:"
	@for file in $(CPP_FILES); do \
		echo "  $$file"; \
	done

# Compile all C++ files in current directory
.PHONY: compile-all
compile-all: $(EXECUTABLES)

# Generic rule to compile C++ file to executable
%: %.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $< -o $@
	@echo "Compilation successful. Executable: $@"

# Compile specific C++ file
.PHONY: compile
compile:
	@if [ -z "$(FILE)" ]; then \
		echo "Error: No file specified. Use 'make compile FILE=file.cpp'"; \
		exit 1; \
	fi
	@if [ ! -f "$(FILE)" ]; then \
		echo "Error: File '$(FILE)' not found"; \
		exit 1; \
	fi
	@echo "Compiling $(FILE)..."
	@$(CXX) $(CXXFLAGS) "$(FILE)" -o "$${FILE%.cpp}"
	@echo "Compilation successful. Executable: $${FILE%.cpp}"

# Run with test case input
.PHONY: run
run:
	@if [ -z "$(CODE)" ]; then \
		echo "Error: No program specified. Use 'make run CODE=executable TEST=testcase'"; \
		exit 1; \
	fi
	@if [ ! -f "$(CODE)" ]; then \
		if [ -f "$(CODE).cpp" ]; then \
			echo "Compiling $(CODE).cpp first..."; \
			$(CXX) $(CXXFLAGS) "$(CODE).cpp" -o "$(CODE)"; \
		else \
			echo "Error: Executable '$(CODE)' not found and '$(CODE).cpp' not found"; \
			exit 1; \
		fi; \
	fi
	@if [ -z "$(TEST)" ]; then \
		echo "Running $(CODE) without input file..."; \
		./$(CODE); \
	else \
		if [ ! -f "$(TEST)" ]; then \
			echo "Error: Test case file '$(TEST)' not found"; \
			exit 1; \
		fi; \
		echo "Running $(CODE) with input from $(TEST)..."; \
		./$(CODE) < "$(TEST)"; \
	fi

# New interactive terminal session rule
.PHONY: run-interactive
run-interactive:
	@if [ -z "$(CODE)" ]; then \
		echo "Error: No program specified. Use 'make run-interactive CODE=executable'"; \
		exit 1; \
	fi
	@if [ ! -f "$(CODE)" ]; then \
		if [ -f "$(CODE).cpp" ]; then \
			echo "Compiling $(CODE).cpp first..."; \
			$(CXX) $(CXXFLAGS) "$(CODE).cpp" -o "$(CODE)"; \
		else \
			echo "Error: Executable '$(CODE)' not found and '$(CODE).cpp' not found"; \
			exit 1; \
		fi; \
	fi
	@echo "Starting interactive session for $(CODE)..."
	@echo "-------------------------------------------"
	@./$(CODE)

# Clean compiled files
.PHONY: clean
clean:
	@echo "Cleaning compiled files in current directory..."
	@for exe in $(EXECUTABLES); do \
		if [ -f "$$exe" ]; then \
			echo "Removing $$exe"; \
			rm "$$exe"; \
		fi; \
	done
	@echo "Clean complete"
