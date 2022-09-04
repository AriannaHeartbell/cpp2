#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream is;
ofstream os;


void main()
{
    vector<string> C;
    vector<string>::iterator it;
    string s;

    is.open("A1.txt");
    if(is.fail()){
        cerr << "failed to lord the file" << endl;
        exit(1);
    }

    while ((! is.eof()))
    {
        is >> s;
        C.push_back(s);
    }

    os.open("A2.txt");
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