#include <iostream>
#include <vector>

using namespace std;
//queue, stack and linked list
class Queue{
private:

public:
    Queue(){}
    void add(int x);
    int next();
    int dispatch();
    void printQueue();
    ~Queue();
    vector <int> data; //stores data

};

void printQueue(Queue * q);

int main()
{
    Queue * myQueue = new Queue();
    int option = 1;
    int value = 0;

    while( option != 5)
    {
        cout<<"\nSelect an option:\n";
        cout<<"1: Add a value\n";
        cout<<"2: Look next value in queue\n";
        cout<<"3: Dispatch next value in queue\n";
        cout<<"4: Print all queue\n";
        cout<<"5: Quit\n";
        cin>>option;

        if(option < 1 || option > 5)
            cout<<"\nInvalid option, please select another\n";
        else if( option == 1)
        {
            cout<<"\nGive me the number to add to the queue\n";
            cin>>value;
            myQueue->add(value);
        }
        else if( option == 2) //look next value
            cout<<"\nThe next value in the queue is: "<<myQueue->next()<<endl<<endl;
        else if( option == 3)
        {
            cout<<"\nDispatching value: "<<myQueue->dispatch()<<endl<<endl;
            printQueue(myQueue);
        }
        else // option 4
            printQueue(myQueue);
    }

    cout<<"\nClosing program"<<endl;

    delete myQueue;
    return 0;
}

void Queue::add(int x)
{
    this->data.push_back(x);
}

int Queue::next()
{
    return data[0];
}

int Queue::dispatch()
{
    int temp = data[0]; //save value to return
    data.erase(data.begin()); //delete value from queue
    return temp; //return value. dispatched
}

void Queue::printQueue() //print from first to last
{
    for(int i = 0; i < data.size(); i++)
        cout<<data[i]<<" ";
    cout<<endl;
}

Queue::~Queue(){}

void printQueue(Queue * q)
{
    cout<<"Remaining values in queue: ";
    q->printQueue();
    cout<<endl;
}
