#include <stdio.h>
#include <stdlib.h>
#include "../tp1/graph/graphe.h"
#include "fifo/fifo.h"

/**
 * Procedure qui recherche le plus court chemin depuis un sommet de reference.
 * @param adjacence - matrice d’adjacence du graphe
 * @param ordre 	- nombre de sommets
 * @param s 		- numero de sommet de reference
 * @param l 		- tab dynamique alloue des longueurs min des sommets depuis s
 * @param pred 		- tab dynamique alloue des predecesseurs des sommets
 */
void plusCourtChemin(Matrice adjacence, int ordre, int s, int *l, int *pred);

void AfficheTableau(const int tab[], int ordre);

int main() {
	printf("Hello, World! TEST GRAPHE\n");
	int ordre = 6;
	Matrice matriceAdj = chargeGrapheAuto(ordre);

	if(matriceAdj != NULL) {
		int *l = malloc(ordre * sizeof(int));
		int *pred = malloc(ordre * sizeof(int));

		int ref = 0;
		printf("Entrer le numero du sommet de ref (le 1er sommet a pour num 0) :");
		scanf_s("%d", &ref);

		plusCourtChemin(matriceAdj, ordre, ref, l, pred);

		free(l);
		free(pred);
	}
	libereGraphe(matriceAdj, ordre);
	return 0;
}

void plusCourtChemin(Matrice adjacence, int ordre, int s, int *l, int *pred) {
	if(adjacence == NULL || ordre < 0 || s < 0 || l == NULL || pred == NULL) {
		printf("Un des parametre est invalide !");
		return;
	}
	int *marques = NULL; // tab dynamique indiquant si les sommets sont marqués ou non
	Fifo *f = NULL; // file d’attente de sommets
	// Allouer le tableau marques de taille "ordre"
	marques = malloc(ordre * sizeof(int));
	// Initialiser les marquages et les longueurs minimales à 0
	for(int i = 0; i < ordre; ++i) {
		marques[i] = 0;
		l[i] = 0;
		pred[i] = -1;
	}
	// Marquer le sommet s à 1
	marques[s] = 1;
	// Creer (allouer) la file f et enfiler s dans f
	f = NouvFifo(&s);
	if(f != NULL) {
		while(*f != NULL) {
			int x = *(int*) PopFirst(f); //  Defiler le 1er sommet de la file f
			for(int y = 0; y < ordre; ++y) {
				printf("x = %d, y = %d", x, y); // Debug
				if(adjacence[x][y] && !marques[y]) {
					marques[y] = 1;
					printf(", Marque y = %d", y);
					// enfiler le sommet y à la fin de f
					int *ptr_y = malloc(sizeof(int));
					*ptr_y = y;
					AddCellInFifo(ptr_y, f);
					pred[y] = x;  // x est le prédécesseur de y
					l[y] = l[x] + 1; // incrémenter la longueur de y
				}
				printf("\n");
			}
		}
	} else printf("Memoire insuffisante");
	free(marques);
	free(f);

	printf("Tab des longueurs min des sommets depuis s :\n");
	AfficheTableau(l, ordre);
	printf("Tab des predecesseurs des sommets :\n");
	AfficheTableau(pred, ordre);
}

void AfficheTableau(const int tab[], int ordre) {
	printf("[");
	for(int i = 0; i < ordre; ++i) {
		printf(" %d,", tab[i]);
	}
	printf("]\n");
}