all: link

compile-task_interface:
	gcc -c task_interface.c -o task_interface.o

compile-inteface:
	gcc -c ../../lessons/17-dynamic-array/9v/DynamicArray.c -o DynamicArray.o

compile-test:
	gcc -c findIndexTest.c -o findIndexTest.o

link: compile-task_interface compile-inteface compile-test 
	gcc task_interface.o findIndexTest.o DynamicArray.o -o findIndexTest.exe

run:
	findIndexTest.exe

clean:
	del *.o
	del *.exe


