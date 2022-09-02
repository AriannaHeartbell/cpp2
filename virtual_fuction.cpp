#include <iostream>
using namespace std;


class point{
public: 
    int x, y;

    virtual void draw() = 0; //pure virtual functon
}; // abstract class. It cannot produce instance.

class Shape : public point {
protected:

public:
    virtual void draw(){
        cout << "Draw Shape" << endl;
    }

    void setORigin(int x, int y){
        this->x = x;
        this->y = y;
    }

};

class Rectangle : public Shape{
private:
    int width, height;

public:
    void setWidth(int w){
        width = w;
    }

    void setHeight(int h){
        height = h;
    }

    void draw(){
        cout << "Draw Rectangle" << endl;
    }
};

class Circle : public Shape{
private:
    int radius;

public:
    void setRadius(int r){
        radius = r;
    }

    void draw(){
        cout << "Draw Circle" << endl;
    }
};


void main()
{
    Shape *arrayOfShapes[3];

    arrayOfShapes[0] = new Rectangle();
    arrayOfShapes[1] = new Circle();
    arrayOfShapes[2] = new Shape();
    for (int i = 0; i<3; i++){
        arrayOfShapes[i]->draw();
    }
}

    