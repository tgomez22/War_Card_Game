#include "card.h"

//contains the data of one card
class node
{
	public:
		node(const card & to_add);
		~node();
		void display() const;
		node *& toNext();
        void copyCard(card & destination);
	private:
		card toUse;
		node * next;
};

//Player has a queue of won cards from each round.
class player
{
	public:
		player();
		~player();
		void display();
		void enqueue(const card & toAdd);
		int countCards()const;
        bool dequeue(card & toTake);
	private:
		int countCards(node * temp, node * rear)const;
		void removeAll(node *& rear);
		node * rear;
};

	
