#include <iostream>
#include <string>
using namespace std;

//exception
class FullStack {};
class EmptytStack {};
//

template <class t>
class Stack{
    private:
    t* s;
    int size;
    int top;

    public:

    // con & des
    Stack(int n = 5) : size(n), top(-1) {
        s = new t[size];
    };
    ~Stack() {delete []s; }

    //push pop
    void push(t v);
    t pop();

    //exception
    bool isEmpty() const {return top == -1;}
    bool isFull() const {return top == size - 1;}
};

template<typename t>
void Stack<t>::push(t v)
{
    if (isFull())
        throw FullStack();
    s[++ top] = v;
}

template<typename t>
t Stack<t>::pop()
{
    if (isEmpty())
        throw EmptytStack();
    return s[top--];
}

void main()
{
    Stack<int> s;
    for (int i = 0; i<4; i++)
        s.push((i+1)*100);
    for (int i = 0; i<4; i++)
        cout << s.pop() << endl;
}

