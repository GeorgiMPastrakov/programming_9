all: hashmap.o main.o
	gcc hashmap.o main.o -o main.exe

hashmap.o: hashmap.c hashmap.h
	gcc -c hashmap.c -o hashmap.o

main.o: main.c hashmap.h
	gcc -c main.c -o main.o

clean:
	del *.exe 
	del *.o