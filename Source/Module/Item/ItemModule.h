typedef enum ItemId { RuleChange = 0, Star = 1, Bomb = 2, Win = 3 } ItemId;
typedef enum ItemState { Active = 0, Inactive = 1, Deleted = 2 } ItemState;

typedef struct Item {
	ItemId id;
	ItemState state;
	int roundCount;
} Item;

Item* getNextItem();
void checkAndRunItem(Item *item);
void putDownItem(Item *item);