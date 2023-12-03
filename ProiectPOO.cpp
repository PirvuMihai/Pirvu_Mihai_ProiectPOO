#include <iostream>
#include <fstream>
using namespace std;

class Oras {
private:
	const int ID;
	string nume;
	int nrLocuitori;
	int nrCartiere;
	static string planeta;
	string* cartiere;
public:
	//Constructorul default
	Oras() : ID(0) {
		this->nume = " nu se cunoaste numele orasului ";
		this->nrLocuitori = 0;
		this->nrCartiere = 0;
		this->cartiere = NULL;
	}
	//Constructorul complet
	Oras(string nume, int nrLocuitori, int nrCartiere, string* cartiere, int ID) : ID(ID) {
		this->nume = nume;
		this->nrLocuitori = nrLocuitori;
		this->nrCartiere = nrCartiere;
		this->cartiere = new string[nrCartiere];
		for (int i = 0; i < nrCartiere; i++)
			this->cartiere[i] = cartiere[i];
	}
	//Constructorul partial
	Oras(string nume, int nrLocuitori, int ID) : ID(ID) {
		this->nume = nume;
		this->nrLocuitori = nrLocuitori;
		this->nrCartiere = 0;
		cartiere = NULL;
	}
	//Constructorul de copiere
	Oras(Oras& o) : ID(o.ID) {
		this->nume = o.nume;
		this->nrLocuitori = o.nrLocuitori;
		this->nrCartiere = o.nrCartiere;
		this->cartiere = new string[nrCartiere];
		for (int i = 0; i < nrCartiere; i++)
			this->cartiere[i] = o.cartiere[i];
	}
	//Destructorul
	~Oras() {
		if (this->cartiere != NULL)
			delete[]this->cartiere;
	}
	//Operatorul =
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
	//Operatorul +
	const Oras operator+(const Oras& o) {
		Oras aux = *this;
		aux.nrLocuitori = this->nrLocuitori + o.nrLocuitori;
		aux.nrCartiere = this->nrCartiere + o.nrCartiere;
		if (aux.cartiere != NULL)
			delete[]aux.cartiere;
		aux.cartiere = new string[aux.nrCartiere];
		for (int i = 0; i < this->nrCartiere; i++)
			aux.cartiere[i] = this->cartiere[i];
		for (int i = this->nrCartiere; i < aux.nrCartiere; i++)
			aux.cartiere[i] = o.cartiere[i - this->nrCartiere];
		return aux;
	}
	//Operatorii == si !=
	bool operator==(const Oras& o) {
		int cnt = 0;
		if (this->nume != o.nume || this->nrLocuitori != o.nrLocuitori || this->nrCartiere != o.nrCartiere)
			return false;
		for (int i = 0; i < this->nrCartiere; i++)
			if (this->cartiere[i] != cartiere[i])
				return false;
		return true;
	}
	bool operator!=(const Oras& o) {
		int cnt = 0;
		if (this->nume != o.nume || this->nrLocuitori != o.nrLocuitori || this->nrCartiere != o.nrCartiere)
			return true;
		for (int i = 0; i < this->nrCartiere; i++)
			if (this->cartiere[i] != cartiere[i])
				return true;
		return false;
	}
	string operator[](int n) {
		if (n >= 0 && n < this->nrCartiere)
			return this->cartiere[n];
	}
	//Seteri si geteri
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
		this->cartiere = new string[nrCar];
	}
	int getNrCartiere() const {
		return this->nrCartiere;
	}

	int getID() const {
		return this->ID;
	}

	static void setPlaneta(string planeta) {
		Oras::planeta = planeta;
	}
	static string getPlaneta() {
		return Oras::planeta;
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

	void scrieInFisBinar(string numeFisier) {
		ofstream f(numeFisier, ios::binary | ios::out);
		int lung = nume.length() + 1;
		f.write((char*)&lung, sizeof(int));
		f.write((char*)nume.c_str(), lung);
		f.write((char*)&nrLocuitori, sizeof(int));
		f.write((char*)&nrCartiere, sizeof(int));
		for (int i = 0; i < nrCartiere; i++) {
			lung = cartiere[i].length() + 1;
			f.write((char*)&lung, sizeof(int));
			f.write((char*)cartiere[i].c_str(), lung);
		}
		f.close();
	}

	void citesteDinFisBinar(string numeFisier) {
		ifstream f(numeFisier, ios::binary | ios::in);
		int lung;
		f.read((char*)&lung, sizeof(int));
		char* numeChar = new char[lung];
		f.read((char*)numeChar, lung);
		nume = numeChar;
		f.read((char*)&nrLocuitori, sizeof(int));
		f.read((char*)&nrCartiere, sizeof(int));
		if (cartiere != NULL)
			delete[]cartiere;
		cartiere = new string[nrCartiere];
		for (int i = 0; i < nrCartiere; i++) {
			lung = cartiere[i].length() + 1;
			f.read((char*)&lung, sizeof(int));
			f.read((char*)numeChar, lung);
			cartiere[i] = numeChar;
		}
		delete[]numeChar;
		f.close();
	}

	friend istream& operator>>(istream& read, Oras& o);
	friend ostream& operator<<(ostream& show, const Oras& o);
	friend ifstream& operator>>(ifstream& citire, Oras& o);
	friend ofstream& operator<<(ofstream& afisare, const Oras& o);
};

