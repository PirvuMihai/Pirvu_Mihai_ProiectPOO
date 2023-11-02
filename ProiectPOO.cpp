#include <iostream>
//Domeniul Pamant, Pirvu Mihai, grupa 1048
using namespace std;
class Continent {
private:
    const int nrContinent;
    string nume;
    static string planeta;
    int populatie;
    int numarTari;
    string* tari;
    static int numarCatastrofe;
public:
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
    Continent(Continent& c) : nrContinent(c.nrContinent) {
        this->nume = c.nume;
        this->populatie = c.populatie;
        this->numarTari = c.numarTari;
        this->tari = new string[numarTari];
        for (int i = 0; i < numarTari; i++)
            this->tari[i] = c.tari[i];
    }
    const Continent& operator= (const Continent& c) {
        if (this != &c) {
            if (this->tari != NULL)
                delete[]this->tari;
            this->nume = c.nume;
            this->populatie = c.populatie;
            this->numarTari = c.numarTari;
            this->tari = new string[numarTari];
            for (int i = 0; i < numarTari; i++)
                this->tari[i] = c.tari[i];
            return *this;
        }
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
        if (this->numarTari != 0 && this->tari != NULL) {
            for (int i = 0; i < this->numarTari; i++) {
                cout << this->tari[i];
                cout << "\n";
            }
        }
        else {
            cout << "Nu au fost introduse numele tarilor"<<endl;
        }
        cout << "In ultimii ani, au avut loc " << this->numarCatastrofe << " catastrofe pe acest continent";
        cout << "\n";
        cout << "\n";
    }
    float populatieMedie() {
        return (float)this->populatie / this->numarTari;
    }

    static void adaugareCatastrofe(int catastrofeNoi) {
        Continent::numarCatastrofe += catastrofeNoi;
    }
    void setNume(string nume) {
        this->nume = nume;
    }
    string getNume() {
        return this->nume;
    }
    int getNrContinent() {
        return this->nrContinent;
    }
    static void setPlaneta(string planeta) {
        Continent::planeta = planeta;
    }
    static string getPlaneta() {
        return Continent::planeta;
    }
    void setPopulatie(int populatie) {
        this->populatie = populatie;
    }
    int getPopulatie() {
        return this->populatie;
    }
    void setNumarTari(int numarTari) {
        this->numarTari = numarTari;
    }
    int getNumarTari() {
        return this->numarTari;
    }
    void setTari(int numarTari, string* tari) {
        if (numarTari != 0) {
            if (this->tari != NULL)
                delete[]this->tari;
            this->numarTari = numarTari;
            this->tari = new string[numarTari];
            for (int i = 0; i < numarTari; i++)
                this->tari[i] = tari[i];
        }
    }
    string* getTari() {
        return this->tari;
    }
    static void setNumarCatastrofe(int numarCatastrofe) {
        Continent::numarCatastrofe = numarCatastrofe;
    }
    static int getNumarCatastrofe() {
        return Continent::numarCatastrofe;
    }

};
string Continent::planeta = "Pamant";
int Continent::numarCatastrofe = 0;

class Tara {
private:
    string nume;
    int populatieTara;
    static string galaxie;
    const float latitudine;
    int nrOrase;
    string capitala;
    string* orase;
public:
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

    Tara(Tara &t) :latitudine(t.latitudine) {
        this->nume = t.nume;
        this->populatieTara = t.populatieTara;
        this->capitala = t.capitala;
        this->nrOrase = t.nrOrase;
        this->orase = new string[nrOrase];
        if (t.orase != NULL) {
            for (int i = 0; i < this->nrOrase; i++)
                this->orase[i] = t.orase[i];
        }
    }

    const Tara& operator=(const Tara& t) {
        if (this != &t) {
            if (this->orase != NULL)
                delete[]this->orase;
            this->nume = t.nume;
            this->populatieTara = t.populatieTara;
            this->capitala = t.capitala;
            this->nrOrase = t.nrOrase;
            this->orase = new string[nrOrase];
            if (t.orase != NULL) {
                for (int i = 0; i < this->nrOrase; i++)
                    this->orase[i] = t.orase[i];
            }
            return *this;
        }
    }

