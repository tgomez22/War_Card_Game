const int MAX = 52;
#include <iostream>
#include <cstring>
#include <cctype>
#include <sys/time.h>
#include <stdlib.h>

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

		int id;
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
