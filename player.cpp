#include "player.h"

node::node(const card & to_add)
{
	to_use.copy(to_add);
	next = NULL;
}

node::~node()
{
	if(next)
		delete next;
	next = NULL;
}

void node::display()const
{
	to_use.display();
	return;
}

node *& node::to_next() 
{
	return next;
}
////////////////////PLAYER/////////////////////////

player::player()
{
	rear = NULL;
}

player::~player()
{
	node * temp = rear->to_next();
	rear->to_next() = NULL;
	remove_all(temp);
}

void player::remove_all(node *& rear)
{
	if(!rear)
		return;

	remove_all(rear->to_next());

	delete rear;
	rear = NULL;

	return;
}

void player::enqueue(const card & to_add)
{
	if(!rear)
	{
		rear = new node(to_add);
		rear->to_next() = rear;
		return;
	}

	else
	{
		node * temp = rear->to_next();
		rear->to_next() = new node(to_add);
		rear = rear->to_next();
		rear->to_next() = temp;

		return;
	}
		
}

int player::count_cards()const
{
	if(!rear)
		return 0;
	else if(rear == rear->to_next())
		return 1;
	else
	{
		node * temp = rear->to_next();
		return count_cards(temp, rear);
	}
}

int player::count_cards(node * temp, node * rear)const
{
	int count = 0;

	if(temp == rear)
		return ++count;

	count = count_cards(temp->to_next(), rear);

	return ++count;
	
}