istream& operator>>(istream& read, Oras& o) {
	cout << "Introduceti numele orasului: ";
	read >> o.nume;
	cout << "Introduceti numarul locuitorilor din orasul " << o.nume << ": ";
	read >> o.nrLocuitori;
	cout << "Introduceti numarul de cartiere :";
	read >> o.nrCartiere;
	delete[]o.cartiere;
	o.cartiere = new string[o.nrCartiere];
	for (int i = 0; i < o.nrCartiere; i++) {
		cout << "Introduceti numele cartierului numarul " << i + 1 << " : ";
		read >> o.cartiere[i];
	}
	return read;
}

ostream& operator<<(ostream& show, const Oras& o) {
	show << "Orasul cu numele " << o.getNume() << ", de pe planeta " << o.getPlaneta() << " are ID-ul " << o.getID() << " si are un numar de " << o.getNrLocuitori();
	if (o.getNrLocuitori() <= 10)
		show << " locuitori";
	else
		show << " de locuitori";
	show << ". Acestia sunt situati in " << o.getNrCartiere();
	if (o.getNrCartiere() <= 10)
		show << " cartiere";
	else
		show << " de cartiere";
	show << ", acestea fiind :" << endl;
	for (int i = 0; i < o.getNrCartiere(); i++) {
		show << o.getCartiere()[i];
		show << endl;
	}
	return show;
}

ifstream& operator>>(ifstream& citire, Oras& o) {
	citire >> o.nume;
	citire >> o.nrLocuitori;
	citire >> o.nrCartiere;
	if (o.cartiere != NULL)
		delete[]o.cartiere;
	o.cartiere = new string[o.nrCartiere];
	for (int i = 0; i < o.nrCartiere; i++)
		citire >> o.cartiere[i];
	return citire;
}

ofstream& operator<<(ofstream& afisare, Oras& o) {
	afisare << o.getNume() << endl;
	afisare << o.getNrLocuitori() << endl;
	afisare << o.getNrCartiere() << endl;
	for (int i = 0; i < o.getNrCartiere(); i++)
		afisare << o.getCartiere()[i] << endl;
	return afisare;
}

string Oras::planeta = "NumePlaneta";

class Tara {
private:
	const int ID;
	string nume;
	int populatie;
	static string continent;
	int nrOrase;
	string capitala;
	Oras* orase;
public:
	//Constructor default
	Tara() : ID(0) {
		this->nume = "Numele tarii nu este cunoscut.";
		this->populatie = 0;
		this->nrOrase = 0;
		this->capitala = "Capitala nu este cunoscuta.";
		this->orase = NULL;
	}
	//Constructor partial
	Tara(int ID, string nume, string capitala, int populatie) : ID(ID) {
		this->nume = nume;
		this->populatie = populatie;
		this->capitala = capitala;
		this->nrOrase = 0;
		this->orase = NULL;
	}
	//Constructor complet
	Tara(int ID, string nume, string capitala, int populatie, int nrOrase, Oras* orase) : ID(ID) {
		this->nume = nume;
		this->populatie = populatie;
		this->capitala = capitala;
		this->nrOrase = nrOrase;
		if (nrOrase > 0) {
			if (this->orase != NULL)
				delete[] this->orase;
			this->orase = new Oras[nrOrase];
			for (int i = 0; i < nrOrase; i++) {
				this->orase[i] = orase[i];
			}
		}
		else
			this->orase = NULL;
	}
	//Destructor
	~Tara() {
		if (this->orase != NULL) {
			delete[] this->orase;
		}
	}
	//Constructor de copiere
	Tara(Tara& t) :ID(t.ID) {
		this->nume = t.nume;
		this->populatie = t.populatie;
		this->capitala = t.capitala;
		this->nrOrase = t.nrOrase;
		this->orase = new Oras[this->nrOrase];
		if (this->orase != NULL) {
			delete[] this->orase;
			this->orase = new Oras[this->nrOrase];
		}
		for (int i = 0; i < nrOrase; i++)
			this->orase[i] = t.orase[i];
	}
	//Operatorul =
	const Tara operator=(const Tara& t) {
		if (this != &t) {
			this->nume = t.nume;
			this->populatie = t.populatie;
			this->capitala = t.capitala;
			this->nrOrase = t.nrOrase;
			if (this->nrOrase > 0) {
				if (this->orase != NULL)
					delete[] this->orase;
				this->orase = new Oras[this->nrOrase];
				for (int i = 0; i < nrOrase; i++) {
					this->orase[i] = t.orase[i];
				}
			}
			else
				this->orase = NULL;
		}
		return *this;
	}
	//Operatorul +
	const Tara operator+(const Tara& t) {
		Tara aux = *this;
		aux.populatie = this->populatie + t.populatie;
		aux.nrOrase = this->nrOrase + t.nrOrase;
		if (aux.orase != NULL)
			delete[]aux.orase;
		aux.orase = new Oras[aux.nrOrase];
		for (int i = 0; i < this->nrOrase; i++) {
			aux.orase[i] = this->orase[i];
		}
		for (int i = this->nrOrase; i < aux.nrOrase; i++) {
			aux.orase[i] = t.orase[i - this->nrOrase];
		}
		return aux;
	}
	//Operatorul cast
	operator int() {
		return this->populatie;
	}
	explicit operator string() {
		return this->nume;
	}
	//Operatorul index
	Oras operator[](int n) {
		return this->orase[n];
	}
	//Operatorii < si >
	bool operator<(Tara& t) {
		if (this->populatie < t.populatie && this->nrOrase < t.populatie)
			return true;
		else
			return false;
	}
	bool operator>(Tara& t) {
		if (this->populatie > t.populatie && this->populatie > t.populatie)
			return true;
		else
			return false;
	}
	//Operatorii * si /
	const Tara operator*(Tara& t) {
		this->populatie = this->populatie * t.populatie;
		return *this;
	}
	const Tara operator/(Tara& t) {
		if (t.populatie != 0)
			this->populatie = this->populatie / t.populatie;
		return *this;
	}

