#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define LIST_T int

//////////////// STRUCTURES ////////////////

typedef struct List {
	LIST_T* buffer;
	unsigned int capacity;

	unsigned int head;
	unsigned int tail;
	unsigned int length;
} List;

typedef unsigned int Place;

//////////////// METHODES ////////////////

// Constructeur
	List list_new_empty(); // creer_vide
////////////////

// Destructeurs
	void list_destroy(List l);
///////////////

// Accesseurs
	bool list_is_empty(List l); // est_vide
	bool list_is_tail(List l, Place nd); // est_dernier
	bool list_is_head(List l, Place nd); // est premier

	Place list_next(List l, Place nd); // successeur
	Place list_previous(List l, Place nd); // predecesseur

	LIST_T list_get(List l, Place nd); // contenu
	Place list_head(List l); // premier
	Place list_tail(List l); // dernier
	LIST_T list_head_get(List l); // contenu(premier)
	LIST_T list_tail_get(List l); // contenu(dernier)

	unsigned int list_length(List l);
/////////////

// Mutateurs
	List list_append_tail(List l, LIST_T x); // inserer_en_queue
	List list_remove_tail(List l); // supprimer_en_queue
	List list_append_head(List l, LIST_T x); // inserer_en_tete
	List list_remove_head(List l); // supprimer_en_tete
////////////

// Affichage
	void list_display(List l, char* buffer); // afficher
////////////
#endif