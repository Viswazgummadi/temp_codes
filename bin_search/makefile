# Variables
CC = g++
CFLAGS = -g

# Targets
build%:
	echo '// C++ file $*.cpp' > $*.cpp

run%: build%
	$(CC) $(CFLAGS) -o $* $*.cpp
	./$*

# Phony targets
.PHONY: build% run%

