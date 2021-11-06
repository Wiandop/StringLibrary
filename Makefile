build: main.o string.o tests.o
	gcc main.o string.o tests.o -lm
	./a.exe

main.o: main.c
	gcc -c main.c

string.o: string.c string.h
	 gcc -c string.c

tests.o: tests/tests.c tests/tests.h
	 gcc -c tests/tests.c -o tests.o

clean: main.o string.o tests.o
	rm a.exe main.o string.o tests.o