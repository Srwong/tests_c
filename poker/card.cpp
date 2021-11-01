#ifndef CARD_CPP
#define CARD_CPP

#include <iostream>

class Card{
private:
    int value; //number or j = 11 q = 12 k = 13
    char type;
    bool color; // 0 black, 1 red
public:
    Card(){}
    Card(int v, char t);
    int getValue();
    char getType();
    bool getColor();
    void inspectCard();
    ~Card(){}
};

Card::Card(int v, char t)
{
    this->value = v;
    this->type = t;
    if(type == 's' || type == 'c' ) //spades or club 
        this->color = 0;
    else  
        this->color = 1;
}

int Card::getValue()
{
    return value;
}

char Card::getType()
{
    return type;
}

bool Card::getColor()
{
    return color;
}

void Card::inspectCard()
{
    if(this->value == 11)
        std::cout<<'J'<<this->type<<std::endl;
    else if(this->value == 12)
        std::cout<<'Q'<<this->type<<std::endl;
    else if(this->value == 13)
        std::cout<<'K'<<this->type<<std::endl;
    else if(this->value == 0)
        std::cout<<"joker"<<std::endl;
    else
        std::cout<<this->value<<this->type<<std::endl;
}

#endif // CARD_CPP