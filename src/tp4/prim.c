#include <stdlib.h>
#include "prim.h"

Edge *Prim(MatriceFloat adjacencePoids, int ordre) {
	// var locales
	Edge *arbre; // arbre d'incidence noeud-arc de poids minimum a retourner
	int indiceA = 0; // indice de l'arbre init à 0
	int *marques = NULL; // tab indiquant si les sommets sont marques ou non
	int s, x, ymin; // num de somtes intermediaires
	float min; // distance min du prochain sommet a marquer

	arbre = malloc((ordre - 1) * sizeof(Edge));
	marques = malloc(ordre * sizeof(int));
	for(int i = 0; i < ordre; ++i) {
		marques[i] = 0;
	}

	// choisir un sommet aleatoire s compris entre 0 et ordre - 1
	s = rand() % ordre;
	marques[s] = 1; // marquer le sommet s

	while(indiceA < ordre - 1) {
		min = INFINI;

		// pour tous les sommets x marques, chercher le sommet de
		// longueur minimal "ymin" adjacent a x et non marques
		for(x = 0; x < ordre; ++x) {
			if(marques[x])
				for(int y = 0; y < ordre; ++y) {
					if(adjacencePoids[x][y] && !marques[y] && adjacencePoids[x][y] < min) {
						min = adjacencePoids[x][y]; // poids min
						ymin = y;
					}
				}
		}

		// marquer les sommet "ymin" de longueur min
		marques[ymin] = 1;
		// inserer l'arete (x, ymin) de longueur min a la position "indiceA" de l'arbre
		int *copy_x = malloc(sizeof(int));
		*copy_x = x;
		int *copy_ymin = malloc(sizeof(int));
		*copy_ymin = ymin;
		arbre[indiceA].vertex1 = NouvVertex(&copy_x);
		arbre[indiceA].vertex2 = NouvVertex(&copy_ymin);
		// passer a l'arete suivante de l'arbre
		indiceA++;
	}

	free(marques);
	return arbre;
}

Vertex *NouvVertex(void *data){
	Vertex *v = malloc(sizeof(Vertex));
	if(v != NULL) v->data = data;
	return v;
}