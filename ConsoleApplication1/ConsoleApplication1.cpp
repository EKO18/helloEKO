// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using std::cout;
using std::endl;
using std::cin;

int main()
{
	////////////////////
	setlocale(LC_ALL, "rus");

	int num1;
	int num2;
	int var = 2;
	char* str = new char[20];
	cout << "Введите значение num1: ";
	cin >> num1;
	cout << "Введите значение num2: ";
	cin >> num2;


	cout << "num1 + num2 = " << num1 + num2 << endl;
	cout << "num1 / num2 = ";

	cout << "Введите строку: ";
	cin.getline(str, 20);

	try
	{
		if (num2 == 0)
		{
			throw 123;
		}
		cout << num1 / num2 << endl;
	}
	catch (int i)
	{
		cout << "Ошибка №" << i << " - на 0 делить нельзя!!!!" << endl;
	}

	cout << "num1 - num2 = " << num1 - num2 << endl;

	cout << "Программа завершила работу!" << endl << endl;;
	////////////////////
	int a;

	system("color 17");
	cout << "HELLO EKO!" << endl;
	system("pause");
    return 0;
}

