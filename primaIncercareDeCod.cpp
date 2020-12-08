#include <iostream>
#include <string>
using namespace std;
class coloana_int
{
	int* x;
	string nume_coloana;
	
	~coloana_int()
	{
		delete[] x;
	}
};
class coloana_string
{
	string* y;
	string nume_coloana;
	
	~coloana_string()
	{
		delete[] y;
	}
};
class coloana_date
{
	time_t* data;
	string nume_coloana;
	
	~coloana_date()
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
	/*coloana_date** date; */                 // intregi[1].x[0] = 10; - prima nota din coloana NOTE
	int nr_atribute_date;
	int nr_inregistrari;
	

};
string* removeDupWord(string str, string* cuvinte, int& marime)
{
	string word = "";
	for (int i=0;i<str.length(); i++)
	{
		if ((str[i] == ' ' || str[i] == '(' || str[i] == ')' || str[i] == ',') &&(str[i+1]  == ' ' || str[i+1] == '(' || str[i+1]  == ')' || str[i+1]  == ','))
		{
			continue;
		}
		if ((str[i] == ' ' || str[i] == '(' || str[i] == ')' || str[i] == ',') && (str[i + 1]  != ' ' || str[i+1] != '(' || str[i+1] != ')' || str[i+1]  != ','))
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
	string* cuvinte=nullptr; 
	cuvinte = new string[100];
	removeDupWord(x, cuvinte,i);
	//cuvinte = new string[i];
	cout << cuvinte->length();
	for(int k=0;k<i;k++)
	{
		cout << cuvinte[k]<<endl;
	}
	
	delete[] cuvinte;


}