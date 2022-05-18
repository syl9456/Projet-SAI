CFLAGS=-W -Wall
LDFLAGS = -lglut -lGLU -lGL -lm
EXEC = apli


jeu : $(EXEC)

apli : main.o affichage.o init.o
	gcc -o apli main.o affichage.o init.o $(CFLAGS) $(LDFLAGS)

main.o : main.c affichage.h setup.h
	gcc -o main.o -c main.c $(CFLAGS)

affichage.o : affichage.c affichage.h setup.h
	gcc -o affichage.o -c affichage.c $(CFLAGS)

init : init.c init.h setup.h
	gcc -o init.o -c init.c $(CFLAGS)

clean : 
	rm -rf *.o $(EXEC)