	//Seteri si geteri
	void setNume(string nume) {
		this->nume = nume;
	}
	string getNume() const{
		return this->nume;
	}
	void setPopulatie(int populatie) {
		this->populatie = populatie;
	}
	int getPopulatie() const{
		return this->populatie;
	}
	void setCapitala(string capitala) {
		this->capitala = capitala;
	}
	string getCapitala() const{
		return this->capitala;
	}
	void setNrOrase(int nrOrase) {
		this->nrOrase = nrOrase;
		this->orase = new Oras[nrOrase];
	}
	int getNrOrase() const{
		return this->nrOrase;
	}
	void setOrase(int nrOrase, Oras* orase) {
		if (nrOrase != 0) {
			if (this->nrOrase >= nrOrase)
				for (int i = 0; i < nrOrase; i++)
					this->orase[i] = orase[i];
			else {
				Oras* aux;
				aux = new Oras[this->nrOrase];
				for (int i = 0; i < this->nrOrase; i++)
					aux[i] = this->orase[i];
				if (this->orase != NULL)
					delete[]this->orase;
				this->orase = new Oras[nrOrase];
				for (int i = 0; i < this->nrOrase; i++)
					this->orase[i] = aux[i];
				for (int i = this->nrOrase; i < nrOrase; i++)
					this->orase[i] = orase[i - this->nrOrase];
				this->nrOrase = nrOrase;
				delete[]aux;
			}
		}
	}
	Oras* getOrase() const {
		return this->orase;
	}

	void scriereInFisBinar(string numeFisier) {
		ofstream f(numeFisier, ios::binary | ios::out);
		int lung = nume.length() + 1;
		f.write((char*)&lung, sizeof(int));
		f.write((char*)nume.c_str(), lung);
		f.write((char*)&populatie, sizeof(int));
		lung = capitala.length() + 1;
		f.write((char*)&lung, sizeof(int));
		f.write((char*)capitala.c_str(), lung);
		f.write((char*)&nrOrase, sizeof(int));
		for (int i = 0; i < nrOrase; i++)
			orase[i].scrieInFisBinar(numeFisier);
		f.close();
	 }
	void citesteDinFisBinar(string numeFisier) {
		ifstream f(numeFisier, ios::binary | ios::in);
		int lung;
		f.read((char*)&lung, sizeof(int));
		char* numeTemp = new char[lung];
		f.read((char*)numeTemp, lung);
		nume = numeTemp;
		f.read((char*)&populatie, sizeof(int));
		f.read((char*)&lung, sizeof(int));
		delete[]numeTemp;
		numeTemp = new char[lung];
		f.read((char*)numeTemp, lung);
		capitala = numeTemp;
		f.read((char*)&nrOrase, sizeof(int));
		if (orase != NULL)
			delete[]orase;
		orase = new Oras[nrOrase];
		for (int i = 0; i < nrOrase; i++)
			orase[i].citesteDinFisBinar(numeFisier);
		f.close();
	}

	friend istream& operator>>(istream& cit, Tara& t);
	friend ostream& operator<<(ostream& afis, const Tara& t);
	friend istream& operator>>(istream& read, Oras& o);
	friend ostream& operator<<(ostream& show, const Oras& o);
	friend ifstream& operator>>(ifstream& citire, Tara& t);
	friend ofstream& operator<<(ofstream& afisare, const Tara& t);
};

