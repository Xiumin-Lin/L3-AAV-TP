#ifndef TP_ALGOAV_PRIM_H
#define TP_ALGOAV_PRIM_H

#define INFINI 1000.0 // un poids reel superieur à la plus grande longueur totale

typedef struct {
	void *data;
} Vertex;

typedef struct {
	Vertex *vertex1;
	Vertex *vertex2;
} Edge;

typedef float **MatriceFloat;

/**
 * Fonction qui retourne l’arbre couvrant de poids minimum d’un graphe valué et non orienté
 * depuis un sommet de référence aléatoire
 * @param adjacencePoids 	- matrice d’adjacence pondérée du graphe
 * @param ordre				- nb sommets
 * @return un arbre de poids minimum
 */
Edge *Prim(MatriceFloat adjacencePoids, int ordre);

Vertex *NouvVertex(void *data);

#endif //TP_ALGOAV_PRIM_H
