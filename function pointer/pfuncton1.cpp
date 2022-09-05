#include <iostream>
using namespace std;



int power2(int x){
    return (x * x);
}

typedef int (*X2)(int x);

int ax2(int a, int x, X2 j){
    return a * (j(x));
}

void main(){

    X2 x2 = &power2;
    cout << ax2(5, 10, x2) << endl;
}









