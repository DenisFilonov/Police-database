#include"Date.h"
#include"MyString.h"

struct Crime
{
	Date date_of_crime;		//Дата нарушения
	MyString description;	//Описание нарушения
	float fine = 0;			//сумма штрафа

	void fillCrime();

	void printCrime();
};
