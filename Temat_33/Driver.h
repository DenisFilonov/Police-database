#include"Crime.h"

struct Driver
{
	MyString name;		//ФИО водителя
	MyString carNumber; //Номер авто
	int sizeCrime = 0;	//Кол-во нарушения
	Crime* arr = NULL;	//Массив нарушений



	void fillDriver();		//Заполнить инфу по водителю
	void printInfo();		//Вывести инфу по водителю
	void addCrime();		//Добавление нарушения
	float calcTotalFine();	//Подсчёт суммарного штрафа
};

void addItem(Driver*& arr, int& size); //1
void showAllCrimesOfAllDrivers(Driver* arr, int size); //4
void payCrimeBycarNumber(Driver* arr, int size, const char* number, float payment); //7
void listOfViolators(Driver* arr, int size); //2
void showDataBase(Driver* arr, int size); //3
void showInfoByCarNumber(Driver* arr, int size, const char* number); //6
void addCarNumber(Driver*& arr, int& size, const char* namuber); //5
