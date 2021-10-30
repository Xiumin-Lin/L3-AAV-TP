#ifndef TP_ALGOAV_LISTE_H
#define TP_ALGOAV_LISTE_H

typedef struct {
	int x;
	int y;
} Point;

typedef struct cel {
	Point pt;
	struct cel *prev_cel;
	struct cel *next_cel;
} Cellule;

/**
 * Create a new cell and fill the cell's fields with the point "p".
 * @param p 	- the point to be stored in the cell.
 * @return 		a new cell with the point "p" in it.
 */
Cellule *NouvCel(Point p);

/**
 * Insert the cell "cel" after the place "pl" in the list "list".
 * @param pl 	- the place before the cell to be inserted.
 * @param cel 	- the cell to be inserted.
 * @param liste - the cell list.
 */
void InsererCellule(int pl, Cellule *cel, Cellule *liste);

/**
 * Delete the cell at position "pl" in the "list" list.
 * @param pl 		- the position of the cell to be deleted.
 * @param p_list 	- the cell list.
 */
void SupprimerCellule(int pl, Cellule **p_list);

/**
 * Display the list of cells.
 * @param liste - the cell list.
 */
void Afficher(Cellule *liste);

#endif //TP_ALGOAV_LISTE_H
