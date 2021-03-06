// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

class Student
{
public:
	const char*	name = new char[30];

	Student()
	{

	}
	Student(const char* name)
	{
		this->name = name;
	}

	void Print()
	{
		cout << "ФИО: " << name << endl;
	}
};

template <typename T>
class List 
{
private:
	int count;
	T* PosPtr;

	void TakeList(List* list) {
		try
		{
			if (list == NULL) {
				throw 1;
			}
			else {
				throw 2;
			}
		}
		catch (int error)
		{
			switch (error) {

			case 1: {
				cout << "List is empty" << endl;
				break;
			}
			case 2: {
				cout << "Else error" << endl;
				break;
			}
			}
		}
	}

public:
	List();
	void Add(T);
};

int main()
{
	setlocale(LC_ALL, "rus");
	
	List<Student> students;
	students.Add("Ваня");
	students.Add("Руся");
	students.Add("Ник");
	students.Add("Тёма");
	students.Add("Вейп");
	students.Add("Лёша");
	students.Add("Макс");
	students.Add("Ден");
	students.Add("Вова");

	system("color 17");
	cout << "HELLO EKO!" << endl;
	system("pause");
	return 0;
}

template<typename T>
List<T>::List()
{
	count = -1;
}

template<typename T>
void List<T>::Add(T element)
{
	count++;
	T* tmp = new T[count + 1];
	if ((count - 1) != -1)
	{
		for (int i = 0; i <= count - 1; i++)
		{
			tmp[i] = PosPtr[i];
		}
	}

	tmp[count] = element;

	PosPtr = new T[count + 1];
	for (int i = 0; i <= count; i++)
	{
		PosPtr[i] = tmp[i];
	}
	delete[] tmp;
}

void fromFileToList(const char* fileName, List<Student> list)
{
	char* buf = new char[100];
	ifstream fin(fileName);

	fin.getline(buf, 100);
	fin.close();

	list.Add(buf);
}