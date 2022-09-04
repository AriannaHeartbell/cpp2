#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream is;
ofstream os;


void main()
{
    vector<char> C;
    vector<char>::iterator it;
    char s;

    is.open("p1.txt");
    if(is.fail()){
        cerr << "failed to lord the file" << endl;
        exit(1);
    }

    while ((! is.eof()))
    {
        is >> s;
        C.push_back(s);
    }
    C.pop_back();

    os.open("p2.txt");
    if(os.fail()){
        cerr << "failed to lord the file" << endl;
        exit(1);
    }


    for (it = C.end() -1; it != C.begin() - 1; --it)
    {
        os << *it << endl;
        cout << *it << endl;
    }
    
    cout << "" << endl;
    cout << "size of the vector is: " << C.size() << endl;

    is.close();
    os.close();

}