istream& operator>>(istream& cit, Tara& t) {
	string a;
	int b;
	cout << "Numele tarii: ";
	cit >> a;
	t.setNume(a);
	cout << "Populatia tarii: ";
	cit >> b;
	t.setPopulatie(b);
	cout << "Capitala: ";
	cit >> a;
	t.setCapitala(a);
	cout << "Numarul oraselor: ";
	cit >> b;
	t.setNrOrase(b);
	if (t.getNrOrase() == 0)
		return cit;
	else {
		delete[]t.orase;
		t.orase = new Oras[t.getNrOrase()];
		for (int i = 0; i < t.nrOrase; i++) {
			cout << "Introdu orasul cu numarul " << i + 1 << endl;
			cit >> t.orase[i];
		}
	}
	return cit;
}

ostream& operator<<(ostream& afis, const Tara& t) {
	afis << "Tara " << t.getNume() << " are capitala in " << t.getCapitala() << ", are o populatie de " << t.getPopulatie() << " de oameni, acestia fiind situati in " << t.getNrOrase() << " orase. Acestea sunt: ";
	if (t.getNrOrase() == 0)
		afis << endl << "Orasele acestei tari nu sunt trecute in baza de date.";
	else
		for (int i = 0; i < t.getNrOrase(); i++)
			afis << endl << t.getOrase()[i];
	return afis;
}

ifstream& operator>>(ifstream& citire, Tara& t) {
	citire >> t.nume;
	citire >> t.populatie;
	citire >> t.capitala;
	citire >> t.nrOrase;
	if (t.orase != NULL)
		delete[]t.orase;
	t.orase = new Oras[t.nrOrase];
	for (int i = 0; i < t.nrOrase; i++)
		citire >> t.orase[i];
	return citire;
}

ofstream& operator<<(ofstream& afisare, const Tara& t) {
	afisare << t.nume << endl;
	afisare << t.populatie << endl;
	afisare << t.capitala << endl;
	afisare << t.nrOrase << endl;
	for (int i = 0; i < t.nrOrase; i++)
		afisare << t.orase[i] << endl;
	return afisare;
}

class Continent {
private:
	const int ID;
	string nume;
	static string planeta;
	int populatie;
	int nrTari;
	Tara* tari;
public:
	//Constructorul default
	Continent() : ID(0) {
		this->nume = " acest continent nu a fost numit inca. ";
		this->populatie = 0;
		this->nrTari = 0;
		this->tari = NULL;
	}
	//Constructorul partial
	Continent(int ID, string nume) : ID(ID) {
		this->nume = nume;
		this->populatie = 0;
		this->nrTari = 0;
		this->tari = NULL;
	}
	//Constructorul complet
	Continent(int ID, string nume, int populatie, int nrTari, Tara* tari) : ID(ID) {
		this->nume = nume;
		this->populatie = populatie;
		this->nrTari = nrTari;
		if (this->tari != NULL)
			delete this->tari;
		this->tari = new Tara[this->nrTari];
		for (int i = 0; i < this->nrTari; i++)
			this->tari[i] = tari[i];
	}
	//Constructorul de copiere
	Continent(Continent& c) : ID(c.ID) {
		this->nume = c.nume;
		this->populatie = c.populatie;
		this->nrTari = c.nrTari;
		if (this->tari != NULL)
			delete[]this->tari;
		this->tari = new Tara[this->nrTari];
		for (int i = 0; i < this->nrTari; i++)
			this->tari[i] = c.tari[i];
	}
	//Destructorul
	~Continent() {
		if (this->tari != NULL) {
			delete[] this->tari;
		}
	}
	//Operatorul =
	const Continent& operator=(const Continent& c) {
		if (this != &c) {
			this->nume = c.nume;
			this->populatie = c.populatie;
			this->nrTari = c.nrTari;
			if (this->tari != NULL)
				delete this->tari;
			this->tari = new Tara[this->nrTari];
			for (int i = 0; i < this->nrTari; i++)
				this->tari[i] = c.tari[i];
		}
		return *this;
	}
	//Operatorul +
	Continent operator+ (const Continent& c) {
		Continent aux = *this;
		aux.populatie = this->populatie + c.populatie;
		aux.nrTari = this->nrTari + c.nrTari;
		if (aux.tari != NULL)
			delete[]aux.tari;
		aux.tari = new Tara[aux.nrTari];
		for (int i = 0; i < this->nrTari; i++)
			aux.tari[i] = this->tari[i];
		for (int j = this->nrTari; j < aux.nrTari; j++)
			aux.tari[j] = c.tari[j - this->nrTari];
		return aux;
	}
	//Operatorul -- (pre si post)
	Continent operator--() {
		if (this->populatie > 20)
			this->populatie = this->populatie - 20;
		else
			this->populatie = 0;
		return *this;
	}
	Continent operator--(int n) {
		Continent aux = *this;
		if (this->populatie > 20)
			this->populatie = this->populatie - 20;
		else
			this->populatie = 0;
		return aux;
	}
	//Operatorul ++ (pre si post)
	Continent operator++() {
		this->populatie = this->populatie + 1;
		return *this;
	}
	Continent operator++(int n) {
		Continent aux = *this;
		this->populatie = this->populatie + 1;
		return aux;
	}
	//Operator []
	Tara operator[](int n) {
		if (n >= 0 && n < this->nrTari)
			return this->tari[n];
	}


