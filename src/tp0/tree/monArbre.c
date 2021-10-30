#include <stdio.h>
#include "arbre.h"

int main() {
	printf("Hello, World! TEST ARBRE\n");
	// TP12 L2 Prog Imperative
	Noeud *node_a = NouvNoeud('A');
	Noeud *node_b = NouvNoeud('B');
	Noeud *node_c = NouvNoeud('C');
	Noeud *node_d = NouvNoeud('D');
	if(node_a != NULL && node_b != NULL && node_c != NULL && node_d != NULL) {
		ArbreBinaire arbre = node_a;
		printf("%d\n", node_a->num);
		printf("%d\n", node_b->num);
		printf("%d\n", node_c->num);
		printf("%d\n", node_d->num);

		InsererNoeudFG(node_b, arbre, 1);
		InsererNoeudFD(node_c, arbre, 1);
		InsererNoeudFG(node_d, arbre, 2);
		InsererNoeudFG(NouvNoeud('E'), arbre, 4);
		InsererNoeudFD(NouvNoeud('F'), arbre, 4);

		int num_to_find = 4;
		Noeud *copy_node = RechercheNoeud(arbre, num_to_find);
		if(copy_node != NULL) printf("copy_node num = %d is %c.\n", copy_node->num, copy_node->val);
		else printf("Node with num = %d not found.\n", num_to_find);
		printf("Prefix path : ");
		ParcoursPrefixe(arbre);
	}
	return 0;
}

