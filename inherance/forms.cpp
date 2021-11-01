#include <iostream>

using namespace std;

class base{
private:
    int sides;
    float length;
    string type;

public:
    base() {} //needed for cube constructor
    base(int sides, float length, string type) { this->sides = sides; this->length = length; this->type = type; }
    void setSides(int sides) { this->sides = sides; }
    void setLength(float length) { this->length = length; }
    int getSides() { return sides; }
    virtual float perimeter() { return sides * length; }
    void setType(string type) { this->type = type; }
    string getType() { return type; }
    ~base() { cout<<"del base"<<endl; }

};

class cube : public base{
private:

public:
    cube(int sides, float length, string type) : base( sides, length, type){} //inherits constructor
    cube(float length);
    ~cube() { cout<<"del cube"<<endl; }
    
};

class rect : public base{
private:
    float shortSide;
    float longSide; 

public:
    rect(float shortSide, float longSide);
    float getLong() { return shortSide; }
    float getShort() { return this->longSide; }
    float perimeter() { return (shortSide * 2)  + (longSide * 2); }
    ~rect() { cout<<"del rect"<<endl; }

};

int main()
{
    cube obj = cube(4, 10, "cube");
    cube obj2 = cube(5);
    rect obj3 = rect(2,3);

    cout<<"Cube perimeter with all values: "<<obj.perimeter()<<endl;
    cout<<"Cube perimeter with length: "<<obj2.perimeter()<<endl;

    cout<<"Rect sides are: "<<obj3.getLong()<<" & "<<obj3.getShort()<<endl;
    cout<<"Rect perimeter with length: "<<obj3.perimeter()<<endl;



    return 0;
}

cube::cube(float length)
{ 
    this->setLength(length); 
    this->setSides(4);
    setType("cube"); //just to test without "this->" value
}

rect::rect(float shortSide, float longSide)
{
    this->shortSide = shortSide;
    this->longSide = longSide;
    setType("rectangle");
    setLength(0);
}