#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

void marquerVoisin(int **adjacence, int ordre, int s) {
	if(s >= ordre) {
		printf("[Err] s >= ordre !\n");
		return;
	} else if(adjacence == NULL) {
		printf("[Err] Matrix adjacence is NULL !\n");
		return;
	}
	// var locales
	int *marques = NULL; // tab dynamique indiquant si les sommets sont marqués ou non
	// int x, y; // num de sommets intermédiaires

	// allouer le tab "marques" de taille "ordre"
	marques = malloc(ordre * sizeof(int));
	// init les marquages à 0
	for(int i = 0; i < ordre; ++i) {
		marques[i] = 0;
	}
	// marque le sommet de ref "s" à 1
	marques[s] = 1;
	// Pour tous les sommets x marqués,marquer les sommets non marqué y adjacents à x
	for(int x = 0; x < ordre; ++x) {
		if(marques[x] == 1)
			for(int y = 0; y < ordre; ++y) {
				if(adjacence[x][y] == 1 && !marques[y]) {
					marques[y] = 1;
					printf("On marque le sommet y = [%d] voisin de x = [%d]\n", y, x);
				}
			}
	}

	afficherMarque(marques, ordre);
	afficherNonMarque(marques, ordre);
	free(marques);

}

void afficherMarque(const int *tab, int ordre) {
	if(tab == NULL) return;
	printf("Sommet Marquee = ");
	for(int i = 0; i < ordre; ++i) {
		if(tab[i] == 1) printf("%d, ", i + 1);
	}
	printf("\n");
}

void afficherNonMarque(const int *tab, int ordre) {
	if(tab == NULL) return;
	printf("Sommet Non Marquee = ");
	for(int i = 0; i < ordre; ++i) {
		if(tab[i] == 0) printf("%d, ", i + 1);
	}
	printf("\n");
}

Matrice chargeGraphe(int ordre) {
	Matrice matriceAdj = malloc(ordre * sizeof(int *));
	if(matriceAdj == NULL) return NULL;

	for(int i = 0; i < ordre; ++i) {
		matriceAdj[i] = malloc(ordre * (sizeof(int)));
		if(matriceAdj[i] != NULL)
			for(int j = 0; j < ordre; ++j) {
				matriceAdj[i][j] = 0;
				printf("matriceAdj[%d][%d] =", i, j);
				scanf_s("%d", &(matriceAdj[i][j]));
			}
		else
			return NULL;
	}

	// Affiche la matrice
	printf("Matrice adjacence : \n");
	for(int i = 0; i < ordre; ++i) {
		for(int j = 0; j < ordre; ++j) {
			printf("%d ", matriceAdj[i][j]);
		}
		printf("\n\n");
	}
	return matriceAdj;
}

Matrice chargeGrapheAuto(int ordre) {
	Matrice matriceAdj = malloc(ordre * sizeof(int *));
	if(matriceAdj == NULL) return NULL;

	for(int i = 0; i < ordre; ++i) {
		matriceAdj[i] = malloc(ordre * (sizeof(int)));
		if(matriceAdj[i] != NULL)
			for(int j = 0; j < ordre; ++j) {
				matriceAdj[i][j] = 0;
			}
		else
			return NULL;
	}
	matriceAdj[0][1] = 1;
	matriceAdj[1][0] = 1;
	matriceAdj[0][4] = 1;
	matriceAdj[4][0] = 1;
	matriceAdj[1][3] = 1;
	matriceAdj[3][1] = 1;
	matriceAdj[4][3] = 1;
	matriceAdj[3][4] = 1;
	matriceAdj[1][2] = 1;
	matriceAdj[2][1] = 1;
	matriceAdj[2][5] = 1;
	matriceAdj[5][2] = 1;
	matriceAdj[3][5] = 1;
	matriceAdj[5][3] = 1;
	matriceAdj[3][2] = 1;
	matriceAdj[2][3] = 1;

	for(int i = 0; i < ordre; ++i) {
		for(int j = 0; j < ordre; ++j) {
			printf("%d ", matriceAdj[i][j]);
		}
		printf("\n");
	}
	return matriceAdj;
}

void libereGraphe(Matrice adjacence, int ordre) {
	printf("Libere la memoire du graphe.");
	for(int i = 0; i < ordre; ++i) {
		free(adjacence[i]);
	}
	free(adjacence);
};
