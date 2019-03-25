OBJSS = connectFour.o gameModes.o board.o adjacencyList.o menu.o

play: $(OBJSS)
	gcc -Wall -Wextra -g -o play $(OBJSS)

connectFour.o: connectFour.c gameModes.h menu.h
	gcc -Wall -Wextra -g -c connectFour.c

gameModes.o: gameModes.c gameModes.h board.c adjacencyList.c
	gcc -Wall -Wextra -g -c gameModes.c

board.o: board.c board.h adjacencyList.c
	gcc -Wall -Wextra -g -c board.c

adjacencyList.o: adjacencyList.c adjacencyList.h
	gcc -Wall -Wextra -g -c adjacencyList.c

menu.o: menu.c menu.h
	gcc -Wall -Wextra -g -c menu.c

clean:
	rm -f *.o

run: play
	./play