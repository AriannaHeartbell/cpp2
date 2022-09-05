#include <iostream>
using namespace std;

class Pokemon{
    public:
    virtual void display()                       // for 'dynamic_cast'. dc determine obj's type by vf table in runtime. 
    {
        cout << "Pokemon Class" << endl;
    }
};
class smPokemon : public Pokemon{
    public:
    void display()
    {
        cout << "Sun & Moon Pokemon Class" << endl;
    }
};

template<typename t>
void show(t a){
    cout << a << endl;
}

void impossible(int i){
    cout << "casting " << i << " is impossible" << endl;
}



int main()
{

    cout << "these are tests by static_cast for casting of basic type" << endl;

    int i = 5;
    show(i);
    double f = 2.17;
    show(f);

    int* pi;
    double* pf = &f;

    i = static_cast<int>(f); // basic type cast is available.
    //pi = static_cast<int*>(pf); pointer castng is not available. Only classes in inheritance are possible.
    show(i);


    cout << "" << endl;
    cout << "these are tests by static_cast for casting of inheitance related classed" << endl;
    //upcast
    smPokemon *psmPoke1 = new smPokemon();
    psmPoke1->display();
    Pokemon *pPoke2 = static_cast<Pokemon *>(psmPoke1);
    pPoke2->display();
    delete psmPoke1, pPoke2;
    
    //downcast
    Pokemon *pPoke1 = new Pokemon();
    pPoke1->display();
    smPokemon *psmPoke2 = static_cast<smPokemon *>(pPoke1); //OK but risk
    psmPoke2->display();
    delete psmPoke2, pPoke1;
    

    cout << "" << endl;
    cout << "these are tests by static_cast for casting of inheitance related classed" << endl;
    
    // dynamic cast return NULL for downcast
    try
    {
    Pokemon *pPoke3 = new Pokemon();
    pPoke3->display();
    smPokemon *psmPoke4 = dynamic_cast<smPokemon *>(pPoke3);
    if(psmPoke4 == 0)
        throw psmPoke4;
    pPoke3->display();
    }
    catch(smPokemon *)
    {
        impossible(3);
    }
    

    // child -> parrent -> chield
    Pokemon *pPoke4 = new smPokemon();
    pPoke4->display();
    smPokemon *psmPoke4 = dynamic_cast<smPokemon *>(pPoke4);
    if(psmPoke4 == 0)
        impossible(4);
    psmPoke4->display();

    return 0;
}
