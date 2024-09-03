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

cp:
	@source=$$(echo $(filter-out cp,$(MAKECMDGOALS))); \
	dest=$$(echo $${source##* }); \
	source=$$(echo $${source%% *}); \
	if [ ! -f $${dest}.cpp ]; then \
		cp $${source}.cpp $${dest}.cpp; \
	else \
		echo "$${dest}.cpp already exists"; \
	fi

# Phony targets
.PHONY: build% run% cp
