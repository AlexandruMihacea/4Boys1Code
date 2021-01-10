#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;

class null_exception : public exception
{
public:
	null_exception()
	{

	}
	null_exception(const char* message) : exception(message)
	{

	}
};

class Citeste
{
	virtual void citeste() = 0;
};
class Afiseaza
{
public:
	virtual void afiseaza() = 0;
};

class coloana_int : public Afiseaza, public Citeste
{
private:
	int v[100];
	int dimensiune_x;
	int* x;
	string nume_coloana;
public:
	void setX(int nr, int i)
	{
		x[i] = nr;
	}
	coloana_int(int dimensiune_x, int* x, string nume_coloana)
	{
		this->dimensiune_x = dimensiune_x;
		this->nume_coloana = nume_coloana;
		this->x = new int[dimensiune_x];
		for (int i = 0; i < dimensiune_x; i++)
		{
			this->x[i] = x[i];
		}
	}
	int getX( int index)
	{
		if (index >= 0 && index < dimensiune_x && x != nullptr)
		{
			return x[index];
		}
	}
	int* getX()
	{
		if (x != nullptr)
		{
			for (int i = 0; i < dimensiune_x; i++)
				cout << x[i] << endl;
		}
	}
	coloana_int(const coloana_int& s)
	{

		nume_coloana = s.nume_coloana;
		if (s.dimensiune_x > 0)
		{
			dimensiune_x = s.dimensiune_x;
			x = new int[s.dimensiune_x];
			for (int i = 0; i < s.dimensiune_x; i++)
			{
				x[i] = s.x[i];
			}
		}
	}

	coloana_int& operator=(const coloana_int& s)
	{
		if (x != nullptr)
		{
			delete[] x;
		}
		this->nume_coloana = s.nume_coloana;
		if (s.dimensiune_x > 0)
		{
			this->dimensiune_x = s.dimensiune_x;
			this->x = new int[s.dimensiune_x];
			for (int i = 0; i < s.dimensiune_x; i++)
			{
				this->x[i] = s.x[i];
			}
		}
		return*this;

	}

	int& operator[](int index)
	{
		if (index >= 0 && index < dimensiune_x)
		{
			return x[index];
		}
		//aruncare exceptie
		throw exception("index invalid");
	}

	void setNumeColoana(string nume_coloana)
	{
		if (nume_coloana != "")
		{
			this->nume_coloana = nume_coloana;
		}
	}

	string getNumeColoanaInt()
	{
		return nume_coloana;
	}


	~coloana_int()
	{
		delete[] x;
	}

	void afiseaza() override
	{
		cout << "nume coloana: " << nume_coloana << endl;
		if (x != nullptr)
			for (int i = 0; i < dimensiune_x; i++)
			{
				cout << "Linia " << i << ": " << x[i] << endl;
			}

	}

	void citeste() override
	{
		cout << "nume coloana: ";
		cin >> nume_coloana;
		while (nume_coloana == "") {
			cout << "nume coloana: ";
			cin >> nume_coloana;
		}

		for (int i = 0; i < dimensiune_x; i++)
		{
			cout << "Linia " << i << ": ";
			cin >> x[i];
			while (x[i] >= 0)
			{
				cout << "Linia " << i << ": ";
				cin >> x[i];
			}
		}

	}
	void setDimensiuneX(int dimensiune)
	{
		dimensiune_x = dimensiune;
	}
	int getDimensiune()
	{
		return dimensiune_x;
	}

	friend ostream& operator<<(ostream&, coloana_int);
	friend istream& operator>>(istream&, coloana_int&);
};

ostream& operator<<(ostream& out, coloana_int s)
{
	out << "Nume coloana: " << s.nume_coloana << endl;
	for (int i = 0; i < s.dimensiune_x; i++)
	{
		out << "Valoare : " << s.x[i] << endl;
	}
	return out;
}

istream& operator>>(istream& in, coloana_int& s)
{
	cout << "Nume coloana: ";
	in >> s.nume_coloana;
	for (int i = 0; i < s.dimensiune_x; i++)
	{
		cout << "Valoare: ";
		in >> s.x[i];
	}
	return in;
}

