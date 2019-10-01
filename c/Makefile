all: Final Test Clear
LS := $(shell ls | grep psh | wc -l )

Final: fonctions.o master_pointer.o main.o
	gcc -lm -Wall -g -std=c99 fonctions.o master_pointer.o main.o -o Final

Test: fonctions.o master_pointer.o tests.o
	gcc -lm -Wall -g -std=c99 fonctions.o master_pointer.o tests.o -o Test

Clear:
	rm *.o
ifeq ($(LS),0)
	$(shell echo $("Lamantin"))
else
	rm *.psh
endif

# ---------------------------------------------------

fonctions.o: fonctions.c header.h
	gcc -lm -Wall -g -std=c99 -c fonctions.c -o fonctions.o

master_pointer.o: master_pointer.c header.h
	gcc -lm -Wall -g -std=c99 -c master_pointer.c -o master_pointer.o

main.o: main.c header.h
	gcc -lm -Wall -g -std=c99 -c main.c -o main.o

purge:
	rm -rf Final Test
