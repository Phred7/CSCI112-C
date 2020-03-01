deconpgm: main.o decon.o
	gcc -o deconpgm main.o decon.o

main.o: decon.h main.c
	gcc -c main.c

decon.o: decon.h decon.c
	gcc -c decon.c

