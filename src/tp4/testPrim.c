#include <stdlib.h>
#include <stdio.h>
#include "prim.h"

int main() {
	int ordre = 8;
	MatriceFloat adj_poids = malloc(ordre * sizeof(float *));
	if(adj_poids == NULL) exit(0);
	for(int i = 0; i < ordre; ++i) {
		adj_poids[i] = malloc(ordre * sizeof(float));
		if(adj_poids[i] == NULL) {
			free(adj_poids);
			exit(0);
		}
		for(int j = 0; j < ordre; ++j) {
			adj_poids[i][j] = 0;
		}
	}
	// exemple du cours
	adj_poids[0][1] = 3; // 1 2
	adj_poids[1][0] = 3;

	adj_poids[0][2] = 1; // 1 3
	adj_poids[2][0] = 1;

	adj_poids[1][2] = 4; // 2 3
	adj_poids[2][1] = 4;

	adj_poids[1][4] = 5; // 2 5
	adj_poids[4][1] = 5;

	adj_poids[1][3] = 3; // 2 4
	adj_poids[3][1] = 3;

	adj_poids[2][5] = 2; // 3 6
	adj_poids[5][2] = 2;

	adj_poids[3][6] = 2; // 4 7
	adj_poids[6][3] = 2;

	adj_poids[3][7] = 3; // 4 8
	adj_poids[7][3] = 3;

	adj_poids[4][6] = 4; // 5 7
	adj_poids[6][4] = 4;

	adj_poids[5][7] = 6; // 6 8
	adj_poids[7][5] = 6;

	adj_poids[6][7] = 1; // 7 8
	adj_poids[7][6] = 1;

	Edge *arbre = Prim(adj_poids, ordre);
	for(int i = 0; i < ordre - 1; ++i) {
		printf("(%d, %d)", *(int *) (arbre[i].vertex1->data), *(int *) (arbre[i].vertex2->data));
	}

	free(adj_poids);
	free(arbre);
}

