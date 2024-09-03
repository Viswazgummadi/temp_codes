# Variables
CC = g++
CFLAGS = -g

# Targets
build%:
	@if [ ! -f $*.cpp ]; then \
		echo '// C++ file $*.cpp' > $*.cpp; \
	fi

run%: build%
	@$(CC) $(CFLAGS) -o $* $*.cpp
	@./$*

# Phony targets
.PHONY: build% run%
