#include "card.h"
#include <iostream>
int main()
{
	deck dealer;
    card temp;
    for(int i = 0; i < MAX; ++i)
    {
        dealer.pop(temp);
        temp.display();
    }
	dealer.~deck();
	exit(EXIT_SUCCESS);	
}
