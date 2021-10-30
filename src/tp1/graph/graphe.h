#ifndef TP_ALGOAV_GRAPHE_H
#define TP_ALGOAV_GRAPHE_H

typedef int **Matrice;

/**
 * Procedure qui marque tous les sommets par ordre de voisinage depuis un sommet de reference
 * @param adjacence - matrice d'adjacence
 * @param ordre 	- nb de sommets
 * @param s 		- num du sommet de ref (le 1er sommet a pour num 0)
 */
void marquerVoisin(int **adjacence, int ordre, int s);

void afficherMarque(const int *tab, int ordre);

void afficherNonMarque(const int *tab, int ordre);

Matrice chargeGraphe(int ordre);

Matrice chargeGrapheAuto(int ordre);

void libereGraphe(Matrice adjacence, int ordre);

#endif //TP_ALGOAV_GRAPHE_H
