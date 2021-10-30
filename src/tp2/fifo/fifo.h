#ifndef TP_ALGOAV_FIFO_H
#define TP_ALGOAV_FIFO_H

#include "../../tp0/list/liste.h"

typedef Cellule *Fifo;

Fifo *NouvFifo(int *val);

void AddCellInFifo(void *data, Fifo *f);

void *PopFirst(Fifo *f);

void MoveToFirst(Fifo *f);

void MoveToPrev(Fifo *f);

void MoveToLast(Fifo *f);

void MoveToNext(Fifo *f);

#endif //TP_ALGOAV_FIFO_H
