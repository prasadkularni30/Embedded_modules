output1: main.o sub.o add.o
	gcc -o output1 main.o sub.o add.o

add.o: add.c
	gcc -c add.c

sub.o: sub.c
	gcc -c sub.c

main.o: main.c
	gcc -c main.c

clean:
	rm *.o output1

run:
	./output1

cdate:
	date
