#include"Date.h"
#include"MyString.h"

struct Crime
{
	Date date_of_crime;		//���� ���������
	MyString description;	//�������� ���������
	float fine = 0;			//����� ������

	void fillCrime();

	void printCrime();
};
