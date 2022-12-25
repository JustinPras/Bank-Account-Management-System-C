#makefile for Runner.out

CC = gcc
CFLAGS = -Wall -Werror -ansi -lm

Runner.out: Runner.o Login.o Menu.o Accounts.o Encryption.o FileManager.o LinkedList.o
	$(CC) $(CFLAGS) -o Runner.out Runner.o Login.o Menu.o Accounts.o Encryption.o FileManager.o LinkedList.o

Runner.o: Runner.c Program.h
	$(CC) $(CFLAGS) -c -o Runner.o Runner.c

Login.o: Login.c Program.h
	$(CC) $(CFLAGS) -c -o Login.o Login.c

Menu.o: Menu.c Program.h
	$(CC) $(CFLAGS) -c -o Menu.o Menu.c

Accounts.o: Accounts.c Program.h
	$(CC) $(CFLAGS) -c -o Accounts.o Accounts.c

Encryption.o: Encryption.c Program.h
	$(CC) $(CFLAGS) -c -o Encryption.o Encryption.c

FileManager.o: FileManager.c Program.h
	$(CC) $(CFLAGS) -c -o FileManager.o FileManager.c

LinkedList.o: LinkedList.c Program.h
	$(CC) $(CFLAGS) -c -o LinkedList.o LinkedList.c

clean:
	rm Runner.o Login.o Menu.o Accounts.o Encryption.o FileManager.o LinkedList.o Runner.out
