#include "Crime.h"

void Crime::fillCrime()
{
	char tmp[200] = "";
	cout << "���� ���������: ";
	date_of_crime.fillDate(); 
	// �������� ������� - ������� ���: cin>>date_of_crime.year 
	// �������� ������� - ������� �����: cin>>date_of_crime.month 
	// �������� ������� - ������� ����: cin>>date_of_crime.day 

	cout << "�������� ���������: ";
	cin.ignore();
	cin.getline(tmp, 200);
	description.setMyString(tmp);

	cout << "����� ������: ";
	cin >> fine;
}

void Crime::printCrime()
{
	cout << "\t���� ���������: " << date_of_crime.toString() << endl;
	cout << "\t�������� ���������: " << description.str << endl;
	cout << "\t������: " << fine << " ���.\n";
	cout << "\t============================================\n\n";
}
