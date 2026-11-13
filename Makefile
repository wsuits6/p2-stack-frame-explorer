CC     = gcc
CFLAGS = -O0 -g -fno-omit-frame-pointer -fno-stack-protector -no-pie -Wall

binaries/p2: src/project2_stack_explorer.c
	mkdir -p binaries
	$(CC) $(CFLAGS) $< -o $@
