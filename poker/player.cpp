#ifndef player_cpp
#define player_cpp
#include "card.cpp"

using namespace std;

class Player{
private:
    Card hand[5];
    bool change = false; //cards changed already?

public:
    Player(){}
    void getCard(Card c, int i); // card, index
    void sortHand();
    void lookHand();
    void changeCards() { change = !change; }
    bool getChange() { return change; }
    int bestHand();
    bool compareStraight(int i, int j);
    bool compareFlush();

};

void Player::getCard(Card c, int i)
{
    this->hand[i] = c;
}


void Player::sortHand()
{
    Card temp;
    int index = 0;

    for(int i = 0; i < 5; i++)
    {
        temp = hand[i]; //lowest?
        index = i;

        for(int j = i; j < 5; j++)
        {
            if(temp.getValue() > hand[j].getValue())//lower number
            {
                index = j;
                temp = hand[j];
            }
        }
        if(i != index)//different cards
            {
                //swap
                hand[index] = hand[i];
                hand[i] = temp;
            }
    }
}

void Player::lookHand()
{
    for(int i = 0; i < 5; i++)
    {
        cout<<"Card "<<i+1<<": ";
        this->hand[i].inspectCard();
    }
}

bool Player::compareStraight(int i, int j)
{
    int dif = (hand[j].getValue() - hand[i].getValue());
    //cout<<hand[j].getValue() <<" "<< hand[i].getValue()<<" "<<dif<<endl; //print sustraction
    if (dif == 1)
        return true;
    return false;
}

bool Player::compareFlush() //check if cards are of the same type
{
    char t = hand[0].getType();
    for(int i = 1; i < 5; i++)
    {
        if(t != hand[i].getType()) //if a card type is different, return false
            return false; 
    }
    return true;
}

int Player::bestHand()
{
    //based on: https://en.wikipedia.org/wiki/List_of_poker_hands#Hand-ranking_categories
    sortHand(); //easier to compare if sorted from lower to highest numbers
    lookHand();

    int flush = 0;
    int straight = 0;
    int three_of_a_kind = 0;



    // no jokers implementation
    if( (bool)(compareStraight( 0 , 1 ) && compareStraight( 1 , 2 ) && compareStraight( 2 , 3 ) &&  compareStraight( 3 , 4 )) || //all values with a difference of 1 is a flush (1,2,3,4,5) or
        (bool)(compareStraight( 1 , 2 ) && compareStraight( 2 , 3 ) &&  compareStraight( 3 , 4 ) && (hand[4].getValue() == 13 && hand[0].getValue() == 1)) ) // getting 10, J, Q , K, 1 
        straight= 6; //asuming is the same color (straight flush)
    
    if( compareFlush() ) //same card type
        flush = 5; //straight means same type (as example all cards are hearts)
    
    cout<<"flush: "<<flush<<endl;
    cout<<"straight: "<<straight<<endl;


    /* Card analysis */

    //straight flush?
    if( flush == 5 && straight == 6 )
        return 2; 
    
    //four of a kind?
    if(hand[0].getValue() == hand[3].getValue() || hand[1].getValue() == hand[4].getValue()) // first and fourth value or second and fifth are the same
        return 3; 

    //full house?
    /*
    if( hand[0].getValue() == hand[2].getValue() || hand[2].getValue() == hand[4].getValue() ) // (1 = 2 = 3) OR (3 = 4 = 5 ) -> three cards with same number
    {
        three_of_a_kind = 7; //mark the three of a kind existence
        if( hand[0].getValue() == hand[1].getValue() || hand[3].getValue() == hand[4].getValue() )
            return 4; //was a full house as we found a pair
    }  
    */
   if( (hand[0].getValue() == hand[2].getValue() && hand[3].getValue() == hand[4].getValue()) || // (1 = 2 = 3)
        (hand[2].getValue() == hand[4].getValue() && hand[0].getValue() == hand[1].getValue()) ) //  (3 = 4 = 5 ) 
            return 4; //was a full house as we found a pair
    
    //already calculated the flush
    if( flush == 5 )
        return flush;
    
    //already calculated the straight
    if ( straight == 6)
        return straight;

    //three of a kind
    if( hand[0].getValue() == hand[2].getValue() || hand[2].getValue() == hand[4].getValue() )
        return 7;
    
    //pairs 
    int pairs = 0;
    for( int i = 0; i < 4; i++)
        if(hand[i].getValue() == hand[i+1].getValue())
            pairs++;

    if (pairs == 2)
        return 8; 
    
    if (pairs == 1)
        return 9;
    
    //worst case scenario, will go to highest card
    return 10;
}

#endif //player_cpp