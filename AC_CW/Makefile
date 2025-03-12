all: integral

integral: integral.o roots.o
	gcc -Wall -o integral integral.o roots.o -lm

integral.o: integral.c
	gcc -Wall -c -o integral.o integral.c

roots.o: roots.c
	gcc -Wall -c -o roots.o roots.c

clean:
	rm *.o
	rm integral
	
