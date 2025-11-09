#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() 
{
    long long zostatok;
    int id, volba;
    string subor,pocethistoria;
    cout<<"(V pripade ze nemas Ucet zadaj 0)\n\n";
    cout<<"Zadaj ID pouzivatela: ";
    cin >>id;
    subor=to_string(id)+".txt";
    cin.ignore();
    ifstream in(subor);
    if (in.good())
        {
        cout<<"Ucet sa nasiel. Pokracujeme do bankomatu.\n\n";
        in >> zostatok;
        in.close();
        }
    else
        {
        in.close();
        cout<<"Ucet neexistuje. Vytvorit novy ucet? (ano=1, nie=0): ";
        cin >>volba;
        if (volba==1)
            {
            cout<<"Pravidla zakladania uctu:\n\n1. Nove ID musi byt 4-ciferne cislo\n2. Nove ID sa nesmie zacinat nulou";
            while (true) 
                {
                    cout << "\n\nZadaj nove ID: ";
                    cin >> id;
                    subor = to_string(id) + ".txt";

                    ifstream test(subor);
                    if (test.good()) 
                    {
                    cout << "Toto ID sa uz pouziva. Skus ine.";
                    test.close();
                    }
                    else 
                    {
                    test.close();
                    ofstream out(subor);
                    out << 0;
                    out.close();
                    zostatok = 0;
                    cout << "\nUcet s ID: " << id << " bol vytvoreny.";
                    break;
                    }
                }
            }
        else
            {
            cout<<"\nProgram sa ukoncuje";
            exit(0);
            }
        }
    pocethistoria = to_string(id) + "historia.txt";
    ifstream testhistoria (pocethistoria);
    if (testhistoria.good())
        {
        cout<<"Historia uctu bola nacitana. Pokracujeme do bankomatu\n\n";
        }
    else
        {
        testhistoria.close();
        ofstream outhistoria (pocethistoria);
        outhistoria << 0;
        outhistoria.close();
        }
    long long akcia, vklad, vyber;
    string transakcia;
    string historia[5];
    int pocet;
    cout<<"1. Stav uctu\n";
    cout<<"2. Vklad na ucet\n";
    cout<<"3. Vybrat peniaze\n";
    cout<<"4. Poslat peniaze\n";
    cout<<"5. Historia transakii\n";
    cout<<"6. Ukoncit program\n";
        do
        {
        cout<<"\n\nZadaj cislo pozadovanej akcie: ";
        cin >>akcia;
        cout<<"\n";
        if (akcia==6)
            {
            ofstream out(subor);
            out << zostatok;
            out.close();
            exit(0);
            }
        else if (akcia==1)
            cout <<"\nZostatok na ucte: "<<zostatok<<" Euro";
        else if (akcia==2)
            {
            cout<<"\nZadaj vkladanu sumu: ";
            cin>>vklad;
            if (vklad>0)
                {
                zostatok=zostatok+vklad;
                ofstream out(subor);
                out << zostatok;
                out.close();
                cout<<"Novy zostatok na ucte: "<<zostatok<<" Euro";
                transakcia = "Vklad " + to_string(vklad) + " Euro. Nový zostatok " + to_string(zostatok) + " Euro";
                ifstream inhistoria (pocethistoria);
                
                if (pocet<5)
                    {
                    historia[pocet] = transakcia;
                    pocet++;
                    }
                else
                    {
                    for (int i=1; i<5; i++)
                        {
                        historia[i-1] = historia[i];
                        }
                    historia[4] = transakcia;
                    }
                }
            else
                cout<<"Neplatna hodnota";
            }
        else if (akcia==3)
            {
            cout<<"\nZadaj vyberanu sumu: ";
            cin>>vyber;
            if (vyber<=zostatok && vyber>0)
                {
                zostatok=zostatok-vyber;
                ofstream out(subor);
                out << zostatok;
                out.close();
                cout<<"Novy zostatok na ucte: "<<zostatok<<" Euro";
                transakcia = "Vyber " + to_string(vyber) + " Euro. Nový zostatok " + to_string(zostatok) + " Euro";
                if (pocet<5)
                    {
                    historia[pocet] = transakcia;
                    pocet++;
                    }
                else
                    {
                    for (int i=1; i<5; i++)
                        {
                        historia[i-1] = historia[i];
                        }
                    historia[4] = transakcia;
                    }
                }
            else if (vyber>zostatok)
                cout<<"Nedostatok zdrojov na ucte";
            else 
                cout<<"Neplatna hodnota";
            }
        else if (akcia==4)
            {
            int idprijem;
            long long posielanie, zostatokprijem;
            string suborprijem;
            cout<<"Zadaj ID prijemcu: ";
            cin >>idprijem;
            suborprijem=to_string(idprijem)+".txt";
            ifstream inprijem(suborprijem);
            if (id==idprijem)
                {
                cout<<"Neplatny ucet\n";
                continue;
                }
            if (inprijem.good())
                {
                inprijem >> zostatokprijem;
                inprijem.close();
                cout<<"Zadaj pozadovanu sumu: ";
                cin>>posielanie;
                if (posielanie<=zostatok && posielanie>0)
                    {
                    cout<<"Posielame na ucet "<<idprijem<<" sumu "<<posielanie<<" Eur\n";
                    zostatokprijem=zostatokprijem+posielanie;
                    ofstream outprijem(suborprijem);
                    outprijem << zostatokprijem;
                    outprijem.close();
                    zostatok=zostatok-posielanie;
                    ofstream out(subor);
                    out << zostatok;
                    out.close();
                    cout<<"Suma "<<posielanie<<" eur bola uspesne poslana na ucet "<<idprijem<<"\n";
                    cout<<"Novy zostatok na ucte je "<<zostatok<<" eur\n";
                    }
                else if (posielanie>zostatok)
                    cout<<"Nedostatok zdrojov na ucte\n";
                else 
                    cout<<"Neplatna hodnota\n";
                }  
            else
                cout<<"Ucet sa nenasiel\n";
            }
            else if (akcia==5)
            {
            
            }
        }   while(true);
    return 0;
}