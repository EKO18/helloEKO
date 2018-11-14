// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;


class Student
{
public:

	char*	name = new char[30];

	Student()
	{

	}
	Student(char* name)
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




public:

	List();


	void Add(T);
	void Del(char*);
	void Insert(T, int);

	T getElement(char*);

	int FindElement(T);

	void Print();



	~List();
};

class Group
{
public:
	List<Student> students;

	Group()
	{

	}


};

int main()
{
	setlocale(LC_ALL, "rus");
	Group* MyGroup = new Group();


	int count = -1;
	for (;;)
	{
		system("cls");
		cout << "1 - Добавить студента" << endl;
		cout << "2 - Вывести студентов" << endl;
		char	symb = _getch();

		if (symb == '1')
		{
			char* name = new char[30];



			cout << "Нажмите любую клавишу...";
			cin.clear();
			cin.ignore();
			system("cls");
			cout << "Введите ФИО студента: ";
			cin.getline(name, 30);
			MyGroup->students.Add(Student(name));
			//	MyGroup->students->Add(Student(name));
			count++;


		}
		else if (symb == '2')
		{
			system("cls");

			MyGroup->students.Print();

			system("pause");
		}

	}

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
T List<T>::getElement(char* name)
{

	for (int i = 0; i <= count; i++)
	{
		if (PosPtr[i].name == name)
		{
			return PosPtr[i];
		}

	}
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
template<typename T>
void List<T>::Del(char* name)
{

	if (count > -1)
	{
		T* tmp = new T[count + 1];
		int indx = 0;
		if ((count - 1) != -1)
		{
			for (int i = 0; i <= count; i++)
			{
				if (tmp[indx].name == name)
				{
					i--;
				}
				else
				{
					tmp[i] = PosPtr[indx];

				}
				indx++;
			}
		}
		count--;
		PosPtr = new T[count + 1];
		for (int i = 0; i <= count; i++)
		{
			PosPtr[i] = tmp[i];
		}

	}


}
template<typename T>
void List<T>::Insert(T element, int index)
{
	if ((count - 1) != -1)
	{
		count++;
		T* tmp = new T[count + 1];
		int indx = 0;
		if ((count - 1) != -1)
		{
			for (int i = 0; i <= count; i++)
			{
				if (indx == index)
				{
					tmp[indx] = element;
					i--;
				}
				else
				{
					tmp[indx] = PosPtr[i];

				}
				indx++;
			}
		}
		PosPtr = new T[count];
		for (int i = 0; i <= count; i++)
		{
			PosPtr[i] = tmp[i];
		}
		delete[] tmp;
	}

}
template<typename T>
int List<T>::FindElement(T element)
{

	if ((count - 1) != -1)
	{
		for (int i = 0; i <= count - 1; i++)
		{
			if (PosPtr[i] == element) return i;
		}
		return -1;
	}
	else return -1;



}




template<typename T>
void List<T>::Print()
{
	for (int i = 0; i < count + 1; i++)
	{
		cout << "============================================" << endl;
		PosPtr[i].Print();
	}
	cout << "============================================" << endl;
}
template<typename T>
List<T>::~List()
{

}


