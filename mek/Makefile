$(CC) = clang

four: four.o add.o sub.o
	$(CC) four.o add.o sub.o -o output

four.o: four.c file.h
	$(CC) -c four.c

add.o: add.c file.h
	$(CC) -c add.c

sub.o: sub.c file.h
	$(CC) -c sub.c

clean: 
	rm -rf *.o output
