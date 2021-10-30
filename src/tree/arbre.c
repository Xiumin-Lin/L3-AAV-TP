#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"

Noeud *NouvNoeud(char carac) {
	static int id = 1;
	Noeud *node = malloc(sizeof(Noeud));
	if(node != NULL) {
		node->num = id++;
		node->val = carac;
		node->n_left = NULL;
		node->n_right = NULL;
	}
	return node;
}

Noeud *RechercheNoeud(Noeud *ptr_n, int node_num) {
	if(node_num <= 0 || ptr_n == NULL) return NULL;
	if(ptr_n->num == node_num) return ptr_n;

	Noeud *tmp_node = NULL;
	tmp_node = RechercheNoeud(ptr_n->n_left, node_num);
	if(tmp_node == NULL) return RechercheNoeud(ptr_n->n_right, node_num);

	return tmp_node;
}

void InsererNoeudFG(Noeud *ptr_n, ArbreBinaire tree, int node_num) {
	if(ptr_n == NULL) {
		printf("Can't insert a NULL node in the tree!\n");
		return;
	}
	Noeud *node_to_find = RechercheNoeud(tree, node_num);
	if(node_to_find != NULL) {
		if(node_to_find->n_left != NULL) {
			ptr_n->n_left = node_to_find->n_left;
			node_to_find->n_left = ptr_n;
		} else node_to_find->n_left = ptr_n;
	} else printf("Failure of insertion : node num = %d not found. \n", node_num);
}

void ParcoursPrefixe(ArbreBinaire arbre) {
	if(arbre == NULL) return;
	printf("%c", arbre->val);
	ParcoursPrefixe(arbre->n_left);
	ParcoursPrefixe(arbre->n_right);
}

void InsererNoeudFD(Noeud *ptr_n, ArbreBinaire tree, int node_num) {
	if(ptr_n == NULL) {
		printf("Can't insert a NULL node in the tree!\n");
		return;
	}
	Noeud *node_to_find = RechercheNoeud(tree, node_num);
	if(node_to_find != NULL) {
		if(node_to_find->n_right != NULL) {
			ptr_n->n_right = node_to_find->n_right;
			node_to_find->n_right = ptr_n;
		} else node_to_find->n_right = ptr_n;
	} else printf("Failure of insertion : node num = %d not found. \n", node_num);
}