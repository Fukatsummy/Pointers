#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS
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
#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr + i << "\t";
		//cout << *(arr + i) << "\t";
	}
	cout << endl;
	for(int*p_arr=arr; *p_arr!=0xCCCCCCCC;p_arr++)
	{
		cout << *p_arr << "\t";
	}
	cout << endl;
}