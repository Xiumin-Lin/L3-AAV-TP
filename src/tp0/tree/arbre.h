#ifndef TP_ALGOAV_ARBRE_H
#define TP_ALGOAV_ARBRE_H

// ---------- Arbre Generique ----------
typedef struct noeud_generique {
	int num;
	char val;
	struct noeud_generique *node_list;
} NoeudGenerique;

typedef NoeudGenerique *ArbreGenerique; // ArbreGenerique == NoeudGenerique *

// ---------- Arbre Binaire ----------
typedef struct noeud_binaire {
	int num;
	char val;
	struct noeud_binaire *n_left;
	struct noeud_binaire *n_right;
} Noeud;

typedef Noeud *ArbreBinaire; // ArbreBinaire == Noeud *

Noeud *NouvNoeud(char carac);

Noeud *RechercheNoeud(Noeud *ptr_n, int node_num);

void InsererNoeudFG(Noeud *ptr_n, ArbreBinaire tree, int node_num);

void ParcoursPrefixe(ArbreBinaire arbre);

void InsererNoeudFD(Noeud *ptr_n, ArbreBinaire tree, int node_num);

#endif //TP_ALGOAV_ARBRE_H
