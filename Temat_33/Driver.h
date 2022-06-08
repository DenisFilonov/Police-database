#include"Crime.h"

struct Driver
{
	MyString name;		//��� ��������
	MyString carNumber; //����� ����
	int sizeCrime = 0;	//���-�� ���������
	Crime* arr = NULL;	//������ ���������



	void fillDriver();		//��������� ���� �� ��������
	void printInfo();		//������� ���� �� ��������
	void addCrime();		//���������� ���������
	float calcTotalFine();	//������� ���������� ������
};

void addItem(Driver*& arr, int& size); //1
void showAllCrimesOfAllDrivers(Driver* arr, int size); //4
void payCrimeBycarNumber(Driver* arr, int size, const char* number, float payment); //7
void listOfViolators(Driver* arr, int size); //2
void showDataBase(Driver* arr, int size); //3
void showInfoByCarNumber(Driver* arr, int size, const char* number); //6
void addCarNumber(Driver*& arr, int& size, const char* namuber); //5
