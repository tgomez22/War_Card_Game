#include "card.h"
using namespace std;

//Default Constructor
card::card(void)
{

	id = 0;
	suit = NULL;

}

//Copy Constructor
card::card(int toUse, char stoUse[])
{
    
	id = toUse;

	if(suit)
	{
		delete [] suit;
	}

	suit = new char[strlen(stoUse) + 1];
	strcpy(suit, stoUse);

}

//Destructor
card::~card(void)
{
	if(suit)
		delete [] suit;

	suit = NULL;

}


//Displays the value of a card.
void card::display(void) const
{
	if(id > 1 && id < 11)
	    cout<<id<<" of "<<suit<<"."<<endl;
	

	else
	{

		if(id == 1)
			cout<<"Ace";	

		else if(id == 11)
			cout<<"Jack";

		else if(id == 12)
			cout<<"Queen";

		else
			cout<<"King";

		cout<<" of "<<suit<<"."<<endl;

	}

	return;
}


//Compares value of calling object against value of the argument.
//Returns 1 if the calling object is of higher value.
//Returns -1 if the argument is of higher value.
//Returns 0 if a tie.
int card::compare(const card & to_compare)
{
	if(id > to_compare.id)
		return 1;
	else if(id < to_compare.id)
		return -1;
	else
		return 0;
}

//Copies the argument into the current card. Deallocates dynamic memory
//currently stored in card.
void card::copyFrom(const card & to_add)
{

	if(suit)
		delete [] suit;

	suit = new char[strlen(to_add.suit) + 1];
	strcpy(suit, to_add.suit);

	id = to_add.id;

	return;

}


//Setter for the card.
void card::insert(int toUse, char * stoUse)
{
	id = toUse;

	if(suit)
		delete [] suit;

	suit = new char[strlen(stoUse) + 1];
	strcpy(suit, stoUse);

	return;
}

////////////////////////////////////////////////////////////////////////////


//Default constructor.
deck::deck()
{
	cardsLeft = MAX;
	//Suits
	char first[] = "Hearts";
	char second[] = "Diamonds";
	char third[] = "Spades";
	char fourth[] = "Clubs";
    int j = 0; 
    for(int i = 1; i < 14; ++i)
    {

            array[j].insert(i, first);
            array[j + 1].insert(i, second);
            array[j + 2].insert(i, third);
            array[j + 3].insert(i, fourth);
            j += 4;
    }
/*
	array[0].insert(1, first);
	array[1].insert(1, second);
	array[2].insert(1, third);
	array[3].insert(1, fourth);

	array[4].insert(2, first);
	array[5].insert(2, second);
	array[6].insert(2, third);
	array[7].insert(2, fourth);

	array[8].insert(3, first);
	array[9].insert(3, second);
	array[10].insert(3, third);
	array[11].insert(3, fourth);

	array[12].insert(4, first);
	array[13].insert(4, second);
	array[14].insert(4, third);
	array[15].insert(4, fourth);

	array[16].insert(5, first);
	array[17].insert(5, second);
	array[18].insert(5, third);
	array[19].insert(5, fourth);

	array[20].insert(6, first);
	array[21].insert(6, second);
	array[22].insert(6, third);
	array[23].insert(6, fourth);

	array[24].insert(7, first);
	array[25].insert(7, second);
	array[26].insert(7, third);
	array[27].insert(7, fourth);

	array[28].insert(8, first);
	array[29].insert(8, second);
	array[30].insert(8, third);
	array[31].insert(8, fourth);

	array[32].insert(9, first);
	array[33].insert(9, second);
	array[34].insert(9, third);
	array[35].insert(9, fourth);

	array[36].insert(10, first);
	array[37].insert(10, second);
	array[38].insert(10, third);
	array[39].insert(10, fourth);

	
	array[40].insert(11, first);
	array[41].insert(11, second);
	array[42].insert(11, third);
	array[43].insert(11, fourth);

	array[44].insert(12, first);
	array[45].insert(12, second);
	array[46].insert(12, third);
	array[47].insert(12, fourth);

	array[48].insert(13, first);
	array[49].insert(13, second);
	array[50].insert(13, third);
	array[51].insert(13, fourth);
    */
    
}


//
bool deck::pop(card & to_use)
{
    if(cardsLeft <= 0)
        return false;

   struct timeval seed;
   gettimeofday(&seed, NULL);
   srand(seed.tv_usec);
    
   int toShuffle = rand() % cardsLeft;
   --cardsLeft;
    
   card temp;
   temp.copyFrom(array[toShuffle]);
   to_use.copyFrom(temp);
   array[toShuffle].copyFrom(array[cardsLeft]);
   array[cardsLeft].copyFrom(temp);

   return true; 
   
}

deck::~deck()
{
}

void deck::display()const
{
	for(int i = 0; i < MAX; ++i)
		array[i].display();

	return;
}
