CFLAGS=-W -Wall 
LDFLAGS = -lglut -lGLU -lGL -lm
EXEC = apli


jeu : $(EXEC)

apli : main.o affichage.o init.o mouvementsFormes.o matrices.o
	gcc -o apli main.o affichage.o init.o mouvementsFormes.o matrices.o $(CFLAGS) $(LDFLAGS)


main.o : main.c affichage.h setup.h mouvementsFormes.h matrices.h
	gcc -o main.o -c main.c $(CFLAGS)


mouvementsFormes.o : mouvementsFormes.c setup.h matrices.h
	gcc -o mouvementsFormes.o -c mouvementsFormes.c $(CFLAGS)


affichage.o : affichage.c affichage.h setup.h
	gcc -o affichage.o -c affichage.c $(CFLAGS)


init.o : init.c init.h setup.h
	gcc -o init.o -c init.c $(CFLAGS)


matrices.o : matrices.c matrices.h setup.h
	gcc -o matrices.o -c matrices.c $(CFLAGS)


clean : 
	rm -rf *.o $(EXEC)
