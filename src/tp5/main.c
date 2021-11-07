#include <stdio.h>
#include <stdlib.h>
#include "../tp0/tree/arbre.h"

#define ZERO_ASCII 48

/**
 * Genere et affiche tous les arbres binaires de taille ordre
 * @param ordre nombre de sommet
 */
void tousLesArbresBinaire(int ordre);

int main() { // TODO bloqué...
	printf("Hello, World! TEST TOUS LES ARBRE BINAIRE\n");
	int n = 4;
	tousLesArbresBinaire(n);
}

void tousLesArbresBinaire(int ordre) {
	if(ordre <= 0) {
		printf("Pas de solution !");
		return;
	}
	// Cree la 1ere solution (tout les noeuds sont dans le fils gauche)
	ArbreBinaire soluce = NouvNoeud((char) ZERO_ASCII);
	// Cree la derniere solution (tout les noeuds sont dans le fils droit)
	ArbreBinaire lastSoluce = NouvNoeud((char) ZERO_ASCII);
	if(soluce == NULL || lastSoluce == NULL) {
		printf("Memoire insuffisante !");
		return;
	}
	// Init la 1er et dernier solution
	for(int i = 1; i < ordre; ++i) {
		InsererNoeudFG(NouvNoeud((char) (ZERO_ASCII + i)), soluce, (ZERO_ASCII + i - 1));
		InsererNoeudFD(NouvNoeud((char) (ZERO_ASCII + i)), lastSoluce, (ZERO_ASCII + i - 1));
	}

	// Printf la 1ere solution en ParcoursPrefixe
	// Ensuite
	// WHILE ParcoursPrefixe(soluce) != ParcoursPrefixe(lastSoluce) DO
	//

	free(soluce);
	free(lastSoluce);
}

