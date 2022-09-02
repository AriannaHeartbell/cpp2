#include <iostream>
using namespace std;

class Animal
{
public:
    int code; 
    virtual void speak(){
        cout << "Animal speak" << endl;
    }
    Animal(){
        cout << "Animal Constructor" << endl;
    }
    virtual ~Animal(){
        cout << "Animal destructor" << endl; 
    }
    
};

class Dog : public Animal
{
public:
    Dog(){
        cout << "Dog Constructor" << endl;
        code = 3;
    }
    ~Dog(){
        cout << "Dog destructor" << endl; 
    }
    void speak(){
        cout << "Dog Speak" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat(){
        cout << "Cat Constructor" << endl;
        code = 7;
    }
    ~Cat(){
        cout << "Cat destructor" << endl; 
    }
    void speak(){
        cout << "Cat speak" << endl;
    }
};

void checkAnimal(Animal* a){

    if (a->code < 5)
    {
        cout << "this is a dog" << endl;
    }
    else
    {
        cout << "this is a cat" << endl;
    }
    
}

void main()
{

    Animal *Array[2];

    Array[0] = new Dog();
    Array[1] = new Cat();

    checkAnimal(Array[0]);
    Array[0]->speak();
    delete Array[0];

    checkAnimal(Array[1]);
    Array[1]->speak();
    delete Array[1];
    
}
