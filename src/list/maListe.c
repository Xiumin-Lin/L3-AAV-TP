#include <stdio.h>
#include "liste.h"

int main() {
	printf("Hello, World! TEST LISTE\n");
	// TP11 L2 Prog Imperative
	Point p1 = {-1, 1};
	Point p2 = {1, 1};
	Point p3 = {1, -1};
	Point p4 = {-1, -1};
	Cellule *liste = NouvCel(p1);
	Cellule *cell2 = NouvCel(p2);
	Cellule *cell3 = NouvCel(p3);
	Cellule *cell4 = NouvCel(p4);
	if(liste != NULL && cell2 != NULL && cell3 != NULL && cell4 != NULL) {
		InsererCellule(1, cell2, liste);
		InsererCellule(2, cell3, liste);
		InsererCellule(3, cell4, liste);
		Afficher(liste);
		printf("Delete first point.\n");
		SupprimerCellule(1,&liste);
		SupprimerCellule(3,&liste);
		Afficher(liste);
	} else printf("Memory allocation failure !");
	return 0;
}
