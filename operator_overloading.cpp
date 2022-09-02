#include <iostream>
using namespace std;

class Vector2D
{
    double v[2];

    public:
    Vector2D(double x, double y){
        v[0] = x;
        v[1] = y;
    }
    void baseExpress(){
        cout << "(" << v[0] << "," << v[1] << ")" << endl;
    }

    friend Vector2D operator+(const Vector2D& v1, const Vector2D& v2);
    friend Vector2D operator-(const Vector2D& v1, const Vector2D& v2);
    friend Vector2D operator*(const double a, const Vector2D& v);
    friend Vector2D operator*(const Vector2D& v, const double a);
};

// Vector Operation VO

Vector2D operator+(const Vector2D& v1, const Vector2D& v2)
{
    Vector2D v(0, 0);
    v.v[0] = v1.v[0] + v2.v[0];
    v.v[1] = v1.v[1] + v2.v[1];
    return v;
}

Vector2D operator-(const Vector2D& v1, const Vector2D& v2)
{
    Vector2D v(0, 0);
    v.v[0] = v1.v[0] - v2.v[0];
    v.v[1] = v1.v[1] - v2.v[1];
    return v;
}

Vector2D operator*(const double a, const Vector2D& v)
{
    return Vector2D(a*v.v[0], a*v.v[1]);
}

Vector2D operator*(const Vector2D& v, const double a)
{
    return Vector2D(a*v.v[0], a*v.v[1]);
}

// VO end


int main(){
    

    double v1Array[2];
    double v2Array[2];
    double* vArray[2] = {v1Array, v2Array};
    double* p;

    for (int i = 1; i < 3; i++){
        p = vArray[i-1];
        cout << "" << endl;
        cout << "input for v" << i << "'s coordinate" << endl;
        cout << "" << endl;
            for (int j = 0; j < 2; j++){
                cout << "input for v" << i <<"'s " << j+1 << " - coordinate" << endl;
                cin >> *p;
                p++;
            }
        
    }
    


    Vector2D v1(v1Array[0],v1Array[1]), v2(v2Array[0],v2Array[1]);
    Vector2D v3 = v1 + v2;
    v3.baseExpress();
    Vector2D v4 = v1 - v2;
    v4.baseExpress();
    Vector2D v5 = 100 * v1;
    v5.baseExpress();

    return 0;
    
}