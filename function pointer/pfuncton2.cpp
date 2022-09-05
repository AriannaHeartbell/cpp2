#include <iostream>
using namespace std;

class A{};
class B : public A {};
class C : public A {virtual ~C();};
class X{};
class D : public A, public X {};

void (*pGF)(); // pointer of Global Function
void (A::*pMFa)(); // pointer of Member Functon
void (B::*pMFb)();
void (C::*pMFc)();
void (D::*pMFd)();

template<typename t>
void size(t){cout << sizeof(t) << endl;}

void main(){
    size(pGF);  // 4
    size(pMFa); // 4
    size(pMFb); // 4
    size(pMFc); // 8
    size(pMFd); // 8
}