    Tara(string nume, int populatieTara, int nrOrase, float latitudine) : latitudine(30) {
        this->nume = nume;
        this->populatieTara = populatieTara;
        this->nrOrase = nrOrase;
        this->orase = NULL;
        this->capitala = "Nu are capitala.";
    }
    void afisare() {
        cout << "Tara " << this->nume << " se afla in galaxia " << this->galaxie << ", are capitala in orasul " << this->capitala <<" cu o populatie de "<<this->populatieTara<< ", are un numar de " << this->nrOrase << " orase, acestea fiind: ";
        cout << "\n";
        if (this->nrOrase != 0 && this->orase != NULL) {
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

    void setNume(string nume) {
        this->nume = nume;
    }
    string getNume() {
        return this->nume;
    }
    void setPopulatieTara(int populatie) {
        this->populatieTara = populatie;
    }
    int getPopulatieTara() {
        return this->populatieTara;
    }
    static void setGalaxie(string galaxie) {
        Tara::galaxie = galaxie;
    }
    static string getGalaxie() {
        return Tara::galaxie;
    }
    float getLatitudine() {
        return this->latitudine;
    }
    void setNrOrase(int nrOrase) {
        this->nrOrase = nrOrase;
    }
    int getNrOrase() {
        return this->nrOrase;
    }
    void setCapitala(string capitala) {
        this->capitala = capitala;
    }
    string getCapitala() {
        return this->capitala;
    }
    void setOrase(int nrOrase, string* orase) {
        if (nrOrase != 0) {
            if (this->orase != NULL)
                delete[]this->orase;
            this->nrOrase = nrOrase;
            this->orase = new string[nrOrase];
            for (int i = 0; i < nrOrase; i++)
                this->orase[i] = orase[i];
        }
    }
    string* getOrase() {
        return this->orase;
    }
    friend int inmultireTara(Tara& tara);
};

string Tara::galaxie = "Calea Lactee";

class Oras {
private:
    string nume;
    int nrLocuitori;
    int nrCartiere;
    const float altitudine;
    static string tara;
    string* cartiere;
public:
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

    Oras(Oras& o) : altitudine(o.altitudine) {
        this->nume = o.nume;
        this->nrLocuitori = o.nrLocuitori;
        this->nrCartiere = o.nrCartiere;
        this->cartiere = new string[nrCartiere];
        for (int i = 0; i < nrCartiere; i++)
            this->cartiere[i] = o.cartiere[i];
    }

    const Oras& operator= (const Oras& o) {
        if (this != &o) {
            if (this->cartiere != NULL)
                delete[]this->cartiere;
            this->nume = o.nume;
            this->nrLocuitori = o.nrLocuitori;
            this->nrCartiere = o.nrCartiere;
            this->cartiere = new string[nrCartiere];
            for (int i = 0; i < nrCartiere; i++)
                this->cartiere[i] = o.cartiere[i];
            return *this;
        }
    }

    ~Oras() {
        if (this->cartiere != NULL)
            delete[]this->cartiere;
    }
    void afisare() {
        cout << "Orasul " << this->nume << " din " << this->tara << ", aflat la atitudinea de " << this->altitudine << " de metri are un numar de " << this->nrLocuitori << " locuitori, situati in " << this->nrCartiere << " cartiere, acestea fiind: " << endl;
        if (this->nrCartiere != 0 && this->cartiere != NULL) {
            for (int i = 0; i < this->nrCartiere; i++)
                cout << this->cartiere[i] << endl;
        }
        else {
            cout << "Nu se cunosc cartierele acestui oras" << endl << endl;
        }
    }
    void setNume(string nume) {
        this->nume = nume;
    }
    string getNume() {
        return this->nume;
    }

    void setNrLocuitori(int nrLoc) {
        this->nrLocuitori = nrLoc;
    }
    int getNrLocuitori() {
        return this->nrLocuitori;
    }

    void setNrCartiere(int nrCar) {
        this->nrCartiere = nrCar;
    }
    int getNrCartiere() {
        return this->nrCartiere;
    }

    float getAltitudine() {
        return this->altitudine;
    }

    static void setTara(string tara) {
        Oras::tara = tara;
    }
    static string getTara() {
        return Oras::tara;
    }

    void setCartiere(int nrCartiere, string* cartiere) {
        if (nrCartiere != 0) {
            if (this->cartiere != NULL)
                delete[]this->cartiere;
            this->nrCartiere = nrCartiere;
            this->cartiere = new string[nrCartiere];
            for (int i = 0; i < nrCartiere; i++)
                this->cartiere[i] = cartiere[i];
        }
    }
    string* getCartiere() {
        return this->cartiere;
    }
    friend int inmultireOras(Oras& oras);
};

int inmultireOras(Oras& oras) {
    return oras.getNrCartiere() * oras.getNrLocuitori();
}

int inmultireTara(Tara& tara) {
    return tara.getNrOrase() * tara.getPopulatieTara();
}

string Oras::tara = "Romania";

int main()
{
    cout << "Teste pentru obiectul continent: " << endl;
    cout << endl;
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
    cout << "Populatia medie pe tara este de " << continent2.populatieMedie() << "\n";

    Continent continent3(3, "Asia", 1000000);
    Continent::setPlaneta("Marte");
    Continent::adaugareCatastrofe(5);
    continent3.afisare();
    cout << endl;

    Continent continent4(continent3);
    continent4.setNumarCatastrofe(25);
    continent4.setNume("America de Sud");
    continent4.setPlaneta("Pluto");
    continent4.afisare();
    cout << endl;

    Continent continent5 = continent2;
    string* tari = new string[10]{ "Algeria", "Angola", "Benin", "Botswana", "Cameroon", "Chad", "Comoros", "Congo", "Egypt", "Ghana" };
    continent5.setNumarTari(10);
    continent5.setTari(10, tari);
    continent5.setNume("Africa");
    continent5.setNumarCatastrofe(1000);
    continent5.afisare();
    cout << endl;
    cout << endl;

    cout << "Teste pentru obiectul tara";

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

    Tara tara4(tara3);
    tara4.setNume("Israel");
    tara4.setNrOrase(3);
    string* orase03 = new string[3];
    orase03[0] = "Safed";
    orase03[1] = "Nazareth";
    orase03[2] = "Haifa";
    tara4.setOrase(3, orase03);
    tara4.afisare();
    cout << endl;
    cout << endl;
    cout << endl << tara4.getNume();
    cout << endl << tara4.getNrOrase();

    cout << endl;

    Tara tara5 = tara2;
    tara5.setNume("Australia");
    tara5.setCapitala("Desert");
    tara5.setPopulatieTara(2000);
    tara5.afisare();

    cout << endl<<endl;

    cout << "Teste pentru obiectul oras: ";

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

    cout << endl;

    Oras oras4(oras2);
    oras4.setNume("Braila");
    oras4.setNrLocuitori(10000);
    Oras::setTara("Romania");
    oras4.setNrCartiere(1);
    string* cart = new string[1]{ "Lacul Dulce" };
    oras4.setCartiere(1, cart);
    oras4.afisare();

    Oras oras5 = oras3;
    oras5.setNume(oras4.getNume());
    oras5.setTara(oras1.getTara());
    oras5.setNrLocuitori(oras2.getNrLocuitori());
    oras5.afisare();

    cout <<oras2.getNrCartiere()<<" "<<oras2.getNrLocuitori()<<" " << inmultireOras(oras2);
    cout << endl;
    cout <<tara3.getNrOrase()<< " " << tara3.getPopulatieTara() << " " << inmultireTara(tara3);
}

