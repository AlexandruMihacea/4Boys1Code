#include <iostream>
using namespace std;
class coloana_int
{
	int* x;
	string nume_coloana;
	int nr_inregistrari;
	~coloana_int()
	{
		delete[] x;
	}
};
class coloana_string
{
	string* y;
	string nume_coloana;
	int nr_inregistrari;
	~coloana_string()
	{
		delete[] y;
	}
};
class coloana_date
{
	time_t* data;
	string nume_coloana;
	int nr_inregistrari;
	coloana_date()
	{
		delete[] data;
	}
};
class coloana_char
{

};
class tabela
{
	friend class coloana_int;
	friend class coloana_string;
	friend class coloana_date;
	coloana_int** intregi;                // intregi[0].nume = "VARSTA";
	int nr_atribute_intregi;              // intregi[0].x[0] = 18; - prima varsta din coloana VARSTE
	coloana_string** stringuri;           // intregi[0].x[1] = 19;
	int nr_atribute_string;               // intregi[1].nume =  "NOTE";
	coloana_date** date;                  // intregi[1].x[0] = 10; - prima nota din coloana NOTE
	int nr_atribute_date;
	

};


//create table student (  (nume, string,  3, ""), (varsta, int, 3, 1)   )

int main()
{
	// create table abecedar
	// select * from abecedar
	// tabela abecedar; 
	/*f >> string; 
	if (string == "select * from abecedar")
	{
		asdjasdjas
	}*/
//	string s;
//	if (firstword == "create")
//	{
//		tabela farmacie;
//	}
}