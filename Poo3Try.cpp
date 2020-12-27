#include <iostream>
#include <string>
using namespace std;
class Citeste
{
	virtual void citeste() = 0;
};
class Afiseaza
{
public:
	virtual void afiseaza() = 0;
};

class coloana_int : public Afiseaza , public Citeste
{
private:
	int v[100];
	int dimensiune_x;
	int* x;
	string nume_coloana;
public:
	coloana_int(int dimensiune_x ,int* x,string nume_coloana)
	{
		this->dimensiune_x = dimensiune_x;
		this->nume_coloana = nume_coloana;
		this->x = new int[dimensiune_x];
			for (int i = 0; i < dimensiune_x; i++)
			{
				this->x[i] = x[i];
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
	void setNumeColoana(string nume_coloana)
	{
		if (nume_coloana != "")
		{
			this->nume_coloana = nume_coloana;
		}
	}

	int getColoane()
	{
		if (dimensiune_x > 0)
		{
			for (int i = 0; i < dimensiune_x; i++)
			{
				return x[i];
			}
		}
	}


	~coloana_int()
	{
		delete[] x;
	}

	void afiseaza() override
	{
		cout << "nume coloana: " << nume_coloana << endl;

		for (int i = 0; i < dimensiune_x; i++)
		{
			cout << "Linia " << i << ": "<< x[i]<< endl;

		}

	}

	void citeste() override
	{
		cout << "nume coloana: ";
		cin >> nume_coloana;
		for (int i = 0; i < dimensiune_x; i++)
		{
			cout << "Linia " << i << ": ";
			cin >> x[i];

		}

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
	for (int i = 0 ; i < s.dimensiune_x; i++)
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

class coloana_string : public Afiseaza , public Citeste
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

	void setNumeColoana(string nume_coloana)
	{
		if (nume_coloana != "")
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
		for (int i = 0; i < dimensiune_y; i++)
		{
			cout << "Linia " << i << ": ";
			cin >> y[i];

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


class coloana_date: public Afiseaza , public Citeste
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

	void setNumeColoana(string nume_coloana)
	{
		if (nume_coloana != "")
		{
			this->nume_coloana = nume_coloana;
		}
	}

	char getColoane()
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

class coloana_char : public Afiseaza , public Citeste
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
			strcpy_s(this->c, dimensiune_c + 1, c);

		}
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
			strcpy_s(this->c, dimensiune_c + 1, c);

		}
		return*this;

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
		for (int i = 0; i < dimensiune_c; i++)
		{
			cout << "Linia " << i << ": ";
			cin >> c[i];

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

class tabela
{
private:
	int v[100];
	coloana_int** intregi;                // intregi[0].nume = "VARSTA";
	int nr_atribute_intregi;              // intregi[0].x[0] = 18; - prima varsta din coloana VARSTE
	coloana_string** stringuri;           // intregi[0].x[1] = 19;
	int nr_atribute_string;               // intregi[1].nume =  "NOTE";
	coloana_date** date;              // intregi[1].x[0] = 10; - prima nota din coloana NOTE
	int nr_atribute_date;
	int nr_inregistrari;
	coloana_char** charuri;
	int nr_atribute;
public:
	friend class coloana_int;
	friend class coloana_string;
	friend class coloana_date;
	friend class cloana_char;
	


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
int main()
{
	string x;
	getline(cin, x);

	int i = 0;
	string* cuvinte = nullptr;
	cuvinte = new string[100];
	removeDupWord(x, cuvinte, i);
	//cuvinte = new string[i];
	cout << cuvinte->length();
	for (int k = 0; k < i; k++)
	{
		cout << cuvinte[k] << endl;
	}

	delete[] cuvinte;


}

//