class coloana_string : public Afiseaza, public Citeste
{
private:
	int v[100];
	int dimensiune_y;
	string* y;
	string nume_coloana;
public:
	coloana_string(int dimensiune_y, string* y, string nume_coloana)
	{
		this->dimensiune_y = dimensiune_y;
		this->nume_coloana = nume_coloana;
		this->y = new string[dimensiune_y];
		for (int i = 0; i < dimensiune_y; i++)
		{
			this->y[i] = y[i];
		}
	}
	void setY(string nume_coloana, int i)
	{
		y[i] = nume_coloana;
	}
	coloana_string(const coloana_string& s)
	{

		nume_coloana = s.nume_coloana;
		if (s.dimensiune_y > 0)
		{
			dimensiune_y = s.dimensiune_y;
			y = new string[s.dimensiune_y];
			for (int i = 0; i < s.dimensiune_y; i++)
			{
				y[i] = s.y[i];
			}
		}
	}

	coloana_string& operator=(const coloana_string& s)
	{
		if (y != nullptr)
		{
			delete[] y;
		}
		this->nume_coloana = s.nume_coloana;
		if (s.dimensiune_y > 0)
		{
			this->dimensiune_y = s.dimensiune_y;
			this->y = new string[s.dimensiune_y];
			for (int i = 0; i < s.dimensiune_y; i++)
			{
				this->y[i] = s.y[i];
			}
		}
		return*this;

	}

	string& operator[](int index)
	{
		if (index >= 0 && index < dimensiune_y)
		{
			return y[index];
		}
		//aruncare exceptie
		throw exception("index invalid");
	}

	void setNumeColoana(string nume_coloana)
	{
		//if (nume_coloana != "")
		{
			this->nume_coloana = nume_coloana;
		}
	}

	string getColoane()
	{
		if (dimensiune_y > 0)
		{
			for (int i = 0; i < dimensiune_y; i++)
			{
				return y[i];
			}
		}
	}

	void setDimensiuneY(int dimensiune)
	{
		dimensiune_y = dimensiune;
	}

	~coloana_string()
	{
		delete[] y;
	}

	void afiseaza() override
	{
		cout << "nume coloana: " << nume_coloana << endl;

		for (int i = 0; i < dimensiune_y; i++)
		{
			cout << "Linia " << i << ": " << y[i] << endl;

		}

	}

	void citeste() override
	{
		cout << "nume coloana: ";
		cin >> nume_coloana;
		while (nume_coloana == "") {
			cout << "nume coloana: ";
			cin >> nume_coloana;
		}

		for (int i = 0; i < dimensiune_y; i++)
		{
			cout << "Linia " << i << ": ";
			cin >> y[i];
			while (y[i] != "")
			{
				cout << "Linia " << i << ": ";
				cin >> y[i];
			}

		}

	}

	friend ostream& operator<<(ostream&, coloana_string);
	friend istream& operator>>(istream&, coloana_string&);
};

ostream& operator<<(ostream& out, coloana_string s)
{
	out << "Nume coloana: " << s.nume_coloana << endl;
	for (int i = 0; i < s.dimensiune_y; i++)
	{
		out << "Valoare : " << s.y[i] << endl;
	}
	return out;
}

istream& operator>>(istream& in, coloana_string& s)
{
	cout << "Nume coloana: ";
	in >> s.nume_coloana;
	for (int i = 0; i < s.dimensiune_y; i++)
	{
		cout << "Valoare: ";
		in >> s.y[i];
	}
	return in;
}


class coloana_date : public Afiseaza, public Citeste
{
private:
	int v[100];
	int dimensiune_data;
	time_t* data;
	string nume_coloana;
public:
	coloana_date(int dimensiune_data, time_t* data, string nume_coloana)
	{
		this->dimensiune_data = dimensiune_data;
		this->nume_coloana = nume_coloana;
		this->data = new time_t[dimensiune_data];
		for (int i = 0; i < dimensiune_data; i++)
		{
			this->data[i] = data[i];
		}
	}

	coloana_date(const coloana_date& s)
	{

		nume_coloana = s.nume_coloana;
		if (s.dimensiune_data > 0)
		{
			dimensiune_data = s.dimensiune_data;
			data = new time_t[s.dimensiune_data];
			for (int i = 0; i < s.dimensiune_data; i++)
			{
				data[i] = s.data[i];
			}
		}
	}

