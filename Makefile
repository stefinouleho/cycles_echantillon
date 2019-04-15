CFLAGS=-g -Wall
#CFLAGS=-O2 -Wall


run: modelisation
	./modelisation 

init: 
	rm -rf Dossier
	rm -f dernier
	rm -f prochain
	rm -f tmp
	rm -f fichiers/liste_molecules_mces
	rm -f fichiers/liste_molecules_mces.save
	echo "0 0" > prochain
	cp fichiers/molecules.data fichiers/molecules.data.save
	mkdir Dossier
	touch Dossier/similarite.result
	touch Dossier/temps.result

val: modelisation
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./modelisation

modelisation: modelisation.o lecture_molecule_sdf.o fonctions_modelisation.o connexite.o
	gcc ${CFLAGS} modelisation.o lecture_molecule_sdf.o fonctions_modelisation.o connexite.o -o modelisation

modelisation.o: modelisation.c modelisation.h
	gcc ${CFLAGS} -c modelisation.c

fonctions_modelisation.o: fonctions_modelisation.c modelisation.h
		gcc ${CFLAGS} -c fonctions_modelisation.c

connexite.o: connexite.c modelisation.h
		gcc ${CFLAGS} -c connexite.c		
	
lecture_molecule_sdf.o: lecture_molecule_sdf.c lecture_molecule_sdf.h 
	gcc ${CFLAGS} -c lecture_molecule_sdf.c

clean: 
	rm -f modelisation
	rm -f modelisation.o
	rm -f lecture_molecule_sdf.o
	rm -f fonctions_modelisation.o
	rm -f connexite.o

