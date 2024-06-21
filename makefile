include update.mk

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g
TARGET = a
SCRIPT = 101-main.c

FILE = 101-cocktail_sort_list.c 
COMPILE_SHELL = compile.sh
GCC_FILES = $(shell bash $(COMPILE_SHELL))
LATEST_MAIN = $(shell ls -t *-main.c | head -n 1)

compile:
		@chmod u+x $(COMPILE_SHELL)
		./$(COMPILE_SHELL)

$(TARGET): $(LATEST_MAIN) $(GCC_FILES)
		$(CC) $(CFLAGS) -o $@ $^

.PHONY: all test git style compile

all: test count style

test: $(TARGET)
	@printf "\rRunning $(FILE) ..."; \
	sleep 2; \
	printf "\r%$${COLUMNS}s\r"; \
	./$(TARGET)
	@echo

git:
	@if [ -f .commit_msg ]; then \
		NEW_MSG=$$(cat .commit_msg); \
	else \
		echo "Enter a commit message: "; \
		read NEW_MSG; \
		fi; \
		git add .;\
		git commit -m "$$NEW_MSG"; \
		git push

clean:
		rm -f $(TARGET)

count:
	@printf "Line count: \n"; \
	OUTPUT=$$(wc -l $(FILE)); \
	echo $$OUTPUT; \
	sleep 3; \
	tput cuu 1; \
	tput el; \
	tput cuu 1; \
	tput el;

style:
	@printf "\rChecking $(FILE) for style errors:\n";
	@sleep 1; \
	bash -c '\
	OUTPUT=$$(betty $(FILE)); \
	echo -e "$$OUTPUT";'