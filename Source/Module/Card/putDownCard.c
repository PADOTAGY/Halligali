#include "card.h"

void putDownCard(CardSet *origin, CardSet *direction)
{
    if (origin->count == 0)
        return;
    if (direction->root->id == BLOCK){
        return;
    }
    Card *tmp;
    tmp = origin->root;
    origin->root = origin->root->next;
    tmp->next = direction->root;
    direction->root = tmp;
    origin->count--;
    direction->count++;
}