	coloana_date& operator=(const coloana_date& s)
	{
		if (data != nullptr)
		{
			delete[] data;
		}
		this->nume_coloana = s.nume_coloana;
		if (s.dimensiune_data > 0)
		{
			this->dimensiune_data = s.dimensiune_data;
			this->data = new time_t[s.dimensiune_data];
			for (int i = 0; i < s.dimensiune_data; i++)
			{
				this->data[i] = s.data[i];
			}
		}
		return*this;

	}

	time_t& operator[](int index)
	{
		if (index >= 0 && index < dimensiune_data)
		{
			return data[index];
		}
		throw exception("index invalid");
	}

	void setNumeColoana(string nume_coloana)
	{
		if (nume_coloana != "")
		{
			this->nume_coloana = nume_coloana;
		}
	}

	time_t getColoane()
	{
		if (dimensiune_data > 0)
		{
			for (int i = 0; i < dimensiune_data; i++)
			{
				return data[i];
			}
		}
	}

	~coloana_date()
	{
		delete[] data;
	}

	void afiseaza() override
	{
		cout << "nume coloana: " << nume_coloana << endl;

		for (int i = 0; i < dimensiune_data; i++)
		{
			cout << "Linia " << i << ": " << data[i] << endl;

		}

	}
	void citeste() override
	{
		cout << "nume coloana: ";
		cin >> nume_coloana;
		while (nume_coloana == "") {
			cout << "nume coloana: ";
			cin >> nume_coloana;
		}

		for (int i = 0; i < dimensiune_data; i++)
		{
			cout << "Linia " << i << ": ";
			cin >> data[i];
		}

	}

	friend ostream& operator<<(ostream&, coloana_date);
	friend istream& operator>>(istream&, coloana_date&);
};

ostream& operator<<(ostream& out, coloana_date s)
{
	out << "Nume coloana: " << s.nume_coloana << endl;
	for (int i = 0; i < s.dimensiune_data; i++)
	{
		out << "Data : " << s.data[i] << endl;
	}
	return out;
}

istream& operator>>(istream& in, coloana_date& s)
{
	cout << "Nume coloana: ";
	in >> s.nume_coloana;
	for (int i = 0; i < s.dimensiune_data; i++)
	{
		cout << "Valoare: ";
		in >> s.data[i];
	}
	return in;

}

class coloana_char : public Afiseaza, public Citeste
{
private:
	int v[100];
	int dimensiune_c;
	char* c;
	string nume_coloana;

public:
	coloana_char(int dimensiune_c, char* c, string nume_coloana)
	{
		this->dimensiune_c = dimensiune_c;
		this->nume_coloana = nume_coloana;
		this->c = new char[dimensiune_c + 1];
		strcpy_s(this->c, dimensiune_c + 1, c);

	}

	coloana_char(const coloana_char& s)
	{

		nume_coloana = s.nume_coloana;
		if (s.dimensiune_c > 0)
		{
			dimensiune_c = s.dimensiune_c;
			this->c = new char[dimensiune_c + 1];
			strcpy_s(this->c, dimensiune_c + 1, s.c);

		}
	}
	string getNumeColoana()
	{
		return nume_coloana;
	}
	coloana_char& operator=(const coloana_char& s)
	{
		if (c != nullptr)
		{
			delete[] c;
		}
		this->nume_coloana = s.nume_coloana;
		if (s.dimensiune_c > 0)
		{
			this->dimensiune_c = s.dimensiune_c;
			this->c = new char[dimensiune_c + 1];
			strcpy_s(this->c, dimensiune_c + 1, s.c);

		}
		return*this;

	}

	char& operator[](int index)
	{
		if (index >= 0 && index < dimensiune_c)
		{
			return c[index];
		}
		throw exception("index invalid");
	}

	~coloana_char()
	{
		delete[] c;
	}

	void afiseaza() override
	{
		cout << "nume coloana: " << nume_coloana << endl;

		for (int i = 0; i < dimensiune_c; i++)
		{
			cout << "Linia " << i << ": " << c[i] << endl;

		}

	}

	void citeste() override
	{
		cout << "nume coloana: ";
		cin >> nume_coloana;
		while (nume_coloana == "") {
			cout << "nume coloana: ";
			cin >> nume_coloana;
		}

		for (int i = 0; i < dimensiune_c; i++)
		{
			cout << "Linia " << i << ": ";
			cin >> c[i];
			while (c[i] != ' ')
			{
				cout << "Linia " << i << ": ";
				cin >> c[i];
			}

		}

	}

