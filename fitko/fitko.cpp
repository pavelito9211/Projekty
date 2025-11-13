#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    string heslo;
    cout<<"Vitaj v gym planner\n\n";
    while (true)
    {
        cout<<"Zadaj heslo: ";
        cin>>heslo;
        if (heslo == "ekko1234")
        {
        break;
        }
        else
        {
        cout<<"Nesprávne heslo. Skús to znova\n";
        continue;
        }
    }

    string den[5];
    den[0] = "pondelok";
    den[1] = "utorok";
    den[2] = "streda";
    den[3] = "stvrtok";
    int cisloden;
    cout<<"1. Pondelok\n2. Utorok\n3. Streda\n4. Stvrtok\nZadaj den: ";
    cin>>cisloden;
     
    return 0;
}