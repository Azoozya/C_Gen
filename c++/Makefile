all: Final Test Clear
LS := $(shell ls | grep psh | wc -l)

Final: main.o fonctions.o classes.o
	g++ -g main.o fonctions.o -o Final

Test: tests.o fonctions.o classes.o
	g++ -g tests.o fonctions.o -o Test

Clear:
	rm *.o
ifeq ($(LS),0)
	$(shell echo $("Lamantin"))
else
	rm *.psh
endif
# -----------------------------------------

main.o: main.cpp header.hh classes.hh
	g++ -g -c  main.cpp

fonctions.o: fonctions.cpp header.hh classes.hh
	g++ -g -c  fonctions.cpp

classes.o: classes.cpp classes.hh
	g++ -g -c  classes.cpp

tests.o: tests.cpp header.hh classes.hh
	g++ -g -c tests.cpp

# -----------------------------------------

purge:
	rm -rf Final Test