	friend ostream& operator<<(ostream&, coloana_char);
	friend istream& operator>>(istream&, coloana_char&);
};

ostream& operator<<(ostream& out, coloana_char s)
{
	out << "Nume coloana: " << s.nume_coloana << endl;
	for (int i = 0; i < s.dimensiune_c; i++)
	{
		out << "Data : " << s.c[i] << endl;
	}
	return out;
}

istream& operator>>(istream& in, coloana_char& s)
{
	cout << "Nume coloana: ";
	in >> s.nume_coloana;
	for (int i = 0; i < s.dimensiune_c; i++)
	{
		cout << "Valoare: ";
		in >> s.c[i];
	}
	return in;

}

// Pentru fiecare atribut se defineste o interfata publica(functii accesor) ce permite citirea si scrierea valorii; functiile 
// de modificare trebuie sa contina minim o regula de validare a valorii
class tabela 
{
private:
	const string nume_bd = "ProiectPoo";
	int v[100];
	coloana_int** intregi;                // intregi[0].nume = "VARSTA";
	int nr_atribute_intregi=0;              // intregi[0].x[0] = 18; - prima varsta din coloana VARSTE
	coloana_string** stringuri;           // intregi[0].x[1] = 19;
	int nr_atribute_string=0;               // intregi[1].nume =  "NOTE";
	//coloana_date** date;              // intregi[1].x[0] = 10; - prima nota din coloana NOTE
	//int nr_atribute_date=0;
	int nr_inregistrari=0;
	coloana_char** charuri;
	int nr_atribute_char=0;
	static string admin;

public:
	friend class coloana_int;
	friend class coloana_string;
	friend class coloana_date;
	friend class cloana_char;
	string* valoare_implicita;
	tabela Create_Table(string* cuvinte, string x)
	{
		string nume_tabela = cuvinte[2];
		int i = 0;
		for(i =3; i<cuvinte->length();i+=4)
		{
			if (cuvinte[i + 1] == "int")
			{
				intregi[nr_atribute_intregi]->setNumeColoana(cuvinte[i]);
				intregi[nr_atribute_intregi]->setDimensiuneX(stoi(cuvinte[i + 2]));
				nr_atribute_intregi++;
			}
			if (cuvinte[i + 1] == "string")
			{
				stringuri[nr_atribute_string]->coloana_string::setNumeColoana(cuvinte[i]);
				stringuri[nr_atribute_string]->coloana_string::setDimensiuneY(stoi(cuvinte[i + 2]));
				nr_atribute_string++;
			}
			/*if (cuvinte[i + 1] == "float")
			{
				float[nr_atribute_float]->setNumeColoana(cuvinte[i]);
				float[nr_atribute_float]->setDimensiuneZ(stoi(cuvinte[i + 1]));
				nr_atribute_float++;
			}*/
		}
		return *this;
	}
	void Drop_Table()
	{
		if (nr_atribute_intregi > 0)
		{
			for (int i = 0; i < nr_atribute_intregi; i++)
			{
				delete[] intregi[i];
			}
			delete[] intregi;
			intregi = nullptr;
			nr_atribute_intregi = 0;
		}
		if (nr_atribute_string > 0)
		{
			for (int i = 0; i < nr_atribute_string; i++)
			{
				delete[] stringuri[i];
			}
			delete[] stringuri;
			stringuri = nullptr;
			nr_atribute_string = 0;
		}
		if (nr_atribute_char > 0)
		{
			for (int i = 0; i < nr_atribute_char; i++)
			{
				delete[] charuri[i];
			}
			delete[] charuri;
			charuri = nullptr;
			nr_atribute_string = 0;
		}
		/*if (nr_atribute_float > 0)
		{
			for (int i = 0; i < nr_atribute_float; i++)
			{
				delete[] floaturi[i];
			}
			delete[] floaturi;
			floaturi = nullptr;
			nr_atribute_string = 0;
		}*/
		cout << "Tabela a fost stearsa";

	}
	void Display_Table(string* cuvinte)
	{
		for (int i = 0; i < nr_atribute_char;i++) //+nr_atribute_float
		{
			//cout << charuri[i].getNumeColoana();
		}
		for (int i = 0; i < nr_atribute_intregi; i++)
		{
			cout << "Nume coloana: " << intregi[i]->getNumeColoanaInt();
			for (int j = 0; j<intregi[i]->getDimensiune(); j++)
			{
				cout << j << " " << intregi[i]->getX();
			}
		}
		//la fel si pt float, string etc
	}
	//create table student (  (nume, string,  3, ""), (varsta, int, 3, 1)   )
	string* tipuriData(string* cuvinte)
	{
		string copie[20]; int k = -1;
		for (int i = 4; i < cuvinte->length(); i += 4)
		{
			copie[++k] = cuvinte[i];
		}
		string* tipData = new string[k];
		for (int i = 0; i < k; i++)
		{
			tipData[i] = copie[i];
		}
		return tipData;
	}
	//INSERT INTO nume_tabela VALUES((nume, prenume, varsta);
	void Insert(string* cuvinte,string* tipData)
	{
		int contor_int = -1, contor_string = -1, contor_char = -1, contor_float = -1, values=4;
		for (int i = 0; i < tipData->length(); i++)
		{
			if (tipData[i] == "int")
			{
				intregi[++contor_int]->setX(stoi(cuvinte[values]), contor_int);
				values++;
			}
			if (tipData[i] == "string")
			{
				stringuri[++contor_string]->setY(cuvinte[values], contor_string);
				values++;
			}
			// mai terbuie pentru float, char
		}

	}
	//DELETE FROM nume_tabela WHERE nume_coloană = valoare
	void Delete_From_Where(string* cuvinte)
	{
		string nume_coloana = cuvinte[4];
		int valoare_int = stoi(cuvinte[5]);
		string valoare = cuvinte[5];
		for (int i = 0; i < nr_atribute_intregi; i++)
		{
			if (intregi[i]->getNumeColoanaInt() == nume_coloana)
			{
				for (int j = 0; j < intregi[i]->getDimensiune(); j++)
				{
					if (intregi[i]->getX(j) == valoare_int)
					{
						delete[] intregi[i];
						delete[] stringuri[i];
						delete[] charuri[i];
						//delete[] floaturi[i]; - inca nu este creata clasa
					}
				}
			}
		}

	}

};
string tabela::admin = "localhost";
class CREATE_TABLE
{
public:
	
