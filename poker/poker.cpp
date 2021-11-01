#ifndef poker_cpp
#define poker_cpp
#include "player.cpp" //includes card
#include "deck.cpp"

class Game{
private:
    Deck d; 
    Player * p1 = new Player();
    Player * pc = new Player();
public:
    Game(bool j);
    Card drawCard() { return d.drawCard(); } //give next card
    void giveP1(int i); //give card to p1
    void lookHand(); //give card to p1
    void givePc(int i); //give card to pc
    void changeP1();
    void changePc();
    bool getP1Change();
    void sortP1(){ p1->sortHand(); }
    int getUsedCards() { return d.getUsedCards(); }
    int bestHandP1(){ return p1->bestHand(); }
    void giveTest();

    ~Game(){ delete p1; delete pc; }
};

Game *  initialize();
void startGame(Game * g);
void play(Game * g);

int main()
{
    Game * g = NULL;
    int selection = 0;
    while(selection != 2)
    {
        cout<<"Select an option: "<<endl;
        cout<<"1) Play"<<endl;
        cout<<"2) Exit"<<endl;
        cin>>selection;

        if(selection == 1 )
        {
            cin.clear();
            g = initialize();
            g->giveTest();
            cout<<g->bestHandP1()<<endl;
            
            startGame(g);
            play(g);
        }
            
        else if(selection != 2)
            cout<<"Invalid option, please select 1 or 2"<<endl<<endl;

    }

    delete g;
    return 0;
}

Game * initialize()
{
    char joker =' ';
    bool j;

    while( joker != 'y' || joker != 'Y' || joker != 'n' || joker != 'N') //only available options
    {
        cout<<"Do you want to use jokers? "<<endl;
        cout<<"They wil be wildcards, only two will be added to the deck."<<endl;
        cout<<"Y / N"<<endl;
        cin>>joker;
    
        if(joker == 'y' || joker == 'Y' )
        {
            j = 1;
            break; //patch as while is not working
        }
        else if(joker == 'n' || joker == 'N')
        {
            j = 0;
            break; //patch as while is not working
        }
        else
            cout<<"Invalid option, please use Y or N"<<endl<<endl;
    }
    
    return new Game(j);
}

void Game::giveTest()
{
    Card c1 =  Card(0, 's');
    Card c2 =  Card(13, 's');
    Card c3 =  Card(12, 'h');
    Card  c4 =  Card(1, 's');
    Card  c5 =  Card(11, 's');

    p1->getCard(c1 , 0);
    p1->getCard(c2 , 1);
    p1->getCard(c3 , 2);
    p1->getCard(c4 , 3);
    p1->getCard(c5 , 4);


}

Game::Game(bool j)
{
    d = Deck(j);
}

void Game::giveP1(int i)
{
    p1->getCard(d.drawCard(), i);
}
void Game::givePc(int i)
{
    pc->getCard(d.drawCard(), i);
}
void Game::lookHand() //lool p1 hand
{
    p1->lookHand();
}
void Game::changeP1()
{
    p1->changeCards();
}
void Game::changePc()
{
    pc->changeCards();
}
bool Game::getP1Change()
{
    return p1->getChange();
}

void startGame(Game * g)
{
    //give cards to players
    for(int i = 0; i < 10; i++)
    {
        if(i%2 == 0) //give to p1
            g->giveP1((i/2)); //give card to p1
        else //give to pc
            g->givePc((i/2)); //give card to pc
    }
    //cout<<"Used: "<<g->getUsedCards()<<endl;
}

void play(Game * g)
{
    int option = 0;
    while(option != 5 || option != 6) //game end
    {
        cout<<"\nChoose the action to perform "<<endl;
        cout<<"1) Look your cards"<<endl;
        cout<<"2) Change cards"<<endl;
        cout<<"3) Sort cards"<<endl;
        cout<<"4) Keep your cards"<<endl;
        cout<<"5) Surrender"<<endl;
        cout<<"6) Best hand"<<endl;
        cout<<"7) Continue"<<endl;


        cin>>option;

        if(option == 1)//option to look hand
            g->lookHand();
        else if(option == 2)//change cards (if not changed yet)
        {
            if(g->getP1Change()) //already changed the cards?
                cout<<"You are not allowed to use this option anymore."<<endl;
            else //change cards
            {
                cout<<"You will not be change cards again."<<endl;
                cout<<"1) Yes, change cards"<<endl;
                cout<<"2) Let me think about it"<<endl;
                cin>>option;
                if(option == 1) //confirmed to keep cards
                {
                    bool swap[5] = {false,false,false,false,false};
                    while (option != 0) //confirm cards to be changed
                    {
                        cout<<"\nThis is your hand: "<<endl;
                        g->lookHand();
                        cout<<"\nYou have selected this cards to be changed: "<<endl;
                        for(int i = 0; i < 5; i++)
                        {
                            if(swap[i] == 1)
                                cout<<"card "<<i+1<<endl; //print selected cards
                        }
                        cout<<"\nSelect or unselect cards to be changed: "<<endl;
                        cout<<"1) Card 1"<<endl;
                        cout<<"2) Card 2"<<endl;
                        cout<<"3) Card 3"<<endl;
                        cout<<"4) Card 4"<<endl;
                        cout<<"5) Card 5"<<endl;
                        cout<<"\n0) Confirm selected cards to be changed"<<endl; //if no cards are selected will be the same as keep them
                        cin>>option;
                        if(option > 0 && option < 6)//card selected
                            swap[option-1] = !swap[option-1]; //swap selection status
                    }
                    //draw new cards
                    for(int i = 0; i < 5; i++)
                    {
                        if(swap[i] == true) //if marked to change
                        {
                            g->giveP1(i);
                        }
                    }
                    cout<<"Used: "<<g->getUsedCards()<<endl;

                    g->changeP1();
                }
            }
        }
        else if(option == 3)//sort hand
        {
            g->sortP1();
        }
        else if(option == 4)//keep hand 
        {
            if(g->getP1Change()) //already changed the cards?
                cout<<"You are not allowed to use this option"<<endl;
            else
            {
                 cout<<"You will not be able to change your cards if you select this option."<<endl;
                cout<<"1) I want to keep my cards"<<endl;
                cout<<"2) Let me think about it"<<endl;
                cin>>option;
                if(option == 1) //confirmed to keep cards
                    g->changeP1();
            }
        }
        else if(option == 6) //best hand
        {
            cout<<"Best hand available: "<<g->bestHandP1()<<endl;
        } 


    }

    
    
}



#endif

