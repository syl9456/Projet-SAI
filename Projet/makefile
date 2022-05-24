CFLAGS=-W -Wall 
LDFLAGS = -lglut -lGLU -lGL -lm
EXEC = apli


jeu : $(EXEC)

apli : main.o affichage.o collision.o init.o mouvementsFormes.o matrices.o TAD_k-arbres.o cube.o 
	gcc -o apli main.o affichage.o collision.o init.o mouvementsFormes.o matrices.o TAD_k-arbres.o cube.o  $(CFLAGS) $(LDFLAGS)


main.o : main.c affichage.h collision.h setup.h mouvementsFormes.h matrices.h TAD_k-arbres.h cube.h
	gcc -o main.o -c main.c $(CFLAGS)

mouvementsFormes.o : mouvementsFormes.c setup.h matrices.h
	gcc -o mouvementsFormes.o -c mouvementsFormes.c $(CFLAGS)

cube.o : cube.c cube.h TAD_k-arbres.h setup.h
	gcc -Wall -c cube.c

TAD_k-arbres.o : TAD_k-arbres.c TAD_k-arbres.h cube.h setup.h
	gcc -o TAD_k-arbres.o -c TAD_k-arbres.c $(CFLAGS)

affichage.o : affichage.c affichage.h setup.h
	gcc -o affichage.o -c affichage.c $(CFLAGS)

collision.o : collision.c collision.h setup.h affichage.h matrices.h
	gcc -o collision.o -c collision.c $(CFLAGS)

init.o : init.c init.h setup.h
	gcc -o init.o -c init.c $(CFLAGS)

matrices.o : matrices.c matrices.h setup.h
	gcc -o matrices.o -c matrices.c $(CFLAGS)


clean : 
	rm -rf *.o $(EXEC)
