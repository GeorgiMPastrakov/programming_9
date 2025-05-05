all: link

compile-siropitalishte:
	gcc -c Siropitalishte.c -o Siropitalishte.o

compile-task_interface:
	gcc -c task_interface.c -o task_interface.o

compile-inteface:
	gcc -c ../../lessons/17-dynamic-array/9v/DynamicArray.c -o DynamicArray.o

compile-test:
	gcc -c findIndexTest.c -o findIndexTest.o

link: compile-task_interface compile-inteface compile-test compile-siropitalishte
	gcc task_interface.o findIndexTest.o DynamicArray.o -o findIndexTest.exe
	gcc task_interface.o  DynamicArray.o Siropitalishte.o -o Siropitalishte.exe

run-findIndexTest:
	findIndexTest.exe

run-Siropitalishte:
	Siropitalishte.exe

clean:
	del *.o
	del *.exe


