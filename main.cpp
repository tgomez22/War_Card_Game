#include "player.h"

void screenClear();
bool again();
void welcome(char userName[]);
void rules();
void playGame(char userName[]);
bool aTurn();

int main()
{
    using namespace std;

    char userName[MAX];

    deck dealer;

    cout<<"Please enter your user name: ";
    cin.get(userName, MAX, '\n');
    cin.ignore(100, '\n');

    do
    {


        screenClear();

        welcome(userName);

        screenClear();

        playGame(userName);

        screenClear(); 

    }while(again());

	return 0;
}

void screenClear()
{
    using namespace std;

    for(int i = 0; i < 200; ++i)
        cout<<endl;

    return;
}

bool again()
{
    using namespace std;

    char response;

    cout<<"Would you like to play again? Y or N: ";
    cin>>response;
    cin.ignore(100, '\n');
    response = toupper(response);

    if(response == 'Y')
        return true;
    else
        return false;

}

void welcome(char userName[])
{
    using namespace std;
    int response;
    do
    {
        cout<<"Hello, "<<userName<<" , welcome to WAR!"<<endl;
        cout<<"Please enter '1' to play the game, or enter '2' to read the rules: "<<endl;
        cin>>response;
        cin.ignore(100, '\n');
        
        if(response == 2)
        {
            screenClear();
            rules();
            screenClear();
            response = 1;
        }

    

    }while(response != 1); 

    return;
}

void playGame(char userName[])
{
    using namespace std;


    deck dealer;

    player humanPlayer;
    player aiPlayer;
    player tempPile;

    card humanTemp;
    card aiTemp;

    int roundScoring = 0;
    int tempPileSize = 0;

    char doesNothing;

    for(int i = 0; i < HALF; ++i)
    {
        dealer.pop(humanTemp);
        dealer.pop(aiTemp);
        
        roundScoring = humanTemp.compare(aiTemp); 

        if(roundScoring == 1)
        {
            
            cout<<userName<<" has won the round by drawing: ";
            humanTemp.display();
            cout<<endl;

            cout<<"The AI player drew: ";
            aiTemp.display();
            cout<<endl;

            cout<<"Press any key to continue: ";
            cin>>doesNothing;
            cin.ignore(100, '\n');

            humanPlayer.enqueue(humanTemp);
            humanPlayer.enqueue(aiTemp);

            if(tempPileSize > 0)
            {
                for(int i = 0; i < tempPileSize; ++i)
                {
                   tempPile.dequeue(humanTemp);
                   humanPlayer.enqueue(humanTemp);
                }
                tempPileSize = 0;

            }
        }

        else if(roundScoring == -1)
        {
            cout<<"The AI player won the round by drawing: ";
            aiTemp.display();
            cout<<endl;

            cout<<userName<<" drew: ";
            humanTemp.display();
            cout<<endl;

            cout<<"Press any key to continue: ";
            cin>>doesNothing;
            cin.ignore(100, '\n');

            aiPlayer.enqueue(humanTemp);
            aiPlayer.enqueue(aiTemp);

            if(tempPileSize > 0)
            {
                for(int i = 0; i < tempPileSize; ++i)
                {
                    tempPile.dequeue(aiTemp);
                    aiPlayer.enqueue(aiTemp);
                }
                tempPileSize = 0;
            }
        }

        else
        {
            cout<<"The round was a draw!!"<<endl;
            cout<<userName<<" drew: ";
            humanTemp.display();
            cout<<endl;

            cout<<"The AI player drew: ";
            aiTemp.display();
            cout<<endl;
            
            cout<<"Press any key to continue: ";
            cin>>doesNothing;
            cin.ignore(100, '\n');

            tempPile.enqueue(humanTemp);
            tempPile.enqueue(aiTemp);
            tempPileSize += 2;
        }

        screenClear();

    } 

    int humanScore = humanPlayer.countCards();
    int aiScore = aiPlayer.countCards();

    if(humanScore > aiScore)
    {
        cout<<"Congratulations "<<userName<<" , you won the game, collecting:  "<<humanScore<<" cards!"<<endl;
        cout<<"The AI player had: "<<aiScore<<" cards."<<endl;
    }

    else if(aiScore > humanScore)
    {
        cout<<"Sorry: "<<userName<<" , the AI player won with: "<<aiScore<<" cards. Better luck next time! "<<endl;
        cout<<userName<<" had: "<<humanScore<<" cards."<<endl;
    }

    else
    {
        cout<<"The game ended in a tie! "<<endl;
    }
       
    cout<<"Enter any key to continue: ";
    cin>>doesNothing;
    cin.ignore(100, '\n');

    return;

}

void rules()
{

    using namespace std;
    char response;
    do
    {
        cout<<"The rules of WAR are simple."<<endl<<endl;
        cout<<"On every turn, each player will draw 1 card. "<<endl;
        cout<<"The player with the highest value card wins the turn and gets both cards. "<<endl;
        cout<<"If it is a draw, each player draws another card and those new card values are compared against each other. "<<endl;
        cout<<"As long as there is a draw, new cards will be drawn and compared until one player wins. The winning player gets all the cards" <<endl;
        cout<<endl<<endl;
        cout<<"The player with the most cards in their personal pile at the end of the game, wins. "<<endl;
        cout<<"Enter 'Y' to continue: ";
        cin>>response;
        cin.ignore(100, '\n');
        response = toupper(response);
    
    }while(response != 'Y');

    return;
}
   


