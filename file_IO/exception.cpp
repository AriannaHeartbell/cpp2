#include <iostream>
using namespace std;

class pException{
    
    public:
        pException(){}
        void display() {cout << "Only positive intengers are available" << endl;}
};

class c1Exception : public pException{
    public:
        c1Exception(){}
        void display() {cout << "numbers must not be zero" << endl;}
};

class c2Exception : public pException{
    public:
        c2Exception(){}
        void display() {cout << "numbers must not be minus" << endl;}
};



void calculation(int a, int b){
        if(a*b == 0)
            throw c1Exception();
        if(a*b < 0)
            throw c2Exception();
        if(a*b > 0 && a <= b)
            throw pException();
        double c = 1 / (a - b);
        cout << c << endl;
    }

void main(){



    try{
        calculation(0, 3);
    }
    catch(c1Exception& p){
        p.display();
    }

    try{
        calculation(-2, 3);
    }
    catch(c2Exception& p){
        p.display();
    }

    try{
        calculation(2, 3);
    }
    catch(pException& p){
        p.display();
    }

    

}