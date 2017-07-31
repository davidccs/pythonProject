CC= gcc

main : main.o stack.o
	$(CC) -o main main.o stack.o

main.o : main.c stack.h
stack.o : stack.c stack.h

clean :
	rm -f core main main.o stack.o
