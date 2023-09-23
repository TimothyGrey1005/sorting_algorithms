#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - card suit enumeration.
 * @SPADE: suit of spades.
 * @HEART: suit of hearts.
 * @CLUB: suit of clubs.
 * @DIAMOND: suit of diamonds.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - deck of playing cards
 *
 * @value: card value
 * From "Ace card" ranging to "King card"
 * @kind: Card kind
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - card deck
 *
 * @card: Pointer to card of node
 * @prev: Pointer to previous node of list
 * @next: Pointer to next node of list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
