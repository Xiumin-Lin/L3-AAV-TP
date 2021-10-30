#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

Cellule *NouvCel(Point *p) {

	Cellule *cel = malloc(sizeof(Cellule));
	if(cel != NULL) {
		cel->data = p;
		cel->prev_cel = NULL;
		cel->next_cel = NULL;
	}
	return cel;
}

Cellule *NouvCelGenerique(void *v){
	Cellule *cel = malloc(sizeof(Cellule));
	if(cel != NULL) {
		cel->data = v;
		cel->prev_cel = NULL;
		cel->next_cel = NULL;
	}
	return cel;
}

void InsererCellule(int pl, Cellule *cel, Cellule *liste) {
	if(liste == NULL || cel == NULL) {
		printf("Liste or cel is NULL");
		return;
	}
	Cellule *current_cel = liste;
	for(int i = 1; i < pl; ++i) {
		if(current_cel->next_cel != NULL) current_cel = current_cel->next_cel;
		else {
			printf("Last cell position is %d, can't place a cell at position %d !\n", i, pl);
			return;
		}
	}
	current_cel->next_cel = cel;
	cel->prev_cel = current_cel;
}

void SupprimerCellule(int pl, Cellule **p_list) {
	if(p_list == NULL) {
		printf("Liste or cel is NULL");
	} else {
		Cellule *current_cel = *p_list;
		for(int i = 1; i < pl; ++i) {
			if(current_cel->next_cel != NULL) current_cel = current_cel->next_cel;
			else {
				printf("Last cell position is %d, can't delete the cell at position %d !\n", i, pl);
				return;
			}
		}

		if(current_cel->prev_cel == NULL && current_cel->next_cel == NULL) {
			// delete the only item in the list, so the list is also deleted
			printf("Delete the list\n");
			free(current_cel);
			*p_list = NULL;
		} else {

			if(current_cel->prev_cel != NULL)
				current_cel->prev_cel->next_cel = current_cel->next_cel;

			if(current_cel->next_cel != NULL)
				current_cel->next_cel->prev_cel = current_cel->prev_cel;

			if(pl == 1) {
				*p_list = current_cel->next_cel;
			}

			free(current_cel);
		}
	}
}

void Afficher(Cellule *liste) {
	if(liste == NULL) {
		printf("Liste is NULL");
		return;
	}
	Cellule *current_cel = liste;
	int counter = 1;
	do {
		printf("Cellule %d : (%d,%d);\n", counter, (*(Point*)(current_cel->data)).x, (*(Point*)(current_cel->data)).y);
		current_cel = current_cel->next_cel;
		counter++;
	} while(current_cel != NULL);
}