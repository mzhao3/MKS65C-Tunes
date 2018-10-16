all: song.o main.o
	gcc song.o main.o

song.o: song.c song.h
	gcc -c song.c

main.o: main.c song.h
	gcc -c main.c

clear:
	rm -rf *.o
	rm -rf a.out

run:
	./a.out

debug: song.o main.o
	gcc -g song.o main.o
	gdb a.out

mem: song.o main.o
	gcc -g song.o main.o
	valgrind ./a.out
