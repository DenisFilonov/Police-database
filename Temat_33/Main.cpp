#include"Driver.h"
#include<Windows.h>


int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//���� ���������
	/*Crime one;
	one.fillCrime();
	cout << endl << endl;
	one.printCrime();*/

	//���� ��������
	/*Driver man;
	man.fillDriver();
	cout << endl << endl;
	man.printInfo();
	cout << endl << endl;
	man.addCrime();
	cout << endl << endl;
	cout << "����� �����: " << man.calcTotalFine() << " ���.\n\n";*/

	int N = 0;					//���-�� ���������
	Driver* drivers = NULL;		//������ ���������
	int menu = 0;
	float crimePaying = 0;

	do
	{
		cout << "1. ������ �������� � ���� ������.\n"; //+
		cout << "2. �������� ������ �����������.\n"; // ���, ����� ���� � ���-�� ���������
		cout << "3. �������� ������ ������ ���� ������.\n"; //+
		cout << "4. �������� ������ ���� ��������� � ���� ���������.\n";//+
		cout << "5. �������� ��������� �� ������ ����.\n"; //+
		cout << "6. �������� ���������� �� ������ ����.\n"; //+
		cout << "7. �������� ����� �� ������ ����.\n";	//+
		cout << "0. ��������� ������ � ��� �������.\n�����: ";
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
			cout << "\n����� ����: ";
			cin.ignore();
			cin.getline(d, 100);
			addCarNumber(drivers, N, d);
			break;
		}
		case 6: 
		{
			char s[100] = "";
			cout << "\n����� ����: ";
			cin.ignore();
			cin.getline(s, 100);
			showInfoByCarNumber(drivers, N, s);
			break;
		}

		case 7:
		{
			char car[100];
			cout << "\n����� ����: ";
			cin.ignore();
			cin.getline(car, 100);
			cout << "������ ������: ";
			cin >> crimePaying;
			payCrimeBycarNumber(drivers, N, car, crimePaying);
			break;
		}

		default: if (menu > 7 && menu != 0) cout << "������� ������ ����� ����.\n\n";	break;
		}


	} while (menu != 0);







	system("pause");
	return 0;
}