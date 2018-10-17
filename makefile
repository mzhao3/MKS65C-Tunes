all: song.o library.o main.o
	gcc song.o library.o main.o

song.o: song.c song.h
	gcc -c song.c

main.o: main.c song.h library.h
	gcc -c main.c

library.o: library.c library.h song.h
	gcc -c library.c

clear:
	rm -rf *.o
	rm -rf a.out

run:
	./a.out

debug: song.o library.o main.o
	gcc -g song.o library.o main.o
	gdb a.out

mem: song.o library.o main.o
	gcc -g song.o library.o main.o
	valgrind ./a.out
