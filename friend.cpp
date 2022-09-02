#include <iostream>
#include <string>
using namespace std;

class Person{
int Crime_Coefficient;
string status;

friend class SibylSystem;
friend void GotoJail(Person* a);

public:
Person(int i){
    Crime_Coefficient = 100*i;
}
void showCC(){
    cout << Crime_Coefficient << endl;
}

};

class SibylSystem{
public:
void Dominator(Person* a){

    // expression likes 10 < x < 100 is impossible. it should be replaced like 10 <x && x < 100.
    // 0 <= & else. 

    if (0 <= a->Crime_Coefficient && a->Crime_Coefficient < 100){
        cout << "Coefficient is " << a->Crime_Coefficient << " Suspect is not a target for enforcement action. The trigger will be locked." << endl;
        a->status = "non target";}
    if (100 <= a->Crime_Coefficient && a->Crime_Coefficient < 300){
        cout << "Coefficient is " << a->Crime_Coefficient << "  Suspect is a target for enforcement action. The Dominator is set to Non-Lethal Paralyzer mode. " << endl;
        a->status = "Non-Lethal Paralyzer";}
    if (a->Crime_Coefficient >= 300){ 
        cout << "Coefficient is " << a->Crime_Coefficient << "  Suspect is a target for enforcement action. The Dominator is set to Lethal Eliminator. " << endl;
        a->status = "Lethal Eliminator";}
}
};

void GotoJail(Person* a){
    if (a->status == "non target"){
        cout << "Innocent Person"  << endl;
    }
    if (a->status == "Non-Lethal Paralyzer"){
        cout << "Go to Jail"  << endl;
    }
    if (a->status == "Lethal Eliminator"){
        cout << "Go to hell"  << endl;
    }
}

int main()
{
    Person* pArray[4];
    for (int i = 0; i<4; i++){
        pArray[i] = new Person(i);
    }

    SibylSystem s;
    for (int i = 0; i<4; i++){
        pArray[i]->showCC();
        s.Dominator(pArray[i]);
        GotoJail(pArray[i]);
    }

    cout << "All for better society" << endl;

    return 0;
}