#include "similarite_cycles.h"


void calcul_similarite_cycle( int i ,int j, struct molecule *M, int *liste_molecules)
{
	int pos1,pos2;

	float r;
	float start,stop;
	pos1 = position_M(liste_molecules[i],M);
	pos2 = position_M(liste_molecules[j],M);
	start = chrono();
	GRAPHE_CYCLE c = construction_graphe_cycles(M[pos1]);
	GRAPHE_CYCLE d = construction_graphe_cycles(M[pos2]);
	r = similarite(c,d);
	stop = chrono();
	char fichier[256];
	//sprintf(fichier,"Dossier/%d_%d.result",i,j);
	sprintf(fichier,"Dossier/similarite.result");
	
	FILE *F = fopen(fichier,"a");
	if( F == NULL)
	{
		fprintf(stdout, "Cannot open the file %s\n",fichier);
		exit(19);
	}
	
	sprintf(fichier,"Dossier/temps.result");
	FILE *G = fopen(fichier,"a");
	if( G == NULL)
	{
		fprintf(stdout, " Cannot open the file %s\n",fichier);
		exit(19);
	}
	fprintf(F,"%.2f	",r);
	fprintf(G,"%.2f	",stop - start);
	
	if( j == i - 1)
	{
		fprintf(F,"\n");
		fprintf(G,"\n");
	}
		
	fclose(F);
	fclose(G);
	
	sauvegarde_compteur(i,j);
	liberer_graphe_cycles(c);
	liberer_graphe_cycles(d);
	//printf(" %d %d %f\n",pos1, pos2 ,r);
}

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


	int i,j;
	
	
	
	
	for ( i = numero ; i < total_molecules; i++)
	{
		
		fprintf(stdout,"\r%5d / %d",i,total_molecules);
		fflush(stdout); 

		for ( j = indice ; j < i ; j++)
		{
			//printf(" %d %d\n",i,j );
			calcul_similarite_cycle(i,j, M,liste_molecules);
			
			
		}
		indice = 0;
		
	} 

	int nb_mol;
	printf("3. Libération de la mémoire : %.3lf s\n",chrono());

	

	free(liste_molecules);
	for(nb_mol= 0 ; nb_mol < NB_MOLECULES ; nb_mol++) 
		liberer_molecule(M[nb_mol]);
	free(M);
	exit(0);
}
