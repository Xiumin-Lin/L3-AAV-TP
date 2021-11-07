#include <stdlib.h>
#include <stdio.h>
#include "fifo.h"

Fifo *NouvFifo(int *val) {
	Fifo *f = malloc(sizeof(Fifo));
	if(f != NULL) {
		*f = NouvCelGenerique(val);
	}
	return f;
}

void AddToFirstInFifo(void *data, Fifo *f) {
	if(f == NULL) return;
	Cellule *new_cell = NouvCelGenerique(data);
	if(new_cell == NULL) {
		printf("Echec de l'ajout : Memoire insuffissante.");
		return;
	}
	MoveToFirst(f);
	Cellule *first_cell = *f;
	new_cell->next_cel = first_cell;
	new_cell->prev_cel = NULL;
	if(first_cell != NULL) first_cell->prev_cel = new_cell;
	*f = new_cell;
}

void *PopLast(Fifo *f) {
	void *ret = NULL;
	if(f != NULL && *f != NULL) {
		Cellule *future_last_cell = NULL;

		MoveToLast(f);
		Cellule *last_cell = *f;
		if(last_cell != NULL) {
			future_last_cell = last_cell->prev_cel;
			ret = last_cell->data;
			free(last_cell);
			last_cell = NULL;
		}

		if(future_last_cell != NULL) future_last_cell->next_cel = NULL;
		*f = future_last_cell;
	}
	return ret;
}

void MoveToFirst(Fifo *f) {
	if(f != NULL && *f != NULL) {
		while((*f)->prev_cel != NULL) MoveToPrev(f);
	}
}

void MoveToPrev(Fifo *f) {
	if(f != NULL && *f != NULL) *f = (*f)->prev_cel;
}

void MoveToLast(Fifo *f) {
	if(f != NULL && *f != NULL) {
		while((*f)->next_cel != NULL) MoveToNext(f);
	}
}

void MoveToNext(Fifo *f) {
	if(f != NULL && *f != NULL) *f = (*f)->next_cel;
}