#include "similarite_cycles.h"


int main(int argc, char *argv[])
{

	struct molecule *M = lecture_fichier_chebi();
	FILE *F = fopen("prochain","r");
	if( F == NULL)
	{
		fprintf(stdout, " Cannot open the file prochain");
		exit(10);
	}
	int numero, indice;
	
	fscanf(F,"%d", &numero);
	fscanf(F,"%d", &indice);
	fclose(F);

	int *liste_molecules = lecture_liste_molecules();

	// on verifie si le fichier GrapheCyclesPrecalcules.cycles existe 
	int position;
	F = fopen("graphe_cycle","r");
	if( F == NULL)
	{
		fprintf(stdout, " Cannot open the file graphe_cycle");
		exit(11);
	}
	fscanf(F,"%d", &position);
	fclose(F);

	GRAPHE_CYCLE *C = NULL;
	if( position != total_molecules)// le fichier fichiers/GrapheCyclesPrecalcules.cycles est totalement rempli
	{
		calcul_graphe_cycles_all(liste_molecules, M, position);
	}
	C = lecture_fichier_graphes_cycles();
	int i,j;
	
	
	printf("\n Debut du calcul de la similarite  : %.3lf s\n",chrono());
	for ( i = numero ; i < total_molecules; i++)
	{
		
		fprintf(stdout,"\r%5d / %d",i,total_molecules);
		fflush(stdout); 
		for ( j = indice ; j < i ; j++)
		{
			calcul_similarite_cycle_optimisation(i,j,C);
		}
		indice = 0;
		
	} 
	printf("\n Fin du calcul de la similarite  : %.3lf s\n",chrono());
	int nb_mol;
	printf("3. Libération de la mémoire : %.3lf s\n",chrono());

	

	free(liste_molecules);
	for(nb_mol= 0 ; nb_mol < total_molecules ; nb_mol++) 
		liberer_graphe_cycles(C[nb_mol]);
	for(nb_mol= 0 ; nb_mol < NB_MOLECULES ; nb_mol++) 
		liberer_molecule(M[nb_mol]);
	free(M);
	exit(0);
}
