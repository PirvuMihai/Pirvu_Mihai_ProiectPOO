#include <iostream>
//Domeniul Pamant, Pirvu Mihai, grupa 1048

//supraincarcate: =, +, [], ==


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

    Continent operator+ (const Continent& c) {
        Continent aux = *this;
        aux.populatie = this->populatie + c.populatie;
        aux.numarTari = this->numarTari + c.numarTari;
        if (aux.tari != NULL)
            delete[]aux.tari;
        aux.tari = new string[aux.numarTari];
        for (int i = 0; i < this->numarTari; i++)
            aux.tari[i] = this->tari[i];
        for (int j = this->numarTari; j < aux.numarTari; j++)
            aux.tari[j] = c.tari[j - this->numarTari];
        return aux;
    }

    string& operator[](int index) {
        return this->tari[index];
    }

    const bool& operator==(const Continent& c) {
        int cnt = 0;
        if (this->nume == c.nume && this->populatie == c.populatie && this->numarTari == c.numarTari)
            for (int i = 0; i < this->numarTari; i++)
                if (this->tari[i] != c.tari[i])
                    cnt = 1;
        if (this->nume != c.nume || this->populatie != c.populatie || this->numarTari != c.numarTari)
            cnt = 1;
        if (cnt == 0)
            return true;
        else
            return false;
    }

    Continent(int nrContinent, string nume, int populatie) : nrContinent(nrContinent) {
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
            cout << "Nu au fost introduse numele tarilor" << endl;
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
    string getNume() const {
        return this->nume;
    }
    int getNrContinent() const {
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
    int getPopulatie() const {
        return this->populatie;
    }
    void setNumarTari(int numarTari) {
        this->numarTari = numarTari;
    }
    int getNumarTari() const {
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
    string* getTari() const {
        return this->tari;
    }
    static void setNumarCatastrofe(int numarCatastrofe) {
        Continent::numarCatastrofe = numarCatastrofe;
    }
    static int getNumarCatastrofe() {
        return Continent::numarCatastrofe;
    }
    friend ostream& operator<<(ostream& out, const Continent& c) {
        out << "Continentul " << c.getNume() << " se afla pe planeta " << c.getPlaneta() << ", are populatia de " << c.getPopulatie() << " de locuitori. Acestia traiesc in " << c.getNumarTari() << " tari, acestea fiind:";
        out << "\n";
        if (c.getNumarTari() != 0 && c.getTari() != NULL) {
            for (int i = 0; i < c.numarTari; i++) {
                out << c.getTari()[i];
                out << "\n";
            }
        }
        out << "Pe acest continent au avut loc " << c.getNumarCatastrofe() << " catastrofe" << endl;
        return out;
    }
    friend istream& operator>>(istream& in, Continent& c) {
        cout << "Numele: ";
        in >> c.nume;
        cout << "Populatie: ";
        in >> c.populatie;
        cout << "Numarul de tari: ";
        in >> c.numarTari;
        cout << "Planeta: ";
        in >> c.planeta;
        if (c.tari != NULL)
            delete[]c.tari;
        c.tari = new string[c.numarTari];
        for (int i = 0; i < c.numarTari; i++) {
            cout << "Numele tarii " << i + 1 << " : ";
            in >> c.tari[i];
        }
        return in;
    }
};
string Continent::planeta = "Pamant";
int Continent::numarCatastrofe = 0;

//supraincarcati: =, <, >, !=, +=

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

    Tara(Tara& t) :latitudine(t.latitudine) {
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

    const bool& operator<(const Tara& t) {
        if (this->populatieTara < t.populatieTara && this->nrOrase < t.nrOrase && this->latitudine <= t.latitudine)
            return true;
        return false;
    }

    const bool& operator>(const Tara& t) {
        if (this->populatieTara > t.populatieTara && this->nrOrase > t.nrOrase && this->latitudine <= t.latitudine)
            return true;
        return false;
    }

    const bool& operator!=(const Tara& t) {
        int cnt = 0;
        if (this->nume == t.nume && this->populatieTara == t.populatieTara && this->latitudine == t.latitudine && this->galaxie == t.galaxie && this->nrOrase == t.nrOrase &&
            this->capitala == t.capitala) {
            for (int i = 0; i < this->nrOrase; i++)
                if (this->orase[i] != t.orase[i])
                    cnt = 1;
        }
        else
            return true;
        if (cnt == 0)
            return false;
    }

    Tara operator+=(const Tara& t) {
        Tara aux = *this;
        aux.populatieTara = this->populatieTara + t.populatieTara;
        aux.nrOrase = this->nrOrase + t.nrOrase;
        if (aux.orase != NULL)
            delete[]aux.orase;
        aux.orase = new string[aux.nrOrase];
        for (int i = 0; i < this->nrOrase; i++)
            aux.orase[i] = this->orase[i];
        for (int j = this->nrOrase; j < aux.nrOrase; j++)
            aux.orase[j] = t.orase[j - this->nrOrase];
        *this = aux;
        return *this;
    }

    Tara(string nume, int populatieTara, int nrOrase, float latitudine) : latitudine(30) {
        this->nume = nume;
        this->populatieTara = populatieTara;
        this->nrOrase = nrOrase;
        this->orase = NULL;
        this->capitala = "Nu are capitala.";
    }
    void afisare() {
        cout << "Tara " << this->nume << " se afla in galaxia " << this->galaxie << ", are capitala in orasul " << this->capitala << " cu o populatie de " << this->populatieTara << ", are un numar de " << this->nrOrase << " orase, acestea fiind: ";
        cout << "\n";
        if (this->nrOrase != 0 && this->orase != NULL) {
            for (int i = 0; i < this->nrOrase; i++) {
                cout << orase[i];
                cout << endl;
            }
        }
        else
            cout << "Numele oraselor nu au fost introduse" << endl << endl;
    }
    ~Tara() {
        if (this->orase != NULL)
            delete[]this->orase;
    }

    void setNume(string nume) {
        this->nume = nume;
    }
    string getNume() const {
        return this->nume;
    }
    void setPopulatieTara(int populatie) {
        this->populatieTara = populatie;
    }
    int getPopulatieTara() const {
        return this->populatieTara;
    }
    static void setGalaxie(string galaxie) {
        Tara::galaxie = galaxie;
    }
    static string getGalaxie() {
        return Tara::galaxie;
    }
    float getLatitudine() const {
        return this->latitudine;
    }
    void setNrOrase(int nrOrase) {
        this->nrOrase = nrOrase;
    }
    int getNrOrase() const {
        return this->nrOrase;
    }
    void setCapitala(string capitala) {
        this->capitala = capitala;
    }
    string getCapitala() const {
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
    string* getOrase() const {
        return this->orase;
    }
    friend int inmultireTara(Tara& tara);
    friend ostream& operator<<(ostream& out, const Tara& t) {
        cout << "Tara cu numele " << t.getNume() << " are capitala in " << t.getCapitala() << " are o populatie de " << t.getPopulatieTara() << " se afla in galaxia " << t.getGalaxie() << " la latitudinea " << t.getLatitudine() <<
            ", are un numar de " << t.getNrOrase() << " orase, acestea fiind: " << endl;
        for (int i = 0; i < t.getNrOrase(); i++)
            cout << t.getOrase()[i] << endl;
        cout << endl;
        return out;
    }
    friend istream& operator>>(istream& in, Tara& t) {
        cout << "Numele: ";
        in >> t.nume;
        cout << "Capitala: ";
        in >> t.capitala;
        cout << "Populatia tarii: ";
        in >> t.populatieTara;
        cout << "Numarul de orase: ";
        in >> t.nrOrase;
        cout << "Galaxie: ";
        in >> t.galaxie;
        if (t.orase != NULL)
            delete[]t.orase;
        t.orase = new string[t.nrOrase];
        for (int i = 0; i < t.nrOrase; i++) {
            cout << "Numele orasului cu numarul " << i + 1 << " :";
            in >> t.orase[i];
        }
        return in;
    }
};

string Tara::galaxie = "Calea Lactee";

//de supraincarcat: ++, *, *=, (), ->
//Supraincarcati: =

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

    Oras operator++() {
        this->nrLocuitori++;
        string* aux = new string[nrCartiere];
        for (int i = 0; i < nrCartiere; i++)
            aux[i] = this->cartiere[i];
        this->nrCartiere++;
        delete[]this->cartiere;
        this->cartiere = new string[this->nrCartiere];
        for (int i = 0; i < nrCartiere - 1; i++)
            this->cartiere[i] = aux[i];
        this->cartiere[nrCartiere - 1] = "Acest cartier a fost introdus ulterior";
        return *this;
    }

    Oras operator++(int) {
        this->nrLocuitori++;
        string* aux = new string[nrCartiere];
        for (int i = 0; i < nrCartiere; i++)
            aux[i] = this->cartiere[i];
        this->nrCartiere++;
        delete[]this->cartiere;
        this->cartiere = new string[this->nrCartiere];
        for (int i = 0; i < nrCartiere - 1; i++)
            this->cartiere[i] = aux[i];
        this->cartiere[nrCartiere - 1] = "Acest cartier a fost introdus ulterior";
        return *this;
    }

    Oras operator*(const Oras& o) {
        Oras aux = *this;
        aux.nrLocuitori = this->nrLocuitori * o.nrLocuitori;
        return aux;
    }

    Oras operator*=(const Oras& o) {
        Oras aux = *this;
        aux.nrLocuitori = this->nrLocuitori * o.nrLocuitori;
        return aux;
    }

    string* operator()(int n) {
        string* vector = new string[n];
        if (n >= 0 && n < this->nrCartiere) {
            for (int i = 0; i < n; i++)
                vector[i] = this->cartiere[i];
        }
        if (vector != NULL)
            return vector;
        delete[]vector;
    }

    
    Oras* operator->(){
        this->nrLocuitori = 100;
        return this;
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
    string getNume() const {
        return this->nume;
    }

    void setNrLocuitori(int nrLoc) {
        this->nrLocuitori = nrLoc;
    }
    int getNrLocuitori() const {
        return this->nrLocuitori;
    }

    void setNrCartiere(int nrCar) {
        this->nrCartiere = nrCar;
    }
    int getNrCartiere() const {
        return this->nrCartiere;
    }

    float getAltitudine() const {
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
    string* getCartiere() const {
        return this->cartiere;
    }
    friend int inmultireOras(Oras& oras);

    friend istream& operator>>(istream& in, Oras& o) {
        cout << "Introduceti numele tarii: ";
        in >> o.nume;
        cout << "Introduceti numarul locuitorilor din tara: ";
        in >> o.nrLocuitori;
        cout << "Introduceti numarul de cartiere :";
        in >> o.nrCartiere;
        delete[]o.cartiere;
        o.cartiere = new string[o.nrCartiere];
        for (int i = 0; i < o.nrCartiere; i++) {
            cout << "Introduceti numele cartierului numarul " << i + 1 << " : ";
            in >> o.cartiere[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, Oras& o) {
        out << "Orasul cu numele " << o.getNume() << ", din tara " << o.getTara() << " se afla la altitudinea " << o.getAltitudine() << " si are un numar de " << o.getNrLocuitori();
        if (o.getNrLocuitori() <= 10)
            out << " locuitori";
        else
            out << " de locuitori";
        out << ". Acestia sunt situati in " << o.getNrCartiere();
        if (o.getNrCartiere() <= 10)
            out << " cartiere";
        else
            out << " de cartiere";
        out << ", acestea fiind :"<<endl;
        for (int i = 0; i < o.getNrCartiere(); i++) {
            out << o.getCartiere()[i];
            out << endl;
        }
        return out;
    }

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

    cout << endl << endl;
    
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
    ++oras5;
    oras5.afisare();
    oras5++;
    oras5.afisare();

    

    cout << oras2.getNrCartiere() << " " << oras2.getNrLocuitori() << " " << inmultireOras(oras2);
    cout << endl;
    cout << tara3.getNrOrase() << " " << tara3.getPopulatieTara() << " " << inmultireTara(tara3);



    Continent c1;
    cin >> c1;
    cout << c1;
    Continent c2;
    cin >> c2;
    Continent c3;
    c3 = c2 + c1;
    cout << c3;
    cout << c2[1];
    cout << endl;
    cout << c3[2];
    cout << endl;
    if (c3 == c1)
    cout << "E bine";
    else
    cout << "Nu e bine";
    cout << endl;
    Continent c4 = c1;
        if(c4==c1)
            cout << "E bine";
        else
            cout << "Nu e bine";

    Tara t1;
    cin >> t1;
    Tara t2;
    cin >> t2;
    if (t1 > t2)
        cout << "Adevarat!"<<endl;
    if (t1 < t2)
        cout << "La fel de adevarat dar invers"<<endl;
    if (t1 != t2)
        cout << "Clar" << endl;
    Tara t3 = t1;
    if (t1 != t3)
        cout << "N-ar trebui?" << endl;
    t3 += t2;
    cout << t3;


    Oras o1;
    cin >> o1;
    cout << o1;
    o1++;
    cout << o1;
    ++o1;
    cout << o1;

    Oras o2 = o1;
    Oras o3;
    o3 = o2 * o1;
    cout << o3;
    Oras o4;
    o3 *= o4;
    cout << o4;
    cout << endl;
    int cnt = o3.getNrCartiere()-1;
    string* orase = o3(cnt);
    if (orase != nullptr)
        for (int i = 0; i < cnt; i++)
            cout << orase[i] << endl;
    int popul = o3.getNrLocuitori();
    cout << "Orasul " << o4.getNume() << " are o populatie de " << o4.getNrLocuitori()<<endl;
    cout << "Insa, primaria orasului doreste sa ajunga la o populatie de " << o3->getNrLocuitori();
    if (popul > o3->getNrLocuitori())
        cout << endl << "Astfel, acestia vor fi nevoiti sa mareasca populatia cu " << popul - o3->getNrLocuitori() << " de locuitori";
    else
        cout << endl << "Astfel, acestia vor fi nevoiti sa scada populatia cu " << o3->getNrLocuitori() - popul << " de locuitori";
    }
