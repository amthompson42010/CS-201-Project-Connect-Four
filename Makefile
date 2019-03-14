CFILES = connectFour.c

connectFour: $(CFILES)
	gcc -Wall -o connectFour $(CFILES)

clean:
	rm -f *.o

run: connectFour
	./connectFour