	//Geteri si Seteri
	int getID() const{
		return this->ID;
	}
	void setNume(string nume) {
		this->nume = nume;
	}
	string getNume() const{
		return this->nume;
	}
	void setPopulatie(int populatie) {
		this->populatie = populatie;
	}
	int getPopulatie() const{
		return this->populatie;
	}
	void setNrTari(int nrTari) {
		this->nrTari = nrTari;
		this->tari = new Tara[nrTari];
	}
	int getNrTari() const{
		return this->nrTari;
	}
	void setTari(int nrTari, Tara* tari) {
		if (nrTari != 0) {
			if (this->nrTari >= nrTari)
				for (int i = 0; i < nrTari; i++)
					this->tari[i] = tari[i];
			else {
				this->nrTari = nrTari;
				//				this->tari = new Tara[nrTari];
				if (this->tari != NULL)
					delete[]this->tari;
				this->tari = new Tara[nrTari];
				for (int i = 0; i < nrTari; i++)
					this->tari[i] = tari[i];
			}
		}
	}
	Tara* getTari() const {
		return this->tari;
	}
	//Functiile de afisare si citire
	friend istream& operator>>(istream& citire, Continent& c);
	friend ostream& operator<<(ostream& afisare, const Continent& c);
	friend istream& operator>>(istream& cit, Tara& t);
	friend ostream& operator<<(ostream& afis, const Tara& t);
	friend ifstream& operator>>(ifstream& citire, Continent& c);
	friend ofstream& operator<<(ofstream& afisare, const Continent& c);
};

istream& operator>>(istream& citire, Continent& c) {
	cout << "Introduceti numele continentului: ";
	citire >> c.nume;
	cout << "Introduceti populatia continentului: ";
	citire >> c.populatie;
	cout << "Cate tari sunt pe acest continent?\n";
	citire >> c.nrTari;
	if (c.tari != NULL)
		delete[]c.tari;
	c.tari = new Tara[c.nrTari];
	for (int i = 0; i < c.nrTari; i++)
		citire >> c.tari[i];
	return citire;
}

ostream& operator<<(ostream& afisare, const Continent& c) {
	afisare << "Continentul " << c.getNume() << " are ID-ul " << c.getID() << ". In acesta locuiesc momentan " << c.getPopulatie() << " de mii de oameni, care sunt impartiti in " << c.getNrTari() << " tari.";
	for (int i = 0; i < c.getNrTari(); i++)
		afisare << "Aceste tari sunt: " << c.getTari()[i];
	return afisare;
}

ifstream& operator>>(ifstream& citire, Continent& c) {
	citire >> c.nume;
	citire >> c.populatie;
	citire >> c.nrTari;
	if (c.tari != NULL)
		delete[]c.tari;
	c.tari = new Tara[c.nrTari];
	for (int i = 0; i < c.nrTari; i++)
		citire >> c.tari[i];
	return citire;
}

ofstream& operator<<(ofstream& afisare, const Continent& c) {
	afisare << c.nume<<endl;
	afisare << c.populatie<<endl;
	afisare << c.nrTari<<endl;
	for (int i = 0; i < c.nrTari; i++)
		afisare << c.tari[i] << endl;
	return afisare;
}

