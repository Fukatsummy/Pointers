#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");

	int a = 2;     //объявление переменной
	int* pa = &a;   //объявление указателя 
	// р - pointer(Венгерская нотация)
	cout << a << endl;//Вывод значения переменной "а" на экран
	cout << &a << endl;//Взятие адреса переменной "а" прямо при выводе
	cout << pa << endl;//Вывод на экран адреса переменной "а" , хранящегося в указателе "ра"
	cout << *pa << endl;//Разыменование указателя "ра", и вывод на экран значение по адресу.

	int* pb;
	int b = 3;
	pb = &b;
	cout << b << endl;
	cout << &b << endl;
	cout << pb << endl;
	cout << *pb << endl;
	// int - int(4Byte)
	//int* - указатель на int
	//double-double
	//double*-указатель на double
}