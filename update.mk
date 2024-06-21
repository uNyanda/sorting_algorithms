#!/usr/bin/make -s -f
TARGET_MAKEFILE := makefile
OLD_MAIN_FILE := $(shell grep -oP 'SCRIPT = \K.*' $(TARGET_MAKEFILE))

# Get the latest file number
LATEST_NUM := $(shell ls -v | grep -oP '^\K\d+' | tail -n 1)

# Check if main and test files exist for the latest number
MAIN_FILE := $(shell if [ -f "$(LATEST_NUM)-main.c" ]; then echo "$(LATEST_NUM)-main.c"; fi)
TEST_FILES := $(shell ls -v $(LATEST_NUM)*.c | grep -v "$(LATEST_NUM)-main.c" | tr '\n' ' ')

# Check for a .h file in the directory
HEADER_FILE := $(shell ls *.h 2> /dev/null)
ifeq ($(HEADER_FILE),)
    $(warning No .h file found)
endif

# Check for a .sh file in the directory
README_SH := $(shell ls update_readme.sh 2> /dev/null)
ifeq ($(README_SH),)
    $(warning No .sh file found)
endif

TEMP_FILE := temp.h

.PHONY: update_makefile

# Updtes the target makefile.
update_makefile:
	@i=0; \
	total=20; \
	while [ $$i -le $$total ]; do \
		perc=$$((200*$$i/$$total % 2 + 100*$$i/$$total)); \
		printf "\rUpdating $(TARGET_MAKEFILE): %3d%%" $$perc; \
		sleep .05; \
		i=$$((i+1)); \
	done; \
	printf "\r%$${COLUMNS}s\r"; \
	if [ "$(MAIN_FILE)" = "$(OLD_MAIN_FILE)" ]; then \
		echo "No new main file found..."; \
		sed -i 's|SCRIPT = .*|SCRIPT = |' $(TARGET_MAKEFILE); \
	else \
		sed -i 's|SCRIPT = .*|SCRIPT = $(MAIN_FILE)|' $(TARGET_MAKEFILE); \
	fi
	@sed -i 's|FILE = .*|FILE = $(TEST_FILES)|' $(TARGET_MAKEFILE)
	@echo -n "UPDATED"; \
	sleep 2; \
	printf "\r%$${COLUMNS}s\r";

# Updates the header file.
update_header:
	@if [ -n "$(HEADER_FILE)" ] && [ -n "$(TEST_FILES)" ]; then \
		printf "\rUpdating $(HEADER_FILE)..."; \
		sleep .05; \
		printf "\r%$${COLUMNS}s\r"; \
		for file in $(TEST_FILES); do \
			printf "\rProcessing $$file\r"; \
			sleep 1; \
			printf "\r%$${COLUMNS}s\r"; \
			prototype=$$(cproto $$file); \
			if ! grep -Fxq "$$prototype" $(HEADER_FILE); then \
				awk -v n="$$prototype" '/#endif/{print n; print "\n"; print; next} 1' $(HEADER_FILE) > $(TEMP_FILE) && mv $(TEMP_FILE) $(HEADER_FILE); \
			fi; \
		done; \
	fi

update_readme:
	@echo
	@i=0; \
	spin='-\|/'; \
	while [ $$i -lt 50 ]; do \
		printf "\rRunning $(README_SH) %c"  "$${spin:i++%4:1}"; \
		sleep .0120; \
		i=$$((i+1)); \
	done; \
	printf "\r%$${COLUMNS}s\r"; \
	if [ -n "$(README_SH)" ]; then \
		chmod u+x $(README_SH); \
		./$(README_SH); \
	fi; \
	printf "\r%$${COLUMNS}s\r"
