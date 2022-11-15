#include "Card.h"

void drawCard(struct Player player, int pos)
{
    if (player.originCardSet->count == 0)
        return;
    if (pos == LEFT)
    {
        struct Card *tmp;
        tmp = player.originCardSet->root;
        player.originCardSet->root = player.originCardSet->root->next;
        tmp->next = player.leftCardSet->root;
        player.leftCardSet->root = tmp;
        player.originCardSet->count--;
        player.leftCardSet->count++;
    }
    else
    {
        struct Card *tmp;
        tmp = player.originCardSet->root;
        player.originCardSet->root = player.originCardSet->root->next;
        tmp->next = player.rightCardSet->root;
        player.rightCardSet->root = tmp;
        player.originCardSet->count--;
        player.rightCardSet->count++;
    }
}
