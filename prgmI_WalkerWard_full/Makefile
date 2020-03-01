prgmI: main.o getClassesParseLine.o sort.o promptUser.o prints.o
	gcc -o prgmI main.o getClassesParseLine.o sort.o promptUser.o prints.o

main.o: header.h main.c
	gcc -c -Wall main.c

getClasses.o: header.h getClassesParseLine.c
	gcc -c -Wall getClassesParseLine.c

sort.o: header.h sort.c
	gcc -c -Wall sort.c

promptUser.o: header.h promptUser.c
	gcc -c -Wall promptUser.c

prints.o: header.h prints.c
	gcc -c -Wall prints.c
