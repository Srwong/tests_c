#ifndef deck_cpp
#define deck_cpp

#include "card.cpp"
#include <vector>
#include <time.h>
#include <stdlib.h>

class Deck{
private:
    Card * d; //DECK, use first 20 cards or change to vector
    vector <Card> container; //temporal container. This will pass cards to d mixed.
    bool jokers; //add two jokers to the deck as wildcards
    int usedCards = 0;// if less than 20, mix deck
public:
    Deck(){  } 
    Deck(bool j);
    void createCards();
    void printDeck(); 
    void mix();
    Card drawCard();
    int getUsedCards() { return usedCards; }
};


Deck::Deck(bool j)
{
    this->jokers = j;
    if(jokers)//add two jokers to the deck as wildcards
        this->d = new Card[54];
    else
        this->d = new Card[52]; //no jokers
    this->createCards();
    this->mix();
    //printDeck(); //testing purposes
}

/* //create deck directly on d
void Deck::createCards()
{
    char types[4] = {'h','d','s','c'}; //heart, diamond, spade, club
    int index = 0; //move through array d to add cards
    for(int j = 0; j < 4; j++) //card type
    {
        for(int i = 1; i < 14; i++)//Card num
        {
            this->d[index] = Card(i, types[j]); //Card(value, type)
            index+=1;
        }
    }

    if(jokers) //if jokers are needed, add them
    {
        this->d[index] = Card(0, 'j'); //
        index++;
        this->d[index] = Card(0, 'j'); //
        index++;
    }
}
*/

void Deck::createCards() //fills container
{
    char types[4] = {'h','d','s','c'}; //heart, diamond, spade, club
    for(int j = 0; j < 4; j++) //card type
    {
        for(int i = 1; i < 14; i++)//Card num
        {
            container.push_back(Card(i, types[j])); //Card(value, type)
        }
    }
    
    if(jokers == 1) //if jokers are needed, add them
    {
        container.push_back(Card(0, 'j')); //
        container.push_back(Card(0, 'j')); //
    }
}

void Deck::mix() //pass from container to d while mixing
{
    /*//fill deck for test
    for(int i = 0; i < container.size(); i++ )
    {
        this->d[i] = container[i];
    }
    */

   srand(time(NULL)); //random seed
   int index = 0;
   int rgn;

   while (container.size() > 0)
   {
       index = container.size()-1; //stack cards
       rgn = rand()%container.size(); //generate random number
       d[index] = container[rgn]; //send card to deck
       index++;
       container.erase(container.begin() + rgn); //remove card from sorted cards
   }
}

void Deck::printDeck()
{
    for(int i = 0; i < 52; i++)
    {
        this->d[i].inspectCard();
    }
    if(jokers)
    {
        this->d[52].inspectCard();
        this->d[53].inspectCard();
    }
}

Card Deck::drawCard() //give next card
{
    usedCards+=1;   
    return d[usedCards-1];
}


#endif