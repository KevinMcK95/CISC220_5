#RULE 1
udll.o: udll.c udll.h
	gcc -Wall -c udll.c -o udll.o

#RULE 2
main.o: main.c
	gcc -Wall -c main.c -o main.o

#RULE 3
universalDoubleLinkedList: main.o udll.o
	gcc -Wall -o universalDoubleLinkedList main.o udll.o -lm

