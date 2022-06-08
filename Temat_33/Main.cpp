#include"Driver.h"
#include<Windows.h>


int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Тест нарушения
	/*Crime one;
	one.fillCrime();
	cout << endl << endl;
	one.printCrime();*/

	//Тест водителя
	/*Driver man;
	man.fillDriver();
	cout << endl << endl;
	man.printInfo();
	cout << endl << endl;
	man.addCrime();
	cout << endl << endl;
	cout << "Общий штраф: " << man.calcTotalFine() << " грн.\n\n";*/

	int N = 0;					//Кол-во водителей
	Driver* drivers = NULL;		//Массив водителей
	int menu = 0;
	float crimePaying = 0;

	do
	{
		cout << "1. Внести водителя в базу данных.\n"; //+
		cout << "2. Показать список нарушетелей.\n"; // фио, номер авто и кол-во нарушений
		cout << "3. Показать полный список базы данных.\n"; //+
		cout << "4. Показать список всех нарушений у всех водителей.\n";//+
		cout << "5. Добавить нарушение по номеру авто.\n"; //+
		cout << "6. Показать информацию по номеру авто.\n"; //+
		cout << "7. Оплатить штраф по номеру авто.\n";	//+
		cout << "0. Закончить работу с КПК Полиции.\nВыбор: ";
		cin >> menu;

		switch (menu)
		{
		case 1: 
			cin.ignore();
			addItem(drivers, N);
			break;

		case 2: 
			listOfViolators(drivers,N);
			break;

		case 3: 
			showDataBase(drivers, N);
			break;

		case 4: 
			showAllCrimesOfAllDrivers(drivers, N);			
			break;

		case 5:
		{
			char d[100] = "";
			cout << "\nНомер авто: ";
			cin.ignore();
			cin.getline(d, 100);
			addCarNumber(drivers, N, d);
			break;
		}
		case 6: 
		{
			char s[100] = "";
			cout << "\nНомер авто: ";
			cin.ignore();
			cin.getline(s, 100);
			showInfoByCarNumber(drivers, N, s);
			break;
		}

		case 7:
		{
			char car[100];
			cout << "\nНомер авто: ";
			cin.ignore();
			cin.getline(car, 100);
			cout << "Внести оплату: ";
			cin >> crimePaying;
			payCrimeBycarNumber(drivers, N, car, crimePaying);
			break;
		}

		default: if (menu > 7 && menu != 0) cout << "Неверно выбран пункт меню.\n\n";	break;
		}


	} while (menu != 0);







	system("pause");
	return 0;
}