all: main

main: main.o todointerface.o
	gcc main.o todointerface.o -o main.out

main.o: main.c todointerface.h
	gcc -c main.c -o main.o

llinterface.o: llinterface.c llinterface.h
	gcc -c llinterface.c -o llinterface.o

todointerface.o: todointerface.c todointerface.h
	gcc -c todointerface.c -o todointerface.o

clean:
	rm -f *.o *.out