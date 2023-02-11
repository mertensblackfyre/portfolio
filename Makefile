output: main.o member.o utils.o
	gcc main.o member.o utils.o -o output

member.o: member.c Member.h
	gcc -c member.c

utils.o: utils.c Utils.h
	gcc -c utils.c

main.o: main.c
	gcc -c main.c

clearn:
	rm *.o output