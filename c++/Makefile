all: Final Test

Final: main.o fonctions.o classes.o
	g++ -g -pthread main.o fonctions.o -o Final

Test: tests.o fonctions.o classes.o
	g++ -g -pthread tests.o fonctions.o -o Test

# -----------------------------------------

main.o: main.cpp header.hh classes.hh
	g++ -g -c -pthread main.cpp

fonctions.o: fonctions.cpp header.hh classes.hh
	g++ -g -c -pthread fonctions.cpp

classes.o: classes.cpp classes.hh
	g++ -g -c -pthread classes.cpp

tests.o: tests.cpp header.hh classes.hh
	g++ -g -c -pthread tests.cpp

# -----------------------------------------

purge:
	rm *.o
	rm Final Test

exec:
	rm *.o
	./Final

test:
	rm *.o
	./Test
