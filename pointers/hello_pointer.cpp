#include <iostream>

using namespace std;

float helloFunction(float a[]);

int main()
{
    float n [3]; 

    cout<<"Give me a number"<<endl;
    cin>>n[0];

    cout<<"Give me another number"<<endl;
    cin>>n[1];
    
    cout<<"type n1: "<<typeid(n[0]).name()<<endl;
    cout<<"type n2: "<<typeid(n[1]).name()<<endl;
    cout<<"length n: "<<sizeof(n)/sizeof(n[0])<<endl;

    cout<<"n : "<<(n)<<endl;
    cout<<"n dir: "<<&n[0]<<endl;
    cout<<"n val: "<<n[0]<<endl;
    cout<<endl;

    float result = helloFunction(n);
    cout<<"Result: "<<result<<endl;
    cout<<"type: "<<typeid(result).name()<<endl;


    float a = n[0];
    float * b = &a;
    float ** c = &b;


    cout<<"a type: "<<typeid(a).name()<<endl;
    cout<<"a content: "<<a<<endl;
    cout<<"a dir: "<<&a<<endl;
    cout<<endl;


    cout<<"b type: "<<typeid(b).name()<<endl;
    cout<<"b content: "<<b<<endl;
    cout<<"b dir: "<<&b<<endl;
    cout<<"a content in b: "<<*b<<endl;

    cout<<endl;


    cout<<"c type: "<<typeid(c).name()<<endl;
    cout<<"c content: "<<c<<endl;
    cout<<"c dir: "<<&c<<endl;
    cout<<"a dir (first c pointer): "<<*c<<endl;
    cout<<"a content from b point under c : "<<**c<<endl;


    cout<<endl;


    return 0;
}


float helloFunction(float a[]){
    cout<<"Hello World with numbers "<<a[0]<<" and "<<a[1]<<endl;
    return (float) (a[0] / a[1]);
}