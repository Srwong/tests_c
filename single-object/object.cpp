#include <iostream> 
#include <string>

using namespace std;

class myObject{
public:
    myObject();
    myObject(string n);
    string getName();    
    void setName(string n);
    ~myObject();

private:
    string name;
};

int main()
{
    string input;

    cout<<"Give me a name: ";
    cin>>input;

    cout<<"Creating "<<input<<endl;

    myObject x  = myObject();
    x.setName(input);

    cout<<"Here is "<<x.getName()<<endl;

    myObject obj2 = myObject(input);

    cout<<"Here is other one with parameters: "<<obj2.getName()<<endl;

    myObject * objP = new myObject("with pointer");

    cout<<"Here is one with pointer: "<<objP->getName()<<endl;

    delete objP; //Need this to delete pointers

    return 0;
}

myObject::myObject(){}

myObject::myObject(string n){
    this-> name = n;
}

void myObject::setName(string n){
    name = n;
}

string myObject::getName(){
    return this->name;
}

myObject::~myObject(){
    cout<<"Destructing object \n";
}