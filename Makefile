CC = gcc -Wall

all: hello

# Checks if hello.o exists, otherwise looks for a rule to create it.
hello: hello.o
	 $(CC) -o hello hello.o

hello.o: hello.c
	 $(CC) -c hello.c

clean:
	 rm hello.o hello
