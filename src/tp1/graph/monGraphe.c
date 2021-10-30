#include <stdio.h>
#include "graphe.h"

int main() {
	printf("Hello, World! TEST GRAPHE\n");
	int ordre = 6; // par défaut, ordre = 6 pour que chargeGraphAuto puisse fonctionner

	// Saisie Automatique
//	Matrice matriceAdj = chargeGrapheAuto(ordre);

	// Saisie Manuelle
	printf("Entrer l'ordre du graphe :");
	scanf_s("%d", &ordre);
	Matrice matriceAdj = chargeGraphe(ordre);

	if(matriceAdj != NULL) {
		int ref = 0;
		printf("Entrer le numero du sommet de ref :");
		scanf_s("%d", &ref);
		marquerVoisin(matriceAdj, ordre, ref);
	}
	libereGraphe(matriceAdj, ordre);
	return 0;
}