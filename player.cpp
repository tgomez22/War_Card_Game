#include "player.h"

//Copy Constructor. 
node::node(const card & toAdd)
{
	toUse.copy(toAdd);
	next = NULL;
}

//destructor.
node::~node()
{
	next = NULL;
}

void node::display()const
{
	toUse.display();
	return;
}

node *& node::toNext() 
{
	return next;
}

void node::copyCard(card & destination)
{
    destination.copy(toUse);
    return;
}
////////////////////PLAYER/////////////////////////

player::player()
{
	rear = NULL;
}

player::~player()
{
    if(!rear)
        return;

    else if(rear == rear->toNext()){
        delete rear;
        rear = NULL;
    }

    else{
        node * temp = rear->toNext();
        rear->toNext() = NULL;
        removeAll(temp);
        rear = NULL;
    }
}

void player::removeAll(node *& rear)
{
	if(!rear)
		return;

	removeAll(rear->toNext());

	delete rear;
	rear = NULL;

	return;
}

void player::enqueue(const card & toAdd)
{
	if(!rear)
	{
		rear = new node(toAdd);
		rear->toNext() = rear;
		return;
	}

	else
	{
		node * temp = rear->toNext();
		rear->toNext() = new node(toAdd);
		rear = rear->toNext();
		rear->toNext() = temp;

		return;
	}
		
}

int player::countCards()const
{
	if(!rear)
		return 0;
	else if(rear == rear->toNext())
		return 1;
	else
	{
		node * temp = rear->toNext();
		return countCards(temp, rear);
	}
}

int player::countCards(node * temp, node * rear)const
{
	int count = 0;

	if(temp == rear)
		return ++count;

	count = countCards(temp->toNext(), rear);

	return ++count;
	
}

bool player::dequeue(card & toTake)
{
    if(!rear)
        return false;

    else if(rear->toNext() == rear)
    {
        rear->copyCard(toTake);
        delete rear;
        rear = NULL;
        return true;
    }

    else
    {
        node * temp = rear->toNext();
        rear->toNext() = temp->toNext();
        temp->copyCard(toTake);
        delete temp;
        temp = NULL;
        return true;
    }
}