class Planeta {
private:
	const int ID;
	int nrContinente;
	Continent* continent;
	string nume;
	bool locuibila;
	int nrSpecii;

public:
	//Constructorul default
	Planeta() : ID(0) {
		this->nrContinente = 0;
		this->continent = NULL;
		this->nume = "nu se cunoaste numele planetei";
		this->nrSpecii = 0;
		this->locuibila = false;
	}
	//Constructorul partial
	Planeta(int id, string nume, bool locuibila, int nrContinente, int nrSpecii) : ID(id) {
		this->nume = nume;
		this->locuibila = locuibila;
		this->nrContinente = nrContinente;
		this->continent = NULL;
		this->nrSpecii = nrSpecii;
	}
	//Constructorul complet
	Planeta(int id, string nume, bool locuibila, int nrContinente, int nrSpecii, Continent* continent) : ID(id) {
		this->nume = nume;
		this->locuibila = locuibila;
		this->nrContinente = nrContinente;
		this->nrSpecii = nrSpecii;
		if (this->continent != NULL)
			delete this->continent;
		this->continent = new Continent[this->nrContinente];
		for (int i = 0; i < this->nrContinente; i++)
			this->continent[i] = continent[i];
	}
	//Destructorul
	~Planeta() {
		if (this->continent != NULL)
			delete[]this->continent;
	}
	//Destructor apelabil, pentru comoditate
	void free() {
		if (this->continent != NULL)
			delete this->continent;
	}
	//Constructor de copiere
	Planeta(const Planeta& p) : ID(p.ID) {
		if (this != &p) {
			this->nume = p.nume;
			this->locuibila = p.locuibila;
			this->nrContinente = p.nrContinente;
			this->nrSpecii = p.nrSpecii;
			if (this->continent != NULL)
				delete this->continent;
			this->continent = new Continent[this->nrContinente];
			for (int i = 0; i < this->nrContinente; i++)
				this->continent[i] = p.continent[i];
		}
	}
	//Operatorul = 
	const Planeta& operator=(const Planeta& p) {
		if (this != &p) {
			this->nume = p.nume;
			this->locuibila = p.locuibila;
			this->nrContinente = p.nrContinente;
			this->nrSpecii = p.nrSpecii;
			if (this->continent != NULL)
				delete this->continent;
			this->continent = new Continent[this->nrContinente];
			for (int i = 0; i < this->nrContinente; i++)
				this->continent[i] = p.continent[i];
		}
		return *this;
	}
	//Operatorul +
	Planeta operator+ (const Planeta& p) {
		Planeta aux;
		aux = *this;
		if ((this->locuibila) || (aux.locuibila))
			aux.locuibila = true;
		else
			aux.locuibila = false;
		aux.nrContinente += p.nrContinente;
		delete aux.continent;
		aux.continent = new Continent[aux.nrContinente];
		for (int i = 0; i < this->nrContinente; i++)
			aux.continent[i] = this->continent[i];
		for (int j = this->nrContinente; j < aux.nrContinente; j++)
			aux.continent[j] = p.continent[j - this->nrContinente];
		return aux;
	}
	//Operatorul index
	Continent& operator[](int n) {
		if (n >= 0 && n < this->nrContinente)
			return this->continent[n];
	}

