all: snake

snake: snake.o
	gcc -Wall -o snake_game snake.o -lncurses

snake.o: snake.c
	gcc -Wall -c -o snake.o snake.c 

clean:
	rm *.o
	rm snake_game
	
