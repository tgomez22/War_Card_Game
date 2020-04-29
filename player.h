#include "card.h"

class node
{
	public:
		node(const card & to_add);
		~node();
		void display() const;
		node *& to_next();
	private:
		card to_use;
		node * next;
};


class player
{
	public:
		player();
		~player();
		void display();
		void enqueue(const card & to_add);
		int count_cards()const;
	private:
		int count_cards(node * temp, node * rear)const;
		void remove_all(node *& rear);
		node * rear;
};

	