	//Operatorul cast, returneaza continentul cu cele mai multe specii
	string operator()() {
		int max = -1;
		int cnt = 0;
		if (this->nrContinente == 0)
			return 0;
		else if (this->locuibila) {
			for (int i = 0; i < this->nrContinente; i++)
				if (max < this->continent[i].getPopulatie()) {
					max = this->continent[i].getPopulatie();
					cnt = i;
				}
			return this->continent[cnt].getNume();
		}
	}
	//Operatorul !
	Planeta operator!() {
		Planeta aux = *this;
		aux.locuibila = !aux.locuibila;
		return aux;
	}
	//Geteri si Seteri
	int getID() const {
		return this->ID;
	}
	void setNrContinente(int nrContinente) {
		this->nrContinente = nrContinente;
	}
	int getNrContinente() const{
		return this->nrContinente;
	}
	void setNume(string nume) {
		this->nume = nume;
	}
	string getNume() const {
		return this->nume;
	}
	void setLocuibila(bool locuibila) {
		this->locuibila = locuibila;
	}
	bool getLocuibila() const {
		return this->locuibila;
	}
	void setNrSpecii(int nrSpecii) {
		this->nrSpecii = nrSpecii;
	}
	int getNrSpecii() const {
		return this->nrSpecii;
	}
	Continent* getContinent() const {
		return this->continent;
	}
	void setContinent(int nrContinente, Continent* c) {
		if (nrContinente != 0) {
			if (this->nrContinente > nrContinente)
				for (int i = 0; i < nrContinente; i++)
					this->continent[i] = c[i];
			else {
				if (this->continent != NULL)
					delete[]this->continent;
				this->continent = new Continent[nrContinente];
				for (int i = 0; i < nrContinente; i++)
					this->continent[i] = c[i];
				this->nrContinente = nrContinente;
			}
		}
	}
	friend istream& operator>>(istream& in, Planeta& p) {
		cout << "Introduceti numele planetei: \n";
		in >> p.nume;
		cout << "Este locuibila? 1-Da, 0-Nu \n";
		in >> p.locuibila;
		if (p.locuibila == true) {
			cout << "Cate specii traiesc pe aceasta planeta?\n";
			in >> p.nrSpecii;
		}
		cout << "Cate continente sunt pe aceasta planeta? \n";
		in >> p.nrContinente;
		if (p.nrContinente == 0)
			return in;
		else {
			if (p.continent != NULL)
				delete[]p.continent;
			p.continent = new Continent[p.nrContinente];
			for (int i = 0; i < p.nrContinente; i++)
				in >> p.continent[i];
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, const Planeta& p) {
		out << "Planeta " << p.getNume() << " are ID-ul " << p.getID();
		if (p.getLocuibila()) {
			out << "\nAceasta planeta este locuibila si are " << p.getNrContinente() <<
				" continente in care traiesc " << p.getNrSpecii() << " de specii.\nContinentele sunt urmatoarele: ";
			if (p.getNrContinente() == 0)
				out << "\nNu se cunosc continentele de pe aceasta planeta.";
			else
				for (int i = 0; i < p.nrContinente; i++)
					if (p.continent != NULL)
						out << p.getContinent()[i];
		}
		else {
			out << "\nAceasta planeta are " << p.getNrContinente() << " continente, insa nu este locuita.";
			if (p.getNrContinente() == 0)
				out << "\nNu se cunosc continentele de pe aceasta planeta.";
			else
				for (int i = 0; i < p.nrContinente; i++)
					if (p.continent != NULL)
						out << p.getContinent()[i];
		}
		return out;
	}
	friend ifstream& operator>>(ifstream& fcitire, Planeta& p);
	friend ofstream& operator<<(ofstream& fafisare, const Planeta& p);
	friend istream& operator>>(istream& citire, Continent& c);
	friend ostream& operator<<(ostream& afisare, Continent& c);
};

ifstream& operator>>(ifstream& fcitire, Planeta& p) {
	fcitire >> p.nume;
	fcitire >> p.locuibila;
	fcitire >> p.nrSpecii;
	fcitire >> p.nrContinente;
	if (p.continent != NULL)
		delete[]p.continent;
	p.continent = new Continent[p.nrContinente];
	for (int i = 0; i < p.nrContinente; i++)
		fcitire >> p.continent[i];
	return fcitire;
}

ofstream& operator<<(ofstream& fafisare, const Planeta& p) {
	fafisare << p.nume<<endl;
	fafisare << p.locuibila << endl;
	fafisare << p.nrSpecii << endl;
	fafisare << p.nrContinente << endl;
	for (int i = 0; i < p.nrContinente; i++)
		fafisare << p.continent[i] << " ";
	fafisare << endl;
	return fafisare;
}

class Capitala : public Oras {
private:
	int anDesemnare;
public:
	Capitala() : Oras() {
		this->anDesemnare = 1500;
	}
	Capitala(int an, int ID, string nume, int nrLoc, int nrCar, string* cartiere) : Oras(nume, nrLoc, nrCar, cartiere, ID) {
		this->anDesemnare = an;
	}
	~Capitala() {

	}
	Capitala(Capitala& c) : Oras(c) {
		this->anDesemnare = c.anDesemnare;
	}
	const Capitala operator=(const Capitala c) {
		this->anDesemnare = c.anDesemnare;
		(Oras&)*this = (Oras&)c;
		return *this;
	}
	void setAnDesemnare(int an) {
		this->anDesemnare = an;
	}
	int getAnDesemnare() const {
		return this->anDesemnare;
	}
	friend istream& operator>>(istream& read, Oras& o);
	friend istream& operator>>(istream& in, Capitala& c) {
		cout << "In ce an a devenit acest oras capitala?" << endl;
		in >> c.anDesemnare;
		//in >> static_cast<Oras&>(c);
		in >> (Oras&)c;
		return in;
	}
	friend ostream& operator<<(ostream& show, const Oras& o);
	friend ostream& operator<<(ostream& out, const Capitala& c) {
		out << "Orasul " << c.getNume() << " a devenit capitala in anul " << c.getAnDesemnare()<<endl;
		out << (const Oras&)c;
		//out << static_cast<const Oras&>(c);
		return out;
	}
};

class PutereGlobala : public Tara {
private:
	int nrTancuri;
	int nrAvioane;
	int nrSoldati;
public:
	PutereGlobala() : Tara() {
		this->nrAvioane = 0;
		this->nrSoldati = 0;
		this->nrTancuri = 0;
	}
	PutereGlobala(int nrAvioane, int nrSoldati, int nrTancuri, int ID, string nume, int populatie, int nrOrase, string capitala, Oras* orase) : Tara(ID, nume, capitala, populatie, nrOrase, orase) {
		this->nrAvioane = nrAvioane;
		this->nrSoldati = nrSoldati;
		this->nrTancuri = nrTancuri;
	}
	~PutereGlobala() {

	}
	PutereGlobala(PutereGlobala& pg) : Tara(pg){
		this->nrAvioane = pg.nrAvioane;
		this->nrSoldati = pg.nrSoldati;
		this->nrTancuri = pg.nrTancuri;
	}
	const PutereGlobala operator=(PutereGlobala& pg) {
		this->nrAvioane = pg.nrAvioane;
		this->nrSoldati = pg.nrSoldati;
		this->nrTancuri = pg.nrTancuri;
		(Tara)*this = pg;
		return *this;
	}
	int getNrAvioane() const{
		return this->nrAvioane;
	}
	int getNrTancuri() const{
		return this->nrTancuri;
	}
	int getNrSoldati() const{
		return this->nrSoldati;
	}
	void setNrAvioane(int nrAvioane) {
		this->nrAvioane = nrAvioane;
	}
	void setNrTancuri(int nrTancuri) {
		this->nrTancuri = nrTancuri;
	}
	void setNrSoldati(int nrSoldati) {
		this->nrSoldati = nrSoldati;
	}
	friend istream& operator>>(istream& cit, Tara& t);
	friend istream& operator>>(istream& in, PutereGlobala& pg) {
		cout << "Cate avioane are aceasta putere globala?" << endl;
		in >> pg.nrAvioane;
		cout << "Dar soldati?"<<endl;
		in >> pg.nrSoldati;
		cout << "Dar tancuri?" << endl;
		in >> pg.nrTancuri;
		in >> (Tara&)pg;
		return in;
	}
	friend ostream& operator<<(ostream& afis, const Tara& t);
	friend ostream& operator<<(ostream& out, const PutereGlobala& pg) {
		out << "Tara " << pg.getNume() << " este o putere globala, avand " << pg.getNrSoldati() << " soldati activi, " << pg.getNrTancuri() << " de tancuri si " << pg.getNrAvioane() << " de avioane la dispozitie." << endl;
		out << (Tara&)pg;
		return out;
	}
};

int main() {
	Capitala cap;
	Oras o("Urlati", 10, 5);
	cin >> cap;
	cout << cap;
	Capitala cap1(cap);
	cout << cap;
	Capitala cap2;
	cap2 = cap;
	cout << cap2;
	PutereGlobala pg1;
	cin >> pg1;
	cout << pg1;
	PutereGlobala pg2(pg1);
	cout << pg2;
	PutereGlobala pg3 = pg1;
	cout << pg3;
	ifstream g("planetaCitire.txt", ios::in);
	ofstream f("planeta.txt", ios::out);
	Planeta p1;
	int nrTari = 0;
	cin >> p1;
	f << p1;
	Continent* c1;
	Continent* c2;
	c2 = new Continent[1];
	c2->setNume(p1.getContinent()[0].getNume());
	c2->setPopulatie(p1.getContinent()[0].getPopulatie());
	c2->setNrTari(p1.getContinent()[0].getNrTari());
	c2->setTari(p1.getContinent()[0].getNrTari(), p1.getContinent()[0].getTari());
	cout << c2[0];
	c1 = new Continent[p1.getNrContinente()];
	for (int i = 0; i < p1.getNrContinente(); i++) {
		c1[i] = p1.getContinent()[i];
	}
	for (int i = 0; i < p1.getNrContinente(); i++)
		cout << endl << c1[i];
	Tara* t1;
	for (int i = 0; i < p1.getNrContinente(); i++) {
		nrTari += p1.getContinent()[i].getNrTari();
	}
	t1 = new Tara[nrTari];
	nrTari = 0;
	for (int i = 0; i < p1.getNrContinente(); i++) {
		for (int j = 0; j < p1.getContinent()[i].getNrTari(); j++) {
			t1[nrTari] = p1.getContinent()[i].getTari()[j];
			nrTari++;
		}
	}
	for (int i = 0; i < nrTari; i++)
		cout << endl << t1[i];
	Oras* o1;
	int nrOrase = 0;
	for (int i = 0; i < nrTari; i++)
		nrOrase += t1[i].getNrOrase();
	o1 = new Oras[nrOrase];
	for (int i = 0; i < nrTari; i++)
		for (int j = 0; j < t1[i].getNrOrase(); j++)
			o1[i] = t1[i].getOrase()[j];
	cout << "Orasele: ";
	for (int i = 0; i < t1[i].getNrOrase(); i++)
		cout << o1[i] << endl;
	//De implementat seterii
		/*
	char raspuns;
	cout << "Doriti sa introduceti o matrice de orase? 1-Da 0-Nu"<<endl;
	cin >> raspuns;
	while (raspuns != 1 && raspuns != 0) {
		cout << "Va rugam sa reintroduceti raspunsul dumneavoastra utilizand valorile mentionate." << endl;
		cin >> raspuns;
	}
	if (raspuns == 1) {
		Oras** o2;
		int nrLin, nrCol;
		cout << endl << "Cate linii doriti sa aiba matricea dumneavoastra?";
		cin >> nrLin;
		cout << endl << "Cate coloane doriti sa aiba matricea dumneavoastra?";
		cin >> nrCol;
		o2 = new Oras * [nrLin];
		for (int i = 0; i < nrLin; i++)
			o2[i] = new Oras[nrCol];
		for (int i = 0; i < nrLin; i++)
			for (int j = 0; j < nrCol; j++)
				cin >> o2[i][j];
	}
	*/
	Oras test;
	o1[0].scrieInFisBinar("test.dat");
	test.citesteDinFisBinar("test.dat");
	cout << endl << "Acest oras a fost citit din fisierul binar" << endl;
	cout << test << endl << o1[0];
	t1[0].scriereInFisBinar("test1.dat");
	Tara t0;
	t0.citesteDinFisBinar("test1.dat");
	cout << t0;
	f.close();
	g.close();
	
}
