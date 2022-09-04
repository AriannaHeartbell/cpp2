#include <iostream>
#include <fstream> //header file for file IO
using namespace std;

ifstream is;
ofstream os;

class grade
{
public:
int ranking;
string name;
};

void main(){
    
    grade g;

    is.open("ranking.txt");
    if(is.fail()){
        cerr << "failed to lord the file" << endl;
        exit(1);
    }

    os.open("result.txt");
    if(os.fail()){
        cerr << "failed to lord the file" << endl;
        exit(1);
    }
    

    while ((! is.eof())) //end of file
    {
        is >> g.ranking >> g.name;
        os << g.ranking << " " << g.name << endl;
    }

    is.close();
    os.close();
}
