#include "Driver.h"

void Driver::fillDriver()
{
	char tmp[100] = "";
	cout << "��� ��������: ";
	cin.getline(tmp, 100);
	name.setMyString(tmp);

	cout << "����� ����: ";
	cin >> tmp;
	carNumber.setMyString(tmp);

	cout << "������� ���������: ";
	cin >> sizeCrime;

	if (sizeCrime > 0)
	{
		cout << endl;
		arr = new Crime[sizeCrime];
		for (int i = 0; i < sizeCrime; i++)
		{
			cout << "��������� # " << i + 1 << endl;
			arr[i].fillCrime();
		}
		cout << "\t================================\n";
		cout << "\t��������� ������� � ���� ������.\n\n";
	}
}

void Driver::printInfo()
{
	cout << "��������: " << name.str << endl;
	cout << "����� ����: " << carNumber.str << endl;
	cout << "���-�� ���������: " << sizeCrime << endl;
	for (int i = 0; i < sizeCrime; i++)
	{
		cout << "��������� #" << i + 1 << endl;
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
	cout << "���������� � ����� ���������:\n";
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
	cout << "������� ������ � ����� ��������: \n";
	tmp[size - 1].fillDriver();
	arr = tmp;
}

void showAllCrimesOfAllDrivers(Driver* arr, int size)
{
	int k = 0;
	for (int i = 0; i < size; i++) // ���������� ���������
	{// � ������� �������� ������������� ������ ���������
		for (int j = 0; j < arr[i].sizeCrime; j++) //������� ����
		{
			cout << "\n��������� #" << ++k << endl;
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
	
	if (id == -1) cout << "���������� � ������� \"" << number << "\" �� ������.\n\n";
	else
	{
		for (int j = 0; j < arr[id].sizeCrime; j++)
		{
			if (payment >= arr[id].arr[j].fine)
			{
				payment -= arr[id].arr[j].fine;
				arr[id].arr[j].fine = 0; // ���������� �����
				cout << "����� \"" << arr[id].arr[j].description.str << "\" �� ����� [" << arr[id].arr[j].date_of_crime.toString() << "] ��������� �������.\n\n";
			}
			else
			{
				arr[id].arr[j].fine -= payment;
				payment = 0;
				cout << "�����: " << arr[id].arr[j].description.str << " �� ����� [" << arr[id].arr[j].date_of_crime.toString() << "] �������� �������.\n\n";
				cout << "������� � �������: " << arr[id].arr[j].fine << " ������.\n\n";
			}
		}
	}
	if (payment > 0) cout << "� ��� �������� �����. ������ �������� � � ���.�����.\n\n";
}

void listOfViolators(Driver* arr, int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
			cout << "���������� # " << i + 1 << ":\n";
			cout << "��������: " << arr[i].name.str << endl;
			cout << "����� ����: " << arr[i].carNumber.str << endl;
			cout << "���-�� ���������: " << arr[i].sizeCrime;
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
	if (id == -1) cout << "���������� � ������� \"" << number << "\" �� ������.\n\n";	
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
	if (id == -1) cout << "���������� � ������� \"" << number << "\" �� ������.\n\n";
	else arr[id].addCrime();
}

