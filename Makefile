#Compiler
CC = gcc
FLAGS = -O3


build: main.c
	${CC} ${FLAGS} main.c -o program

launch:
	./program.exe

clean:
	$(RM) program.exe

run: build launch clean