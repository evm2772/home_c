all: integral

integral: integral.o roots.o itrapez.o
	gcc -Wall -o integral integral.o roots.o itrapez.o -lm

roots.o: roots.c
	gcc -Wall -c -o roots.o roots.c
	
itrapez.o: itrapez.c
	gcc -Wall -c -o itrapez.o itrapez.c

integral.o: integral.c 
	gcc -Wall -c -o integral.o integral.c

clean:
	rm *.o
	rm integral
	
