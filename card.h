//Tristan Gomez
//
//I wanted to take some old CS 163 programs and update them using knowledge acquired from later courses. I am writing this program in a more OO style using C++


//Denotes normal deck of cards length, not including Jokers.
const int MAX = 52;
const int HALF = 26;

#include <iostream>
#include <cstring>
#include <cctype>
#include <sys/time.h>
#include <stdlib.h>

//This represents one playing card. It contains an int representing its type 1-13. 1 is an "Ace", 11 is a "Jack", 12 is a "Queen", and 13 is a "King"
class card
{

	public:
		card();
		card(int toUse, char stoUse[]);
		~card();

		void display() const;
		void copy(const card & to_add);	
		void insert(int toUse, char * stoUse);
		int compare(const card & to_compare);


	private:

		int id; //Int 1 - 13
		char * suit; 
};


class deck
{

	public:
		deck();
		~deck();
		void display() const;
		bool pop(card & to_use);

	private:
		card array[MAX];
		int cardsLeft;
};
