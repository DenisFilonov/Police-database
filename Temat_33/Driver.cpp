#include "Driver.h"

void Driver::fillDriver()
{
	char tmp[100] = "";
	cout << "ФИО водителя: ";
	cin.getline(tmp, 100);
	name.setMyString(tmp);

	cout << "Номер авто: ";
	cin >> tmp;
	carNumber.setMyString(tmp);

	cout << "Сколько нарушений: ";
	cin >> sizeCrime;

	if (sizeCrime > 0)
	{
		cout << endl;
		arr = new Crime[sizeCrime];
		for (int i = 0; i < sizeCrime; i++)
		{
			cout << "Нарушение # " << i + 1 << endl;
			arr[i].fillCrime();
		}
		cout << "\t================================\n";
		cout << "\tНарушения внесены в базу данных.\n\n";
	}
}

void Driver::printInfo()
{
	cout << "Водитель: " << name.str << endl;
	cout << "Номер авто: " << carNumber.str << endl;
	cout << "Кол-во нарушений: " << sizeCrime << endl;
	for (int i = 0; i < sizeCrime; i++)
	{
		cout << "Нарушение #" << i + 1 << endl;
		arr[i].printCrime();
	}
}

void Driver::addCrime()
{
	Crime* tmp = new Crime[++sizeCrime];
	for (int i = 0; i < sizeCrime - 1; i++)
	{
		tmp[i] = arr[i];
	}
	if (arr != NULL) delete[] arr;
	cout << "Информация о новом нарушении:\n";
	tmp[sizeCrime - 1].fillCrime();
	arr = tmp;
}

float Driver::calcTotalFine()
{
	float sum = 0;
	for (int i = 0; i < sizeCrime; i++)
	{
		sum += arr[i].fine;
	}
	return sum;
}

void addItem(Driver*& arr, int& size)
{
	cout << endl;
	Driver* tmp = new Driver[++size];
	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	}
	if (arr != NULL) delete[] arr;
	cout << "Введите данные о новом водителе: \n";
	tmp[size - 1].fillDriver();
	arr = tmp;
}

void showAllCrimesOfAllDrivers(Driver* arr, int size)
{
	int k = 0;
	for (int i = 0; i < size; i++) // перебираем водителей
	{// у каждого водителя просматриваем список нарушений
		for (int j = 0; j < arr[i].sizeCrime; j++) //вывести инфу
		{
			cout << "\nНарушение #" << ++k << endl;
			arr[i].arr[j].printCrime();
		}
	}
}

void payCrimeBycarNumber(Driver* arr, int size, const char* number, float payment)
{
	int id = -1;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].carNumber.str, number) == 0)
		{
			id = i;
		}
	}
	
	if (id == -1) cout << "Автомобиль с номером \"" << number << "\" не найден.\n\n";
	else
	{
		for (int j = 0; j < arr[id].sizeCrime; j++)
		{
			if (payment >= arr[id].arr[j].fine)
			{
				payment -= arr[id].arr[j].fine;
				arr[id].arr[j].fine = 0; // оплачиваем штраф
				cout << "Штраф \"" << arr[id].arr[j].description.str << "\" за число [" << arr[id].arr[j].date_of_crime.toString() << "] полностью оплачен.\n\n";
			}
			else
			{
				arr[id].arr[j].fine -= payment;
				payment = 0;
				cout << "Штраф: " << arr[id].arr[j].description.str << " за число [" << arr[id].arr[j].date_of_crime.toString() << "] частично оплачен.\n\n";
				cout << "Остаток к доплате: " << arr[id].arr[j].fine << " гривен.\n\n";
			}
		}
	}
	if (payment > 0) cout << "У Вас осталась сдача. Можете получить её в Нац.Банке.\n\n";
}

void listOfViolators(Driver* arr, int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
			cout << "Нарушитель # " << i + 1 << ":\n";
			cout << "Водитель: " << arr[i].name.str << endl;
			cout << "Номер авто: " << arr[i].carNumber.str << endl;
			cout << "Кол-во нарушений: " << arr[i].sizeCrime;
			cout << "\n====================================================\n\n";		
	}
}

void showDataBase(Driver* arr, int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i].printInfo();
		cout << "\n====================================================\n\n";
	}
}

void showInfoByCarNumber(Driver* arr, int size, const char* number)
{
	int id = -1;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].carNumber.str, number) == 0)
		{
			id = i;
		}
	}
	if (id == -1) cout << "Автомобиль с номером \"" << number << "\" не найден.\n\n";	
	else arr[id].printInfo();
}

void addCarNumber(Driver*& arr, int& size, const char* number)
{
	int id = -1;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].carNumber.str, number) == 0)
		{
			id = i;
		}
	}
	if (id == -1) cout << "Автомобиль с номером \"" << number << "\" не найден.\n\n";
	else arr[id].addCrime();
}

