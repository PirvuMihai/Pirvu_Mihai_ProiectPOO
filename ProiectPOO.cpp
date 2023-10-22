#include <iostream>
//Domeniul Pamant, Pirvu Mihai, grupa 1048
using namespace std;
class Continent {
public:
    const int nrContinent;
    string nume;
    static string planeta;
    int populatie;
    int numarTari;
    string* tari;
    static int numarCatastrofe;

    Continent() : nrContinent(1) {
        this->nume = "Nu are nume";
        this->populatie = 0;
        this->numarTari = 0;
        this->tari = NULL;
    }
    Continent(int nrContinent, string nume, int numarTari, string* tari, int populatie) : nrContinent(nrContinent) {
        this->nume = nume;
        this->populatie = populatie;
        this->numarTari = numarTari;
        this->tari = new string[numarTari];
        for (int i = 0; i < numarTari; i++)
            this->tari[i] = tari[i];
    }
    Continent(int nrContinent,string nume,int populatie) : nrContinent(nrContinent) {
        this->nume = nume;
        this->populatie = 0;
        this->numarTari = numarTari;
        this->tari = NULL;
    }
    ~Continent() {
        if (this->tari != NULL)
            delete[]this->tari;
    }
    void afisare() {
        cout << "Continentul " << this->nume << " se afla pe planeta " << this->planeta << ", are populatia de " << this->populatie << " de locuitori. Acestia traiesc in " << this->numarTari << " tari, acestea fiind:";
        cout << "\n";
        for (int i = 0; i < this->numarTari; i++) {
            cout << this->tari[i];
            cout << "\n";
        }
        cout << "In ultimii ani, au avut loc " << this->numarCatastrofe << " catastrofe pe acest continent";
    }
    float populatieMedie() {
        return (float)this->populatie / this->numarTari;
    }

    static void setPlaneta(string planeta) {
        Continent::planeta = planeta;
    }
    static void adaugareCatastrofe(int catastrofeNoi) {
        Continent::numarCatastrofe += catastrofeNoi;
    }
};
string Continent::planeta = "Pamant";
int Continent::numarCatastrofe = 0;

class Tara {
public:
    string nume;
    int populatieTara;
    static string galaxie;
    const float latitudine;
    int nrOrase;
    string capitala;
    string* orase;

    Tara() :latitudine(45) {
        this->nume = "nu are nume";
        this->populatieTara = 100;
        this->nrOrase = 0;
        this->capitala = "Nu are capitala";
        this->orase = NULL;
    }
    Tara(string nume, int populatieTara, string capitala, int nrOrase, string* orase, float latitudine) : latitudine(latitudine) {
        this->nume = nume;
        this->populatieTara = populatieTara;
        this->capitala = capitala; 
        this->nrOrase = nrOrase;
        this->orase = new string[nrOrase];
        for (int i = 0; i < this->nrOrase; i++)
            this->orase[i] = orase[i];
    }
    Tara(string nume, int populatieTara, int nrOrase, float latitudine) : latitudine(30) {
        this->nume = nume;
        this->populatieTara = populatieTara;
        this->nrOrase = nrOrase;
        this->orase = NULL;
        this->capitala = "Nu are capitala.";
    }
    void afisare() {
        cout << "Tara " << this->nume << " se afla in galaxia " << this->galaxie << ", are capitala in orasul " << this->capitala << ", are un numar de " << this->nrOrase << " orase, acestea fiind: " << endl;
        if (nrOrase != 0 && orase != NULL) {
            for (int i = 0; i < this->nrOrase; i++) {
                cout << orase[i];
                cout << endl;
            }
        }
        else
            cout << "Numele oraselor nu au fost introduse" << endl<<endl;
    }
    ~Tara() {
        if (this->orase != NULL)
            delete[]this->orase;
    }
    static void setGalaxie(string galaxie) {
        Tara::galaxie = galaxie;
    }
};

string Tara::galaxie = "Calea Lactee";

class Oras {
public:
    string nume;
    int nrLocuitori;
    int nrCartiere;
    const float altitudine;
    static string tara;
    string* cartiere;

    Oras() : altitudine(0) {
        this->nume = " nu se cunoaste numele orasului ";
        this->nrLocuitori = 5;
        this->nrCartiere = 0;
        this->cartiere = NULL;
    }

    Oras(string nume, int nrLocuitori, int nrCartiere, string* cartiere, float altitudine) : altitudine(altitudine) {
        this->nume = nume;
        this->nrLocuitori = nrLocuitori;
        this->nrCartiere = nrCartiere;
        this->cartiere = new string[nrCartiere];
        for (int i = 0; i < nrCartiere; i++)
            this->cartiere[i] = cartiere[i];
    }
    Oras(string nume, int nrLocuitori, float altitudine) : altitudine(altitudine) {
        this->nume = nume;
        this->nrLocuitori = nrLocuitori;
        this->nrCartiere = 0;
        cartiere = NULL;
    }
    ~Oras() {
        if (this->cartiere != NULL)
            delete[]this->cartiere;
    }
    void afisare() {
        cout << "Orasul " << this->nume <<" din "<<this->tara<<", aflat la atitudinea de "<<this->altitudine << " de metri are un numar de " << this->nrLocuitori << " locuitori, situati in " << this->nrCartiere << " cartiere, acestea fiind: " << endl;
        if (this->nrCartiere != 0 && this->cartiere != NULL) {
            for (int i = 0; i < this->nrCartiere; i++)
                cout << this->cartiere[i] << endl;
        }
        else {
            cout << "Nu se cunosc cartierele acestui oras" << endl;
        }
    }

    static void setTara(string tara) {
        Oras::tara = tara;
    }
};
string Oras::tara = "Romania";
int main()
{
    Continent continent1;
    continent1.afisare();

    string* numeTari = new string[5];
    numeTari[0] = "Germania";
    numeTari[1] = "Polonia";
    numeTari[2] = "Romania";
    numeTari[3] = "Grecia";
    numeTari[4] = "Vatican";
    Continent continent2(2, "Europa", 5, numeTari, 100000);
    continent2.afisare();
    cout<<"Populatia medie pe tara este de "<<continent2.populatieMedie()<<"\n";

    Continent continent3(3, "Asia", 1000000);
    Continent::setPlaneta("Marte");
    Continent::adaugareCatastrofe(5);
    continent3.afisare();
    cout << endl;



    cout << endl;
    Tara tara1;
    tara1.afisare();
    string* orase = new string[2];
    orase[0] = "Timisoara";
    orase[1] = "Cluj";

    Tara tara2("Romania", 100000, "Bucuresti", 2, orase, 52.5);
    tara2.afisare();

    cout << endl;

    Tara tara3("Bulgaria", 50000, 5, 42);
    Tara::setGalaxie("Andromeda");
    tara3.afisare();
    cout << endl;

    cout << endl;
    Oras oras1;
    oras1.afisare();

    string* cartiere = new string[3];
    cartiere[0] = "Militari";
    cartiere[1] = "Giulesti";
    cartiere[2] = "Berceni";
    Oras oras2("Bucuresti", 200000, 3, cartiere, 200);
    oras2.afisare();

    Oras oras3("Sofia", 50000, 1000);
    Oras::setTara("Bulgaria");
    oras3.afisare();
}