	//string nume_tabela = cuvinte[2];
	
};

string* removeDupWord(string str, string* cuvinte, int& marime)
{
	string word = "";
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] == ' ' || str[i] == '(' || str[i] == ')' || str[i] == ',') && (str[i + 1] == ' ' || str[i + 1] == '(' || str[i + 1] == ')' || str[i + 1] == ','))
		{
			continue;
		}
		if ((str[i] == ' ' || str[i] == '(' || str[i] == ')' || str[i] == ',') && (str[i + 1] != ' ' || str[i + 1] != '(' || str[i + 1] != ')' || str[i + 1] != ','))
		{
			marime += 1;
			word = "";
		}
		else
		{
			word = word + str[i];
			cuvinte[marime] = word;
		}

	}

	return cuvinte;

}

//create table student (  (nume, string,  3, ""), (varsta, int, 3, 1)   )
//string tipComanda = cuvinte[0];

int main()
{
	string x;
	getline(cin, x);

	int i = 0;
	string* cuvinte = nullptr;
	cuvinte = new string[100];
	removeDupWord(x, cuvinte, i);
	//cuvinte = new string[i];
	int nr_cuvinte= cuvinte->length();
	cout << "numar cuvinte: " << nr_cuvinte << endl;
	for (int k = 0; k < i; k++)
	{
		cout << cuvinte[k] << endl;
	}
	// Identificarea tipului comenzii:
	string tipComanda = cuvinte[0];
	tabela baza_de_date;
	baza_de_date.Create_Table(cuvinte, x);
	baza_de_date.Display_Table(cuvinte);

	//cout << "tipul comenzii: " << tipComanda;

	//switch (tipComanda) {
	//case "Create":
	//	// code block
	//	break;
	//case y:
	//	// code block
	//	break;
	//default:
	//	// code block
	//}

	delete[] cuvinte;
}


