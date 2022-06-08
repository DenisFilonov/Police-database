#include "Crime.h"

void Crime::fillCrime()
{
	char tmp[200] = "";
	cout << "Дата нарушения: ";
	date_of_crime.fillDate(); 
	// заменяет строчку - Введите год: cin>>date_of_crime.year 
	// заменяет строчку - Введите месяц: cin>>date_of_crime.month 
	// заменяет строчку - Введите день: cin>>date_of_crime.day 

	cout << "Описание нарушения: ";
	cin.ignore();
	cin.getline(tmp, 200);
	description.setMyString(tmp);

	cout << "Сумма штрафа: ";
	cin >> fine;
}

void Crime::printCrime()
{
	cout << "\tДата нарушения: " << date_of_crime.toString() << endl;
	cout << "\tОписание нарушения: " << description.str << endl;
	cout << "\tШтрафа: " << fine << " грн.\n";
	cout << "\t============================================\n\n";
}
